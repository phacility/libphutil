<?php

final class PhagePHPAgent extends Phobject {

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
            foreach ($this->exec as $read_key => $read_future) {
              $this->readFuture($read_key, $read_future);
            }

            break;
          } else {
            $this->resolveFuture($key, $future);
          }
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
      throw new Exception(pht('Channel closed!'));
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

        $timeout = $spec['timeout'];
        if ($timeout) {
          $future->setTimeout(ceil($timeout));
        }

        $future->isReady();

        $this->exec[$key] = $future;
        break;
      case 'EXIT':
        $this->terminateAgent();
        break;
    }
  }

  private function readFuture($key, ExecFuture $future) {
    $master = $this->getMaster();

    list($stdout, $stderr) = $future->read();
    $future->discardBuffers();

    if (strlen($stdout)) {
      $master->write(
        array(
          'type' => 'TEXT',
          'key' => $key,
          'kind' => 'stdout',
          'text' => $stdout,
        ));
    }

    if (strlen($stderr)) {
      $master->write(
        array(
          'type' => 'TEXT',
          'key' => $key,
          'kind' => 'stderr',
          'text' => $stderr,
        ));
    }
  }

  private function resolveFuture($key, ExecFuture $future) {
    $result = $future->resolve();
    $master = $this->getMaster();

    $master->write(
      array(
        'type'    => 'RSLV',
        'key'     => $key,
        'err'     => $result[0],
        'stdout'  => $result[1],
        'stderr'  => $result[2],
        'timeout' => (bool)$future->getWasKilledByTimeout(),
      ));

    unset($this->exec[$key]);
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
