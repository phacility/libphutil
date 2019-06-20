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
        ->setPID((int)$pid)
        ->setCommand($command);

      // If this process is a "phd-daemon" process, mark it as a daemon
      // overseer.
      $is_overseer = (bool)preg_match('/\bphd-daemon\b/', $command);
      $ref->setIsOverseer($is_overseer);

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

}
