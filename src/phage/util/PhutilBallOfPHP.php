<?php

/**
 * Concatenates PHP files together into a single stream. Used by Phage to
 * transmit bootloading code.
 */
final class PhutilBallOfPHP {

  private $parts = array();

  public function addFile($path) {
    $data = Filesystem::readFile($path);
    if (strncmp($data, "<?php\n", 6)) {
      throw new Exception(
        "Expected file '{$path}' to begin \"<?php\\n\".");
    }
    $this->parts[] = substr($data, 6);
    return $this;
  }

  public function addText($text) {
    $this->parts[] = $text;
  }

  public function toString() {
    return implode('', $this->parts);
  }

}
