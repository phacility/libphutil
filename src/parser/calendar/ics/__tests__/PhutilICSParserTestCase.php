<?php

final class PhutilICSParserTestCase extends PhutilTestCase {

  public function testICSParser() {
    $root = $this->parseICSDocument('simple.ics');

    $documents = $root->getDocuments();
    $this->assertEqual(1, count($documents));
    $document = head($documents);

    $events = $document->getEvents();
    $this->assertEqual(1, count($events));

    $event = head($events);
    $this->assertEqual(
      array(
        array(
          'name' => 'CREATED',
          'parameters' => array(),
          'value' => array(
            'type' => 'DATE-TIME',
            'value' => array(
              '20160908T172702Z',
            ),
            'raw' => '20160908T172702Z',
          ),
        ),
        array(
          'name' => 'UID',
          'parameters' => array(),
          'value' => array(
            'type' => 'TEXT',
            'value' => array(
              '1CEB57AF-0C9C-402D-B3BD-D75BD4843F68',
            ),
            'raw' => '1CEB57AF-0C9C-402D-B3BD-D75BD4843F68',
          ),
        ),
        array(
          'name' => 'DTEND',
          'parameters' => array(
            array(
              'name' => 'TZID',
              'values' => array(
                array(
                  'value' => 'America/Los_Angeles',
                  'quoted' => false,
                ),
              ),
            ),
          ),
          'value' => array(
            'type' => 'DATE-TIME',
            'value' => array(
              '20160915T100000',
            ),
            'raw' => '20160915T100000',
          ),
        ),
        array(
          'name' => 'SUMMARY',
          'parameters' => array(),
          'value' => array(
            'type' => 'TEXT',
            'value' => array(
              'Example Event',
            ),
            'raw' => 'Example Event',
          ),
        ),
      ),
      $event->getAttribute('ics.properties'));
  }

  public function testICSParserErrors() {
    $map = array(
      'err-missing-end.ics' => PhutilICSParser::PARSE_MISSING_END,
      'err-bad-base64.ics' => PhutilICSParser::PARSE_BAD_BASE64,
      'err-bad-boolean.ics' => PhutilICSParser::PARSE_BAD_BOOLEAN,
      'err-extra-end.ics' => PhutilICSParser::PARSE_EXTRA_END,
      'err-initial-unfold.ics' => PhutilICSParser::PARSE_INITIAL_UNFOLD,
      'err-malformed-double-quote.ics' =>
        PhutilICSParser::PARSE_MALFORMED_DOUBLE_QUOTE,
      'err-malformed-parameter.ics' =>
        PhutilICSParser::PARSE_MALFORMED_PARAMETER_NAME,
      'err-malformed-property.ics' =>
        PhutilICSParser::PARSE_MALFORMED_PROPERTY,
      'err-missing-value.ics' => PhutilICSParser::PARSE_MISSING_VALUE,
      'err-mixmatched-sections.ics' =>
        PhutilICSParser::PARSE_MISMATCHED_SECTIONS,
      'err-root-property.ics' => PhutilICSParser::PARSE_ROOT_PROPERTY,
      'err-unescaped-backslash.ics' =>
        PhutilICSParser::PARSE_UNESCAPED_BACKSLASH,
      'err-unexpected-child.ics' => PhutilICSParser::PARSE_UNEXPECTED_CHILD,
      'err-unexpected-text.ics' => PhutilICSParser::PARSE_UNEXPECTED_TEXT,

      'simple.ics' => null,
      'good-boolean.ics' => null,
      'multiple-vcalendars.ics' => null,
    );

    foreach ($map as $test_file => $expect) {
      $caught = null;
      try {
        $this->parseICSDocument($test_file);
      } catch (PhutilICSParserException $ex) {
        $caught = $ex;
      }

      if ($expect === null) {
        $this->assertTrue(
          ($caught === null),
          pht(
            'Expected no exception parsing "%s", got: %s',
            $test_file,
            (string)$ex));
      } else {
        if ($caught) {
          $code = $ex->getParserFailureCode();
          $explain = pht(
            'Expected one exception parsing "%s", got a different '.
            'one: %s',
            $test_file,
            (string)$ex);
        } else {
          $code = null;
          $explain = pht(
            'Expected exception parsing "%s", got none.',
            $test_file);
        }

        $this->assertEqual($expect, $code, $explain);
      }
    }
  }

  private function parseICSDocument($name) {
    $path = dirname(__FILE__).'/data/'.$name;
    $data = Filesystem::readFile($path);
    return id(new PhutilICSParser())
      ->parseICSData($data);
  }


}
