<?php

final class AphrontMultipartPart extends Phobject {

  private $headers = array();
  private $value = '';

  private $name;
  private $filename;

  public function appendRawHeader($bytes) {
    $parser = id(new AphrontHTTPHeaderParser())
      ->parseRawHeader($bytes);

    $header_name = $parser->getHeaderName();

    $this->headers[] = array(
      $header_name,
      $parser->getHeaderContent(),
    );

    if (strtolower($header_name) === 'content-disposition') {
      $pairs = $parser->getHeaderContentAsPairs();
      foreach ($pairs as $pair) {
        list($key, $value) = $pair;
        switch ($key) {
          case 'filename':
            $this->filename = $value;
            break;
          case 'name':
            $this->name = $value;
            break;
        }
      }
    }

    return $this;
  }

  public function appendData($bytes) {
    if ($this->isVariable()) {
      $this->value .= $bytes;
    } else {
      throw new Exception(pht('File multipart stuff is not yet supported.'));
    }

    return $this;
  }

  public function isVariable() {
    return ($this->filename === null);
  }

  public function getName() {
    return $this->name;
  }

  public function getVariableValue() {
    if (!$this->isVariable()) {
      throw new Exception(pht('This part is not a variable!'));
    }

    return $this->value;
  }

}
