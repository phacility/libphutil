<?php

/**
 * Remarkup prevents several classes of text-processing problems by replacing
 * tokens in the text as they are marked up. For example, if you write something
 * like this:
 *
 *   //D12//
 *
 * It is processed in several stages. First the "D12" matches and is replaced:
 *
 *   //\11Z//
 *
 * Now the italics match and are replaced:
 *
 *   \12Z
 *
 * When processing completes, all the tokens are replaced again in reverse
 * order:
 *
 *   <em>\11Z</em>
 *
 * Then:
 *
 *   <em><a href="http://...">...</a></em>
 *
 * If we didn't do this, the italics rule could match the "//" in "http://",
 * or any other number of processing mistakes could occur, some of which create
 * security risks.
 *
 * This class generates keys, and stores the map of keys to replacement text.
 */
final class PhutilRemarkupBlockStorage extends Phobject {

  const MAGIC_BYTE = "\1";

  private $map = array();
  private $index;

  public function store($text) {
    $key = self::MAGIC_BYTE.(++$this->index).'Z';
    $this->map[$key] = $text;
    return $key;
  }

  public function restore($corpus, $text_mode = false) {
    if ($this->map) {
      if ($text_mode) {
        $corpus = str_replace(
          array_reverse(array_keys($this->map)),
          array_reverse($this->map),
          $corpus);
      } else {
        $corpus = phutil_safe_html(str_replace(
          array_reverse(array_keys($this->map)),
          array_map('phutil_escape_html', array_reverse($this->map)),
          phutil_escape_html($corpus)));
      }
    }
    return $corpus;
  }

  public function overwrite($key, $new_text) {
    $this->map[$key] = $new_text;
    return $this;
  }

  public function getMap() {
    return $this->map;
  }

  public function setMap(array $map) {
    $this->map = $map;
    return $this;
  }

}
