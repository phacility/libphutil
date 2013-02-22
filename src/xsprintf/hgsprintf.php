<?php

/**
 * Format a Mercurial revset expression. Supports the following conversions:
 *
 *  %s Symbol
 *    Escapes a Mercurial symbol, like a branch or bookmark name.
 *
 *  %R Rrraw Rreferrrence / Rrrrevset
 *    Passes text through unescaped (e.g., an already-escaped revset).
 *
 * @group mercurial
 */
function hgsprintf($pattern /* , ... */) {
  $args = func_get_args();
  return xsprintf('xsprintf_mercurial', null, $args);
}


/**
 * xsprintf() callback for Mercurial encoding.
 *
 * @group mercurial
 */
function xsprintf_mercurial($userdata, &$pattern, &$pos, &$value, &$length) {

  $type = $pattern[$pos];

  switch ($type) {
    case 's':
      $value = "'".addcslashes($value, "'\\")."'";
      break;
    case 'R':
      $type = 's';
      break;
  }

  $pattern[$pos]  = $type;
}
