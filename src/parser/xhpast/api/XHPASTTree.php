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
 * @group xhpast
 */
final class XHPASTTree extends AASTTree {

  public function __construct(array $tree, array $stream, $source) {
    $this->setTreeType('XHP');
    $this->setNodeConstants(xhp_parser_node_constants());
    $this->setTokenConstants(xhpast_parser_token_constants());

    parent::__construct($tree, $stream, $source);
  }

  public function newNode($id, array $data, AASTTree $tree) {
    return new XHPASTNode($id, $data, $tree);
  }

  public function newToken(
    $id,
    $type,
    $value,
    $offset,
    AASTTree $tree) {
    return new XHPASTToken($id, $type, $value, $offset, $tree);
  }

  public static function newFromData($php_source) {
    $future = xhpast_get_parser_future($php_source);
    return self::newFromDataAndResolvedExecFuture(
      $php_source,
      $future->resolve());
  }

  public static function evalStaticString($string) {
    $string = '<?php '.rtrim($string, ';').';';
    $tree = XHPASTTree::newFromData($string);
    $statements = $tree->getRootNode()->selectDescendantsOfType('n_STATEMENT');
    if (count($statements) != 1) {
      throw new Exception("String does not parse into exactly one statement!");
    }
    // Return the first one, trying to use reset() with iterators ends in tears.
    foreach ($statements as $statement) {
      return $statement->evalStatic();
    }
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

}
