<?php

final class PhutilDeferredLogTestCase extends PhutilTestCase {

  public function testLogging() {
    $this->checkLog(
      "derp\n",
      'derp',
      array());

    $this->checkLog(
      "[20 Aug 1984] alincoln\n",
      '[%T] %u',
      array(
        'T' => '20 Aug 1984',
        'u' => 'alincoln',
      ));

    $this->checkLog(
      "%%%%%\n",
      '%%%%%%%%%%',
      array(
        '%' => '%',
      ));

    $this->checkLog(
      "\\000\\001\\002\n",
      '%a%b%c',
      array(
        'a' => chr(0),
        'b' => chr(1),
        'c' => chr(2),
      ));

    $this->checkLog(
      "Download: 100%\n",
      'Download: %C',
      array(
        'C' => '100%',
      ));

    $this->checkLog(
      "- bee -\n",
      '%a %b %c',
      array(
        'b' => 'bee',
      ));

    $this->checkLog(
      "\\\\\n",
      '%b',
      array(
        'b' => '\\',
      ));

    $this->checkLog(
      "a\t\\t\n",
      "%a\t%b",
      array(
        'a' => 'a',
        'b' => "\t",
      ));

    $this->checkLog(
      "\1ab\n",
      "\1a%a",
      array(
        'a' => 'b',
      ));

    $this->checkLog(
      "a % xb\n",
      '%a %% x%b',
      array(
        'a' => 'a',
        'b' => 'b',
      ));
  }

  public function testLogWriteFailure() {
    $caught = null;
    try {
      if (phutil_is_hiphop_runtime()) {
        // In HipHop exceptions thrown in destructors are not normally
        // catchable, so call __destruct() explicitly.
        $log = new PhutilDeferredLog('/derp/derp/derp/derp/derp', 'derp');
        $log->__destruct();
      } else {
        new PhutilDeferredLog('/derp/derp/derp/derp/derp', 'derp');
      }
    } catch (Exception $ex) {
      $caught = $ex;
    }
    $this->assertTrue($caught instanceof Exception);
  }

  public function testManyWriters() {
    $root = phutil_get_library_root('phutil').'/../';
    $bin = $root.'scripts/test/deferred_log.php';

    $n_writers = 3;
    $n_lines   = 8;

    $tmp = new TempFile();

    $futures = array();
    for ($ii = 0; $ii < $n_writers; $ii++) {
      $futures[] = new ExecFuture('%s %d %s', $bin, $n_lines, (string)$tmp);
    }

    id(new FutureIterator($futures))
      ->resolveAll();

    $this->assertEqual(
      str_repeat("abcdefghijklmnopqrstuvwxyz\n", $n_writers * $n_lines),
      Filesystem::readFile($tmp));
  }

  public function testNoWrite() {
    $tmp = new TempFile();

    $log = new PhutilDeferredLog($tmp, 'xyz');
    $log->setFile(null);
    unset($log);

    $this->assertEqual('', Filesystem::readFile($tmp), pht('No Write'));
  }

  public function testDoubleWrite() {
    $tmp = new TempFile();

    $log = new PhutilDeferredLog($tmp, 'xyz');
    $log->write();
    $log->write();
    unset($log);

    $this->assertEqual(
      "xyz\n",
      Filesystem::readFile($tmp), pht('Double Write'));
  }

  public function testSetAfterWrite() {
    $tmp1 = new TempFile();
    $tmp2 = new TempFile();

    $log = new PhutilDeferredLog($tmp1, 'xyz');
    $log->write();

    $caught = null;
    try {
      $log->setFile($tmp2);
    } catch (Exception $ex) {
      $caught = $ex;
    }

    $this->assertTrue($caught instanceof Exception, pht('Set After Write'));
  }

  private function checkLog($expect, $format, $data) {
    $tmp = new TempFile();

    $log = new PhutilDeferredLog($tmp, $format);
    $log->setData($data);
    unset($log);

    $this->assertEqual($expect, Filesystem::readFile($tmp), $format);
  }

}
