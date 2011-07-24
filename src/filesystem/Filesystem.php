<?php

/*
 * Copyright 2011 Facebook, Inc.
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
 * Simple wrapper class for common filesystem tasks like reading and writing
 * files. When things go wrong, this class throws detailed exceptions with
 * good information about what didn't work.
 *
 * Filesystem will resolve relative paths against PWD from the environment.
 * When Filesystem is unable to complete an operation, it throws a
 * FilesystemException.
 *
 * @task directory   Directories
 * @task file        Files
 * @task path        Paths
 * @task assert      Assertions
 * @group filesystem
 */
class Filesystem {


/* -(  Files  )-------------------------------------------------------------- */


  /**
   * Read a file in a manner similar to file_get_contents(), but throw detailed
   * exceptions on failure.
   *
   * @param  string  File path to read. This file must exist and be readable,
   *                 or an exception will be thrown.
   * @return string  Contents of the specified file.
   *
   * @task   file
   */
  public static function readFile($path) {
    $path = self::resolvePath($path);

    self::assertExists($path);
    self::assertIsFile($path);
    self::assertReadable($path);

    $data = @file_get_contents($path);
    if ($data === false) {
      throw new FilesystemException(
        $path,
        "Failed to read file `{$path}'.");
    }

    return $data;
  }


  /**
   * Write a file in a manner similar to file_put_contents(), but throw
   * detailed exceptions on failure. If the file already exists, it will be
   * overwritten.
   *
   * @param  string  File path to write. This file must be writable and its
   *                 parent directory must exist.
   * @param  string  Data to write.
   *
   * @task   file
   */
  public static function writeFile($path, $data) {
    $path = self::resolvePath($path);
    $dir  = dirname($path);

    self::assertExists($dir);
    self::assertIsDirectory($dir);

    // File either needs to not exist and have a writable parent, or be
    // writable itself.
    $exists = true;
    try {
      self::assertNotExists($path);
      $exists = false;
    } catch (Exception $ex) {
      self::assertWritable($path);
    }

    if (!$exists) {
      self::assertWritable($dir);
    }

    if (@file_put_contents($path, $data) === false) {
      throw new FilesystemException(
        $path,
        "Failed to write file `{$path}'.");
    }
  }


  /**
   * Append to a file without having to deal with file handles, with
   * detailed exceptions on failure.
   *
   * @param  string  File path to write. This file must be writable or its
   *                 parent directory must exist and be writable.
   * @param  string  Data to write.
   *
   * @task   file
   */
  public static function appendFile($path, $data) {
    $path = self::resolvePath($path);

    // Use self::writeFile() if the file doesn't already exist
    try {
      self::assertExists($path);
    } catch (FilesystemException $ex) {
      self::writeFile($path, $data);
      return;
    }

    // File needs to exist or the directory needs to be writable
    $dir = dirname($path);
    self::assertExists($dir);
    self::assertIsDirectory($dir);
    self::assertWritable($dir);

    if (($fh = fopen($path, 'a')) === false) {
      throw new FilesystemException(
        $path, "Failed to open file `{$path}'.");
    }
    $dlen = strlen($data);
    if (fwrite($fh, $data) !== $dlen) {
      throw new FilesystemException(
        $path,
        "Failed to write {$dlen} bytes to `{$path}'.");
    }
    if (!fflush($fh) || !fclose($fh)) {
      throw new FilesystemException(
        $path,
        "Failed closing file `{$path}' after write.");
    }
  }


  /**
   * Remove a file or directory.
   *
   * @param  string    File to a path or directory to remove.
   * @return void
   *
   * @task   file
   */
  public static function remove($path) {
    if (!strlen($path)) {
      // Avoid removing PWD.
      throw new Exception("No path provided to remove().");
    }

    $path = self::resolvePath($path);

    if (!file_exists($path)) {
      return;
    }

    //  PHP's builtin functions for this are such a mess that it's much easier
    //  to exec out. :/
    list($err, $stdout, $stderr) = exec_manual('rm -rf %s', $path);
    if ($err) {
      throw new FilesystemException(
        $path,
        "Unable to remove `{$path}'.");
    }
  }


  /**
   * Change the permissions of a file or directory.
   *
   * @param  string    Path to the file or directory.
   * @param  int       Permission umask. Note that umask is in octal, so you
   *                   should specify it as, e.g., `0777', not `777'.
   * @return void
   *
   * @task   file
   */
  public static function changePermissions($path, $umask) {
    $path = self::resolvePath($path);

    self::assertExists($path);

    if (!@chmod($path, $umask)) {
      $readable_umask = sprintf("%04o", $umask);
      throw new FilesystemException(
        $path, "Failed to chmod `{$path}' to `{$readable_umask}'.");
    }
  }


  /**
   * Get the last modified time of a file
   *
   * @param string Path to file
   * @return Time last modified
   *
   * @task file
   */
  public static function getModifiedTime($path) {
    $path = self::resolvePath($path);
    self::assertExists($path);
    self::assertIsFile($path);
    self::assertReadable($path);

    $modified_time = @filemtime($path);

    if ($modified_time === false) {
      throw new FilesystemException(
        $path,
        'Failed to read modified time for '.$path);
    }

    return $modified_time;
  }


  /**
   * Read random bytes from /dev/urandom or equivalent.
   *
   * @param   int     Number of bytes to read.
   * @return  string  Random bytestring of the provided length.
   *
   * @task file
   */
  public static function readRandomBytes($bytes) {

    $urandom = @fopen('/dev/urandom', 'rb');
    if (!$urandom) {
      throw new FilesystemException(
        '/dev/urandom',
        'Failed to open /dev/urandom for reading!');
    }

    $data = @fread($urandom, $bytes);
    if (strlen($data) != $bytes) {
      throw new FilesystemException(
        '/dev/urandom',
        'Failed to read random bytes!');
    }

    @fclose($urandom);

    return $data;
  }


/* -(  Directories  )-------------------------------------------------------- */


  /**
   * Create a directory in a manner similar to mkdir(), but throw detailed
   * exceptions on failure.
   *
   * @param  string    Path to directory. The parent directory must exist and
   *                   be writable.
   * @param  int       Permission umask. Note that umask is in octal, so you
   *                   should specify it as, e.g., `0777', not `777'. By
   *                   default, these permissions are very liberal (0777).
   * @param  boolean   Recursivly create directories.  Default to false
   * @return string    Path to the created directory.
   *
   * @task   directory
   */
  public static function createDirectory($path, $umask = 0777,
                                            $recursive = false) {
    $path = self::resolvePath($path);

    if (is_dir($path)) {
      Filesystem::changePermissions($path, $umask);
      return $path;
    }

    $dir = dirname($path);
    if ($recursive && !file_exists($dir)) {
      // Note: We could do this with the recursive third parameter of mkdir(),
      // but then we loose the helpful FilesystemExceptions we normally get.
      self::createDirectory($dir, $umask, true);
    }

    self::assertIsDirectory($dir);
    self::assertExists($dir);
    self::assertWritable($dir);
    self::assertNotExists($path);

    if (!mkdir($path, $umask)) {
      throw new FilesystemException(
        $path,
        "Failed to create directory `{$path}'.");
    }

    // Need to change premissions explicitly because mkdir does something
    // slightly different. mkdir(2) man page:
    // 'The parameter mode specifies the permissions to use. It is modified by
    // the process's umask in the usual way: the permissions of the created
    // directory are (mode & ~umask & 0777)."'
    Filesystem::changePermissions($path, $umask);

    return $path;
  }


  /**
   * Create a temporary directory and return the path to it. You are
   * responsible for removing it (e.g., with Filesystem::remove())
   * when you are done with it.
   *
   * @param  string    Optional directory prefix.
   * @param  int       Permissions to create the directory with. By default,
   *                   these permissions are very restrictive (0700).
   * @return string    Path to newly created temporary directory.
   *
   * @task   directory
   */
  public static function createTemporaryDirectory($prefix = '', $umask = 0700) {
    $prefix = preg_replace('/[^A-Z0-9._-]+/i', '', $prefix);

    $tmp = sys_get_temp_dir();
    if (!$tmp) {
      throw new FilesystemException(
        $tmp, 'Unable to determine system temporary directory.');
    }

    $base = $tmp.DIRECTORY_SEPARATOR.$prefix;

    $tries = 3;
    do {
      $dir = $base.substr(base_convert(md5(mt_rand()), 16, 36), 0, 16);
      try {
        self::createDirectory($dir, $umask);
        break;
      } catch (FilesystemException $ex) {
        //  Ignore.
      }
    } while (--$tries);

    if (!$tries) {

      $df = disk_free_space($tmp);
      if ($df !== false && $df < 1024 * 1024) {
        throw new FilesystemException(
          $dir, "Failed to create a temporary directory: the disk is full.");
      }

      throw new FilesystemException(
        $dir, "Failed to create a temporary directory.");
    }

    return $dir;
  }


  /**
   * List files in a directory.
   *
   * @param  string    Path, absolute or relative to PWD.
   * @param  bool      If false, exclude files beginning with a ".".
   *
   * @return array     List of files and directories in the specified
   *                   directory, excluding `.' and `..'.
   *
   * @task   directory
   */
  public static function listDirectory($path, $include_hidden = true) {
    $path = self::resolvePath($path);

    self::assertExists($path);
    self::assertIsDirectory($path);
    self::assertReadable($path);

    $list = @scandir($path);
    if ($list === false) {
      throw new FilesystemException(
        $path,
        "Unable to list contents of directory `{$path}'.");
    }

    foreach ($list as $k => $v) {
      if ($v == '.' || $v == '..' || (!$include_hidden && $v[0] == '.')) {
        unset($list[$k]);
      }
    }

    return array_values($list);
  }


  /**
   * Return all directories between a path and "/". Iterating over them walks
   * from the path to the root.
   *
   * @param  string Path, absolute or relative to PWD.
   * @return list   List of parent paths, including the provided path.
   * @task   directory
   */
  public static function walkToRoot($path) {
    $path = self::resolvePath($path);

    if (is_link($path)) {
      $path = realpath($path);
    }

    $walk = array();
    $parts = explode('/', $path);
    foreach ($parts as $k => $part) {
      if (!strlen($part)) {
        unset($parts[$k]);
      }
    }
    do {
      $walk[] = '/'.implode('/', $parts);
      if (empty($parts)) {
        break;
      }
      array_pop($parts);
    } while (true);

    return $walk;
  }


/* -(  Paths  )-------------------------------------------------------------- */


  /**
   * Canonicalize a path by resolving it relative to some directory (by
   * default PWD), following parent symlinks and removing artifacts. If the
   * path is itself a symlink it is left unresolved.
   *
   * @param  string    Path, absolute or relative to PWD.
   * @return string    Canonical, absolute path.
   *
   * @task   path
   */
  public static function resolvePath($path, $relative_to = null) {
    if (strncmp($path, '/', 1)) {
      if (!$relative_to) {
        $relative_to = $_SERVER['PWD'];
      }
      $path = $relative_to.'/'.$path;
    }

    if (is_link($path)) {
      $parent_realpath = realpath(dirname($path));
      if ($parent_realpath !== false) {
        return $parent_realpath.'/'.basename($path);
      }
    }

    $realpath = realpath($path);
    if ($realpath !== false) {
      return $realpath;
    }

    // This won't work if the file doesn't exist or is on an unreadable mount
    // or something crazy like that. Try to resolve a parent so we at least
    // cover the nonexistent file case.
    $parts = explode('/', trim($path, '/'));
    while (end($parts) !== false) {
      array_pop($parts);
      $attempt = '/'.implode('/', $parts);
      $realpath = realpath($attempt);
      if ($realpath !== false) {
        $path = $realpath.substr($path, strlen($attempt));
        break;
      }
    }

    return $path;
  }

  /**
   * Test whether a path is descendant from some root path after resolving all
   * symlinks and removing artifacts. Both paths must exists for the relation
   * to obtain. A path is always a descendant of itself as long as it exists.
   *
   * @param  string   Child path, absolute or relative to PWD.
   * @param  string   Root path, absolute or relative to PWD.
   * @return bool     True if resolved child path is in fact a descendant of
   *                  resolved root path and both exist.
   * @task   path
   */
  public static function isDescendant($path, $root) {

    try {
      self::assertExists($path);
      self::assertExists($root);
    } catch (FilesystemException $e) {
      return false;
    }
    $fs = new FileList(array($root));
    return $fs->contains($path);
  }

  /**
   * Convert a canonical path to its most human-readable format. It is
   * guaranteed that you can use resolvePath() to restore a path to its
   * canonical format.
   *
   * @param  string    Path, absolute or relative to PWD.
   * @param  string    Optionally, working directory to make files readable
   *                   relative to.
   * @return string    Human-readable path.
   *
   * @task   path
   */
  public static function readablePath($path, $pwd = null) {
    if ($pwd === null) {
      $pwd = $_SERVER['PWD'];
    }

    foreach (array($pwd, self::resolvePath($pwd)) as $parent) {
      $parent = rtrim($parent, '/').'/';
      $len = strlen($parent);
      if (!strncmp($parent, $path, $len)) {
        $path = substr($path, $len);
        return $path;
      }
    }

    return $path;
  }

  /**
   * Determine whether or not a path exists in the filesystem. This differs from
   * file_exists() in that it returns true for symlinks. This method does not
   * attempt to resolve paths before testing them.
   *
   * @param   string  Test for the existence of this path.
   * @return  bool    True if the path exists in the filesystem.
   * @task    path
   */
  public static function pathExists($path) {
    return file_exists($path) || is_link($path);
  }


  /**
   * Determine if two paths are equivalent by resolving symlinks. This is
   * different from resolving both paths and comparing them because
   * resolvePath() only resolves symlinks in parent directories, not the
   * path itself.
   *
   * @param string First path to test for equivalence.
   * @param string Second path to test for equivalence.
   * @return bool  True if both paths are equivalent, i.e. reference the same
   *               entity in the filesystem.
   * @task path
   */
  public static function pathsAreEquivalent($u, $v) {
    $u = Filesystem::resolvePath($u);
    $v = Filesystem::resolvePath($v);

    $real_u = realpath($u);
    $real_v = realpath($v);

    if ($real_u) {
      $u = $real_u;
    }
    if ($real_v) {
      $v = $real_v;
    }
    return ($u == $v);
  }


/* -(  Assert  )------------------------------------------------------------- */

  /**
   * Assert that something (e.g., a file, directory, or symlink) is an
   * absolute path to the specified location.
   *
   * @param  string    Assert that this path is absolute.
   * @return void
   *
   * @task   assert
   */
  public static function assertAbsolute($path) {
    if (empty($path) || $path[0] != '/') {
      throw new FilesystemException(
        $path,
        "Filesystem entity `{$path}' is not absolute.");
    }
  }

  /**
   * Assert that something (e.g., a file, directory, or symlink) exists at a
   * specified location.
   *
   * @param  string    Assert that this path exists.
   * @return void
   *
   * @task   assert
   */
  public static function assertExists($path) {
    if (!self::pathExists($path)) {
      throw new FilesystemException(
        $path,
        "Filesystem entity `{$path}' does not exist.");
    }
  }


  /**
   * Assert that nothing exists at a specified location.
   *
   * @param  string    Assert that this path does not exist.
   * @return void
   *
   * @task   assert
   */
  public static function assertNotExists($path) {
    if (file_exists($path) || is_link($path)) {
      throw new FilesystemException(
        $path,
        "Path `{$path}' already exists!");
    }
  }


  /**
   * Assert that a path represents a file, strictly (i.e., not a directory).
   *
   * @param  string    Assert that this path is a file.
   * @return void
   *
   * @task   assert
   */
  public static function assertIsFile($path) {
    if (!is_file($path)) {
      throw new FilesystemException(
        $path,
        "Requested path `{$path}' is not a file.");
    }
  }


  /**
   * Assert that a path represents a directory, strictly (i.e., not a file).
   *
   * @param  string    Assert that this path is a directory.
   * @return void
   *
   * @task   assert
   */
  public static function assertIsDirectory($path) {
    if (!is_dir($path)) {
      throw new FilesystemException(
        $path,
        "Requested path `{$path}' is not a directory.");
    }
  }


  /**
   * Assert that a file or directory exists and is writable.
   *
   * @param  string    Assert that this path is writable.
   * @return void
   *
   * @task   assert
   */
  public static function assertWritable($path) {
    if (!is_writable($path)) {
      throw new FilesystemException(
        $path,
        "Requested path `{$path}' is not writable.");
    }
  }


  /**
   * Assert that a file or directory exists and is readable.
   *
   * @param  string    Assert that this path is readable.
   * @return void
   *
   * @task   assert
   */
  public static function assertReadable($path) {
    if (!is_readable($path)) {
      throw new FilesystemException(
        $path,
        "Path `{$path}' is not readable.");
    }
  }
}
