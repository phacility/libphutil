<?php

/*
 * Copyright 2011 Facebook, Inc.
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

class XHPASTTree {

  protected $tree = array();
  protected $stream = array();

  public static function newFromData($php_source) {
    $future = xhpast_get_parser_future($php_source);
    return self::newFromDataAndResolvedExecFuture($future->resolve());
  }

  public static function newFromDataAndResolvedExecFuture(
    $php_source,
    array $resolved) {

    list($err, $stdout, $stderr) = $resolved;
    if ($err) {
      if ($err == 1) {
        $matches = null;
        $is_syntax = preg_match(
          '/^XHPAST Parse Error: (.*) on line (\d+)/',
          $stderr,
          $matches);
        if ($is_syntax) {
          throw new XHPASTSyntaxErrorException($matches[2], $stderr);
        }
      }
      throw new Exception("XHPAST failed to parse file data {$err}: {$stderr}");
    }

    $data = json_decode($stdout, true);
    if (!is_array($data)) {
      throw new Exception("XHPAST: failed to decode tree.");
    }

    return new XHPASTTree($data['tree'], $data['stream'], $php_source);
  }

  public function __construct(array $tree, array $stream, $source) {
    $ii = 0;
    $offset = 0;
    foreach ($stream as $token) {
      $this->stream[$ii] = new XHPASTToken(
        $ii,
        $token[0],
        substr($source, $offset, $token[1]),
        $offset,
        $this);
      $offset += $token[1];
      ++$ii;
    }

    $this->buildTree(array($tree));
  }

  public function getRootNode() {
    return $this->tree[0];
  }

  protected function buildTree(array $tree) {
    $ii = count($this->tree);
    $nodes = array();
    foreach ($tree as $node) {
      $this->tree[$ii] = new XHPASTNode($ii, $node, $this);
      $nodes[$ii] = $node;
      ++$ii;
    }
    foreach ($nodes as $node_id => $node) {
      if (isset($node[3])) {
        $children = $this->buildTree($node[3]);
        foreach ($children as $child) {
          $child->setParentNode($this->tree[$node_id]);
        }
        $this->tree[$node_id]->setChildren($children);
      }
    }
    return array_select_keys($this->tree, array_keys($nodes));
  }

  public function getRawTokenStream() {
    return $this->stream;
  }

  public function renderAsText() {
    return $this->executeRenderAsText(array($this->getRootNode()), 0);
  }

  protected function executeRenderAsText($list, $depth) {
    $return = '';
    foreach ($list as $node) {
      if ($depth) {
        $return .= str_repeat('  ', $depth);
      }
      $return .= $node->getDescription()."\n";
      $return .= $this->executeRenderAsText($node->getChildren(), $depth + 1);
    }
    return $return;
  }

}
