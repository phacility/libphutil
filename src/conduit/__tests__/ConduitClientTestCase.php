<?php

final class ConduitClientTestCase extends PhutilTestCase {

  public function testConduitRequestEncoding() {
    $input = array(
      'z' => array(
        'nothing' => null,
        'emptystring' => '',
      ),
      'empty' => array(
      ),
      'list' => array(
        15,
        'quack',
        true,
        false,
      ),
      'a' => array(
        'key' => 'value',
        'key2' => 'value2',
      ),
    );

    $expect =
      'O4:S1:aO2:S3:keyS5:valueS4:key2S6:value2S5:emptyA0:S4:listA4:I2:15'.
      'S5:quackB1:B0:S1:zO2:S11:emptystringS0:S7:nothingN:';

    $this->assertEqual(
      $expect,
      ConduitClient::encodeRawDataForSignature($input));
  }

}
