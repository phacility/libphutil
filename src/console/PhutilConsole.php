<?php

/**
 * Provides access to the command-line console. Instead of reading from or
 * writing to stdin/stdout/stderr directly, this class provides a richer API
 * including support for ANSI color and formatting, convenience methods for
 * prompting the user, and the ability to interact with stdin/stdout/stderr
 * in some other process instead of this one.
 *
 * @task  construct   Construction
 * @task  interface   Interfacing with the User
 * @task  internal    Internals
 */
final class PhutilConsole extends Phobject {

  private static $console;

  private $server;
  private $channel;
  private $messages = array();

  private $flushing = false;
  private $disabledTypes;


/* -(  Console Construction  )----------------------------------------------- */


  /**
   * Use @{method:newLocalConsole} or @{method:newRemoteConsole} to construct
   * new consoles.
   *
   * @task construct
   */
  private function __construct() {
    $this->disabledTypes = new PhutilArrayWithDefaultValue();
  }


  /**
   * Get the current console. If there's no active console, a new local console
   * is created (see @{method:newLocalConsole} for details). You can change the
   * active console with @{method:setConsole}.
   *
   * @return PhutilConsole  Active console.
   * @task construct
   */
  public static function getConsole() {
    if (empty(self::$console)) {
      self::setConsole(self::newLocalConsole());
    }
    return self::$console;
  }


  /**
   * Set the active console.
   *
   * @param PhutilConsole
   * @return void
   * @task construct
   */
  public static function setConsole(PhutilConsole $console) {
    self::$console = $console;
  }


  /**
   * Create a new console attached to stdin/stdout/stderr of this process.
   * This is how consoles normally work -- for instance, writing output with
   * @{method:writeOut} prints directly to stdout. If you don't create a
   * console explicitly, a new local console is created for you.
   *
   * @return PhutilConsole A new console which operates on the pipes of this
   *                       process.
   * @task construct
   */
  public static function newLocalConsole() {
    return self::newConsoleForServer(new PhutilConsoleServer());
  }


  public static function newConsoleForServer(PhutilConsoleServer $server) {
    $console = new PhutilConsole();
    $console->server = $server;
    return $console;
  }


  public static function newRemoteConsole() {
    $io_channel = new PhutilSocketChannel(
      fopen('php://stdin', 'r'),
      fopen('php://stdout', 'w'));
    $protocol_channel = new PhutilPHPObjectProtocolChannel($io_channel);

    $console = new PhutilConsole();
    $console->channel = $protocol_channel;

    return $console;
  }


/* -(  Interfacing with the User  )------------------------------------------ */


  public function confirm($prompt, $default = false) {
    $message = id(new PhutilConsoleMessage())
      ->setType(PhutilConsoleMessage::TYPE_CONFIRM)
      ->setData(
        array(
          'prompt'  => $prompt,
          'default' => $default,
        ));

    $this->writeMessage($message);
    $response = $this->waitForMessage();

    return $response->getData();
  }

  public function prompt($prompt, $history = '') {
    $message = id(new PhutilConsoleMessage())
      ->setType(PhutilConsoleMessage::TYPE_PROMPT)
      ->setData(
        array(
          'prompt'  => $prompt,
          'history' => $history,
        ));

    $this->writeMessage($message);
    $response = $this->waitForMessage();

    return $response->getData();
  }

  public function sendMessage($data) {
    $message = id(new PhutilConsoleMessage())->setData($data);
    return $this->writeMessage($message);
  }

  public function writeOut($pattern /* , ... */) {
    $args = func_get_args();
    return $this->writeTextMessage(PhutilConsoleMessage::TYPE_OUT, $args);
  }

  public function writeErr($pattern /* , ... */) {
    $args = func_get_args();
    return $this->writeTextMessage(PhutilConsoleMessage::TYPE_ERR, $args);
  }

  public function writeLog($pattern /* , ... */) {
    $args = func_get_args();
    return $this->writeTextMessage(PhutilConsoleMessage::TYPE_LOG, $args);
  }

  public function beginRedirectOut() {
    // We need as small buffer as possible. 0 means infinite, 1 means 4096 in
    // PHP < 5.4.0.
    ob_start(array($this, 'redirectOutCallback'), 2);
    $this->flushing = true;
  }

  public function endRedirectOut() {
    $this->flushing = false;
    ob_end_flush();
  }


/* -(  Internals  )---------------------------------------------------------- */

  // Must be public because it is called from output buffering.
  public function redirectOutCallback($string) {
    if (strlen($string)) {
      $this->flushing = false;
      $this->writeOut('%s', $string);
      $this->flushing = true;
    }
    return '';
  }

  private function writeTextMessage($type, array $argv) {

    $message = id(new PhutilConsoleMessage())
      ->setType($type)
      ->setData($argv);

    $this->writeMessage($message);

    return $this;
  }

  private function writeMessage(PhutilConsoleMessage $message) {
    if ($this->disabledTypes[$message->getType()]) {
      return $this;
    }

    if ($this->flushing) {
      ob_flush();
    }
    if ($this->channel) {
      $this->channel->write($message);
      $this->channel->flush();
    } else {
      $response = $this->server->handleMessage($message);
      if ($response) {
        $this->messages[] = $response;
      }
    }
    return $this;
  }

  private function waitForMessage() {
    if ($this->channel) {
      $message = $this->channel->waitForMessage();
    } else if ($this->messages) {
      $message = array_shift($this->messages);
    } else {
      throw new Exception(
        pht(
          '%s called with no messages!',
          __FUNCTION__.'()'));
    }

    return $message;
  }

  public function getServer() {
    return $this->server;
  }

  private function disableMessageType($type) {
    $this->disabledTypes[$type] += 1;
    return $this;
  }

  private function enableMessageType($type) {
    if ($this->disabledTypes[$type] == 0) {
      throw new Exception(pht("Message type '%s' is already enabled!", $type));
    }
    $this->disabledTypes[$type] -= 1;
    return $this;
  }

  public function disableOut() {
    return $this->disableMessageType(PhutilConsoleMessage::TYPE_OUT);
  }

  public function enableOut() {
    return $this->enableMessageType(PhutilConsoleMessage::TYPE_OUT);
  }

  public function isLogEnabled() {
    $message = id(new PhutilConsoleMessage())
      ->setType(PhutilConsoleMessage::TYPE_ENABLED)
      ->setData(
        array(
          'which' => PhutilConsoleMessage::TYPE_LOG,
        ));

    $this->writeMessage($message);
    $response = $this->waitForMessage();

    return $response->getData();
  }

  public function isErrATTY() {
    $message = id(new PhutilConsoleMessage())
      ->setType(PhutilConsoleMessage::TYPE_TTY)
      ->setData(
        array(
          'which' => PhutilConsoleMessage::TYPE_ERR,
        ));

    $this->writeMessage($message);
    $response = $this->waitForMessage();

    return $response->getData();
  }

  public function getErrCols() {
    $message = id(new PhutilConsoleMessage())
      ->setType(PhutilConsoleMessage::TYPE_COLS)
      ->setData(
        array(
          'which' => PhutilConsoleMessage::TYPE_ERR,
        ));

    $this->writeMessage($message);
    $response = $this->waitForMessage();

    return $response->getData();
  }


}
