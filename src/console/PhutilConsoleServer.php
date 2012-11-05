<?php

/**
 * @group console
 */
final class PhutilConsoleServer {

  private $clients = array();
  private $handler;
  private $enableLog;

  public function handleMessage(PhutilConsoleMessage $message) {
    $data = $message->getData();
    $type = $message->getType();

    switch ($type) {

      case PhutilConsoleMessage::TYPE_CONFIRM:
        $ok = phutil_console_confirm($data['prompt'], !$data['default']);
        return $this->buildMessage(
          PhutilConsoleMessage::TYPE_INPUT,
          $ok);

      case PhutilConsoleMessage::TYPE_PROMPT:
        $response = phutil_console_prompt(
          $data['prompt'],
          idx($data, 'history'));
        return $this->buildMessage(
          PhutilConsoleMessage::TYPE_INPUT,
          $response);

      case PhutilConsoleMessage::TYPE_OUT:
        $this->writeText(STDOUT, $data);
        return null;

      case PhutilConsoleMessage::TYPE_ERR:
        $this->writeText(STDERR, $data);
        return null;

      case PhutilConsoleMessage::TYPE_LOG:
        if ($this->enableLog) {
          $this->writeText(STDERR, $data);
        }
        return null;

      default:
        if ($this->handler) {
          return call_user_func($this->handler, $message);
        } else {
          throw new Exception(
            "Received unknown console message of type '{$type}'.");
        }

    }
  }

  /**
   * Set handler called for unknown messages.
   *
   * @param callable Signature: (PhutilConsoleMessage $message).
   */
  public function setHandler($callback) {
    $this->handler = $callback;
    return $this;
  }

  private function buildMessage($type, $data) {
    $response = new PhutilConsoleMessage();
    $response->setType($type);
    $response->setData($data);
    return $response;
  }

  public function addExecFutureClient(ExecFuture $future) {
    $io_channel = new PhutilExecChannel($future);
    $protocol_channel = new PhutilPHPObjectProtocolChannel($io_channel);
    $server_channel = new PhutilConsoleServerChannel($protocol_channel);
    $io_channel->setStderrHandler(array($server_channel, 'didReceiveStderr'));
    return $this->addClient($server_channel);
  }

  public function addClient(PhutilConsoleServerChannel $channel) {
    $this->clients[] = $channel;
    return $this;
  }

  public function setEnableLog($enable) {
    $this->enableLog = $enable;
    return $this;
  }

  public function run() {
    while ($this->clients) {
      PhutilChannel::waitForAny($this->clients);
      foreach ($this->clients as $key => $client) {
        if (!$client->update()) {
          // If the client has exited, remove it from the list of clients.
          // We still need to process any remaining buffered I/O.
          unset($this->clients[$key]);
        }
        while ($message = $client->read()) {
          $response = $this->handleMessage($message);
          if ($response) {
            $client->write($response);
          }
        }
      }
    }
  }

  private function writeText($where, array $argv) {
    $text = call_user_func_array('phutil_console_format', $argv);
    fprintf($where, '%s', $text);
  }

}
