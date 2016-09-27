<?php

final class PhutilCalendarRecurrenceRuleTestCase extends PhutilTestCase {

  public function testSimpleRecurrenceRules() {
    $start = PhutilCalendarAbsoluteDateTime::newFromISO8601('20160101T120000Z');

    $rrule = id(new PhutilCalendarRecurrenceRule())
      ->setStartDateTime($start)
      ->setFrequency(PhutilCalendarRecurrenceRule::FREQUENCY_DAILY);

    $set = id(new PhutilCalendarRecurrenceSet())
      ->addSource($rrule);

    $result = $set->getEventsBetween(null, null, 3);

    $expect = array(
      PhutilCalendarAbsoluteDateTime::newFromISO8601('20160101T120000Z'),
      PhutilCalendarAbsoluteDateTime::newFromISO8601('20160102T120000Z'),
      PhutilCalendarAbsoluteDateTime::newFromISO8601('20160103T120000Z'),
    );

    $this->assertEqual(
      mpull($expect, 'getISO8601'),
      mpull($result, 'getISO8601'),
      pht('Simple daily event.'));



    $rrule = id(new PhutilCalendarRecurrenceRule())
      ->setStartDateTime($start)
      ->setFrequency(PhutilCalendarRecurrenceRule::FREQUENCY_HOURLY)
      ->setByHour(array(12, 13));

    $set = id(new PhutilCalendarRecurrenceSet())
      ->addSource($rrule);

    $result = $set->getEventsBetween(null, null, 5);

    $expect = array(
      PhutilCalendarAbsoluteDateTime::newFromISO8601('20160101T120000Z'),
      PhutilCalendarAbsoluteDateTime::newFromISO8601('20160101T130000Z'),
      PhutilCalendarAbsoluteDateTime::newFromISO8601('20160102T120000Z'),
      PhutilCalendarAbsoluteDateTime::newFromISO8601('20160102T130000Z'),
      PhutilCalendarAbsoluteDateTime::newFromISO8601('20160103T120000Z'),
    );

    $this->assertEqual(
      mpull($expect, 'getISO8601'),
      mpull($result, 'getISO8601'),
      pht('Hourly event with BYHOUR.'));


    $rrule = id(new PhutilCalendarRecurrenceRule())
      ->setStartDateTime($start)
      ->setFrequency(PhutilCalendarRecurrenceRule::FREQUENCY_YEARLY);

    $set = id(new PhutilCalendarRecurrenceSet())
      ->addSource($rrule);

    $result = $set->getEventsBetween(null, null, 2);

    $expect = array(
      PhutilCalendarAbsoluteDateTime::newFromISO8601('20160101T120000Z'),
      PhutilCalendarAbsoluteDateTime::newFromISO8601('20170101T120000Z'),
    );

    $this->assertEqual(
      mpull($expect, 'getISO8601'),
      mpull($result, 'getISO8601'),
      pht('Yearly event.'));


    // This is an efficiency test for bizarre rules: it defines a secondly
    // event which only occurs one a year, and generates 3 instances of it.
    // This implementation should be fast enough that this test doesn't take
    // a significant amount of time.

    $rrule = id(new PhutilCalendarRecurrenceRule())
      ->setStartDateTime($start)
      ->setFrequency(PhutilCalendarRecurrenceRule::FREQUENCY_SECONDLY)
      ->setByMonth(array(1))
      ->setByMonthDay(array(1))
      ->setByHour(array(12))
      ->setByMinute(array(0))
      ->setBySecond(array(0));

    $set = id(new PhutilCalendarRecurrenceSet())
      ->addSource($rrule);

    $result = $set->getEventsBetween(null, null, 3);

    $expect = array(
      PhutilCalendarAbsoluteDateTime::newFromISO8601('20160101T120000Z'),
      PhutilCalendarAbsoluteDateTime::newFromISO8601('20170101T120000Z'),
      PhutilCalendarAbsoluteDateTime::newFromISO8601('20180101T120000Z'),
    );

    $this->assertEqual(
      mpull($expect, 'getISO8601'),
      mpull($result, 'getISO8601'),
      pht('Secondly event with many constraints.'));
  }

  public function testYearlyRecurrenceRules() {
    $tests = array();
    $expect = array();

    $tests[] = array();
    $expect[] = array(
      '19970902',
      '19980902',
      '19990902',
    );

    $tests[] = array(
      'INTERVAL' => 2,
    );
    $expect[] = array(
      '19970902',
      '19990902',
      '20010902',
    );

    $tests[] = array(
      'DTSTART' => '20000229',
    );
    $expect[] = array(
      '20000229',
      '20040229',
      '20080229',
    );

    $this->assertRules(
      array(
        'FREQ' => 'YEARLY',
        'COUNT' => 3,
        'DTSTART' => '19970902',
      ),
      $tests,
      $expect);
  }

  private function assertRules(array $defaults, array $tests, array $expect) {
    foreach ($tests as $key => $test) {
      $options = $test + $defaults;

      $start = PhutilCalendarAbsoluteDateTime::newFromISO8601(
        $options['DTSTART']);

      $rrule = id(new PhutilCalendarRecurrenceRule())
        ->setStartDateTime($start)
        ->setFrequency($options['FREQ']);

      $interval = idx($options, 'INTERVAL');
      if ($interval) {
        $rrule->setInterval($interval);
      }

      $set = id(new PhutilCalendarRecurrenceSet())
        ->addSource($rrule);

      $result = $set->getEventsBetween(null, null, $options['COUNT']);

      $this->assertEqual(
        $expect[$key],
        mpull($result, 'getISO8601'));
    }
  }


}
