<?php

/*
 * Copyright 2011 Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * Oversees a daemon and restarts it if it fails.
 *
 * @group daemon
 */
class PhutilDaemonOverseer {

  private $captureBufferSize = 65536;

  private $deadline;
  private $deadlineTimeout  = 300;
  private $restartDelay     = 30;
  private $killDelay        = 3;

  private $daemon;
  private $argv;
  private $childPID;
  private $signaled;
  private static $instance;

  public function __construct($daemon, array $argv) {
    $this->daemon = $daemon;
    $this->argv = array_slice($argv, 1);

    if (self::$instance) {
      throw new Exception(
        "You may not instantiate more than one Overseer per process.");
    }

    self::$instance = $this;

    declare(ticks = 1);
    pcntl_signal(SIGUSR1, array($this, 'didReceiveKeepaliveSignal'));

    pcntl_signal(SIGINT,  array($this, 'didReceiveTerminalSignal'));
    pcntl_signal(SIGTERM, array($this, 'didReceiveTerminalSignal'));
  }

  public function run() {

    $root = phutil_get_library_root('phutil');
    $root = dirname($root);
    $exec_daemon = $root.'/scripts/daemon/exec/exec_daemon.php';

    $argv = $this->argv;
    array_unshift($argv, $exec_daemon, $this->daemon);
    foreach ($argv as $k => $arg) {
      $argv[$k] = escapeshellarg($arg);
    }

    $command = 'exec '.implode(' ', $argv);

    while (true) {
      $this->logMessage('[INIT] Starting process.');

      $future = new ExecFuture($command);
      $future->setStdoutSizeLimit($this->captureBufferSize);
      $future->setStderrSizeLimit($this->captureBufferSize);

      $this->deadline = time() + $this->deadlineTimeout;

      $future->isReady();
      $this->childPID = $future->getPID();

      do {
        do {
          // $memuse = number_format(memory_get_usage() / 1024, 1);
          // $this->logMessage('[STAT] Memory Usage: '.$memuse.' KB');

          // We need a shortish timeout here so we can run the tick handler
          // frequently in order to process signals.
          $result = $future->resolve(1);

          if ($result !== null) {
            list($err) = $result;
            if ($err) {
              $this->logMessage('[FAIL] Process edited with error '.$err.'.');
            } else {
              $this->logMessage('[DONE] Process exited successfully.');
            }
            break 2;
          }
        } while (time() < $this->deadline);

        $this->logMessage('[HANG] Hang detected. Restarting process.');
        $this->annihilateProcessGroup();
      } while (false);

      $this->logMessage('[WAIT] Waiting to restart process.');
      sleep($this->restartDelay);
    }
  }

  public function didReceiveKeepaliveSignal($signo) {
    $this->deadline = time() + $this->deadlineTimeout;
  }

  public function didReceiveTerminalSignal($signo) {
    if ($this->signaled) {
      exit(128 + $signo);
    }
    echo "\n>>> Shutting down...\n";
    $this->signaled = true;
    $this->annihilateProcessGroup();
    exit(128 + $signo);
  }

  private function logMessage($message) {
    echo date('Y-m-d g:i:s A').' '.$message."\n";
  }

  private function annihilateProcessGroup() {
    $pid = $this->childPID;
    $pgid = posix_getpgid($pid);
    if ($pid && $pgid) {
      exec("kill -TERM -- -{$pgid}");
      sleep($this->killDelay);
      exec("kill -KILL -- -{$pgid}");
      $this->childPID = null;
    }
  }

}
