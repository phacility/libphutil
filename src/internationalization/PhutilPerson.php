<?php

interface PhutilPerson {
  const SEX_MALE = 'm';
  const SEX_FEMALE = 'f';
  const SEX_UNKNOWN = '';

  public function getSex();
  public function __toString();
}
