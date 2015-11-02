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
        $this->executeParserTest($file, Filesystem::readFile($dir.$file));
      }
    }
  }

  private function executeParserTest($name, $data) {
    $data = explode("\n", $data, 2);
    if (count($data) !== 2) {
      throw new Exception(
        pht('Expected multiple lines in parser test file "%s".', $name));
    }

    $head = head($data);
    $body = last($data);

    if (!preg_match('/^#/', $head)) {
      throw new Exception(
        pht(
          'Expected first line of parser test file "%s" to begin with `%s` '.
          'and specify test options.',
          $name,
          '#'));
    }

    $head = preg_replace('/^#\s*/', '', $head);

    $options_parser = new PhutilSimpleOptions();
    $options = $options_parser->parse($head);

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
          $body = rtrim($body);
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

    $future = PhutilXHPASTBinary::getParserFuture($body);
    list($err, $stdout, $stderr) = $future->resolve();

    switch ($type) {
      case 'pass':
      case 'fail-parse':
        $this->assertEqual(0, $err, pht('Exit code for "%s".', $name));

        $expect_name = preg_replace('/\.test$/', '.expect', $name);

        $dir = dirname(__FILE__).'/data/';
        $expect = Filesystem::readFile($dir.$expect_name);

        try {
          $expect = phutil_json_decode($expect);
        } catch (PhutilJSONParserException $ex) {
          throw new PhutilProxyException(
            pht(
              'Test ".expect" file "%s" for test "%s" is not valid JSON.',
              $expect_name,
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
