<?php

final class PhutilICSWriterTestCase extends PhutilTestCase {

  public function testICSWriterTeaTime() {
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

  public function testICSWriterAllDay() {
    $event = id(new PhutilCalendarEventNode())
      ->setUID('christmas-day')
      ->setName('Christmas 2016')
      ->setDescription('A minor religious holiday.')
      ->setCreatedDateTime(
        PhutilCalendarAbsoluteDateTime::newFromISO8601('20160901T232425Z'))
      ->setModifiedDateTime(
        PhutilCalendarAbsoluteDateTime::newFromISO8601('20160901T232425Z'))
      ->setStartDateTime(
        PhutilCalendarAbsoluteDateTime::newFromISO8601('20161225'))
      ->setEndDateTime(
        PhutilCalendarAbsoluteDateTime::newFromISO8601('20161226'));

    $ics_data = $this->writeICSSingleEvent($event);

    $this->assertICS('writer-christmas.ics', $ics_data);
  }

  public function testICSWriterUsers() {
    $event = id(new PhutilCalendarEventNode())
      ->setUID('office-party')
      ->setName('Office Party')
      ->setCreatedDateTime(
        PhutilCalendarAbsoluteDateTime::newFromISO8601('20161001T120000Z'))
      ->setModifiedDateTime(
        PhutilCalendarAbsoluteDateTime::newFromISO8601('20161001T120000Z'))
      ->setStartDateTime(
        PhutilCalendarAbsoluteDateTime::newFromISO8601('20161215T200000Z'))
      ->setEndDateTime(
        PhutilCalendarAbsoluteDateTime::newFromISO8601('20161215T230000Z'))
      ->setOrganizer(
        id(new PhutilCalendarUserNode())
          ->setName('Big Boss')
          ->setURI('mailto:big.boss@example.com'))
      ->addAttendee(
        id(new PhutilCalendarUserNode())
          ->setName('Milton')
          ->setStatus(PhutilCalendarUserNode::STATUS_INVITED)
          ->setURI('mailto:milton@example.com'))
      ->addAttendee(
        id(new PhutilCalendarUserNode())
          ->setName('Nancy')
          ->setStatus(PhutilCalendarUserNode::STATUS_ACCEPTED)
          ->setURI('mailto:nancy@example.com'));

    $ics_data = $this->writeICSSingleEvent($event);
    $this->assertICS('writer-office-party.ics', $ics_data);
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
