<?php

/**
 * NOTE: This is very new and unstable.
 */
final class PhutilSpriteSheet {

  private $sprites = array();
  private $sources = array();
  private $cssHeader;
  private $generated;

  private $css;
  private $image;

  public function addSprite(PhutilSprite $sprite) {
    $this->generated = false;
    $this->sprites[] = $sprite;
    return $this;
  }

  public function setCSSHeader($header) {
    $this->generated = false;
    $this->cssHeader = $header;
    return $this;
  }

  private function generate() {
    if ($this->generated) {
      return;
    }

    $css = array();
    if ($this->cssHeader) {
      $css[] = $this->cssHeader;
    }

    $vertical_margin = 1;

    $out_w = 0;
    $out_h = 0;
    foreach ($this->sprites as $sprite) {
      $out_w = max($out_w, $sprite->getSourceW());
      $out_h += $sprite->getSourceH();

      $out_h += $vertical_margin;
    }

    $out = imagecreatetruecolor($out_w, $out_h);
    imagesavealpha($out, true);
    imagefill($out, 0, 0, imagecolorallocatealpha($out, 0, 0, 0, 127));

    $pos_x = 0;
    $pos_y = 0;
    foreach ($this->sprites as $sprite) {
      $src = $this->loadSource($sprite);

      imagecopy(
        $out,             $src,
        $pos_x, $pos_y,   $sprite->getSourceX(), $sprite->getSourceY(),
                          $sprite->getSourceW(), $sprite->getSourceH());

      $rule = $sprite->getTargetCSS();
      $cssx = (-$pos_x).'px';
      $cssy = (-$pos_y).'px';

      $css[] = "{$rule} {\n  background-position: {$cssx} {$cssy};\n}";
      $pos_y += $sprite->getSourceH();
      $pos_y += $vertical_margin;
    }

    $this->image = $out;
    $this->css = implode("\n\n", $css)."\n";
    $this->generated = true;
  }

  public function generateImage($path) {
    $this->generate();
    $this->log("Writing sprite '{$path}'...");
    imagepng($this->image, $path);
  }

  public function generateCSS($path) {
    $this->generate();
    $this->log("Writing CSS '{$path}'...");
    Filesystem::writeFile($path, $this->css);
  }

  private function log($message) {
    echo $message."\n";
  }

  private function loadSource(PhutilSprite $sprite) {
    $file = $sprite->getSourceFile();
    if (empty($this->sources[$file])) {
      $data = Filesystem::readFile($file);
      $this->sources[$file] = imagecreatefromstring($data);
    }
    return $this->sources[$file];
  }

}
