<?php

final class PhutilcsprintfTestCase extends ArcanistTestCase {

  public function testCommandReadableEscapes() {
    // For arguments comprised of only characters which are safe in any context,
    // %R this should avoid adding quotes.
    $this->assertEqual(
      true,
      ('ab' === (string)csprintf('%R', 'ab')));

    // For arguments which have any characters which are not safe in some
    // context, %R should apply standard escaping.
    $this->assertEqual(
      false,
      ('a b' === (string)csprintf('%R', 'a b')));
  }

  public function testPasswords() {

    // Normal "%s" doesn't do anything special.
    $command = csprintf('echo %s', 'hunter2trustno1');
    $this->assertEqual(
      true,
      strpos($command, 'hunter2trustno1') !== false);

    // "%P" takes a PhutilOpaqueEnvelope.
    $caught = null;
    try {
      csprintf('echo %P', 'hunter2trustno1');
    } catch (Exception $ex) {
      $caught = $ex;
    }
    $this->assertEqual(
      true,
      ($caught instanceof Exception));


    // "%P" masks the provided value.
    $command = csprintf('echo %P', new PhutilOpaqueEnvelope('hunter2trustno1'));
    $this->assertEqual(
      false,
      strpos($command, 'hunter2trustno1'));


    // Executing the command works as expected.
    list($out) = execx('%C', $command);
    $this->assertEqual(
      true,
      strpos($out, 'hunter2trustno1') !== false);


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
      $this->assertEqual(
        true,
        strpos($out, '!@#$%^&*()') !== false);
    }

  }

}
