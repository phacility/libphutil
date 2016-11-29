<?php

final class PhutilAWSEC2Future extends PhutilAWSFuture {

  private $parameters = array();

  public function setParameters($parameters) {
    $this->parameters = $parameters;
    return $this;
  }

  protected function getParameters() {
    return $this->parameters;
  }

  public function getServiceName() {
    return 'ec2';
  }

}
