<?php

/**
 * Format an LDAP string. This function behaves like `sprintf`, except that all
 * the normal conversions (like "%s") will be properly escaped, and additional
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
 * @{function:ldap_sprintf} callback for LDAP encoding.
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

  $pattern[$pos] = $type;
}
