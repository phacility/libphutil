<?php

/**
 * A JSON parser.
 *
 * @phutil-external-symbol class JsonLintJsonParser
 * @phutil-external-symbol class JsonLintParsingException
 */
final class PhutilJSONParser extends Phobject {

  private $allowDuplicateKeys = false;

  public function setAllowDuplicateKeys($allow_duplicate_keys) {
    $this->allowDuplicateKeys = $allow_duplicate_keys;
    return $this;
  }

  public function parse($json) {
    $jsonlint_root = phutil_get_library_root('phutil').'/../externals/jsonlint';
    require_once $jsonlint_root.'/src/Seld/JsonLint/JsonParser.php';
    require_once $jsonlint_root.'/src/Seld/JsonLint/Lexer.php';
    require_once $jsonlint_root.'/src/Seld/JsonLint/ParsingException.php';
    require_once $jsonlint_root.'/src/Seld/JsonLint/Undefined.php';

    $parser = new JsonLintJsonParser();
    try {
      $output = $parser->parse($json, $this->getFlags());
    } catch (JsonLintParsingException $ex) {
      $details = $ex->getDetails();
      $message = preg_replace("/^Parse error .*\\^\n/s", '', $ex->getMessage());

      throw new PhutilJSONParserException(
          $message,
          idx(idx($details, 'loc', array()), 'last_line'),
          idx(idx($details, 'loc', array()), 'last_column'),
          idx($details, 'token'),
          idx($details, 'expected'));
    }

    if (!is_array($output)) {
      throw new PhutilJSONParserException(
        pht(
          '%s is not a valid JSON object.',
          PhutilReadableSerializer::printShort($json)));
    }

    return $output;
  }

  private function getFlags() {
    $flags = JsonLintJsonParser::PARSE_TO_ASSOC;

    if ($this->allowDuplicateKeys) {
      $flags |= JsonLintJsonParser::ALLOW_DUPLICATE_KEYS;
    } else {
      $flags |= JsonLintJsonParser::DETECT_KEY_CONFLICTS;
    }

    return $flags;
  }

}
