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

    $tests[] = array(
      'BYMONTH' => array(1, 3),
    );
    $expect[] = array(
      '19980102',
      '19980302',
      '19990102',
    );

    $tests[] = array(
      'BYMONTHDAY' => array(1, 3),
    );
    $expect[] = array(
      '19970903',
      '19971001',
      '19971003',
    );

    $tests[] = array(
      'BYMONTH' => array(1, 3),
      'BYMONTHDAY' => array(5, 7),
    );
    $expect[] = array(
      '19980105',
      '19980107',
      '19980305',
    );

    $tests[] = array(
      'BYDAY' => array('TU', 'TH'),
    );
    $expect[] = array(
      '19970902',
      '19970904',
      '19970909',
    );

    $tests[] = array(
      'BYDAY' => array('SU'),
    );
    $expect[] = array(
      '19970907',
      '19970914',
      '19970921',
    );

    $tests[] = array(
      'BYMONTH' => array(1, 3),
      'BYDAY' => array('TU', 'TH'),
    );
    $expect[] = array(
      '19980101',
      '19980106',
      '19980108',
    );

    $tests[] = array(
      'BYMONTHDAY' => array(1, 3),
      'BYDAY' => array('TU', 'TH'),
    );
    $expect[] = array(
      '19980101',
      '19980203',
      '19980303',
    );

    $tests[] = array(
      'BYMONTHDAY' => array(1, 3),
      'BYDAY' => array('TU', 'TH'),
      'BYMONTH' => array(1, 3),
    );
    $expect[] = array(
      '19980101',
      '19980303',
      '20010301',
    );

    $tests[] = array(
      'BYYEARDAY' => array(1, 100, 200, 365),
      'COUNT' => 4,
    );
    $expect[] = array(
      '19971231',
      '19980101',
      '19980410',
      '19980719',
    );

    $tests[] = array(
      'BYYEARDAY' => array(-365, -266, -166, -1),
      'COUNT' => 4,
    );
    $expect[] = array(
      '19971231',
      '19980101',
      '19980410',
      '19980719',
    );

    $tests[] = array(
      'BYYEARDAY' => array(1, 100, 200, 365),
      'BYMONTH' => array(4, 7),
      'COUNT' => 4,
    );
    $expect[] = array(
      '19980410',
      '19980719',
      '19990410',
      '19990719',
    );

    $tests[] = array(
      'BYYEARDAY' => array(-365, -266, -166, -1),
      'BYMONTH' => array(4, 7),
      'COUNT' => 4,
    );
    $expect[] = array(
      '19980410',
      '19980719',
      '19990410',
      '19990719',
    );

    $tests[] = array(
      'BYWEEKNO' => array(20),
    );
    $expect[] = array(
      '19980511',
      '19980512',
      '19980513',
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

      $by_day = idx($options, 'BYDAY');
      if ($by_day) {
        $rrule->setByDay($by_day);
      }

      $by_month = idx($options, 'BYMONTH');
      if ($by_month) {
        $rrule->setByMonth($by_month);
      }

      $by_monthday = idx($options, 'BYMONTHDAY');
      if ($by_monthday) {
        $rrule->setByMonthDay($by_monthday);
      }

      $by_yearday = idx($options, 'BYYEARDAY');
      if ($by_yearday) {
        $rrule->setByYearDay($by_yearday);
      }

      $by_weekno = idx($options, 'BYWEEKNO');
      if ($by_weekno) {
        $rrule->setByWeekNumber($by_weekno);
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
