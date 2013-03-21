<?php

/**
 * @group markup
 */
final class PhutilRemarkupEngineRemarkupCodeBlockRule
  extends PhutilRemarkupEngineBlockRule {

  public function getBlockPattern() {
    return "/^(\s{2,}|```)/";
  }

  public function shouldMatchBlock($block) {
    if (!preg_match($this->getBlockPattern(), $block)) {
      return false;
    }

    if (preg_match('@^[a-z]+://\S+$@', trim($block))) {
      return false;
    }

    return true;
  }

  public function shouldContinueWithBlock($block, $last_block) {
    // If the first code block begins with ```, we keep matching blocks until
    // we hit a terminating ```, regardless of their content.
    if (preg_match('/^```/', $last_block)) {
      if (preg_match('/```$/', $last_block)) {
        return false;
      }
      return true;
    }

    // If we just matched a code block based on indentation, always match the
    // next block if it is indented, too. This basically means that we'll treat
    // lists after code blocks as more code, but usually the "-" is from a diff
    // or from objective C or something; it is rare to intentionally follow a
    // code block with a list.
    if (preg_match('/^\s{2,}/', $block)) {
      return true;
    }

    return false;
  }

  public function shouldMergeBlocks() {
    return true;
  }

  public function markupText($text) {
    if (preg_match('/^```/', $text)) {
      // If this is a ```-style block, trim off the backticks.
      $text = preg_replace('/```\s*$/', '', substr($text, 3));
    }

    $lines = explode("\n", $text);

    $options = array(
      'counterexample'  => false,
      'lang'            => null,
      'name'            => null,
      'lines'           => null,
    );

    $parser = new PhutilSimpleOptions();
    $custom = $parser->parse(head($lines));
    if ($custom) {
      $valid = true;
      foreach ($custom as $key => $value) {
        if (!array_key_exists($key, $options)) {
          $valid = false;
          break;
        }
      }
      if ($valid) {
        array_shift($lines);
        $options = $custom + $options;
      }
    }

    // Normalize the text back to a 0-level indent.
    $min_indent = 80;
    foreach ($lines as $line) {
      for ($ii = 0; $ii < strlen($line); $ii++) {
        if ($line[$ii] != ' ') {
          $min_indent = min($ii, $min_indent);
          break;
        }
      }
    }

    $text = implode("\n", $lines);
    if ($min_indent) {
      $indent_string = str_repeat(' ', $min_indent);
      $text = preg_replace('/^'.$indent_string.'/m', '', $text);
    }

    if ($this->getEngine()->isTextMode()) {
      $out = array();

      $header = array();
      if ($options['counterexample']) {
        $header[] = 'counterexample';
      }
      if ($options['name'] != '') {
        $header[] = 'name='.$options['name'];
      }
      if ($header) {
        $out[] = implode(', ', $header);
      }

      $text = preg_replace('/^/m', '  ', $text);
      $text = preg_replace('/^\s+$/m', '', $text);
      $out[] = $text;

      return implode("\n", $out);
    }

    if (empty($options['lang'])) {
      // If the user hasn't specified "lang=..." explicitly, try to guess the
      // language. If we fail, fall back to configured defaults.
      $lang = PhutilLanguageGuesser::guessLanguage($text);
      if (!$lang) {
        $lang = nonempty(
          $this->getEngine()->getConfig('phutil.codeblock.language-default'),
          'php');
      }
      $options['lang'] = $lang;
    }

    $code_body = $this->highlightSource($text, $options);

    $name_header = null;
    if ($options['name']) {
      $name_header = phutil_tag(
        'div',
        array(
          'class' => 'remarkup-code-header',
        ),
        $options['name']);
    }

    return phutil_tag(
      'div',
      array(
        'class' => 'remarkup-code-block',
        'data-code-lang' => $options['lang'],
      ),
      array($name_header, $code_body));
  }

  private function highlightSource($text, array $options) {
    if ($options['counterexample']) {
      $aux_class = ' remarkup-counterexample';
    } else {
      $aux_class = null;
    }

    $aux_style = null;
    if ($options['lines']) {
      // Put a minimum size on this because the scrollbar is otherwise
      // unusable.
      $height = max(6, (int)$options['lines']);
      $aux_style = 'max-height: '.(2 * $height).'em;';
    }

    $engine = $this->getEngine()->getConfig('syntax-highlighter.engine');
    if (!$engine) {
      $engine = 'PhutilDefaultSyntaxHighlighterEngine';
    }
    $engine = newv($engine, array());
    $engine->setConfig(
      'pygments.enabled',
      $this->getEngine()->getConfig('pygments.enabled'));
    return phutil_tag(
      'pre',
      array(
        'class' => 'remarkup-code'.$aux_class,
        'style' => $aux_style,
      ),
      PhutilSafeHTML::applyFunction(
        'trim',
        $engine->highlightSource($options['lang'], $text)));
  }

}
