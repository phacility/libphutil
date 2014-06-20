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

    $parser = new JsonLintJsonParser();
    try {
      $output = $parser->parse($json);
    } catch (JsonLintParsingException $ex) {
      $details = $ex->getDetails();
      $message = preg_replace("/^Parse error .*\\^\n/s", '', $ex->getMessage());

      throw new PhutilJSONParserException(
          $message,
          $details['loc']['last_line'],
          $details['loc']['last_column'],
          $details['token'],
          $details['expected']);
    }

    if (!is_array($output)) {
      throw new PhutilJSONParserException(
        pht(
          '%s is not a valid JSON object.',
          PhutilReadableSerializer::printShort($json)));
    }

    return $output;
  }

}
