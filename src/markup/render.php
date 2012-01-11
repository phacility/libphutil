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
 * @group markup
 */
function phutil_render_tag($tag, array $attributes = array(), $content = null) {

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
    return '<'.$tag.$attributes.' />';
  } else {
    return '<'.$tag.$attributes.'>'.$content.'</'.$tag.'>';
  }
}

/**
 * @group markup
 */
function phutil_escape_html($string) {
  return htmlspecialchars($string, ENT_QUOTES, 'UTF-8');
}

/**
 * @group markup
 */
function phutil_escape_uri($string) {
  return rawurlencode($string);
}
