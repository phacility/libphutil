<?php

final class PhutilProcessRefTestCase
  extends PhutilTestCase {

  public function testIdentifyOverseerProcess() {

    // Test if various process argument vectors are correctly identified as
    // daemon overseer processes or not. We're hoping to identify legitimate
    // daemons and ignore false positives for processes with titles that look
    // similar but are not really daemons, like "grep phd-daemon".

    $tests = array(
      array(
        array('php', 'phd-daemon'),
        true,
      ),
      array(
        array('/path/to/php', '/path/to/phd-daemon'),
        true,
      ),
      array(
        array('/path/to/phd-daemon'),
        true,
      ),
      array(
        array('phd-daemon'),
        true,
      ),
      array(
        array('php', 'phd-daemon', '-l', 'instance-label'),
        true,
      ),
      array(
        array('grep phd-daemon'),
        false,
      ),
      array(
        array('this-is-a-phd-daemon'),
        false,
      ),
    );

    foreach ($tests as $case) {
      list($argv, $expect) = $case;

      $ref = id(new PhutilProcessRef())
        ->setArgv($argv);

      $actual = $ref->getIsOverseer();

      $this->assertEqual(
        $expect,
        $actual,
        pht('argv: %s', implode(' ', $argv)));
    }
  }

}
