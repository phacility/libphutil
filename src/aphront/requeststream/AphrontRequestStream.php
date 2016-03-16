<?php

final class AphrontRequestStream extends Phobject {

  private $encoding;
  private $stream;
  private $closed;

  public function setEncoding($encoding) {
    $this->encoding = $encoding;
    return $this;
  }

  public function getEncoding() {
    return $this->encoding;
  }

  public function readData() {
    if ($this->closed) {
      return null;
    }

    $stream = $this->getStream();
    if (feof($stream)) {
      $this->closeStream();
      return null;
    }

    $bytes = fread($stream, 64 * 1024);
    if ($bytes === false) {
      throw new Exception(
        pht('Failed to fread() from request input stream.'));
    }

    return $bytes;
  }

  private function getStream() {
    if (!$this->stream) {
      $this->stream = $this->newStream();
    }

    return $this->stream;
  }

  private function closeStream() {
    $stream = $this->getStream();
    fclose($stream);
    $this->closed = true;
  }

  private function newStream() {
    $stream = fopen('php://input', 'rb');
    if (!$stream) {
      throw new Exception(
        pht(
          'Failed to open stream "%s" for reading.',
          'php://input'));
    }

    $encoding = $this->getEncoding();
    if ($encoding === 'gzip') {
      // This parameter is magic. Values 0-15 express a time/memory tradeoff,
      // but the largest value (15) corresponds to only 32KB of memory and
      // data encoded with a smaller window size than the one we pass can not
      // be decompressed. Always pass the maximum window size.

      // Additionally, you can add 16 (to enable gzip) or 32 (to enable both
      // gzip and zlib). Add 32 to support both.
      $zlib_window = 15 + 32;

      $ok = stream_filter_append(
        $stream,
        'zlib.inflate',
        STREAM_FILTER_READ,
        array(
          'window' => $zlib_window,
        ));
      if (!$ok) {
        throw new Exception(
          pht(
            'Failed to append filter "%s" to input stream while processing '.
            'a request with "%s" encoding.',
            'zlib.inflate',
            $encoding));
      }
    }

    return $stream;
  }

}
