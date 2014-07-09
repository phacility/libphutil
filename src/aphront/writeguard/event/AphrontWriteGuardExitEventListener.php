<?php
/**
 * Listener for "will exit abruptly" events. Shuts down the attached write guard
 * before request exits.
 */
final class AphrontWriteGuardExitEventListener extends PhutilEventListener {

  public function register() {
    $this->listen(PhutilEventType::TYPE_WILLEXITABRUPTLY);

    return $this;
  }

  public function handleEvent(PhutilEvent $event) {
    if (AphrontWriteGuard::isGuardActive()) {
      AphrontWriteGuard::getInstance()->disposeAbruptly();
    }
  }

}
