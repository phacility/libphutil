<?php

final class PhutilAWSCloudWatchFuture extends PhutilAWSFuture {
  private $parameters = array();

  public function setParameters($parameters) {
    $this->parameters = $parameters;
    return $this;
  }

  protected function getParameters() {
    return $this->parameters;
  }

  public function getServiceName() {
    return 'monitoring';
  }

}
