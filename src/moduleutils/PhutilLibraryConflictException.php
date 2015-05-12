<?php

/**
 * Thrown when you attempt to load two different copies of a library with the
 * same name. Trying to load the second copy of the library will trigger this,
 * and the library will not be loaded.
 *
 * This means you've either done something silly (like tried to explicitly load
 * two different versions of the same library into the same program -- this
 * won't work because they'll have namespace conflicts), or your configuration
 * might have some problems which caused two parts of your program to try to
 * load the same library but end up loading different copies of it, or there
 * may be some subtle issue like running 'arc' in a different Arcanist working
 * directory. (Some bootstrapping workflows like that which run low-level
 * library components on other copies of themselves are expected to fail.)
 *
 * To resolve this, you need to make sure your program loads no more than one
 * copy of each libphutil library, but exactly how you approach this depends on
 * why it's happening in the first place.
 *
 * @task info Getting Exception Information
 * @task construct Creating Library Conflict Exceptions
 */
final class PhutilLibraryConflictException extends Exception {

  private $library;
  private $oldPath;
  private $newPath;

  /**
   * Create a new library conflict exception.
   *
   * @param string The name of the library which conflicts with an existing
   *               library.
   * @param string The path of the already-loaded library.
   * @param string The path of the attempting-to-load library.
   *
   * @task construct
   */
  public function __construct($library, $old_path, $new_path) {
    $this->library = $library;
    $this->oldPath = $old_path;
    $this->newPath = $new_path;

    parent::__construct(pht(
      "Library conflict! The library '%s' has already been loaded (from '%s') ".
      "but is now being loaded again from a new location ('%s'). You can not ".
      "load multiple copies of the same library into a program.",
      $library,
      $old_path,
      $new_path));
  }

  /**
   * Retrieve the name of the library in conflict.
   *
   * @return string The name of the library which conflicts with an existing
   *                library.
   * @task info
   */
  public function getLibrary() {
    return $this->library;
  }

  /**
   * Get the path to the library which has already been loaded earlier in the
   * program's execution.
   *
   * @return string The path of the already-loaded library.
   * @task info
   */
  public function getOldPath() {
    return $this->oldPath;
  }

  /**
   * Get the path to the library which is causing this conflict.
   *
   * @return string The path of the attempting-to-load library.
   * @task info
   */
  public function getNewPath() {
    return $this->newPath;
  }

}
