<?php

final class PhutilCalendarRecurrenceRuleTestCase extends PhutilTestCase {

  public function testSimpleRecurrenceRules() {
    $start = PhutilCalendarAbsoluteDateTime::newFromISO8601('20160101T120000Z');

    $rrule = id(new PhutilCalendarRecurrenceRule())
      ->setStartDateTime($start)
      ->setFrequency('DAILY');

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
      ->setFrequency('HOURLY')
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
      ->setFrequency('YEARLY');

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
      ->setFrequency('SECONDLY')
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

}
