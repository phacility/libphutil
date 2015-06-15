<?php

/**
 * Concatenates PHP files together into a single stream. Used by Phage to
 * transmit bootloading code.
 */
final class PhutilBallOfPHP extends Phobject {

  private $parts = array();

  public function addFile($path) {
    $data = Filesystem::readFile($path);
    if (strncmp($data, "<?php\n", 6)) {
      throw new Exception(
        pht(
          "Expected file '%s' to begin `%s`.",
          $path,
          '<?php\n'));
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
