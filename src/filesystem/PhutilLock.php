<?php


/**
 * Base class for locks, like file locks.
 *
 * libphutil provides a concrete lock in @{class:PhutilFileLock}.
 *
 *   $lock->lock();
 *     do_contentious_things();
 *   $lock->unlock();
 *
 * If the lock can't be acquired because it is already held,
 * @{class:PhutilLockException} is thrown. Other exceptions indicate
 * permanent failure unrelated to locking.
 *
 * When extending this class, you should call @{method:getLock} to look up
 * an existing lock object, and @{method:registerLock} when objects are
 * constructed to register for automatic unlock on shutdown.
 *
 * @task  impl        Lock Implementation
 * @task  registry    Lock Registry
 * @task  construct   Constructing Locks
 * @task  status      Determining Lock Status
 * @task  lock        Locking
 * @task  internal    Internals
 */
abstract class PhutilLock extends Phobject {

  private static $registeredShutdownFunction = false;
  private static $locks = array();

  private $locked = false;
  private $profilerID;
  private $name;

/* -(  Constructing Locks  )------------------------------------------------- */


  /**
   * Build a new lock, given a lock name. The name should be globally unique
   * across all locks.
   *
   * @param string Globally unique lock name.
   * @task construct
   */
  protected function __construct($name) {
    $this->name = $name;
  }


/* -(  Lock Implementation  )------------------------------------------------ */


  /**
   * Acquires the lock, or throws @{class:PhutilLockException} if it fails.
   *
   * @param  float  Seconds to block waiting for the lock.
   * @return void
   * @task impl
   */
  abstract protected function doLock($wait);


  /**
   * Releases the lock.
   *
   * @return void
   * @task impl
   */
  abstract protected function doUnlock();


/* -(  Lock Registry  )------------------------------------------------------ */


  /**
   * Returns a globally unique name for this lock.
   *
   * @return string Globally unique lock name, across all locks.
   * @task registry
   */
  final public function getName() {
    return $this->name;
  }


  /**
   * Get a named lock, if it has been registered.
   *
   * @param string Lock name.
   * @task registry
   */
  protected static function getLock($name) {
    return idx(self::$locks, $name);
  }


  /**
   * Register a lock for cleanup when the process exits.
   *
   * @param PhutilLock Lock to register.
   * @task registry
   */
  protected static function registerLock(PhutilLock $lock) {
    if (!self::$registeredShutdownFunction) {
      register_shutdown_function(array(__CLASS__, 'unlockAll'));
      self::$registeredShutdownFunction = true;
    }

    $name = $lock->getName();
    if (self::getLock($name)) {
      throw new Exception(
        pht("Lock '%s' is already registered!", $name));
    }

    self::$locks[$name] = $lock;
  }


/* -(  Determining Lock Status  )-------------------------------------------- */


  /**
   * Determine if the lock is currently held.
   *
   * @return bool True if the lock is held.
   *
   * @task status
   */
  final public function isLocked() {
    return $this->locked;
  }


/* -(  Locking  )------------------------------------------------------------ */


  /**
   * Acquire the lock. If lock acquisition fails because the lock is held by
   * another process, throws @{class:PhutilLockException}. Other exceptions
   * indicate that lock acquisition has failed for reasons unrelated to locking.
   *
   * If the lock is already held by this process, this method throws. You can
   * test the lock status with @{method:isLocked}.
   *
   * @param  float  Seconds to block waiting for the lock. By default, do not
   *                block.
   * @return this
   *
   * @task lock
   */
  final public function lock($wait = 0) {
    if ($this->locked) {
      $name = $this->getName();
      throw new Exception(
        pht("Lock '%s' has already been locked by this process.", $name));
    }

    $profiler = PhutilServiceProfiler::getInstance();
    $profiler_id = $profiler->beginServiceCall(
      array(
        'type'  => 'lock',
        'name'  => $this->getName(),
      ));

    try {
      $this->doLock((float)$wait);
    } catch (Exception $ex) {
      $profiler->endServiceCall(
        $profiler_id,
        array(
          'lock' => false,
        ));
      throw $ex;
    }

    $this->profilerID = $profiler_id;
    $this->locked = true;

    return $this;
  }


  /**
   * Release the lock. Throws an exception on failure, e.g. if the lock is not
   * currently held.
   *
   * @return this
   *
   * @task lock
   */
  final public function unlock() {
    if (!$this->locked) {
      $name = $this->getName();
      throw new Exception(
        pht("Lock '%s is not locked by this process!", $name));
    }

    $this->doUnlock();

    $profiler = PhutilServiceProfiler::getInstance();
    $profiler->endServiceCall(
      $this->profilerID,
      array(
        'lock' => true,
      ));

    $this->profilerID = null;
    $this->locked = false;

    return $this;
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
