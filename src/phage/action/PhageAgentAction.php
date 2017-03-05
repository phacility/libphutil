<?php

abstract class PhageAgentAction
  extends PhageAction {

  private $future;
  private $channel;
  private $commands = array();
  private $commandKey = 0;

  private $isExiting = false;
  private $isActive = false;

  private $limit = 0;
  private $throttle = 0;
  private $waitUntil;

  private $queued = array();
  private $active = array();

  final public function isContainerAction() {
    return true;
  }

  protected function willAddAction(PhageAction $action) {
    // TODO: You should probably be able to add agents to an agent, is that
    // explicit or by making agents execute actions?

    if (!($action instanceof PhageExecuteAction)) {
      throw new Exception(
        pht(
          'Can only add execute actions to an agent.'));
    }

    if ($this->isExiting) {
      throw new Exception(
        pht(
          'You can not add new actions to an exiting agent.'));
    }

    $key = 'command/'.$this->commandKey++;

    $this->commands[$key] = array(
      'key' => $key,
      'command' => $action,
    );

    $this->queued[$key] = $key;
  }

  public function isActiveAgent() {
    return $this->isActive;
  }

  final public function setLimit($limit) {
    $this->limit = $limit;
    return $this;
  }

  final public function getLimit() {
    return $this->limit;
  }

  final public function setThrottle($throttle) {
    $this->throttle = $throttle;
    return $this;
  }

  final public function getThrottle() {
    return $this->throttle;
  }

  abstract protected function newAgentFuture(PhutilCommandString $command);

  protected function getAllWaitingChannels() {
    $channels = array();

    if ($this->isActiveAgent()) {
      $channels[] = $this->channel;
    }

    return $channels;
  }

  public function startAgent() {
    $bootloader = new PhagePHPAgentBootloader();

    $future = $this->newAgentFuture($bootloader->getBootCommand());

    $future->write($bootloader->getBootSequence(), $keep_open = true);

    $channel = new PhutilExecChannel($future);
    $channel->setStderrHandler(array($this, 'didReadAgentStderr'));

    $channel = new PhutilJSONProtocolChannel($channel);

    $this->future = $future;
    $this->channel = $channel;
    $this->isActive = true;
  }

  private function updateQueue() {
    // If we don't have anything waiting in queue, we have nothing to do.
    if (!$this->queued) {
      return false;
    }

    $now = microtime(true);

    // If we're throttling commands and recently started one, don't start
    // another one yet.
    $throttle = $this->getThrottle();
    if ($throttle) {
      if ($this->waitUntil && ($now < $this->waitUntil)) {
        return false;
      }
    }

    // If we're limiting parallelism and the active list is full, don't
    // start anything else yet.
    $limit = $this->getLimit();
    if ($limit) {
      if (count($this->active) >= $limit) {
        return false;
      }
    }

    // Move a command out of the queue and tell the agent to execute it.
    $key = head($this->queued);
    unset($this->queued[$key]);

    $this->active[$key] = $key;
    $command = $this->commands[$key]['command'];

    $channel = $this->getChannel();

    $channel->write(
      array(
        'type' => 'EXEC',
        'key' => $key,
        'command' => $command->getCommand()->getUnmaskedString(),
        'timeout' => $command->getTimeout(),
      ));

    if ($throttle) {
      $this->waitUntil = ($now + $throttle);
    }

    return true;
  }

  private function getChannel() {
    return $this->channel;
  }

  public function updateAgent() {
    if (!$this->isActiveAgent()) {
      return;
    }

    $channel = $this->channel;

    while (true) {
      do {
        $did_update = $this->updateQueue();
      } while ($did_update);

      $is_open = $channel->update();

      $message = $channel->read();
      if ($message !== null) {
        switch ($message['type']) {
          case 'TEXT':
            $key = $message['key'];
            $this->writeOutput($key, $message['kind'], $message['text']);
            break;
          case 'RSLV':
            $key = $message['key'];
            $command = $this->commands[$key]['command'];

            $this->writeOutput($key, 'stdout', $message['stdout']);
            $this->writeOutput($key, 'stderr', $message['stderr']);

            $exit_code = $message['err'];

            $command->setExitCode($exit_code);
            $command->setDidTimeout((bool)idx($message, 'timeout'));

            if ($exit_code != 0) {
              $exit_code = $this->formatOutput(
                pht(
                  'Command ("%s") exited nonzero ("%s")!',
                  $command->getCommand(),
                  $exit_code),
                $command->getLabel());

              fprintf(STDOUT, '%s', $exit_code);
            }

            unset($this->active[$key]);

            if (!$this->active && !$this->queued) {
              $channel->write(
                array(
                  'type' => 'EXIT',
                  'key' => 'exit',
                ));

              $this->isExiting = true;
              break;
            }
        }
      }

      if (!$is_open) {
        if ($this->isExiting) {
          $this->isActive = false;
          break;
        } else {
          throw new Exception(pht('Channel closed unexpectedly!'));
        }
      }

      if ($message === null) {
        break;
      }
    }
  }

  private function writeOutput($key, $kind, $text) {
    if (!strlen($text)) {
      return;
    }

    switch ($kind) {
      case 'stdout':
        $target = STDOUT;
        break;
      case 'stderr':
        $target = STDERR;
        break;
      default:
        throw new Exception(pht('Unknown output kind "%s".', $kind));
    }

    $command = $this->commands[$key]['command'];

    $label = $command->getLabel();
    if (!strlen($label)) {
      $label = pht('Unknown Command');
    }

    $text = $this->formatOutput($text, $label);
    fprintf($target, '%s', $text);
  }

  private function formatOutput($output, $context) {
    $output = phutil_split_lines($output, false);
    foreach ($output as $key => $line) {
      $output[$key] = tsprintf("[%s] %R\n", $context, $line);
    }
    $output = implode('', $output);

    return $output;
  }

  public function didReadAgentStderr($channel, $stderr) {
    throw new Exception(
      pht(
        'Unexpected output on agent stderr: %s.',
        $stderr));
  }

}
