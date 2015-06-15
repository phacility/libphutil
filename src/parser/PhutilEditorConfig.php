<?php

/**
 * Parser for [[http://editorconfig.org/ | EditorConfig]] files.
 */
final class PhutilEditorConfig extends Phobject {

  const CHARSET             = 'charset';
  const END_OF_LINE         = 'end_of_line';
  const INDENT_SIZE         = 'indent_size';
  const INDENT_STYLE        = 'indent_style';
  const FINAL_NEWLINE       = 'insert_final_newline';
  const LINE_LENGTH         = 'max_line_length';
  const TAB_WIDTH           = 'tab_width';
  const TRAILING_WHITESPACE = 'trim_trailing_whitespace';

  /**
   * Valid properties.
   *
   * See http://editorconfig.org/#file-format-details.
   */
  private static $knownProperties = array(
    self::CHARSET => array(
      'latin1',
      'utf-8',
      'utf-8-bom',
      'utf-16be',
      'utf-16le',
    ),
    self::END_OF_LINE => array('lf', 'cr', 'crlf'),
    self::INDENT_SIZE => 'int|string',
    self::INDENT_STYLE => array('space', 'tab'),
    self::FINAL_NEWLINE => 'bool',
    self::LINE_LENGTH => 'int',
    self::TAB_WIDTH => 'int',
    self::TRAILING_WHITESPACE => 'bool',
  );

  private $root;

  /**
   * Constructor.
   *
   * @param string  The root directory.
   */
  public function __construct($root) {
    $this->root = $root;
  }

  /**
   * Get the specified EditorConfig property for the specified path.
   *
   * @param  string
   * @param  string
   * @return wild
   */
  public function getProperty($path, $key) {
    if (!idx(self::$knownProperties, $key)) {
      throw new InvalidArgumentException(pht('Invalid EditorConfig property.'));
    }

    $props = $this->getProperties($path);

    switch ($key) {
      case self::INDENT_SIZE:
        if (idx($props, self::INDENT_SIZE) === null &&
            idx($props, self::INDENT_STYLE) === 'tab') {
          return 'tab';
        } else if (idx($props, self::INDENT_SIZE) === 'tab' &&
                   idx($props, self::TAB_WIDTH) === null) {
          return idx($props, self::TAB_WIDTH);
        }
        break;

      case self::TAB_WIDTH:
        if (idx($props, self::TAB_WIDTH) === null &&
            idx($props, self::INDENT_SIZE) !== null &&
            idx($props, self::INDENT_SIZE) !== 'tab') {
          return idx($props, self::INDENT_SIZE);
        }
        break;
    }

    return idx($props, $key);
  }

  /**
   * Get the EditorConfig properties for the specified path.
   *
   * Returns a map containing all of the EditorConfig properties which apply
   * to the specified path. The following rules are applied when processing
   * EditorConfig files:
   *
   * - If a glob does not contain `/`, it can match a path in any subdirectory.
   * - If the first character of a glob is `/`, it will only match files in the
   *   same directory as the `.editorconfig` file.
   * - Properties and values are case-insensitive.
   * - Unknown properties will be silently ignored.
   * - Values are not validated against the specification (this may change in
   *   the future).
   * - Invalid glob patterns will be silently ignored.
   *
   * @param  string
   * @return map<string, wild>
   */
  public function getProperties($path) {
    $configs = $this->getEditorConfigs($path);
    $matches = array();

    foreach ($configs as $config) {
      list($path_prefix, $editorconfig) = $config;

      foreach ($editorconfig as $glob => $properties) {
        if (!$glob) {
          continue;
        }

        if (strpos($glob, '/') === false) {
          $glob = '**/'.$glob;
        } else if (strncmp($glob, '/', 0)) {
          $glob = substr($glob, 1);
        }

        $glob = $path_prefix.'/'.$glob;
        try {
          if (!phutil_fnmatch($glob, $path)) {
            continue;
          }
        } catch (Exception $ex) {
          // Invalid glob pattern... ignore it.
          continue;
        }

        foreach ($properties as $property => $value) {
          $property = strtolower($property);

          if (!idx(self::$knownProperties, $property)) {
            // Unknown property... ignore it.
            continue;
          }

          if (is_string($value)) {
            $value = strtolower($value);
          }
          if ($value === '') {
            $value = null;
          }
          $matches[$property] = $value;
        }
      }
    }

    return $matches;
  }

  /**
   * Returns the EditorConfig files which affect the specified path.
   *
   * Find and parse all `.editorconfig` files between the specified path and
   * the root directory. The results are returned in the same order that they
   * should be matched.
   *
   * return list<pair<string, map>>
   */
  private function getEditorConfigs($path) {
    $configs    = array();
    $found_root = false;
    $root       = $this->root;

    do {
      $path = dirname($path);
      $file = $path.'/.editorconfig';

      if (!Filesystem::pathExists($file)) {
        continue;
      }

      $contents = Filesystem::readFile($file);
      $config = phutil_ini_decode($contents);

      if (idx($config, 'root') === true) {
        $found_root = true;
      }
      unset($config['root']);
      array_unshift($configs, array($path, $config));

      if ($found_root) {
        break;
      }
    } while ($path != $root && Filesystem::isDescendant($path, $root));

    return $configs;
  }

}
