<?php

/**
 * Channel on an underlying stream socket or socket pair. For a description of
 * channels, see @{class:PhutilChannel}.
 *
 * Using a network socket:
 *
 *   $socket = stream_socket_client(...);
 *   $channel = new PhutilSocketChannel($socket);
 *
 * Using stdin/stdout:
 *
 *   $channel = new PhutilSocketChannel(
 *     fopen('php://stdin', 'r'),
 *     fopen('php://stdout', 'w'));
 *
 * @task construct Construction
 *
 * @group channel
 */
final class PhutilSocketChannel extends PhutilChannel {

  private $readSocket;
  private $writeSocket;

/* -(  Construction  )------------------------------------------------------- */


  /**
   * Construct a socket channel from a socket or a socket pair.
   *
   * NOTE: This must be a //stream// socket from `stream_socket_client()` or
   * `stream_socket_server()` or similar, not a //plain// socket from
   * `socket_create()` or similar.
   *
   * @param socket  Socket (stream socket, not plain socket). If only one
   *                socket is provided, it is used for reading and writing.
   * @param socket? Optional write socket.
   *
   * @task construct
   */
  public function __construct($read_socket, $write_socket = null) {

    foreach (array($read_socket, $write_socket) as $socket) {
      if (!$socket) {
        continue;
      }
      $ok = stream_set_blocking($socket, false);
      if (!$ok) {
        throw new Exception("Failed to set socket nonblocking!");
      }
    }

    $this->readSocket = $read_socket;
    $this->writeSocket = $write_socket;
  }

  public function __destruct() {
    $this->closeSockets();
  }


  /**
   * Creates a pair of socket channels that are connected to each other. This
   * is mostly useful for writing unit tests of, e.g., protocol channels.
   *
   *   list($x, $y) = PhutilSocketChannel::newChannelPair();
   *
   * @task construct
   */
  public static function newChannelPair() {
    $sockets = null;

    $domain = phutil_is_windows() ? STREAM_PF_INET : STREAM_PF_UNIX;
    $pair = stream_socket_pair($domain, STREAM_SOCK_STREAM, STREAM_IPPROTO_IP);
    if (!$pair) {
      throw new Exception("stream_socket_pair() failed!");
    }

    $x = new PhutilSocketChannel($pair[0]);
    $y = new PhutilSocketChannel($pair[1]);

    return array($x, $y);
  }

  public function isOpen() {
    return (bool)$this->readSocket;
  }

  protected function readBytes() {
    $data = @fread($this->readSocket, 4096);

    if ($data === false) {
      $this->closeSockets();
      $data = '';
    }

    // NOTE: fread() continues returning empty string after the socket is
    // closed, we need to check for EOF explicitly.
    if ($data === '') {
      if (feof($this->readSocket)) {
        $this->closeSockets();
      }
    }

    return $data;
  }

  protected function writeBytes($bytes) {
    $socket = $this->writeSocket;
    if (!$socket) {
      $socket = $this->readSocket;
    }

    $len = @fwrite($socket, $bytes);
    if ($len === false) {
      $this->closeSockets();
      return 0;
    }
    return $len;
  }

  protected function getReadSockets() {
    return array($this->readSocket);
  }

  protected function getWriteSockets() {
    if ($this->isWriteBufferEmpty()) {
      return array();
    } else if ($this->writeSocket) {
      return array($this->writeSocket);
    } else {
      return array($this->readSocket);
    }
  }

  private function closeSockets() {
    foreach (array($this->readSocket, $this->writeSocket) as $socket) {
      if (!$socket) {
        continue;
      }

      // We should also stream_socket_shutdown() here but HHVM throws errors
      // with it (for example 'Unexpected object type PlainFile'). We depend
      // just on fclose() until it is fixed.
      @fclose($socket);
    }
    $this->readSocket = null;
    $this->writeSocket = null;
  }

}
