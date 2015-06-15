<?php

/**
 * A list of files, primarily useful for parsing command line arguments. This
 * class makes it easier to deal with user-specified lists of files and
 * directories used by command line tools.
 *
 *    $list = new FileList(array_slice($argv, 1));
 *    foreach ($some_files as $file) {
 *      if ($list->contains($file)) {
 *        do_something_to_this($file);
 *      }
 *    }
 *
 * This sort of construction will allow the user to type "src" in order
 * to indicate 'all relevant files underneath "src/"'.
 *
 * @task create Creating a File List
 * @task test   Testing File Lists
 */
final class FileList extends Phobject {

  private $files = array();
  private $dirs  = array();

  /**
   * Build a new FileList from an array of paths, e.g. from $argv.
   *
   * @param  list  List of relative or absolute file paths.
   * @return this
   * @task create
   */
  public function __construct($paths) {
    foreach ($paths as $path) {
      $path = Filesystem::resolvePath($path);
      if (is_dir($path)) {
        $path = rtrim($path, DIRECTORY_SEPARATOR).DIRECTORY_SEPARATOR;
        $this->dirs[$path] = true;
      }
      $this->files[] = $path;
    }
  }


  /**
   * Determine if a path is one of the paths in the list. Note that an empty
   * file list is considered to contain every file.
   *
   * @param  string  Relative or absolute system file path.
   * @param  bool    If true, consider the path to be contained in the list if
   *                 the list contains a parent directory. If false, require
   *                 that the path be part of the list explicitly.
   * @return bool    If true, the file is in the list.
   * @task test
   */
  public function contains($path, $allow_parent_directory = true) {

    if ($this->isEmpty()) {
      return true;
    }

    $path = Filesystem::resolvePath($path);
    if (is_dir($path)) {
      $path .= DIRECTORY_SEPARATOR;
    }

    foreach ($this->files as $file) {
      if ($file == $path) {
        return true;
      }
      if ($allow_parent_directory) {
        $len = strlen($file);
        if (isset($this->dirs[$file]) && !strncmp($file, $path, $len)) {
          return true;
        }
      }
    }
    return false;
  }


  /**
   * Check if the file list is empty -- that is, it contains no files.
   *
   * @return   bool  If true, the list is empty.
   * @task test
   */
  public function isEmpty() {
    return !$this->files;
  }

}
