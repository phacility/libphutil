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
final class PhutilArgumentParserTestCase extends ArcanistPhutilTestCase {

  public function testBasics() {
    $specs = array(
      array(
        'name' => 'flag',
      ));

    $args = new PhutilArgumentParser(array('bin'));
    $args->parseFull($specs);
    $this->assertEqual(false, $args->getArg('flag'));

    $args = new PhutilArgumentParser(array('bin', '--flag'));
    $args->parseFull($specs);
    $this->assertEqual(true, $args->getArg('flag'));
  }

  public function testWildcards() {
    $specs = array(
      array(
        'name' => 'flag',
      ),
      array(
        'name' => 'files',
        'wildcard' => true,
      ),
    );

    $args = new PhutilArgumentParser(array('bin', '--flag', 'a', 'b'));
    $args->parseFull($specs);
    $this->assertEqual(true, $args->getArg('flag'));
    $this->assertEqual(
      array('a', 'b'),
      $args->getArg('files'));

    $caught = null;
    try {
      $args = new PhutilArgumentParser(array('bin', '--derp', 'a', 'b'));
      $args->parseFull($specs);
    } catch (PhutilArgumentUsageException $ex) {
      $caught = $ex;
    }

    $this->assertEqual(true, $caught instanceof Exception);

    $args = new PhutilArgumentParser(array('bin', '--', '--derp', 'a', 'b'));
    $args->parseFull($specs);
    $this->assertEqual(
      array('--derp', 'a', 'b'),
      $args->getArg('files'));
  }

  public function testPartialParse() {
    $specs = array(
      array(
        'name' => 'flag',
      ),
    );

    $args = new PhutilArgumentParser(array('bin', 'a', '--flag', '--', 'b'));
    $args->parsePartial($specs);

    $this->assertEqual(
      array('a', '--', 'b'),
      $args->getUnconsumedArgumentVector());
  }

  public function testBadArg() {
    $args = new PhutilArgumentParser(array('bin'));
    $args->parseFull(array());

    $caught = null;
    try {
      $args->getArg('flag');
    } catch (PhutilArgumentSpecificationException $ex) {
      $caught = $ex;
    }

    $this->assertEqual(true, $caught instanceof Exception);
  }

  public function testDuplicateNames() {
    $args = new PhutilArgumentParser(array('bin'));
    $caught = null;
    try {
      $args->parseFull(
        array(
          array(
            'name' => 'x',
          ),
          array(
            'name' => 'x',
          )));
    } catch (PhutilArgumentSpecificationException $ex) {
      $caught = $ex;
    }

    $this->assertEqual(true, $caught instanceof Exception);
  }

  public function testDuplicateNamesWithParsePartial() {
    $args = new PhutilArgumentParser(array('bin'));
    $caught = null;
    try {
      $args->parsePartial(
        array(
          array(
            'name' => 'x',
          )));
      $args->parsePartial(
        array(
          array(
            'name' => 'x',
          )));
    } catch (PhutilArgumentSpecificationException $ex) {
      $caught = $ex;
    }

    $this->assertEqual(true, $caught instanceof Exception);
  }

  public function testDuplicateShortAliases() {
    $args = new PhutilArgumentParser(array('bin'));
    $caught = null;
    try {
      $args->parseFull(
        array(
          array(
            'name' => 'x',
            'short' => 'x',
          ),
          array(
            'name' => 'y',
            'short' => 'x',
          )));
    } catch (PhutilArgumentSpecificationException $ex) {
      $caught = $ex;
    }

    $this->assertEqual(true, $caught instanceof Exception);
  }

  public function testDuplicateWildcards() {
    $args = new PhutilArgumentParser(array('bin'));
    $caught = null;
    try {
      $args->parseFull(
        array(
          array(
            'name' => 'x',
            'wildcard' => true,
          ),
          array(
            'name' => 'y',
            'wildcard' => true,
          )));
    } catch (PhutilArgumentSpecificationException $ex) {
      $caught = $ex;
    }

    $this->assertEqual(true, $caught instanceof Exception);
  }

  public function testDuplicatePartialWildcards() {
    $args = new PhutilArgumentParser(array('bin'));
    $caught = null;
    try {
      $args->parsePartial(
        array(
          array(
            'name' => 'x',
            'wildcard' => true,
          ),
        ));
      $args->parsePartial(
        array(
          array(
            'name' => 'y',
            'wildcard' => true,
          ),
        ));
    } catch (PhutilArgumentSpecificationException $ex) {
      $caught = $ex;
    }

    $this->assertEqual(true, $caught instanceof Exception);
  }

  public function testConflictSpecificationWithUnrecognizedArg() {
    $args = new PhutilArgumentParser(array('bin'));
    $caught = null;
    try {
      $args->parseFull(
        array(
          array(
            'name' => 'x',
            'conflicts' => array(
              'y' => true,
            ),
          ),
        ));
    } catch (PhutilArgumentSpecificationException $ex) {
      $caught = $ex;
    }

    $this->assertEqual(true, $caught instanceof Exception);
  }

  public function testConflictSpecificationWithSelf() {
    $args = new PhutilArgumentParser(array('bin'));
    $caught = null;
    try {
      $args->parseFull(
        array(
          array(
            'name' => 'x',
            'conflicts' => array(
              'x' => true,
            ),
          ),
        ));
    } catch (PhutilArgumentSpecificationException $ex) {
      $caught = $ex;
    }

    $this->assertEqual(true, $caught instanceof Exception);
  }

  public function testUnrecognizedFlag() {
    $args = new PhutilArgumentParser(array('bin', '--flag'));
    $caught = null;
    try {
      $args->parseFull(array());
    } catch (PhutilArgumentUsageException $ex) {
      $caught = $ex;
    }

    $this->assertEqual(true, $caught instanceof Exception);
  }

  public function testDuplicateFlag() {
    $args = new PhutilArgumentParser(array('bin', '--flag', '--flag'));
    $caught = null;
    try {
      $args->parseFull(
        array(
          array(
            'name' => 'flag',
          ),
        ));
    } catch (PhutilArgumentUsageException $ex) {
      $caught = $ex;
    }

    $this->assertEqual(true, $caught instanceof Exception);
  }

  public function testMissingParameterValue() {
    $args = new PhutilArgumentParser(array('bin', '--with'));
    $caught = null;
    try {
      $args->parseFull(
        array(
          array(
            'name'  => 'with',
            'param' => 'stuff',
          ),
        ));
    } catch (PhutilArgumentUsageException $ex) {
      $caught = $ex;
    }

    $this->assertEqual(true, $caught instanceof Exception);
  }

  public function testExtraParameterValue() {
    $args = new PhutilArgumentParser(array('bin', '--true=apple'));
    $caught = null;
    try {
      $args->parseFull(
        array(
          array(
            'name'  => 'true',
          ),
        ));
    } catch (PhutilArgumentUsageException $ex) {
      $caught = $ex;
    }

    $this->assertEqual(true, $caught instanceof Exception);
  }

  public function testConflictParameterValue() {
    $args = new PhutilArgumentParser(array('bin', '--true', '--false'));
    $caught = null;
    try {
      $args->parseFull(
        array(
          array(
            'name'  => 'true',
            'conflicts' => array(
              'false' => true,
            ),
          ),
          array(
            'name'  => 'false',
            'conflicts' => array(
              'true' => true,
            ),
          ),
        ));
    } catch (PhutilArgumentUsageException $ex) {
      $caught = $ex;
    }

    $this->assertEqual(true, $caught instanceof Exception);
  }

  public function testParameterValues() {
    $specs = array(
      array(
        'name' => 'a',
        'param' => 'value',
      ),
      array(
        'name' => 'b',
        'param' => 'value',
      ),
      array(
        'name' => 'cee',
        'short' => 'c',
        'param' => 'value',
      ),
      array(
        'name' => 'dee',
        'short' => 'd',
        'param' => 'value',
      ),
    );

    $args = new PhutilArgumentParser(
      array(
        'bin', '--a', 'a', '--b=b', '-c', 'c', '-d=d',
      ));
    $args->parseFull($specs);

    $this->assertEqual('a', $args->getArg('a'));
    $this->assertEqual('b', $args->getArg('b'));
    $this->assertEqual('c', $args->getArg('cee'));
    $this->assertEqual('d', $args->getArg('dee'));
  }

  public function testStdinValidParameter() {
    $specs = array(
      array(
        'name' => 'file',
        'param' => 'file',
      ),
    );

    $args = new PhutilArgumentParser(
      array(
        'bin', '-', '--file', '-',
      ));
    $args->parsePartial($specs);

    $this->assertEqual('-', $args->getArg('file'));
  }

  public function testRepeatableFlag() {
    $specs = array(
      array(
        'name' => 'verbose',
        'short' => 'v',
        'repeat' => true,
      ),
    );

    $args = new PhutilArgumentParser(array('bin', '-v', '-v', '-v'));
    $args->parseFull($specs);

    $this->assertEqual(3, $args->getArg('verbose'));
  }

  public function testRepeatableParam() {
    $specs = array(
      array(
        'name' => 'eat',
        'param' => 'fruit',
        'repeat' => true,
      ),
    );

    $args = new PhutilArgumentParser(array(
      'bin', '--eat', 'apple', '--eat', 'pear', '--eat=orange',
    ));
    $args->parseFull($specs);

    $this->assertEqual(
      array('apple', 'pear', 'orange'),
      $args->getArg('eat'));
  }

}
