<?php

/*
 * Copyright 2012 Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * Format an LDAP string. This function behaves like sprintf(), except that all
 * the normal conversions (like %s) will be properly escaped, and additional
 * conversions are supported:
 *
 *   %S (Search Filter)
 *     Escapes text for use in a search filter.
 *
 *   %Q (Raw Query)
 *     Inserts raw, unescaped text. DANGEROUS!
 *
 */
function ldap_sprintf($pattern /* , ... */) {
  $args = func_get_args();
  return xsprintf('xsprintf_ldap', null, $args);
}

/**
 * ldap_sprintf() callback for LDAP encoding.
 * @group markup
 */
function xsprintf_ldap($userdata, &$pattern, &$pos, &$value, &$length) {

  $type = $pattern[$pos];

  // https://www.owasp.org/index.php/Preventing_LDAP_Injection_in_Java

  switch ($type) {
    case 'S':
      $value = str_replace(
        array('\\',   '*',    '(',    ')',    "\0"),
        array('\\5c', '\\2a', '\\28', '\\29', '\\00'),
        $value);
      $type = 's';
      break;

    case 's':
      $value = addcslashes($value, ',\\#+<>;"= ');
      $type = 's';
      break;

    case 'Q':
      $type = 's';
      break;
  }

  $pattern[$pos]  = $type;
}
