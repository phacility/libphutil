<?php

final class PhageLocalAction
  extends PhageAgentAction {

  protected function newAgentFuture(PhutilCommandString $command) {
    return new ExecFuture('sh -c %s', $command);
  }

}
