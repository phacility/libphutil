<?php

/*
 * Copyright 2012 Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @group testcase
 */
final class PhutilTranslatorTestCase extends ArcanistPhutilTestCase {

  public function testEnglish() {
    $translator = new PhutilTranslator();
    $translator->addTranslations(
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
    $translator = new PhutilTranslator();
    $translator->setLanguage('cs');
    $translator->addTranslations(
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
    $translator = new PhutilTranslator();
    $translator->setLanguage('cs');
    $translator->addTranslations(
      array(
        '%s wrote.' => array('%s napsal.', '%s napsala.'),
      ));

    $person = new PhutilPersonTest();
    $this->assertEqual(
      'Test () napsal.',
      $translator->translate('%s wrote.', $person));

    $person->setSex(PhutilPerson::SEX_MALE);
    $this->assertEqual(
      'Test (m) napsal.',
      $translator->translate('%s wrote.', $person));

    $person->setSex(PhutilPerson::SEX_FEMALE);
    $this->assertEqual(
      'Test (f) napsala.',
      $translator->translate('%s wrote.', $person));
  }

  public function testTranslateDate() {
    $date = new DateTime('2012-06-21');

    $translator = new PhutilTranslator();
    $this->assertEqual('June', $translator->translateDate('F', $date));
    $this->assertEqual('June 21', $translator->translateDate('F d', $date));
    $this->assertEqual('F', $translator->translateDate('\F', $date));

    $translator->addTranslations(
      array(
        'June' => 'correct',
        '21' => 'wrong',
        'F' => 'wrong'
      ));
    $this->assertEqual('correct', $translator->translateDate('F', $date));
    $this->assertEqual('correct 21', $translator->translateDate('F d', $date));
    $this->assertEqual('F', $translator->translateDate('\F', $date));
  }

  public function testSetInstance() {
    PhutilTranslator::setInstance(new PhutilTranslator());
    $original = PhutilTranslator::getInstance();
    $this->assertEqual('color', pht('color'));

    $british = new PhutilTranslator();
    $british->addTranslations(
      array(
        'color' => 'colour',
      ));
    PhutilTranslator::setInstance($british);
    $this->assertEqual('colour', pht('color'));

    PhutilTranslator::setInstance($original);
    $this->assertEqual('color', pht('color'));
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

    $translator = new PhutilTranslator();
    foreach ($tests as $original => $translations) {
      foreach ($translations as $translation => $expect) {
        $valid = ($expect ? "valid" : "invalid");
        $this->assertEqual(
          $expect,
          $translator->validateTranslation($original, $translation),
          "'{$original}' should be {$valid} with '{$translation}'.");
      }
    }
  }

}
