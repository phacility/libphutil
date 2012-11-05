<?php

abstract class PhutilTestCase extends ArcanistPhutilTestCase {

  protected function getLink($method) {
    $libphutil_project = 'PHID-APRJ-8d75d09d9c1e15afec3d';
    return
      'https://secure.phabricator.com/diffusion/symbol/'.$method.
      '/?lang=php&projects='.$libphutil_project.
      '&jump=true&context='.get_class($this);
  }

}
