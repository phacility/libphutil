<?php

final class PhagePHPAgentBootloader extends PhageAgentBootloader {

  private $bootSequence;
  private $bootLength;
  private $mainLength;

  public function getName() {
    return 'php';
  }

  public function getBootCommand() {
    $this->buildBootSequence();
    $len = $this->bootLength;

    // We need to run a command which will bootload a full agent by reading
    // and evaluating source code from stdin. This is the smallest bootstrap
    // I was able to construct:
    //
    //   - Using `fread(STDIN, ...)` is only good up to 8192 bytes.
    //   - Using `fread(STDIN, ...)` or various other constructs prevents us
    //     from opening STDIN later.
    //
    // Instead, we `fread()` a second-stage bootstrap which has enough code
    // to do arbitrary-length reads from stdin. The second-stage bootstrap
    // reads and evaluates the main agent program.

    return csprintf(
      'php -r %s',
      "eval(fread(\$I=fopen('php://stdin', 'r'), {$len})); /* phage! */");
  }

  public function getBootSequence() {
    $boot = $this->buildBootSequence();
    return $boot->toString();
  }

  private function buildBootSequence() {
    if (!$this->bootSequence) {
      $files = array(
        'utils/utils.php',
        'object/Phobject.php',
        'utils/PhutilRope.php',
        'xsprintf/xsprintf.php',
        'xsprintf/csprintf.php',
        'xsprintf/PhutilCommandString.php',
        'future/Future.php',
        'future/FutureIterator.php',
        'future/exec/PhutilExecutableFuture.php',
        'future/exec/ExecFuture.php',
        'future/exec/CommandException.php',
        'channel/PhutilChannel.php',
        'channel/PhutilSocketChannel.php',
        'channel/PhutilChannelChannel.php',
        'channel/PhutilProtocolChannel.php',
        'channel/PhutilJSONProtocolChannel.php',
        'phage/agent/PhagePHPAgent.php',
      );

      $main_sequence = new PhutilBallOfPHP();
      $root = phutil_get_library_root('phutil');
      foreach ($files as $file) {
        $main_sequence->addFile($root.'/'.$file);
      }

      // NOTE: If we use id() here, we don't get a stack trace out of it when
      // we call a nonexistent method from inside "execute()"? Not exactly sure
      // what's going on here, but just sweep it under the rug for now.

      $main_sequence->addText('$A = new PhagePHPAgent($I); $A->execute();');
      $main_length = strlen($main_sequence->toString());

      $boot_sequence = new PhutilBallOfPHP();
      $boot = '
        $length = '.$main_length.';
        $buffer = "";
        while (strlen($buffer) < $length) {
          $data = fread($I, $length - strlen($buffer));
          if (!strlen($data)) {
            exit(1);
          }
          $buffer .= $data;
        }

        eval($buffer);';
      $boot_sequence->addText($boot);
      $boot_length = strlen($boot_sequence->toString());
      $boot_sequence->addText($main_sequence->toString());

      if (strlen($boot_length) > 8192) {
        throw new Exception(pht('Stage 1 bootloader is too large!'));
      }

      $this->bootSequence = $boot_sequence;
      $this->bootLength = $boot_length;
      $this->mainLength = $main_length;
    }

    return $this->bootSequence;
  }

}
