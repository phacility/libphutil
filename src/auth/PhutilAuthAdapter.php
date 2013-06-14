<?php

abstract class PhutilAuthAdapter {

  abstract public function getAccountID();
  abstract public function getAdapterType();
  abstract public function getAdapterDomain();

  public function getAdapterKey() {
    return $this->getAdapterType().':'.$this->getAdapterDomain();
  }

  public function getAccountEmail() {
    return null;
  }

  public function getAccountName() {
    return null;
  }

  public function getAccountURI() {
    return null;
  }

  public function getAccountImageURI() {
    return null;
  }

  public function getAccountRealName() {
    return null;
  }

}
