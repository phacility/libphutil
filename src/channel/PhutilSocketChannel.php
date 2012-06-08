<?php

/*
 * Copyright 2012 Facebook, Inc.
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
 * Channel on an underlying stream socket. For a description of channels,
 * see @{class:PhutilChannel}.
 *
 * @task construct Construction
 *
 * @group channel
 */
final class PhutilSocketChannel extends PhutilChannel {

  private $socket;


/* -(  Construction  )------------------------------------------------------- */


  /**
   * Construct a socket channel from a socket.
   *
   * NOTE: This must be a //stream// socket from `stream_socket_client()` or
   * `stream_socket_server()` or similar, not a //plain// socket from
   * `socket_create()` or similar.
   *
   * @param socket  Socket (stream socket, not plain socket).
   *
   * @task construct
   */
  public function __construct($socket) {
    $ok = stream_set_blocking($socket, false);
    if (!$ok) {
      throw new Exception("Failed to set socket nonblocking!");
    }

    $this->socket = $socket;
  }

  public function __destruct() {
    $this->closeSocket();
  }

  public function isOpen() {
    return (bool)$this->socket;
  }

  protected function readBytes() {
    $data = @fread($this->socket, 4096);

    if ($data === false) {
      $this->closeSocket();
      $data = '';
    }

    // NOTE: fread() continues returning empty string after the socket is
    // closed, we need to check for EOF explicitly.
    if ($data === '') {
      if (feof($this->socket)) {
        $this->closeSocket();
      }
    }

    return $data;
  }

  protected function writeBytes($bytes) {
    $len = @fwrite($this->socket, $bytes);
    if ($len === false) {
      $this->closeSocket();
      return 0;
    }
    return $len;
  }

  protected function getReadSockets() {
    return array($this->socket);
  }

  protected function getWriteSockets() {
    if ($this->isWriteBufferEmpty()) {
      return array();
    } else {
      return array($this->socket);
    }
  }

  private function closeSocket() {
    if ($this->socket) {
      @stream_socket_shutdown($this->socket);
      @fclose($this->socket);
      $this->socket = null;
    }
  }

}
