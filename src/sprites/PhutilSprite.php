<?php

/**
 * NOTE: This is very new and unstable.
 */
final class PhutilSprite {

  private $sourceFile;
  private $sourceX;
  private $sourceY;
  private $sourceW;
  private $sourceH;
  private $targetCSS;
  private $spriteSheet;

  public function setTargetCSS($target_css) {
    $this->targetCSS = $target_css;
    return $this;
  }

  public function getTargetCSS() {
    return $this->targetCSS;
  }

  public function setSourcePosition($x, $y) {
    $this->sourceX = $x;
    $this->sourceY = $y;
    return $this;
  }

  public function setSourceSize($w, $h) {
    $this->sourceW = $w;
    $this->sourceH = $h;
    return $this;
  }

  public function getSourceH() {
    return $this->sourceH;
  }

  public function getSourceW() {
    return $this->sourceW;
  }

  public function getSourceY() {
    return $this->sourceY;
  }

  public function getSourceX() {
    return $this->sourceX;
  }

  public function setSourceFile($source_file) {
    $this->sourceFile = $source_file;
    return $this;
  }

  public function getSourceFile() {
    return $this->sourceFile;
  }

}
