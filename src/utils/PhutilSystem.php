<?php

/**
 * Interact with the operating system.
 *
 * @task memory Interacting with System Memory
 */
final class PhutilSystem extends Phobject {


  /**
   * Get information about total and free memory on the system.
   *
   * Because "free memory" is a murky concept, the interpretation of the values
   * returned from this method will vary from system to system and the numbers
   * themselves may be only roughly accurate.
   *
   * @return map<string, wild> Dictionary of memory information.
   * @task memory
   */
  public static function getSystemMemoryInformation() {
    $meminfo_path = '/proc/meminfo';
    if (Filesystem::pathExists($meminfo_path)) {
      $meminfo_data = Filesystem::readFile($meminfo_path);
      return self::parseMemInfo($meminfo_data);
    } else if (Filesystem::binaryExists('vm_stat')) {
      list($vm_stat_stdout) = execx('vm_stat');
      return self::parseVMStat($vm_stat_stdout);
    } else {
      throw new Exception(
        pht(
          'Unable to access %s or `%s` on this system to '.
          'get system memory information.',
          '/proc/meminfo',
          'vm_stat'));
    }
  }


  /**
   * Parse the output of `/proc/meminfo`.
   *
   * See @{method:getSystemMemoryInformation}. This method is used to get memory
   * information on Linux.
   *
   * @param string Raw `/proc/meminfo`.
   * @return map<string, wild> Parsed memory information.
   * @task memory
   */
  public static function parseMemInfo($data) {
    $data = phutil_split_lines($data);

    $map = array();
    foreach ($data as $line) {
      list($key, $value) = explode(':', $line, 2);
      $key = trim($key);
      $value = trim($value);

      $matches = null;
      if (preg_match('/^(\d+) kB\z/', $value, $matches)) {
        $value = (int)$matches[1] * 1024;
      }

      $map[$key] = $value;
    }

    $expect = array(
      'MemTotal',
      'MemFree',
      'Buffers',
      'Cached',
    );
    foreach ($expect as $key) {
      if (!array_key_exists($key, $map)) {
        throw new Exception(
          pht(
            'Expected to find "%s" in "%s" output, but did not.',
            $key,
            '/proc/meminfo'));
      }
    }

    $total = $map['MemTotal'];
    $free = $map['MemFree'] + $map['Buffers'] + $map['Cached'];

    return array(
      'total' => $total,
      'free' => $free,
    );
  }


  /**
   * Parse the output of `vm_stat`.
   *
   * See @{method:getSystemMemoryInformation}. This method is used to get memory
   * information on Mac OS X.
   *
   * @param string Raw `vm_stat` output.
   * @return map<string, wild> Parsed memory information.
   * @task memory
   */
  public static function parseVMStat($data) {
    $data = phutil_split_lines($data);

    $page_size = null;
    $map = array();

    foreach ($data as $line) {
      list($key, $value) = explode(':', $line, 2);
      $key = trim($key);
      $value = trim($value);

      $matches = null;
      if (preg_match('/page size of (\d+) bytes/', $value, $matches)) {
        $page_size = (int)$matches[1];
        continue;
      }

      $value = trim($value, '.');
      $map[$key] = $value;
    }

    if (!$page_size) {
      throw new Exception(
        pht(
          'Expected to find "%s" in `%s` output, but did not.',
          'page size',
          'vm_stat'));
    }

    $expect = array(
      'Pages free',
      'Pages active',
      'Pages inactive',
      'Pages wired down',
    );
    foreach ($expect as $key) {
      if (!array_key_exists($key, $map)) {
        throw new Exception(
          pht(
            'Expected to find "%s" in `%s` output, but did not.',
            $key,
            'vm_stat'));
      }
    }

    // NOTE: This calculation probably isn't quite right. In particular,
    // the numbers don't exactly add up, and "Pages inactive" includes a
    // bunch of disk cache. So these numbers aren't totally reliable and they
    // aren't directly comparable to the /proc/meminfo numbers.

    $free = $map['Pages free'];
    $active = $map['Pages active'];
    $inactive = $map['Pages inactive'];
    $wired = $map['Pages wired down'];

    return array(
      'total' => ($free + $active + $inactive + $wired) * $page_size,
      'free' => ($free) * $page_size,
    );
  }

}
