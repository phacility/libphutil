<?php

final class PhagePHPAgent {

  private $stdin;
  private $master;
  private $exec = array();

  public function __construct($stdin) {
    $this->stdin = $stdin;
  }

  public function execute() {
    while (true) {
      if ($this->exec) {
        $iterator = new FutureIterator($this->exec);
        $iterator->setUpdateInterval(0.050);
        foreach ($iterator as $key => $future) {
          if ($future === null) {
            break;
          }
          $this->resolveFuture($key, $future);
          break;
        }
      } else {
        PhutilChannel::waitForAny(array($this->getMaster()));
      }

      $this->processInput();
    }
  }

  private function getMaster() {
    if (!$this->master) {
      $raw_channel = new PhutilSocketChannel(
        $this->stdin,
        fopen('php://stdout', 'w'));

      $json_channel = new PhutilJSONProtocolChannel($raw_channel);
      $this->master = $json_channel;
    }

    return $this->master;
  }

  private function processInput() {
    $channel = $this->getMaster();

    $open = $channel->update();
    if (!$open) {
      throw new Exception('Channel closed!');
    }

    while (true) {
      $command = $channel->read();
      if ($command === null) {
        break;
      }
      $this->processCommand($command);
    }
  }

  private function processCommand(array $spec) {
    switch ($spec['type']) {
      case 'EXEC':
        $key = $spec['key'];
        $cmd = $spec['command'];

        $future = new ExecFuture('%C', $cmd);
        $this->exec[$key] = $future;
        break;
      case 'EXIT':
        $this->terminateAgent();
        break;
    }
  }

  private function resolveFuture($key, Future $future) {
    $result = $future->resolve();
    $master = $this->getMaster();

    $master->write(
      array(
        'type'    => 'RSLV',
        'key'     => $key,
        'err'     => $result[0],
        'stdout'  => $result[1],
        'stderr'  => $result[2],
      ));
  }

  public function __destruct() {
    $this->terminateAgent();
  }

  private function terminateAgent() {
    foreach ($this->exec as $key => $future) {
      $future->resolveKill();
    }
    exit(0);
  }

}
