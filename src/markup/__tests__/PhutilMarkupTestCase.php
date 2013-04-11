<?php

/**
 * @group testcase
 */
final class PhutilMarkupTestCase extends PhutilTestCase {

  public function testTagDefaults() {
    $this->assertEqual(
      (string)phutil_tag('br'),
      (string)phutil_tag('br', array()));

    $this->assertEqual(
      (string)phutil_tag('br', array()),
      (string)phutil_tag('br', array(), null));
  }

  public function testTagEmpty() {
    $this->assertEqual(
      '<br />',
      (string)phutil_tag('br', array(), null));

    $this->assertEqual(
      '<div></div>',
      (string)phutil_tag('div', array(), null));

    $this->assertEqual(
      '<div></div>',
      (string)phutil_tag('div', array(), ''));
  }

  public function testTagBasics() {
    $this->assertEqual(
      '<br />',
      (string)phutil_tag('br'));

    $this->assertEqual(
      '<div>y</div>',
      (string)phutil_tag('div', array(), 'y'));
  }

  public function testTagAttributes() {
    $this->assertEqual(
      '<div u="v">y</div>',
      (string)phutil_tag('div', array('u' => 'v'), 'y'));

    $this->assertEqual(
      '<br u="v" />',
      (string)phutil_tag('br', array('u' => 'v')));
  }

  public function testTagEscapes() {
    $this->assertEqual(
      '<br u="&lt;" />',
      (string)phutil_tag('br', array('u' => '<')));

    $this->assertEqual(
      '<div><br /></div>',
      (string)phutil_tag('div', array(), phutil_tag('br')));
  }

  public function testTagNullAttribute() {
    $this->assertEqual(
      '<br />',
      (string)phutil_tag('br', array('y' => null)));
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
          phutil_tag('a', array('href' => $href), 'click for candy');
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
      (string)hsprintf('<div>%s</div>', '<3'));
  }

  public function testAppendHTML() {
    $html = phutil_tag('hr');
    $html->appendHTML(phutil_tag('br'), '<evil>');
    $this->assertEqual('<hr /><br />&lt;evil&gt;', $html->getHTMLContent());
  }

  public function testArrayEscaping() {
    $this->assertEqual(
      '<div>&lt;div&gt;</div>',
      phutil_escape_html(
        array(
          hsprintf('<div>'),
          array(
            array(
              '<',
              array(
                'd',
                array(
                  array(
                    hsprintf('i'),
                  ),
                  'v',
                ),
              ),
              array(
                array(
                  '>',
                ),
              ),
            ),
          ),
          hsprintf('</div>'),
        )));

      $this->assertEqual(
        '<div><br /><hr /><wbr /></div>',
        phutil_tag(
          'div',
          array(
          ),
          array(
            array(
              array(
                phutil_tag('br'),
                array(
                  phutil_tag('hr'),
                ),
                phutil_tag('wbr'),
              ),
            ),
          ))->getHTMLContent());
    }

}
