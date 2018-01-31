<?php

/**
 * Find files on disk matching criteria, like the 'find' system utility. Use of
 * this class is straightforward:
 *
 *    // Find PHP files in /tmp
 *    $files = id(new FileFinder('/tmp'))
 *      ->withType('f')
 *      ->withSuffix('php')
 *      ->find();
 *
 * @task  create    Creating a File Query
 * @task  config    Configuring File Queries
 * @task  exec      Executing the File Query
 * @task  internal  Internal
 */
final class FileFinder extends Phobject {

  private $root;
  private $exclude = array();
  private $paths = array();
  private $name = array();
  private $suffix = array();
  private $nameGlobs = array();
  private $type;
  private $generateChecksums = false;
  private $followSymlinks;
  private $forceMode;

  /**
   * Create a new FileFinder.
   *
   * @param string Root directory to find files beneath.
   * @return this
   * @task create
   */
  public function __construct($root) {
    $this->root = rtrim($root, '/');
  }

  /**
   * @task config
   */
  public function excludePath($path) {
    $this->exclude[] = $path;
    return $this;
  }

  /**
   * @task config
   */
  public function withName($name) {
    $this->name[] = $name;
    return $this;
  }

  /**
   * @task config
   */
  public function withSuffix($suffix) {
    $this->suffix[] = $suffix;
    return $this;
  }

  /**
   * @task config
   */
  public function withPath($path) {
    $this->paths[] = $path;
    return $this;
  }

  /**
   * @task config
   */
  public function withType($type) {
    $this->type = $type;
    return $this;
  }

  /**
   * @task config
   */
  public function withFollowSymlinks($follow) {
    $this->followSymlinks = $follow;
    return $this;
  }

  /**
   * @task config
   */
  public function setGenerateChecksums($generate) {
    $this->generateChecksums = $generate;
    return $this;
  }

  public function getGenerateChecksums() {
    return $this->generateChecksums;
  }

  public function withNameGlob($pattern) {
    $this->nameGlobs[] = $pattern;
    return $this;
  }

  /**
   * @task config
   * @param string Either "php", "shell", or the empty string.
   */
  public function setForceMode($mode) {
    $this->forceMode = $mode;
    return $this;
  }

  /**
   * @task internal
   */
  public function validateFile($file) {

    if ($this->name) {
      $matches = false;
      foreach ($this->name as $curr_name) {
        if (basename($file) === $curr_name) {
          $matches = true;
          break;
        }
      }

      if (!$matches) {
        return false;
      }
    }

    if ($this->nameGlobs) {
      $name = basename($file);

      $matches = false;
      foreach ($this->nameGlobs as $glob) {
        $glob = addcslashes($glob, '\\');
        if (fnmatch($glob, $name)) {
          $matches = true;
          break;
        }
      }

      if (!$matches) {
        return false;
      }
    }

    if ($this->suffix) {
      $matches = false;
      foreach ($this->suffix as $suffix) {
        $suffix = addcslashes($suffix, '\\?*');
        $suffix = '*.'.$suffix;
        if (fnmatch($suffix, $file)) {
          $matches = true;
          break;
        }
      }

      if (!$matches) {
        return false;
      }
    }

    if ($this->paths) {
      $matches = false;
      foreach ($this->paths as $path) {
        if (fnmatch($path, $this->root.'/'.$file)) {
          $matches = true;
          break;
        }
      }

      if (!$matches) {
        return false;
      }
    }

    $fullpath = $this->root.'/'.ltrim($file, '/');
    if (($this->type == 'f' && is_dir($fullpath))
        || ($this->type == 'd' && !is_dir($fullpath))) {
      return false;
    }

    return true;
  }

  /**
   * @task internal
   */
  private function getFiles($dir) {
    $found = Filesystem::listDirectory($this->root.'/'.$dir, true);
    $files = array();
    if (strlen($dir) > 0) {
      $dir = rtrim($dir, '/').'/';
    }
    foreach ($found as $filename) {
      // Only exclude files whose names match relative to the root.
      if ($dir == '') {
        $matches = true;
        foreach ($this->exclude as $exclude_path) {
          if (fnmatch(ltrim($exclude_path, './'), $dir.$filename)) {
            $matches = false;
            break;
          }
        }
        if (!$matches) {
          continue;
        }
      }

      if ($this->validateFile($dir.$filename)) {
        $files[] = $dir.$filename;
      }

      if (is_dir($this->root.'/'.$dir.$filename)) {
        foreach ($this->getFiles($dir.$filename) as $file) {
          $files[] = $file;
        }
      }
    }
    return $files;
  }

  /**
   * @task exec
   */
  public function find() {

    $files = array();

    if (!is_dir($this->root) || !is_readable($this->root)) {
      throw new Exception(
        pht(
          "Invalid %s root directory specified ('%s'). Root directory ".
          "must be a directory, be readable, and be specified with an ".
          "absolute path.",
          __CLASS__,
          $this->root));
    }

    if ($this->forceMode == 'shell') {
      $php_mode = false;
    } else if ($this->forceMode == 'php') {
      $php_mode = true;
    } else {
      $php_mode = (phutil_is_windows() || !Filesystem::binaryExists('find'));
    }

    if ($php_mode) {
      $files = $this->getFiles('');
    } else {
      $args = array();
      $command = array();

      $command[] = 'find';
      if ($this->followSymlinks) {
        $command[] = '-L';
      }
      $command[] = '.';

      if ($this->exclude) {
        $command[] = $this->generateList('path', $this->exclude).' -prune';
        $command[] = '-o';
      }

      if ($this->type) {
        $command[] = '-type %s';
        $args[] = $this->type;
      }

      if ($this->name) {
        $command[] = $this->generateList('name', $this->name, 'name');
      }

      if ($this->suffix) {
        $command[] = $this->generateList('name', $this->suffix, 'suffix');
      }

      if ($this->paths) {
        $command[] = $this->generateList('path', $this->paths);
      }

      if ($this->nameGlobs) {
        $command[] = $this->generateList('name', $this->nameGlobs);
      }

      $command[] = '-print0';

      array_unshift($args, implode(' ', $command));
      list($stdout) = newv('ExecFuture', $args)
        ->setCWD($this->root)
        ->resolvex();

      $stdout = trim($stdout);
      if (!strlen($stdout)) {
        return array();
      }

      $files = explode("\0", $stdout);

      // On OSX/BSD, find prepends a './' to each file.
      foreach ($files as $key => $file) {
        // When matching directories, we can get "." back in the result set,
        // but this isn't an interesting result.
        if ($file == '.') {
          unset($files[$key]);
          continue;
        }

        if (substr($files[$key], 0, 2) == './') {
          $files[$key] = substr($files[$key], 2);
        }
      }
    }

    if (!$this->generateChecksums) {
      return $files;
    } else {
      $map = array();
      foreach ($files as $line) {
        $fullpath = $this->root.'/'.ltrim($line, '/');
        if (is_dir($fullpath)) {
          $map[$line] = null;
        } else {
          $map[$line] = md5_file($fullpath);
        }
      }
      return $map;
    }
  }

  /**
   * @task internal
   */
  private function generateList(
    $flag,
    array $items,
    $mode = 'glob') {

    foreach ($items as $key => $item) {
      // If the mode is not "glob" mode, we're going to escape glob characters
      // in the pattern. Otherwise, we escape only backslashes.
      if ($mode === 'glob') {
        $item = addcslashes($item, '\\');
      } else {
        $item = addcslashes($item, '\\*?');
      }

      if ($mode === 'suffix') {
        $item = '*.'.$item;
      }

      $item = (string)csprintf('%s %s', '-'.$flag, $item);

      $items[$key] = $item;
    }

    $items = implode(' -o ', $items);
    return '"(" '.$items.' ")"';
  }
}
