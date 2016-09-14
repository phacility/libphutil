<?php

final class PhutilICSWriterTestCase extends PhutilTestCase {

  public function testICSWriter() {
    $teas = array(
      'earl grey tea',
      'English breakfast tea',
      'black tea',
      'green tea',
      't-rex',
      'oolong tea',
      'mint tea',
      'tea with milk',
    );

    $teas = implode(', ', $teas);

    $event = id(new PhutilCalendarEventNode())
      ->setUID('tea-time')
      ->setName('Tea Time')
      ->setDescription(
        "Tea and, perhaps, crumpets.\n".
        "Your presence is requested!\n".
        "This is a long list of types of tea to test line wrapping: {$teas}.")
      ->setCreatedDateTime(
        PhutilCalendarAbsoluteDateTime::newFromISO8601('20160915T070000Z'))
      ->setModifiedDateTime(
        PhutilCalendarAbsoluteDateTime::newFromISO8601('20160915T070000Z'))
      ->setStartDateTime(
        PhutilCalendarAbsoluteDateTime::newFromISO8601('20160916T150000Z'))
      ->setEndDateTime(
        PhutilCalendarAbsoluteDateTime::newFromISO8601('20160916T160000Z'));

    $ics_data = $this->writeICSSingleEvent($event);

    $this->assertICS('writer-tea-time.ics', $ics_data);
  }

  private function writeICSSingleEvent(PhutilCalendarEventNode $event) {
    $calendar = id(new PhutilCalendarDocumentNode())
      ->appendChild($event);

    $root = id(new PhutilCalendarRootNode())
      ->appendChild($calendar);

    return $this->writeICS($root);
  }

  private function writeICS(PhutilCalendarRootNode $root) {
    return id(new PhutilICSWriter())
      ->writeICSDocument($root);
  }

  private function assertICS($name, $actual) {
    $path = dirname(__FILE__).'/data/'.$name;
    $data = Filesystem::readFile($path);
    $this->assertEqual($data, $actual, pht('ICS: %s', $name));
  }

}
