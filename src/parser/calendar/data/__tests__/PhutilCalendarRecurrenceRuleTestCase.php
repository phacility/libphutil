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
      'BYDAY' => array('1TU', '-1TH'),
    );
    $expect[] = array(
      '19971225',
      '19980106',
      '19981231',
    );

    // Same test as above, just making sure the optional "+" syntax works.
    $tests[] = array(
      'BYDAY' => array('+1TU', '-1TH'),
    );
    $expect[] = array(
      '19971225',
      '19980106',
      '19981231',
    );

    $tests[] = array(
      'BYDAY' => array('3TU', '-3TH'),
    );
    $expect[] = array(
      '19971211',
      '19980120',
      '19981217',
    );

    $tests[] = array(
      'BYMONTH' => array(1, 3),
      'BYDAY' => array('1TU', '-1TH'),
    );
    $expect[] = array(
      '19980106',
      '19980129',
      '19980303',
    );

    $tests[] = array(
      'BYMONTH' => array(1, 3),
      'BYDAY' => array('3TU', '-3TH'),
    );
    $expect[] = array(
      '19980115',
      '19980120',
      '19980312',
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

    $tests[] = array(
      'BYWEEKNO' => array(1),
      'BYDAY' => array('MO'),
    );
    $expect[] = array(
      '19971229',
      '19990104',
      '20000103',
    );

    $tests[] = array(
      'BYWEEKNO' => array(52),
      'BYDAY' => array('SU'),
    );
    $expect[] = array(
      '19971228',
      '19981227',
      '20000102',
    );

    $tests[] = array(
      'BYWEEKNO' => array(-1),
      'BYDAY' => array('SU'),
    );
    $expect[] = array(
      '19971228',
      '19990103',
      '20000102',
    );

    $tests[] = array(
      'BYWEEKNO' => array(53),
      'BYDAY' => array('MO'),
    );
    $expect[] = array(
      '19981228',
      '20041227',
      '20091228',
    );

    $tests[] = array(
      'BYHOUR' => array(6, 18),
    );
    $expect[] = array(
      '19970902T060000Z',
      '19970902T180000Z',
      '19980902T060000Z',
    );

    $tests[] = array(
      'BYMINUTE' => array(15, 30),
    );
    $expect[] = array(
      '19970902T001500Z',
      '19970902T003000Z',
      '19980902T001500Z',
    );

    $tests[] = array(
      'BYSECOND' => array(10, 20),
    );
    $expect[] = array(
      '19970902T000010Z',
      '19970902T000020Z',
      '19980902T000010Z',
    );

    $tests[] = array(
      'BYHOUR' => array(6, 18),
      'BYMINUTE' => array(15, 30),
    );
    $expect[] = array(
      '19970902T061500Z',
      '19970902T063000Z',
      '19970902T181500Z',
    );

    $tests[] = array(
      'BYHOUR' => array(6, 18),
      'BYSECOND' => array(10, 20),
    );
    $expect[] = array(
      '19970902T060010Z',
      '19970902T060020Z',
      '19970902T180010Z',
    );

    $tests[] = array(
      'BYMINUTE' => array(15, 30),
      'BYSECOND' => array(10, 20),
    );
    $expect[] = array(
      '19970902T001510Z',
      '19970902T001520Z',
      '19970902T003010Z',
    );

    $tests[] = array(
      'BYHOUR' => array(6, 18),
      'BYMINUTE' => array(15, 30),
      'BYSECOND' => array(10, 20),
    );
    $expect[] = array(
      '19970902T061510Z',
      '19970902T061520Z',
      '19970902T063010Z',
    );

    $tests[] = array(
      'BYMONTHDAY' => array(15),
      'BYHOUR' => array(6, 18),
      'BYSETPOS' => array(3, -3),
    );
    $expect[] = array(
      '19971115T180000Z',
      '19980215T060000Z',
      '19981115T180000Z',
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

  public function testMonthlyRecurrenceRules() {
    $tests = array();
    $expect = array();

    $tests[] = array();
    $expect[] = array(
      '19970902',
      '19971002',
      '19971102',
    );

    $tests[] = array(
      'INTERVAL' => 2,
    );
    $expect[] = array(
      '19970902',
      '19971102',
      '19980102',
    );

    $tests[] = array(
      'INTERVAL' => 18,
    );
    $expect[] = array(
      '19970902',
      '19990302',
      '20000902',
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
      'BYMONTHDAY' => array(5, 7),
      'BYMONTH' => array(1, 3),
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
      'BYDAY' => array('3MO'),
    );
    $expect[] = array(
      '19970915',
      '19971020',
      '19971117',
    );

    $tests[] = array(
      'BYDAY' => array('1TU', '-1TH'),
    );
    $expect[] = array(
      '19970902',
      '19970925',
      '19971007',
    );

    $tests[] = array(
      'BYDAY' => array('3TU', '-3TH'),
    );
    $expect[] = array(
      '19970911',
      '19970916',
      '19971016',
    );

    $tests[] = array(
      'BYDAY' => array('TU', 'TH'),
      'BYMONTH' => array(1, 3),
    );
    $expect[] = array(
      '19980101',
      '19980106',
      '19980108',
    );

    $tests[] = array(
      'BYMONTH' => array(1, 3),
      'BYDAY' => array('1TU', '-1TH'),
    );
    $expect[] = array(
      '19980106',
      '19980129',
      '19980303',
    );

    $tests[] = array(
      'BYMONTH' => array(1, 3),
      'BYDAY' => array('3TU', '-3TH'),
    );
    $expect[] = array(
      '19980115',
      '19980120',
      '19980312',
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
      'BYMONTH' => array(1, 3),
      'BYMONTHDAY' => array(1, 3),
      'BYDAY' => array('TU', 'TH'),
    );
    $expect[] = array(
      '19980101',
      '19980303',
      '20010301',
    );

    $tests[] = array(
      'BYDAY' => array('MO', 'TU', 'WE', 'TH', 'FR'),
      'BYSETPOS' => array(-1),
    );
    $expect[] = array(
      '19970930',
      '19971031',
      '19971128',
    );

    $tests[] = array(
      'BYDAY' => array('1MO', '1TU', '1WE', '1TH', '1FR', '-1FR'),
      'BYMONTHDAY' => array(1, -1, -2),
    );
    $expect[] = array(
      '19971001',
      '19971031',
      '19971201',
    );

    $tests[] = array(
      'BYDAY' => array('1MO', '1TU', '1WE', '1TH', 'FR'),
      'BYMONTHDAY' => array(1, -1, -2),
    );
    $expect[] = array(
      '19971001',
      '19971031',
      '19971201',
    );

    $tests[] = array(
      'BYHOUR' => array(6, 18),
    );
    $expect[] = array(
      '19970902T060000Z',
      '19970902T180000Z',
      '19971002T060000Z',
    );

    $tests[] = array(
      'BYMINUTE' => array(6, 18),
    );
    $expect[] = array(
      '19970902T000600Z',
      '19970902T001800Z',
      '19971002T000600Z',
    );

    $tests[] = array(
      'BYSECOND' => array(6, 18),
    );
    $expect[] = array(
      '19970902T000006Z',
      '19970902T000018Z',
      '19971002T000006Z',
    );

    $tests[] = array(
      'BYMONTHDAY' => array(13, 17),
      'BYHOUR' => array(6, 18),
      'BYSETPOS' => array(3, -3),
    );
    $expect[] = array(
      '19970913T180000Z',
      '19970917T060000Z',
      '19971013T180000Z',
    );

    $tests[] = array(
      'BYMONTHDAY' => array(13, 17),
      'BYHOUR' => array(6, 18),
      'BYSETPOS' => array(3, 3, -3),
    );
    $expect[] = array(
      '19970913T180000Z',
      '19970917T060000Z',
      '19971013T180000Z',
    );

    $tests[] = array(
      'BYMONTHDAY' => array(13, 17),
      'BYHOUR' => array(6, 18),
      'BYSETPOS' => array(4, -1),
    );
    $expect[] = array(
      '19970917T180000Z',
      '19971017T180000Z',
      '19971117T180000Z',
    );

    $this->assertRules(
      array(
        'FREQ' => 'MONTHLY',
        'COUNT' => 3,
        'DTSTART' => '19970902',
      ),
      $tests,
      $expect);
  }

  public function testDailyRecurrenceRules() {
    $tests = array();
    $expect = array();

    $tests[] = array();
    $expect[] = array(
      '19970902',
      '19970903',
      '19970904',
    );

    $tests[] = array(
      'INTERVAL' => 2,
    );
    $expect[] = array(
      '19970902',
      '19970904',
      '19970906',
    );

    $tests[] = array(
      'INTERVAL' => 92,
    );
    $expect[] = array(
      '19970902',
      '19971203',
      '19980305',
    );

    $tests[] = array(
      'BYMONTH' => array(1, 3),
    );
    $expect[] = array(
      '19980101',
      '19980102',
      '19980103',
    );

    // This is testing that INTERVAL is respected in the presence of a BYMONTH
    // filter which skips some months.
    $tests[] = array(
      'BYMONTH' => array(12),
      'INTERVAL' => 17,
    );
    $expect[] = array(
      '19971213',
      '19971230',
      '19981205',
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
      'BYMONTH' => array(1, 3),
      'BYMONTHDAY' => array(1, 3),
      'BYDAY' => array('TU', 'TH'),
    );
    $expect[] = array(
      '19980101',
      '19980303',
      '20010301',
    );

    $tests[] = array(
      'BYHOUR' => array(6, 18),
      'BYMINUTE' => array(15, 45),
      'BYSETPOS' => array(3, -3),
      'DTSTART' => '19970902T090000Z',
    );
    $expect[] = array(
      '19970902T181500Z',
      '19970903T064500Z',
      '19970903T181500Z',
    );

    $this->assertRules(
      array(
        'FREQ' => 'DAILY',
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

      $by_hour = idx($options, 'BYHOUR');
      if ($by_hour) {
        $rrule->setByHour($by_hour);
      }

      $by_minute = idx($options, 'BYMINUTE');
      if ($by_minute) {
        $rrule->setByMinute($by_minute);
      }

      $by_second = idx($options, 'BYSECOND');
      if ($by_second) {
        $rrule->setBySecond($by_second);
      }

      $by_setpos = idx($options, 'BYSETPOS');
      if ($by_setpos) {
        $rrule->setBySetPosition($by_setpos);
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
