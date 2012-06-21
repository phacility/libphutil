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
 * Test cases for functions in pht.php.
 *
 * @group testcase
 */
final class PhutilPHTTestCase extends ArcanistPhutilTestCase {

  public function testPHT() {
    PhutilTranslator::setInstance(new PhutilTranslator());

    $this->assertEqual('beer', pht('beer'));
    $this->assertEqual('1 beer(s)', pht('%d beer(s)', 1));

    PhutilTranslator::getInstance()->addTranslations(
      array(
        '%d beer(s)' => array('%d beer', '%d beers'),
      ));

    $this->assertEqual('1 beer', pht('%d beer(s)', 1));

    PhutilTranslator::getInstance()->setLanguage('cs');
    PhutilTranslator::getInstance()->addTranslations(
      array(
        '%d beer(s)' => array('%d pivo', '%d piva', '%d piv'),
      ));

    $this->assertEqual('5 piv', pht('%d beer(s)', 5));
  }

  public function getDateTranslations() {
    // The only purpose of this function is to provide a static list of
    // translations which can come from PhutilTranslator::translateDate() to
    // allow translation extractor getting them.
    return array(
      'D' => array(
        pht('Sun'),
        pht('Mon'),
        pht('Tue'),
        pht('Wed'),
        pht('Thu'),
        pht('Fri'),
        pht('Sat'),
      ),
      'l' => array(
        pht('Sunday'),
        pht('Monday'),
        pht('Tuesday'),
        pht('Wednesday'),
        pht('Thursday'),
        pht('Friday'),
        pht('Saturday'),
      ),
      'S' => array(
        pht('st'),
        pht('nd'),
        pht('rd'),
        pht('th'),
      ),
      'F' => array(
        pht('January'),
        pht('February'),
        pht('March'),
        pht('April'),
        pht('May'),
        pht('June'),
        pht('July'),
        pht('August'),
        pht('September'),
        pht('October'),
        pht('November'),
        pht('December'),
      ),
      'M' => array(
        pht('Jan'),
        pht('Feb'),
        pht('Mar'),
        pht('Apr'),
        pht('May'),
        pht('Jun'),
        pht('Jul'),
        pht('Aug'),
        pht('Sep'),
        pht('Oct'),
        pht('Nov'),
        pht('Dec'),
      ),
      'a' => array(
        pht('am'),
        pht('pm'),
      ),
      'A' => array(
        pht('AM'),
        pht('PM'),
      ),
    );
  }

}
