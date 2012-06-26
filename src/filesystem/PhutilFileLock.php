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
 * Wrapper around `flock()` for advisory filesystem locking. Usage is
 * straightforward:
 *
 *   $path = '/path/to/lock.file';
 *   $lock = new PhutilFileLock($path);
 *   $lock->lock();
 *
 *     do_contentious_things();
 *
 *   $lock->unlock();
 *
 * If the lock can't be acquired because it is already held,
 * @{class:PhutilFileLockException} is thrown. Other exceptions indicate
 * permanent failure unrelated to locking.
 *
 * @task  construct   Constructing Locks
 * @task  status      Determining Lock Status
 * @task  lock        Locking
 * @task  internal    Internals
 *
 * @group filesystem
 */
final class PhutilFileLock {

  private $lockfile;
  private $locked = false;
  private $handle;
  private $profilerID;

  private static $registeredShutdownFunction = false;
  private static $locks = array();


/* -(  Constructing Locks  )------------------------------------------------- */


  /**
   * Create a new lock on a lockfile. The file need not exist yet.
   *
   * @param   string          The lockfile to use.
   * @return  PhutilFileLock  New lock object.
   *
   * @task construct
   */
  public static function newForPath($lockfile) {
    $lockfile = Filesystem::resolvePath($lockfile);

    if (!self::$registeredShutdownFunction) {
      register_shutdown_function(array('PhutilFileLock', 'unlockAll'));
      self::$registeredShutdownFunction = true;
    }

    if (empty(self::$locks[$lockfile])) {
      $lock = new PhutilFileLock();
      $lock->lockfile = $lockfile;
      self::$locks[$lockfile] = $lock;
    }

    return self::$locks[$lockfile];
  }


  /**
   * Private constructor, build new locks with @{method:newForPath}.
   *
   * @task construct
   */
  private function __construct() {
    // <private>
  }


/* -(  Determining Lock Status  )-------------------------------------------- */


  /**
   * Determine if the lock is currently held.
   *
   * @return bool True if the lock is held.
   *
   * @task status
   */
  public function isLocked() {
    return $this->locked;
  }


/* -(  Locking  )------------------------------------------------------------ */


  /**
   * Acquire the lock. If lock acquisition fails because the lock is held by
   * another process, throws @{class:PhutilFileLockException}. Other exceptions
   * indicate that lock acquisition has failed for reasons unrelated to locking.
   *
   * If the lock is already held, this method throws. You can test the lock
   * status with @{method:isLocked}.
   *
   * @return void
   *
   * @task lock
   */
  public function lock() {
    if ($this->locked) {
      throw new Exception(
        "Lockfile '{$this->lockfile}' is already locked by this process!");
    }

    $path = $this->lockfile;

    $profiler = PhutilServiceProfiler::getInstance();
    $profiler_id = $profiler->beginServiceCall(
      array(
        'type'  => 'flock',
        'file'  => $this->lockfile,
      ));

    $handle = @fopen($path, 'a+');
    if (!$handle) {
      throw new FilesystemException(
        $path,
        "Unable to open lock '{$path}' for writing!");
    }

    $would_block = null;
    $ok = flock($handle, LOCK_EX | LOCK_NB, $would_block);

    if (!$ok) {
      $profiler->endServiceCall(
        $profiler_id,
        array(
          'lock'  => false,
        ));

      fclose($handle);
      throw new PhutilFileLockException($path);
    }

    $this->profilerID = $profiler_id;
    $this->handle = $handle;
    $this->locked = true;
  }


  /**
   * Release the lock. Throws an exception on failure, e.g. if the lock is not
   * currently held.
   *
   * @return void
   *
   * @task lock
   */
  public function unlock() {
    if (!$this->locked) {
      throw new Exception("Lock is not locked!");
    }

    $ok = flock($this->handle, LOCK_UN | LOCK_NB);
    if (!$ok) {
      throw new Exception("Unable to unlock file!");
    }

    $ok = fclose($this->handle);
    if (!$ok) {
      throw new Exception("Unable to close file!");
    }

    PhutilServiceProfiler::getInstance()->endServiceCall(
      $this->profilerID,
      array(
        'lock'  => true,
      ));

    $this->profilerID = null;
    $this->handle = null;
    $this->locked = false;
  }


/* -(  Internals  )---------------------------------------------------------- */


  /**
   * On shutdown, we release all the locks. You should not call this method
   * directly. Use @{method:unlock} to release individual locks.
   *
   * @return void
   *
   * @task internal
   */
  public static function unlockAll() {
    foreach (self::$locks as $key => $lock) {
      if ($lock->locked) {
        $lock->unlock();
      }
    }
  }

}
