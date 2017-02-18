<?php

abstract class PhageAgentAction
  extends PhageAction {

  private $future;
  private $channel;
  private $commands = array();
  private $commandKey = 0;

  private $isExiting = false;
  private $isActive = false;

  final public function isContainerAction() {
    return true;
  }

  protected function willAddAction(PhageAction $action) {
    // TODO: You should probably be able to add agents to an agent, is that
    // explicit or by making agents execute actions?

    if (!($action instanceof PhageExecuteAction)) {
      throw new Exception(pht('Can only add execute actions to an agent.'));
    }
  }

  public function isActiveAgent() {
    return $this->isActive;
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

    foreach ($this->getActions() as $command) {
      $key = 'command/'.$this->commandKey++;

      $this->commands[$key] = array(
        'key' => $key,
        'command' => $command,
      );

      $channel->write(
        array(
          'type' => 'EXEC',
          'key' => $key,
          'command' => $command->getCommand()->getUnmaskedString(),
        ));
    }

    $this->future = $future;
    $this->channel = $channel;
    $this->isActive = true;
  }

  public function updateAgent() {
    if (!$this->isActiveAgent()) {
      return;
    }

    $channel = $this->channel;

    while (true) {
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

            if ($exit_code != 0) {
              $exit_code = $this->formatOutput(
                pht(
                  'Command ("%s") exited nonzero ("%s")!',
                  $command->getCommand(),
                  $exit_code),
                $key.'/exit');

              fprintf(STDOUT, $exit_code);
            }

            unset($this->commands[$key]);

            if (!$this->commands) {
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
    fprintf($target, $text);
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
