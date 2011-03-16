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
  private $deadlineTimeout  = 86400;
  private $restartDelay     = 60;
  private $killDelay        = 3;

  private $daemon;
  private $argv;
  private $childPID;
  private $signaled;
  private static $instance;

  private $traceMode;
  private $traceMemory;
  private $daemonize;
  private $phddir;
  private $conduitURI;

  public function __construct($daemon, array $argv) {
    $this->daemon = $daemon;

    $original_argv = $argv;

    $len = count($argv);
    for ($ii = 1; $ii < $len; $ii++) {
      $matches = null;
      if ($argv[$ii] == '--') {
        break;
      } else if ($argv[$ii] == '--trace') {
        $this->traceMode = true;
      } else if ($argv[$ii] == '--trace-memory') {
        $this->traceMode = true;
        $this->traceMemory = true;
      } else if ($argv[$ii] == '--daemonize') {
        $this->daemonize = true;
        unset($argv[$ii]);
      } else if (preg_match('/^--phd=(.*)$/', $argv[$ii], $matches)) {
        $this->phddir = $matches[1];
        unset($argv[$ii]);
      } else if (preg_match('/^--conduit-uri=(.*)$/', $argv[$ii], $matches)) {
        $this->conduitURI = $matches[1];
        unset($argv[$ii]);
      }
    }

    $this->argv = array_slice($argv, 1);

    if (self::$instance) {
      throw new Exception(
        "You may not instantiate more than one Overseer per process.");
    }

    self::$instance = $this;

    if ($this->daemonize) {

      // We need to get rid of these or the daemon will hang when we TERM it
      // waiting for something to read the buffers. TODO: Learn how unix works.
      fclose(STDOUT);
      fclose(STDERR);
      ob_start();

      $pid = pcntl_fork();
      if ($pid === -1) {
        throw new Exception("Unable to fork!");
      } else if ($pid) {
        exit(0);
      }
    }

    if ($this->phddir) {
      $desc = array(
        'name'            => $this->daemon,
        'pid'             => getmypid(),
        'start'           => time(),
      );
      Filesystem::writeFile(
        $this->phddir.'/daemon.'.getmypid(),
        json_encode($desc));
    }

    if ($this->conduitURI) {
      $this->conduit = new ConduitClient($this->conduitURI);
      $this->daemonLogID = $this->conduit->callMethodSynchronous(
        'daemon.launched',
        array(
          'daemon'  => $this->daemon,
          'host'    => php_uname('n'),
          'pid'     => getmypid(),
          'argv'    => json_encode(array_slice($original_argv, 1)),
        ));
    }

    declare(ticks = 1);
    pcntl_signal(SIGUSR1, array($this, 'didReceiveKeepaliveSignal'));

    pcntl_signal(SIGINT,  array($this, 'didReceiveTerminalSignal'));
    pcntl_signal(SIGTERM, array($this, 'didReceiveTerminalSignal'));
  }

  public function run() {
    if (!$this->traceMode) {
      echo "Running daemon '{$this->daemon}' silently. Use '--trace' to ".
           "produce debugging output.\n";
    }

    $root = phutil_get_library_root('phutil');
    $root = dirname($root);

    $exec_dir = $root.'/scripts/daemon/exec/';

    $exec_daemon = './exec_daemon.php';
    $argv = $this->argv;
    array_unshift($argv, $exec_daemon, $this->daemon);
    foreach ($argv as $k => $arg) {
      $argv[$k] = escapeshellarg($arg);
    }

    $command = implode(' ', $argv);

    while (true) {
      $this->logMessage('INIT', 'Starting process.');

      $future = new ExecFuture($command);
      $future->setCWD($exec_dir);
      $future->setStdoutSizeLimit($this->captureBufferSize);
      $future->setStderrSizeLimit($this->captureBufferSize);

      $this->deadline = time() + $this->deadlineTimeout;

      $future->isReady();
      $this->childPID = $future->getPID();

      do {
        do {
          if ($this->traceMemory) {
            $memuse = number_format(memory_get_usage() / 1024, 1);
            $this->logMessage('RAMS', 'Overseer Memory Usage: '.$memuse.' KB');
          }

          // We need a shortish timeout here so we can run the tick handler
          // frequently in order to process signals.
          $result = $future->resolve(1);

          if ($this->traceMode || $this->conduit) {
            list($stdout, $stderr) = $future->read();
            $stdout = trim($stdout);
            $stderr = trim($stderr);
            if (strlen($stdout)) {
              $this->logMessage('STDO', $stdout, $stdout);
            }
            if (strlen($stderr)) {
              $this->logMessage('STDE', $stderr, $stderr);
            }
            $future->discardBuffers();
          }

          if ($result !== null) {
            list($err) = $result;
            if ($err) {
              $this->logMessage(
                'FAIL',
                'Process exited with error '.$err.'.',
                $err);
            } else {
              $this->logMessage('DONE', 'Process exited successfully.');
            }
            break 2;
          }
        } while (time() < $this->deadline);

        $this->logMessage('HANG', 'Hang detected. Restarting process.');
        $this->annihilateProcessGroup();
      } while (false);

      $this->logMessage('WAIT', 'Waiting to restart process.');
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
    fflush(STDOUT);
    fflush(STDERR);
    fclose(STDOUT);
    fclose(STDERR);
    $this->signaled = true;
    $this->annihilateProcessGroup();
    exit(128 + $signo);
  }

  private function logMessage($type, $message, $remote = null) {
    if ($this->traceMode) {
      echo date('Y-m-d g:i:s A').' ['.$type.'] '.$message."\n";
    }
    if ($this->conduit) {
      // TODO: This is kind of sketchy to do without any timeouts since a
      // conduit server hang could throw a wrench into things.
      $this->conduit->callMethodSynchronous(
        'daemon.log',
        array(
          'daemonLogID' => $this->daemonLogID,
          'type'         => $type,
          'message'      => substr($remote, 0, 1024 * 128),
        ));
    }
  }

  private function annihilateProcessGroup() {
    $pid = $this->childPID;
    $pgid = posix_getpgid($pid);
    if ($pid && $pgid) {
      exec("kill -TERM -- -{$pgid}");
      sleep($this->killDelay);

      // On OSX, we'll get a permission error on stderr if the SIGTERM was
      // successful in ending the life of the process group, presumably because
      // all that's left is the daemon itself as a zombie waiting for us to
      // reap it. However, we still need to issue this command for process
      // groups that resist SIGTERM. Rather than trying to figure out if the
      // process group is still around or not, just SIGKILL unconditionally and
      // ignore any error which may be raised.
      exec("kill -KILL -- -{$pgid} 2>/dev/null");
      $this->childPID = null;
    }
  }

}
