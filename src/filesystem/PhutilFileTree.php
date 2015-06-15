<?php

/**
 * Data structure for representing filesystem directory trees.
 */
final class PhutilFileTree extends Phobject {

  private $name;
  private $fullPath;
  private $data;
  private $depth = 0;
  private $parentNode;
  private $children = array();

  public function addPath($path, $data) {
    $parts = $this->splitPath($path);
    $parts = array_reverse($parts);
    $this->insertPath($parts, $data);
    return $this;
  }

  public function destroy() {
    $this->parentNode = null;
    foreach ($this->children as $child) {
      $child->destroy();
    }
    $this->children = array();
    return $this;
  }

  /**
   * Get the next node, iterating in depth-first order.
   */
  public function getNextNode() {
    if ($this->children) {
      return head($this->children);
    }
    $cursor = $this;
    while ($cursor) {
      if ($cursor->getNextSibling()) {
        return $cursor->getNextSibling();
      }
      $cursor = $cursor->parentNode;
    }
    return null;
  }

  public function getName() {
    return $this->name;
  }

  public function getFullPath() {
    return $this->fullPath;
  }

  public function getDepth() {
    return $this->depth;
  }

  public function getData() {
    return $this->data;
  }

  protected function insertPath(array $parts, $data) {
    $part = array_pop($parts);
    if ($part === null) {
      if ($this->data) {
        $full_path = $this->getFullPath();
        throw new Exception(
          pht("Duplicate insertion for path '%s'.", $full_path));
      }
      $this->data = $data;
      return;
    }

    if (empty($this->children[$part])) {
      $node = new PhutilFileTree();
      $node->parentNode = $this;
      $node->depth = $this->depth + 1;
      $node->name = $part;
      $node->fullPath = $this->parentNode ? ($this->fullPath.'/'.$part) : $part;
      $this->children[$part] = $node;
    }

    $this->children[$part]->insertPath($parts, $data);
  }

  protected function splitPath($path) {
    $path = trim($path, '/');
    $parts = preg_split('@/+@', $path);
    return $parts;
  }

  protected function getNextSibling() {
    if (!$this->parentNode) {
      return null;
    }

    $found = false;
    foreach ($this->parentNode->children as $node) {
      if ($found) {
        return $node;
      }
      if ($this->name === $node->name) {
        $found = true;
      }
    }

    return null;
  }

}
