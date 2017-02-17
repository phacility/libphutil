<?php

final class PhagePlanAction
  extends PhageAction {

  public function isContainerAction() {
    return true;
  }

  protected function willAddAction(PhageAction $action) {
    if (!($action instanceof PhageAgentAction)) {
      throw new Exception(
        pht('Only agent actions may be added to a plan.'));
    }
  }

  public function executePlan() {
    $agents = $this->getAgents();
    foreach ($agents as $agent) {
      $agent->startAgent();
    }

    while (true) {
      $channels = $this->getAllWaitingChannels();
      PhutilChannel::waitForAny($channels);

      $agents = $this->getActiveAgents();
      if (!$agents) {
        break;
      }

      foreach ($agents as $agent) {
        $agent->updateAgent();
      }
    }
  }

  protected function getAgents() {
    return $this->getActions();
  }

  protected function getActiveAgents() {
    $agents = $this->getAgents();

    foreach ($agents as $key => $agent) {
      if (!$agent->isActiveAgent()) {
        unset($agents[$key]);
      }
    }

    return $agents;
  }


}
