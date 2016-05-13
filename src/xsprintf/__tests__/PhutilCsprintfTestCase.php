<?php

final class PhutilCsprintfTestCase extends PhutilTestCase {

  public function testCommandReadableEscapes() {
    $inputs = array(
      // For arguments comprised of only characters which are safe in any
      // context, %R this should avoid adding quotes.
      'ab' => true,

      // For arguments which have any characters which are not safe in some
      // context, %R should apply standard escaping.
      'a b' => false,


      'http://domain.com/path/' => true,
      'svn+ssh://domain.com/path/' => true,
      '`rm -rf`' => false,
      '$VALUE' => false,
    );

    foreach ($inputs as $input => $expect_same) {
      $actual = (string)csprintf('%R', $input);
      if ($expect_same) {
        $this->assertEqual($input, $actual);
      } else {
        $this->assertFalse($input === $actual);
      }
    }
  }

  public function testPowershell() {
    $cmd = csprintf('%s', "\n");
    $cmd->setEscapingMode(PhutilCommandString::MODE_POWERSHELL);

    $this->assertEqual(
      '"`n"',
      (string)$cmd);
  }

  public function testNoPowershell() {
    if (!phutil_is_windows()) {
      $cmd = csprintf('%s', '#');
      $cmd->setEscapingMode(PhutilCommandString::MODE_DEFAULT);

      $this->assertEqual(
        '\'#\'',
        (string)$cmd);
    }
  }

  public function testPasswords() {
    // Normal "%s" doesn't do anything special.
    $command = csprintf('echo %s', 'hunter2trustno1');
    $this->assertTrue(strpos($command, 'hunter2trustno1') !== false);

    // "%P" takes a PhutilOpaqueEnvelope.
    $caught = null;
    try {
      csprintf('echo %P', 'hunter2trustno1');
    } catch (Exception $ex) {
      $caught = $ex;
    }
    $this->assertTrue($caught instanceof InvalidArgumentException);


    // "%P" masks the provided value.
    $command = csprintf('echo %P', new PhutilOpaqueEnvelope('hunter2trustno1'));
    $this->assertFalse(strpos($command, 'hunter2trustno1'));


    // Executing the command works as expected.
    list($out) = execx('%C', $command);
    $this->assertTrue(strpos($out, 'hunter2trustno1') !== false);
  }

  public function testEscapingIsRobust() {
    if (phutil_is_windows()) {
      $this->assertSkipped(pht("This test doesn't work on Windows."));
    }

    // Escaping should be robust even when used to escape commands which take
    // other commands.
    list($out) = execx(
      'sh -c %s',
      csprintf(
        'sh -c %s',
        csprintf(
          'sh -c %s',
          csprintf(
            'echo %P',
            new PhutilOpaqueEnvelope('!@#$%^&*()')))));
    $this->assertTrue(strpos($out, '!@#$%^&*()') !== false);
  }

}
