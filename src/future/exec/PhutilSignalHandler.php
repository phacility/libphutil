<?php

abstract class PhutilSignalHandler extends Phobject {

  abstract public function canHandleSignal(PhutilSignalRouter $router, $signo);
  abstract public function handleSignal(PhutilSignalRouter $router, $signo);

}
