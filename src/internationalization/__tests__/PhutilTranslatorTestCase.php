<?php

final class PhutilTranslatorTestCase extends PhutilTestCase {

  public function testEnglish() {
    $translator = $this->newTranslator('en_US');
    $translator->setTranslations(
      array(
        '%d line(s)' => array('%d line', '%d lines'),
        '%d char(s) on %d row(s)' => array(
          array('%d char on %d row', '%d char on %d rows'),
          array('%d chars on %d row', '%d chars on %d rows'),
        ),
      ));

    $this->assertEqual('line', $translator->translate('line'));
    $this->assertEqual('param', $translator->translate('%s', 'param'));

    $this->assertEqual('0 lines', $translator->translate('%d line(s)', 0));
    $this->assertEqual('1 line', $translator->translate('%d line(s)', 1));
    $this->assertEqual('2 lines', $translator->translate('%d line(s)', 2));

    $this->assertEqual(
      '1 char on 1 row',
      $translator->translate('%d char(s) on %d row(s)', 1, 1));
    $this->assertEqual(
      '5 chars on 2 rows',
      $translator->translate('%d char(s) on %d row(s)', 5, 2));

    $this->assertEqual('1 beer(s)', $translator->translate('%d beer(s)', 1));
  }

  public function testCzech() {
    $translator = $this->newTranslator('cs_CZ');
    $translator->setTranslations(
      array(
        '%d beer(s)' => array('%d pivo', '%d piva', '%d piv'),
      ));

    $this->assertEqual('0 piv', $translator->translate('%d beer(s)', 0));
    $this->assertEqual('1 pivo', $translator->translate('%d beer(s)', 1));
    $this->assertEqual('2 piva', $translator->translate('%d beer(s)', 2));
    $this->assertEqual('5 piv', $translator->translate('%d beer(s)', 5));

    $this->assertEqual('1 line(s)', $translator->translate('%d line(s)', 1));
  }

  public function testPerson() {
    $translator = $this->newTranslator('cs_CZ');
    $translator->setTranslations(
      array(
        '%s wrote.' => array('%s napsal.', '%s napsala.'),
      ));

    $person = new PhutilPersonTest();
    $this->assertEqual(
      'Test () napsal.',
      $translator->translate('%s wrote.', $person));

    $person->setGender(PhutilPerson::GENDER_MASCULINE);
    $this->assertEqual(
      'Test (m) napsal.',
      $translator->translate('%s wrote.', $person));

    $person->setGender(PhutilPerson::GENDER_FEMININE);
    $this->assertEqual(
      'Test (f) napsala.',
      $translator->translate('%s wrote.', $person));
  }

  public function testTranslateDate() {
    $date = new DateTime('2012-06-21');
    $translator = $this->newTranslator('en_US');

    $this->assertEqual('June', $translator->translateDate('F', $date));
    $this->assertEqual('June 21', $translator->translateDate('F d', $date));
    $this->assertEqual('F', $translator->translateDate('\F', $date));

    $translator->setTranslations(
      array(
        'June' => 'correct',
        '21' => 'wrong',
        'F' => 'wrong',
      ));
    $this->assertEqual('correct', $translator->translateDate('F', $date));
    $this->assertEqual('correct 21', $translator->translateDate('F d', $date));
    $this->assertEqual('F', $translator->translateDate('\F', $date));
  }

  public function testSetInstance() {
    $english_translator = $this->newTranslator('en_US');

    PhutilTranslator::setInstance($english_translator);
    $original = PhutilTranslator::getInstance();
    $this->assertEqual('color', pht('color'));

    $british_locale = PhutilLocale::loadLocale('en_GB');

    $british = new PhutilTranslator();
    $british->setLocale($british_locale);
    $british->setTranslations(
      array(
        'color' => 'colour',
      ));
    PhutilTranslator::setInstance($british);
    $this->assertEqual('colour', pht('color'));

    PhutilTranslator::setInstance($original);
    $this->assertEqual('color', pht('color'));
  }

  public function testFormatNumber() {
    $translator = $this->newTranslator('en_US');

    $this->assertEqual('1,234', $translator->formatNumber(1234));
    $this->assertEqual('1,234.5', $translator->formatNumber(1234.5, 1));
    $this->assertEqual('1,234.5678', $translator->formatNumber(1234.5678, 4));

    $translator->setTranslations(
      array(
        ',' => ' ',
        '.' => ',',
      ));
    $this->assertEqual('1 234', $translator->formatNumber(1234));
    $this->assertEqual('1 234,5', $translator->formatNumber(1234.5, 1));
    $this->assertEqual('1 234,5678', $translator->formatNumber(1234.5678, 4));
  }

  public function testNumberTranslations() {
    $translator = $this->newTranslator('en_US');

    $translator->setTranslations(
      array(
        '%s line(s)' => array('%s line', '%s lines'),
      ));

    $this->assertEqual(
      '1 line',
      $translator->translate('%s line(s)', new PhutilNumber(1)));

    $this->assertEqual(
      '1,000 lines',
      $translator->translate('%s line(s)', new PhutilNumber(1000)));

    $this->assertEqual(
      '8.5 lines',
      $translator->translate(
        '%s line(s)',
        id(new PhutilNumber(8.5))->setDecimals(1)));
  }

  public function testValidateTranslation() {
    $tests = array(
      'a < 2' => array(
        'a < 2' => true,
        'b < 3' => true,
        '2 > a' => false,
        'a<2' => false,
      ),
      'We <em>win</em>' => array(
        'We <em>win</em>' => true,
        'We </em>win<em>' => true, // false positive
        'We win' => false,
        'We <em onmouseover="">win</em>' => false,
      ),
      'We <em title="%s">win</em> &amp; triumph' => array(
        'We <em title="%s">triumph</em> &amp; win' => true,
        'We <em title="%s">win</em> and triumph' => false,
      ),
      'beer' => array(
        'pivo' => true,
        'b<>r' => false,
        'b&&r' => false,
      ),
    );

    $translator = $this->newTranslator('en_US');

    foreach ($tests as $original => $translations) {
      foreach ($translations as $translation => $expect) {
        $valid = ($expect ? 'valid' : 'invalid');
        $this->assertEqual(
          $expect,
          $translator->validateTranslation($original, $translation),
          pht(
            "'%s' should be %s with '%s'.",
            $original,
            $valid,
            $translation));
      }
    }
  }

  private function newTranslator($locale_code) {
    $locale = PhutilLocale::loadLocale($locale_code);
    return id(new PhutilTranslator())
      ->setLocale($locale);
  }

}
