<?php

/**
 * Replaces ticket or issue IDs in a block of text with links. This mechanism
 * is based on (and compatible with) the Bugtraq system in TortiseSVN. See
 *
 *   http://tortoisesvn.net/docs/release/TortoiseSVN_en/tsvn-dug-bugtracker.html
 *
 * For example, to link ticket IDs formatted like this:
 *
 *   Issues: 123, 345
 *
 * ...you can use:
 *
 *   $message = id(new PhutilBugtraqParser())
 *     ->setBugtraqPattern('http://bugs.com/%BUGID%')
 *     ->setBugtraqCaptureExpression('/[Ii]ssues?:?(\s*,?\s*#\d+)+/')
 *     ->setBugtraqSelectExpression('/(\d+)/')
 *     ->processCorpus($message);
 *
 * This will produce:
 *
 *   Issues: http://bugs.com/123, http://bugs.com/345
 *
 */
final class PhutilBugtraqParser extends Phobject {

  private $bugtraqPattern;
  private $bugtraqCaptureExpression;
  private $bugtraqSelectExpression;

  public function setBugtraqPattern($pattern) {
    $this->bugtraqPattern = $pattern;
    return $this;
  }

  public function setBugtraqCaptureExpression($regex) {
    PhutilTypeSpec::newFromString('regex')->check($regex);

    $this->bugtraqCaptureExpression = $regex;
    return $this;
  }

  public function setBugtraqSelectExpression($regex) {
    PhutilTypeSpec::newFromString('regex')->check($regex);

    $this->bugtraqSelectExpression = $regex;
    return $this;
  }

  public function processCorpus($corpus) {
    $regexp = $this->bugtraqCaptureExpression;
    $matches = null;
    $flags = PREG_SET_ORDER | PREG_OFFSET_CAPTURE;

    // First, find all the matching text ranges. We do this up front because
    // when we do the replacement pass at the end, the whole thing needs to go
    // in reverse order.

    preg_match_all($regexp, $corpus, $matches, $flags);
    $captures = array();
    foreach ($matches as $match) {
      list($captured_text, $captured_offset) = $match[0];
      $captures[] = array(
        'text' => $captured_text,
        'at' => $captured_offset,
      );
    }

    // Find the actual bug IDs. If there's a selection expression, we use that
    // to pick bug IDs out of a larger context. For example, the syntax may be:
    //
    //   Issues: 123, 124
    //
    // In this case, "123" and "124" are the issue IDs, and could be selected
    // with an expression like:
    //
    //   /(\d+)/
    //
    // If there's no selection expression, we use the entire match.

    $bug_ids = array();
    $select_regexp = $this->bugtraqSelectExpression;
    foreach ($captures as $capture) {
      $captured_text = $capture['text'];
      $captured_offset = $capture['at'];

      if (strlen($select_regexp)) {
        $selections = null;
        preg_match_all(
          $select_regexp,
          $captured_text,
          $selections,
          PREG_OFFSET_CAPTURE);

        foreach ($selections[1] as $selection) {
          $bug_ids[] = array(
            'text' => $selection[0],
            'at' => $captured_offset + $selection[1],
          );
        }
      } else {
        $bug_ids[] = array(
          'text' => $captured_text,
          'at' => $captured_offset,
        );
      }
    }

    // Now that we have all the bug IDs to replace, replace them (in reverse
    // order, so the offsets don't get messed up).
    $bug_ids = array_reverse($bug_ids);
    foreach ($bug_ids as $bug) {
      $new_text = str_replace(
        '%BUGID%',
        $bug['text'],
        $this->bugtraqPattern);

      $corpus = substr_replace(
        $corpus,
        $new_text,
        $bug['at'],
        strlen($bug['text']));
    }

    return $corpus;
  }

}
