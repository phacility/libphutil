<?php

final class PhutilSystemTestCase extends PhutilTestCase {

  public function testParseVMStat() {
    $tests = array(
      'vmstat.yosemite.txt' => array(
        'total' => 16503578624,
        'free' => 1732366336,
      ),
    );

    $dir = dirname(__FILE__).'/memory';
    foreach ($tests as $input => $expect) {
      $raw = Filesystem::readFile($dir.'/'.$input);
      $actual = PhutilSystem::parseVMStat($raw);
      $this->assertEqual(
        $expect,
        $actual,
        pht('Parse of "%s".', $input));
    }
  }

  public function testParseMeminfo() {
    $tests = array(
      'meminfo.ubuntu14.txt' => array(
        'total' => 7843336192,
        'free' => 3758297088,
      ),
    );

    $dir = dirname(__FILE__).'/memory';
    foreach ($tests as $input => $expect) {
      $raw = Filesystem::readFile($dir.'/'.$input);
      $actual = PhutilSystem::parseMemInfo($raw);
      $this->assertEqual(
        $expect,
        $actual,
        pht('Parse of "%s".', $input));
    }
  }

}
