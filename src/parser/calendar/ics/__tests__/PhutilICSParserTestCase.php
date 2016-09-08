<?php

final class PhutilICSParserTestCase extends PhutilTestCase {

  public function testICSParser() {
    $document = $this->parseICSDocument('simple.ics');

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

  private function parseICSDocument($name) {
    $path = dirname(__FILE__).'/data/'.$name;
    $data = Filesystem::readFile($path);
    return id(new PhutilICSParser())
      ->parseICSData($data);
  }


}
