<?php

abstract class Phobject {

  public function __set($name, $value) {
    throw new DomainException(
      "Attempted write to undeclared property ".get_class($this)."::\$$name. ".
      "This is an application error, please report it at ".
      "https://secure.phabricator.com/maniphest/task/create/");
  }

}
