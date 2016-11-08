<?php

interface PhutilPerson {

  const GENDER_MASCULINE = 'm';
  const GENDER_FEMININE = 'f';
  const GENDER_UNKNOWN = '';

  public function getGender();
  public function __toString();
}
