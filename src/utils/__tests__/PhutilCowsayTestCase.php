<?php

final class PhutilCowsayTestCase extends PhutilTestCase {

  public function testCowsay() {
    $dir = dirname(__FILE__).'/cowsay/';
    $tests = array();
    foreach (Filesystem::listDirectory($dir, false) as $test) {
      if (preg_match('/\.test\z/', $test)) {
        $tests[] = $test;
      }
    }

    foreach ($tests as $test) {
      $data = Filesystem::readFile($dir.$test);
      $expect = preg_replace('/\.test\z/', '.expect', $test);
      $expect = Filesystem::readFile($dir.$expect);

      $pattern = '/^~~~+$/m';

      if (!preg_match($pattern, $data)) {
        throw new Exception(
          pht(
            'Expected cowsay test file "%s" to contain a line of tildes '.
            'separating the template from the test parameters.',
            $test));
      }

      list($template, $spec) = preg_split($pattern, $data, 2);
      $spec = phutil_json_decode($spec);

      $cowsay = id(new PhutilCowsay())
        ->setTemplate($template);

      if (idx($spec, 'text') !== null) {
        $cowsay->setText($spec['text']);
      }

      if (idx($spec, 'eyes') !== null) {
        $cowsay->setEyes($spec['eyes']);
      }

      if (idx($spec, 'tongue') !== null) {
        $cowsay->setTongue($spec['tongue']);
      }

      if (idx($spec, 'action') !== null) {
        $cowsay->setAction($spec['action']);
      }

      $actual = $cowsay->renderCow();

      $this->assertEqual(
        rtrim($expect),
        rtrim($actual),
        pht('Cowsay Test Case "%s"', $test));
    }
  }

}
