<?php

/**
 * Utilities for parsing HTTP query strings.
 *
 * The builtin functions in PHP (notably, `parse_str()` and automatic parsing
 * prior to request handling) are not suitable in the general case because they
 * silently convert some characters in parameter names into underscores.
 *
 * For example, if you call `parse_str()` with input like this:
 *
 *   x.y=z
 *
 * ...the output is this:
 *
 *   array(
 *     'x_y' => 'z',
 *   );
 *
 * ...with the `.` replaced with an underscore, `_`. Other characters converted
 * in this way include space and unmatched opening brackets.
 *
 * Broadly, this is part of the terrible legacy of `register_globals`. Since
 * we'd like to be able to parse all valid query strings without destroying any
 * data, this class implements a less-encumbered parser.
 */
final class PhutilQueryStringParser extends Phobject {


  /**
   * Parses a query string into a dictionary, applying PHP rules for handling
   * array nomenclature (like `a[]=1`) in parameter names.
   *
   * For a more basic parse, see @{method:parseQueryStringToPairList}.
   *
   * @param   string              Query string.
   * @return  map<string, wild>   Parsed dictionary.
   */
  public function parseQueryString($query_string) {
    $result = array();

    $list = $this->parseQueryStringToPairList($query_string);
    foreach ($list as $parts) {
      list($key, $value) = $parts;
      if (!strlen($key)) {
        continue;
      }
      $this->parseQueryKeyToArr($key, $value, $result);
    }

    return $result;
  }


  /**
   * Parses a query string into a basic list of pairs, without handling any
   * array information in the keys. For example:
   *
   *   a[]=1&a[]=2
   *
   * ...will parse into:
   *
   *   array(
   *     array('a[]', '1'),
   *     array('a[]', '2'),
   *   );
   *
   * Use @{method:parseQueryString} to produce a more sophisticated parse which
   * applies array rules and returns a dictionary.
   *
   * @param   string                      Query string.
   * @return  list<pair<string, string>>  List of parsed parameters.
   */
  public function parseQueryStringToPairList($query_string) {
    $list = array();

    if (!strlen($query_string)) {
      return $list;
    }

    $pairs = explode('&', $query_string);
    foreach ($pairs as $pair) {
      if (!strlen($pair)) {
        continue;
      }
      $parts = explode('=', $pair, 2);
      if (count($parts) < 2) {
        $parts[] = '';
      }
      $list[] = array(
        urldecode($parts[0]),
        urldecode($parts[1]),
      );
    }

    return $list;
  }


  /**
   * Treats the key as a flat query that potentially has square brackets. If
   * there are square brackets we parse them into an array.
   *
   * Example input:
   * $key = "email[0]";
   * $val = "my@example.com";
   *
   * Example output:
   * array("email" => array(0 => "my@example.com"));
   *
   * @param string $key
   * @param string $val
   * @param array  $input_arr
   */
  private function parseQueryKeyToArr($key, $val, array &$input_arr) {
    if (preg_match('/^[^\[\]]+(?:\[[^\[\]]*\])+$/', $key)) {
      $key_pieces = preg_split('/\]?\[/', rtrim($key, ']'));
      if ($key_pieces) {
        $cursor     = &$input_arr;
        foreach ($key_pieces as $piece) {
          if (strlen($piece)) {
            if (empty($cursor[$piece]) || !is_array($cursor[$piece])) {
              $cursor[$piece] = array();
            }
          } else {
            $cursor[] = array();
            $piece    = last_key($cursor);
          }
          $cursor = &$cursor[$piece];
        }

        $cursor = $val;
        unset($cursor);
      }
    } else {
      $input_arr[$key] = $val;
    }
  }
}
