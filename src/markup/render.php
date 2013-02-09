<?php

/**
 * @group markup
 * @deprecated Use phutil_tag() instead.
 */
function phutil_render_tag($tag, array $attributes = array(), $content = null) {
  if (is_array($content)) {
    $content = implode('', $content);
  }
  $html = phutil_tag($tag, $attributes, phutil_safe_html($content));
  return $html->getHTMLContent();
}

/**
 * @group markup
 */
function phutil_tag($tag, array $attributes = array(), $content = null) {
  if (!empty($attributes['href'])) {

    // This might be a URI object, so cast it to a string.
    $href = (string)$attributes['href'];

    // Block 'javascript:' hrefs at the tag level: no well-designed application
    // should ever use them, and they are a potent attack vector. This function
    // is deep in the core and performance sensitive, so skip the relatively
    // expensive preg_match() call if the initial character is '/' (this is the
    // case with essentially every URI Phabricator renders).
    if (isset($href[0]) &&
        ($href[0] != '/') &&
        preg_match('/^\s*javascript:/i', $href)) {
      throw new Exception(
        "Attempting to render a tag with an 'href' attribute that begins ".
        "with 'javascript:'. This is either a serious security concern or a ".
        "serious architecture concern. Seek urgent remedy.");
    }
  }

  foreach ($attributes as $k => $v) {
    if ($v === null) {
      continue;
    }
    $v = phutil_escape_html($v);
    $attributes[$k] = ' '.$k.'="'.$v.'"';
  }

  $attributes = implode('', $attributes);

  if ($content === null) {
    return new PhutilSafeHTML('<'.$tag.$attributes.' />');
  }

  if (is_array($content)) {
    $content = implode('', array_map('phutil_escape_html', $content));
  } else {
    $content = phutil_escape_html($content);
  }
  return new PhutilSafeHTML('<'.$tag.$attributes.'>'.$content.'</'.$tag.'>');
}

/**
 * @group markup
 */
function phutil_escape_html($string) {
  if ($string instanceof PhutilSafeHTML) {
    return $string;
  }
  return htmlspecialchars($string, ENT_QUOTES, 'UTF-8');
}

/**
 * @group markup
 */
function phutil_escape_html_newlines($string) {
  return phutil_safe_html(nl2br(phutil_escape_html($string)));
}

/**
 * Mark string as safe for use in HTML.
 *
 * @group markup
 */
function phutil_safe_html($string) {
  if ($string == '') {
    return $string;
  } else if ($string instanceof PhutilSafeHTML) {
    return $string;
  } else {
    return new PhutilSafeHTML($string);
  }
}

/**
 * HTML safe version of implode().
 *
 * @group markup
 */
function phutil_implode_html($glue, array $pieces) {
  $glue = phutil_escape_html($glue);
  $pieces = array_map('phutil_escape_html', $pieces);
  return phutil_safe_html(implode($glue, $pieces));
}

/**
 * Format a HTML code. This function behaves like sprintf(), except that all
 * the normal conversions (like %s) will be properly escaped.
 *
 * @group markup
 */
function hsprintf($html/* , ... */) {
  $args = func_get_args();
  array_shift($args);
  return new PhutilSafeHTML(
    vsprintf($html, array_map('phutil_escape_html', $args)));
}


/**
 * Escape text for inclusion in a URI or a query parameter. Note that this
 * method does NOT escape '/', because "%2F" is invalid in paths and Apache
 * will automatically 404 the page if it's present. This will produce correct
 * (the URIs will work) and desirable (the URIs will be readable) behavior in
 * these cases:
 *
 *    '/path/?param='.phutil_escape_uri($string);         # OK: Query Parameter
 *    '/path/to/'.phutil_escape_uri($string);             # OK: URI Suffix
 *
 * It will potentially produce the WRONG behavior in this special case:
 *
 *    COUNTEREXAMPLE
 *    '/path/to/'.phutil_escape_uri($string).'/thing/';   # BAD: URI Infix
 *
 * In this case, any '/' characters in the string will not be escaped, so you
 * will not be able to distinguish between the string and the suffix (unless
 * you have more information, like you know the format of the suffix). For infix
 * URI components, use @{function:phutil_escape_uri_path_component} instead.
 *
 * @param   string  Some string.
 * @return  string  URI encoded string, except for '/'.
 *
 * @group markup
 */
function phutil_escape_uri($string) {
  return str_replace('%2F', '/', rawurlencode($string));
}


/**
 * Escape text for inclusion as an infix URI substring. See discussion at
 * @{function:phutil_escape_uri}. This function covers an unusual special case;
 * @{function:phutil_escape_uri} is usually the correct function to use.
 *
 * This function will escape a string into a format which is safe to put into
 * a URI path and which does not contain '/' so it can be correctly parsed when
 * embedded as a URI infix component.
 *
 * However, you MUST decode the string with
 * @{function:phutil_unescape_uri_path_component} before it can be used in the
 * application.
 *
 * @param   string  Some string.
 * @return  string  URI encoded string that is safe for infix composition.
 *
 * @group markup
 */
function phutil_escape_uri_path_component($string) {
  return rawurlencode(rawurlencode($string));
}


/**
 * Unescape text that was escaped by
 * @{function:phutil_escape_uri_path_component}. See
 * @{function:phutil_escape_uri} for discussion.
 *
 * Note that this function is NOT the inverse of
 * @{function:phutil_escape_uri_path_component}! It undoes additional escaping
 * which is added to survive the implied unescaping performed by the webserver
 * when interpreting the request.
 *
 * @param string  Some string emitted
 *                from @{function:phutil_escape_uri_path_component} and
 *                then accessed via a web server.
 * @return string Original string.
 * @group markup
 */
function phutil_unescape_uri_path_component($string) {
  return rawurldecode($string);
}
