<?php

final class PhageAgentTestCase extends PhutilTestCase {

  public function testPhagePHPAgent() {
    return $this->runBootloaderTests(new PhagePHPAgentBootloader());
  }

  private function runBootloaderTests(PhageAgentBootloader $boot) {
    $name = get_class($boot);

    $exec = new ExecFuture('%C', $boot->getBootCommand());
    $exec->write($boot->getBootSequence(), $keep_open = true);

    $exec_channel = new PhutilExecChannel($exec);
    $agent = new PhutilJSONProtocolChannel($exec_channel);

    $agent->write(
      array(
        'type'    => 'EXEC',
        'key'     => 1,
        'command' => 'echo phage',
        'timeout' => null,
      ));

    $this->agentExpect(
      $agent,
      array(
        'type'    => 'RSLV',
        'key'     => 1,
        'err'     => 0,
        'stdout'  => "phage\n",
        'stderr'  => '',
        'timeout' => false,
      ),
      pht("'%s' for %s", 'echo phage', $name));

    $agent->write(
      array(
        'type'    => 'EXIT',
      ));
  }

  private function agentExpect(PhutilChannel $agent, $expect, $what) {
    $message = $agent->waitForMessage();
    $this->assertEqual($expect, $message, $what);
  }

}
