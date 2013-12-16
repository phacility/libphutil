<?php

final class PhutilChannelTestCase extends PhutilTestCase {

  public function testChannelBasics() {
    list($x, $y) = PhutilSocketChannel::newChannelPair();

    $str_len_8 = 'abcdefgh';
    $str_len_4 = 'abcd';

    // Do a write with no buffer limit.

    $x->write($str_len_8);
    while (true) {
      $x->update();
      $y->update();
      $read = $y->read();
      if (strlen($read)) {
        break;
      }
    }

    // We expect to read the entire message.
    $this->assertEqual($str_len_8, $read);


    // Again, with a read buffer limit.

    $y->setReadBufferSize(4);
    $x->write($str_len_8);

    while (true) {
      $x->update();
      $y->update();
      $read = $y->read();
      if (strlen($read)) {
        break;
      }
    }

    // We expect to see only the first 4 bytes of the message.
    $this->assertEqual($str_len_4, $read);
  }

}
