<?php

final class PhutilcsprintfTestCase extends ArcanistTestCase {

  public function testCommandReadableEscapes() {
    // For arguments comprised of only characters which are safe in any context,
    // %R this should avoid adding quotes.
    $this->assertTrue(('ab' === (string)csprintf('%R', 'ab')));

    // For arguments which have any characters which are not safe in some
    // context, %R should apply standard escaping.
    $this->assertFalse(('a b' === (string)csprintf('%R', 'a b')));
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
    $this->assertTrue($caught instanceof Exception);


    // "%P" masks the provided value.
    $command = csprintf('echo %P', new PhutilOpaqueEnvelope('hunter2trustno1'));
    $this->assertFalse(strpos($command, 'hunter2trustno1'));


    // Executing the command works as expected.
    list($out) = execx('%C', $command);
    $this->assertTrue(strpos($out, 'hunter2trustno1') !== false);


    // Escaping should be robust even when used to escape commands which take
    // other commands.
    if (!phutil_is_windows()) {
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

}
