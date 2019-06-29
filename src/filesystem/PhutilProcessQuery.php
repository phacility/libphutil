<?php

final class PhutilProcessQuery
  extends Phobject {

  private $isOverseer;
  private $instances;

  public function withIsOverseer($is_overseer) {
    $this->isOverseer = $is_overseer;
    return $this;
  }

  public function withInstances(array $instances) {
    $this->instances = $instances;
    return $this;
  }

  public function execute() {
    if (phutil_is_windows()) {
      throw new Exception(
        pht(
          'Querying system processes is not currently supported on '.
          'Windows.'));
    }

    // TODO: See T12827. This formulation likely does not work properly on
    // Solaris.

    list($processes) = execx('ps -o pid,command -a -x -w -w -w');
    $processes = phutil_split_lines($processes, false);

    $refs = array();
    foreach ($processes as $process) {
      $parts = preg_split('/\s+/', trim($process), 2);
      list($pid, $command) = $parts;

      $ref = id(new PhutilProcessRef())
        ->setPID((int)$pid);

      $argv = $this->getArgv($pid, $command);
      $ref->setArgv($argv);

      // If this is an overseer and the command has a "-l" ("Label") argument,
      // the argument contains the "PHABRICATOR_INSTANCE" value for the daemon.
      // Parse it out and annotate the process.
      $instance = null;
      if ($ref->getIsOverseer()) {
        $matches = null;
        if (preg_match('/-l (\S+)/', $command, $matches)) {
          $instance = $matches[1];
        }
      }

      $ref->setInstance($instance);

      $refs[] = $ref;
    }

    if ($this->isOverseer !== null) {
      foreach ($refs as $key => $ref) {
        if ($ref->getIsOverseer() !== $this->isOverseer) {
          unset($refs[$key]);
        }
      }
    }

    if ($this->instances) {
      $instances_map = array_fuse($this->instances);
      foreach ($refs as $key => $ref) {
        if (!isset($instances_map[$ref->getInstance()])) {
          unset($refs[$key]);
        }
      }
    }

    return array_values($refs);
  }

  private function getArgv($pid, $command) {

    // In the output of "ps", arguments in process titles are not escaped, so
    // we can not distinguish between the processes created by running these
    // commands by looking only at the output of "ps":
    //
    //   echo 'a b'
    //   echo a b
    //
    // Both commands will have the same process title in the output of "ps".

    // This means we may split the command incorrectly in the general case,
    // and this misparsing may be important if the process binary resides in
    // a directory with spaces in its path and we're trying to identify which
    // binary a process is running.

    // On Ubuntu, and likely most other Linux systems, we can get a raw
    // command line from "/proc" with arguments delimited by "\0".

    // On macOS, there's no "/proc" and we don't currently have a robust way
    // to split the process command in a way that parses spaces properly, so
    // fall back to a best effort based on the output of "ps". This is almost
    // always correct, since it is uncommon to put binaries under paths with
    // spaces in them.

    $proc_cmdline = sprintf('/proc/%d/cmdline', $pid);
    try {
      $argv = Filesystem::readFile($proc_cmdline);
      $argv = explode("\0", $argv);

      // The output itself is terminated with "\0", so remove the final empty
      // argument.
      if (last($argv) === '') {
        array_pop($argv);
      }

      return $argv;
    } catch (Exception $ex) {
      // If we fail to read "/proc", fall through to less reliable methods.
    }

    // If we haven't found a better source, just split the "ps" output on
    // spaces.
    return preg_split('/\s+/', $command);
  }
}
