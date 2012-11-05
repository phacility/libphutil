<?php

/**
 * @group internationalization
 */
interface PhutilPerson {
  const SEX_MALE = 'm';
  const SEX_FEMALE = 'f';
  const SEX_UNKNOWN = '';

  function getSex();
  function __toString();

}
