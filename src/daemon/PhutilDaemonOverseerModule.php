<?php

/**
 * Overseer modules allow daemons to be externally influenced.
 *
 * See @{class:PhabricatorDaemonOverseerModule} for a concrete example.
 */
abstract class PhutilDaemonOverseerModule extends Phobject {

  /**
   * This method is used to indicate to the overseer that daemons should reload.
   *
   * @return bool  True if the daemons should reload, otherwise false.
   */
  abstract public function shouldReloadDaemons();


  public static function getAllModules() {
    return id(new PhutilClassMapQuery())
      ->setAncestorClass(__CLASS__)
      ->execute();
  }

}
