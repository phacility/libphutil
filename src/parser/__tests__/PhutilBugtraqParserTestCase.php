<?php

final class PhutilBugtraqParserTestCase extends PhutilTestCase {

  public function testBugtraq() {
    $actual = id(new PhutilBugtraqParser())
      ->setBugtraqPattern('http://bugs.com/%BUGID%')
      ->setBugtraqCaptureExpression('/[Ii]ssues?:?(\s*,?\s*\d+)+/')
      ->setBugtraqSelectExpression('/(\d+)/')
      ->processCorpus('Issues: 123, 345');
    $this->assertEqual(
      'Issues: http://bugs.com/123, http://bugs.com/345',
      $actual);

    $actual = id(new PhutilBugtraqParser())
      ->setBugtraqPattern('<%BUGID%>')
      ->setBugtraqCaptureExpression('/([A-Z]{2,}-\d+)/')
      ->processCorpus('AB-1 BC-2 CD-3');
    $this->assertEqual(
      '<AB-1> <BC-2> <CD-3>',
      $actual);

    $actual = id(new PhutilBugtraqParser())
      ->setBugtraqPattern('<%BUGID%>')
      ->setBugtraqCaptureExpression('/\d+/')
      ->processCorpus('This text has no bugs in it.');
    $this->assertEqual(
      'This text has no bugs in it.',
      $actual);

    $actual = id(new PhutilBugtraqParser())
      ->setBugtraqPattern('<%BUGID%>')
      ->setBugtraqCaptureExpression('/.*/')
      ->setBugtraqSelectExpression('/(\d+)/')
      ->processCorpus('This text captures but does not select.');
    $this->assertEqual(
      'This text captures but does not select.',
      $actual);

    $caught = null;
    try {
      id(new PhutilBugtraqParser())
        ->setBugtraqCaptureExpression('!');
    } catch (Exception $ex) {
      $caught = $ex;
    }
    $this->assertTrue($caught instanceof PhutilTypeCheckException);


    $caught = null;
    try {
      id(new PhutilBugtraqParser())
        ->setBugtraqSelectExpression('!');
    } catch (Exception $ex) {
      $caught = $ex;
    }
    $this->assertTrue($caught instanceof PhutilTypeCheckException);
  }


}
