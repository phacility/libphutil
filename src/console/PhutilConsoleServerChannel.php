<?php

final class PhutilConsoleServerChannel extends PhutilChannelChannel {

  public function didReceiveStderr(PhutilExecChannel $channel, $stderr) {
    $message = id(new PhutilConsoleMessage())
      ->setType(PhutilConsoleMessage::TYPE_ERR)
      ->setData(array('%s', $stderr));
    $this->getUnderlyingChannel()->addMessage($message);
  }

}
