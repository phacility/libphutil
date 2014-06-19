<?php

/**
 * WARNING: This is not quite usable yet. See T5297.
 *
 * @phutil-external-symbol class JsonLintJsonParser
 * @phutil-external-symbol class JsonLintParsingException
 */
final class PhutilJSONParser {

  public function parse($json) {
    $jsonlint_root = phutil_get_library_root('phutil').'/../externals/jsonlint';
    require_once($jsonlint_root.'/src/Seld/JsonLint/JsonParser.php');
    require_once($jsonlint_root.'/src/Seld/JsonLint/Lexer.php');
    require_once($jsonlint_root.'/src/Seld/JsonLint/ParsingException.php');
    require_once($jsonlint_root.'/src/Seld/JsonLint/Undefined.php');

    if (!$json) {
      throw new PhutilJSONParserException(
        pht(
          '%s is not a valid JSON object.',
          PhutilReadableSerializer::printShort($json)));
    }

    $parser = new JsonLintJsonParser();
    try {
      $output = $parser->parse($json);
    } catch (JsonLintParsingException $ex) {
      throw new PhutilJSONParserException($ex->getMessage());
    }

    if (!$output instanceof stdClass && !is_array($output)) {
      throw new PhutilJSONParserException(
        pht(
          '%s is not a valid JSON object.',
          PhutilReadableSerializer::printShort($json)));
    }

    return (array)$output;
  }

}
