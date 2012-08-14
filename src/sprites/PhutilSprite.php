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
