<?php

final class PhutilAuthAdapterEmpty extends PhutilAuthAdapter {

  private $accountID;
  private $adapterType;
  private $adapterDomain;

  public function setAdapterDomain($adapter_domain) {
    $this->adapterDomain = $adapter_domain;
    return $this;
  }

  public function getAdapterDomain() {
    return $this->adapterDomain;
  }


  public function setAdapterType($adapter_type) {
    $this->adapterType = $adapter_type;
    return $this;
  }

  public function getAdapterType() {
    return $this->adapterType;
  }

  public function setAccountID($account_id) {
    $this->accountID = $account_id;
    return $this;
  }

  public function getAccountID() {
    return $this->accountID;
  }

}
