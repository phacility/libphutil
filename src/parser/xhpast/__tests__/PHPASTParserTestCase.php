<?php

final class PHPASTParserTestCase extends PhutilTestCase {

  public function testParser() {
    if (!PhutilXHPASTBinary::isAvailable()) {
      try {
        PhutilXHPASTBinary::build();
      } catch (Exception $ex) {
        $this->assertSkipped(
          pht('%s is not built or not up to date.', 'xhpast'));
      }
    }

    $dir = dirname(__FILE__).'/data/';
    foreach (Filesystem::listDirectory($dir) as $file) {
      if (preg_match('/\.test$/', $file)) {
        $this->executeParserTest($file, $dir.$file);
      }
    }
  }

  private function executeParserTest($name, $file) {
    $contents = Filesystem::readFile($file);
    $contents = preg_split('/^~{4,}\n/m', $contents);

    if (count($contents) < 2) {
      throw new Exception(
        pht(
          "Expected '%s' separating test case and results.",
          '~~~~~~~~~~'));
    }

    list($data, $options, $expect) = array_merge($contents, array(null));

    $options = id(new PhutilSimpleOptions())->parse($options);

    $type = null;
    foreach ($options as $key => $value) {
      switch ($key) {
        case 'pass':
        case 'fail-syntax':
        case 'fail-parse':
          if ($type !== null) {
            throw new Exception(
              pht(
                'Test file "%s" unexpectedly specifies multiple expected '.
                'test outcomes.',
                $name));
          }
          $type = $key;
          break;
        case 'comment':
          // Human readable comment providing test case information.
          break;
        case 'rtrim':
          // Allows construction of tests which rely on EOF without newlines.
          $data = rtrim($data);
          break;
        default:
          throw new Exception(
            pht(
              'Test file "%s" has unknown option "%s" in its options '.
              'string.',
              $name,
              $key));
      }
    }

    if ($type === null) {
      throw new Exception(
        pht(
          'Test file "%s" does not specify a test result (like "pass") in '.
          'its options string.',
          $name));
    }

    $future = PhutilXHPASTBinary::getParserFuture($data);
    list($err, $stdout, $stderr) = $future->resolve();

    switch ($type) {
      case 'pass':
      case 'fail-parse':
        $this->assertEqual(0, $err, pht('Exit code for "%s".', $name));

        if (!strlen($expect)) {
          // If there's no "expect" data in the test case, that's OK.
          break;
        }

        try {
          $expect = phutil_json_decode($expect);
        } catch (PhutilJSONParserException $ex) {
          throw new PhutilProxyException(
            pht(
              'Expect data for test "%s" is not valid JSON.',
              $name),
            $ex);
        }

        try {
          $stdout = phutil_json_decode($stdout);
        } catch (PhutilJSONParserException $ex) {
          throw new PhutilProxyException(
            pht(
              'Output for test file "%s" is not valid JSON.',
              $name),
            $ex);
        }

        $json = new PhutilJSON();

        $expect_nice = $json->encodeFormatted($expect);
        $stdout_nice = $json->encodeFormatted($stdout);

        if ($type == 'pass') {
          $this->assertEqual(
            $expect_nice,
            $stdout_nice,
            pht('Parser output for "%s".', $name));
        } else {
          $this->assertFalse(
            ($expect_nice == $stdout_nice),
            pht('Expected parser to parse "%s" incorrectly.', $name));
        }
        break;
      case 'fail-syntax':
        $this->assertEqual(1, $err, pht('Exit code for "%s".', $name));
        $this->assertTrue(
          (bool)preg_match('/syntax error/', $stderr),
          pht('Expect "syntax error" in stderr or "%s".', $name));
        break;
    }
  }

}
