<?php

/**
 * Parses a request string leaving all characters intact.
 *
 * http://php.net/manual/en/language.variables.external.php#language.variables.external.dot-in-names
 * http://php.net/manual/en/language.variables.external.php#81080
 */
final class PhutilQueryStringParser {

  public function parseQueryString($query_string) {
    $parsed_arr  = array();
    $query_arr   = array();

    if (strlen($query_string)) {
      $query_pairs = explode("&", $query_string);

      foreach ($query_pairs as $query) {
        $query_part_arr = explode("=", $query, 2);
        if (strlen($query_part_arr[0])) {
          $query_arr[] = array(
            "key" => $query_part_arr[0],
            "val" => isset($query_part_arr[1]) ? $query_part_arr[1] : "",
          );
        }
      }

      foreach ($query_arr as $query_parts) {
        $decoded_key = urldecode($query_parts["key"]);
        $decoded_val = urldecode($query_parts["val"]);

        $this->parseQueryKeyToArr(
          $decoded_key,
          $decoded_val,
          $parsed_arr);
      }

    }

    return $parsed_arr;
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
      $key_pieces = preg_split('/\]?\[/', rtrim($key, "]"));
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
