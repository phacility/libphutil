<?php

final class PhutilProseDiff extends Phobject {

  private $parts = array();

  public function addPart($type, $text) {
    $this->parts[] = array(
      'type' => $type,
      'text' => $text,
    );
    return $this;
  }

  public function getParts() {
    return $this->parts;
  }

  public function reorderParts() {
    // Reorder sequences of removed and added sections to put all the "-"
    // parts together first, then all the "+" parts together. This produces
    // a more human-readable result than intermingling them.
    $o_run = array();
    $n_run = array();
    $result = array();
    foreach ($this->parts as $part) {
      $type = $part['type'];
      switch ($type) {
        case '-':
          $o_run[] = $part;
          break;
        case '+':
          $n_run[] = $part;
          break;
        default:
          foreach ($o_run as $o) {
            $result[] = $o;
          }
          foreach ($n_run as $n) {
            $result[] = $n;
          }
          $result[] = $part;
          $o_run = array();
          $n_run = array();
          break;
      }
    }

    foreach ($o_run as $o) {
      $result[] = $o;
    }
    foreach ($n_run as $n) {
      $result[] = $n;
    }

    // Now, combine consecuitive runs of the same type of change (like a
    // series of "-" parts) into a single run.
    $combined = array();

    $last = null;
    $last_text = null;
    foreach ($result as $part) {
      $type = $part['type'];

      if ($last !== $type) {
        if ($last !== null) {
          $combined[] = array(
            'type' => $last,
            'text' => $last_text,
          );
        }
        $last_text = null;
        $last = $type;
      }

      $last_text .= $part['text'];
    }

    if ($last_text !== null) {
      $combined[] = array(
        'type' => $last,
        'text' => $last_text,
      );
    }

    $this->parts = $combined;

    return $this;
  }

}
