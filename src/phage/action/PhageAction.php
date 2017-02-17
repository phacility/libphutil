<?php

abstract class PhageAction
  extends Phobject {

  private $actions = array();

  abstract public function isContainerAction();

  protected function willAddAction(PhageAction $action) {
    throw new PhutilMethodNotImplementedException();
  }

  final protected function getActions() {
    $this->requireContainerAction();

    return $this->actions;
  }

  final public function addAction(PhageAction $action) {
    $this->requireContainerAction();

    $this->willAddAction($action);

    $this->actions[] = $action;
  }

  protected function getAllWaitingChannels() {
    if (!$this->isContainerAction()) {
      throw new PhutilMethodNotImplementedException();
    }

    $channels = array();
    foreach ($this->getActions() as $action) {
      foreach ($action->getAllWaitingChannels() as $channel) {
        $channels[] = $channel;
      }
    }

    return $channels;
  }

  private function requireContainerAction() {
    if (!$this->isContainerAction()) {
      throw new Exception(pht('This is not a container action.'));
    }
  }

}
