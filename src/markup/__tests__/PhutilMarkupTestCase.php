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
 * @group testcase
 */
final class PhutilMarkupTestCase extends PhutilTestCase {

  public function testTagDefaults() {
    $this->assertEqual(
      phutil_render_tag('x'),
      phutil_render_tag('x', array()));

    $this->assertEqual(
      phutil_render_tag('x', array()),
      phutil_render_tag('x', array(), null));
  }

  public function testTagEmpty() {
    $this->assertEqual(
      '<x />',
      phutil_render_tag('x', array(), null));

    $this->assertEqual(
      '<x></x>',
      phutil_render_tag('x', array(), ''));
  }


  public function testTagBasics() {
    $this->assertEqual(
      '<x />',
      phutil_render_tag('x'));

    $this->assertEqual(
      '<x>y</x>',
      phutil_render_tag('x', array(), 'y'));
  }

  public function testTagAttributes() {
    $this->assertEqual(
      '<x u="v">y</x>',
      phutil_render_tag('x', array('u' => 'v'), 'y'));

    $this->assertEqual(
      '<x u="v" />',
      phutil_render_tag('x', array('u' => 'v')));
  }

  public function testTagEscapes() {
    $this->assertEqual(
      '<x u="&lt;" />',
      phutil_render_tag('x', array('u' => '<')));

    $this->assertEqual(
      '<x><y /></x>',
      phutil_render_tag('x', array(), phutil_render_tag('y')));
  }

  public function testTagNullAttribute() {
    $this->assertEqual(
      '<x />',
      phutil_render_tag('x', array('y' => null)));
  }

  public function testTagJavascriptProtocolRejection() {
    $hrefs = array(
      'javascript:alert(1)'         => true,
      'JAVASCRIPT:alert(1)'         => true,
      '     javascript:alert(1)'    => true,
      '/'                           => false,
      '/path/to/stuff/'             => false,
      ''                            => false,
      'http://example.com/'         => false,
      '#'                           => false,
    );

    foreach (array(true, false) as $use_uri) {
      foreach ($hrefs as $href => $expect) {
        if ($use_uri) {
          $href = new PhutilURI($href);
        }

        $caught = null;
        try {
          phutil_render_tag('a', array('href' => $href), 'click for candy');
        } catch (Exception $ex) {
          $caught = $ex;
        }
        $this->assertEqual(
          $expect,
          $caught instanceof Exception,
          "Rejected href: {$href}");
      }
    }
  }

  public function testURIEscape() {
    $this->assertEqual(
      '%2B/%20%3F%23%26%3A%21xyz%25',
      phutil_escape_uri('+/ ?#&:!xyz%'));
  }

  public function testURIPathComponentEscape() {
    $this->assertEqual(
      'a%252Fb',
      phutil_escape_uri_path_component('a/b'));

    $str = '';
    for ($ii = 0; $ii <= 255; $ii++) {
      $str .= chr($ii);
    }

    $this->assertEqual(
      $str,
      phutil_unescape_uri_path_component(
        rawurldecode( // Simulates webserver.
          phutil_escape_uri_path_component($str))));
  }

  public function testHsprintf() {
    $this->assertEqual(
      '<div>&lt;3</div>',
      hsprintf('<div>%s</div>', '<3'));
  }

}
