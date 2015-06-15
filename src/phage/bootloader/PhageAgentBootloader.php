<?php

abstract class PhageAgentBootloader extends Phobject {

  abstract public function getName();
  abstract public function getBootCommand();
  abstract public function getBootSequence();

}
