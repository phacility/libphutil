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
 */
final class PhutilSocketChannel extends PhutilChannel {

  private $readSocket;
  private $writeSocket;
  private $isSingleSocket;

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
    parent::__construct();

    foreach (array($read_socket, $write_socket) as $socket) {
      if (!$socket) {
        continue;
      }
      $ok = stream_set_blocking($socket, false);
      if (!$ok) {
        throw new Exception(pht('Failed to set socket nonblocking!'));
      }
    }

    $this->readSocket = $read_socket;
    if ($write_socket) {
      $this->writeSocket = $write_socket;
    } else {
      $this->writeSocket = $read_socket;
      $this->isSingleSocket = true;
    }
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
      throw new Exception(pht('%s failed!', 'stream_socket_pair()'));
    }

    $x = new PhutilSocketChannel($pair[0]);
    $y = new PhutilSocketChannel($pair[1]);

    return array($x, $y);
  }

  public function isOpen() {
    return ($this->isOpenForReading() || $this->isOpenForWriting());
  }

  public function isOpenForReading() {
    return (bool)$this->readSocket;
  }

  public function isOpenForWriting() {
    return (bool)$this->writeSocket;
  }

  protected function readBytes($length) {
    $socket = $this->readSocket;
    if (!$socket) {
      return '';
    }

    $data = @fread($socket, min($length, 64 * 1024));

    if ($data === false) {
      $this->closeReadSocket();
      $data = '';
    }

    // NOTE: fread() continues returning empty string after the socket is
    // closed, we need to check for EOF explicitly.
    if ($data === '') {
      if (feof($socket)) {
        $this->closeReadSocket();
      }
    }

    return $data;
  }

  protected function writeBytes($bytes) {
    $socket = $this->writeSocket;
    if (!$socket) {
      return 0;
    }

    $len = phutil_fwrite_nonblocking_stream($socket, $bytes);
    if ($len === false) {
      $this->closeWriteSocket();
      return 0;
    }
    return $len;
  }

  protected function getReadSockets() {
    if ($this->readSocket) {
      return array($this->readSocket);
    }
    return array();
  }

  protected function getWriteSockets() {
    if ($this->writeSocket) {
      return array($this->writeSocket);
    } else {
      return array();
    }
  }

  private function closeReadSocket() {
    $this->closeOneSocket($this->readSocket);
    $this->readSocket = null;
    if ($this->isSingleSocket) {
      $this->writeSocket = null;
    }
  }

  private function closeWriteSocket() {
    $this->closeOneSocket($this->writeSocket);
    $this->writeSocket = null;
    if ($this->isSingleSocket) {
      $this->readSocket = null;
    }
  }

  public function closeWriteChannel() {
    $this->closeWriteSocket();
  }

  private function closeOneSocket($socket) {
    if (!$socket) {
      return;
    }
    // We should also stream_socket_shutdown() here but HHVM throws errors
    // with it (for example 'Unexpected object type PlainFile'). We depend
    // just on fclose() until it is fixed.
    @fclose($socket);
  }

  private function closeSockets() {
    $this->closeReadSocket();
    $this->closeWriteSocket();
  }

}
