<?php

/**
 * @group testcase
 */
final class PhutilFileLockTestCase extends PhutilTestCase {

  public function testLockTesting() {

    // We should be able to acquire locks.

    $file = new TempFile();

    $this->assertEqual(
      true,
      $this->lockTest($file));

    $this->assertEqual(
      true,
      $this->lockTest($file));
  }

  public function testLockHolding() {

    // When a process is holding a lock, other processes should be unable
    // to acquire it.

    $file = new TempFile();
    $hold = $this->holdLock($file);

    $this->assertEqual(
      false,
      $this->lockTest($file));

    $hold->resolveKill();

    $this->assertEqual(
      true,
      $this->lockTest($file));
  }

  public function testInProcessLocking() {

    // Other processes should be unable to lock a file if we hold the lock.

    $file = new TempFile();

    $lock = PhutilFileLock::newForPath($file);
    $lock->lock();

    $this->assertEqual(
      false,
      $this->lockTest($file));

    $lock->unlock();

    $this->assertEqual(
      true,
      $this->lockTest($file));
  }

  public function testInProcessHolding() {
    // We should be unable to lock a file if another process is holding the
    // lock.

    $file = new TempFile();
    $lock = PhutilFileLock::newForPath($file);

    $hold = $this->holdLock($file);
    $caught = null;
    try {
      $lock->lock();
    } catch (PhutilLockException $ex) {
      $caught = $ex;
    }

    $this->assertEqual(
      true,
      ($caught instanceof PhutilLockException));

    $hold->resolveKill();

    $this->assertEqual(
      true,
      $this->lockTest($file));

    $lock->lock();
    $lock->unlock();
  }

  public function testRelock() {

    // Trying to lock a file twice should throw an exception.

    $file = new TempFile();
    $lock = PhutilFileLock::newForPath($file);
    $lock->lock();

    $caught = null;
    try {
      $lock->lock();
    } catch (Exception $ex) {
      $caught = $ex;
    }

    $this->assertEqual(
      true,
      ($caught instanceof Exception));
  }

  public function testExcessiveUnlock() {

    // Trying to unlock a file twice should throw an exception.

    $file = new TempFile();
    $lock = PhutilFileLock::newForPath($file);
    $lock->lock();

    $lock->unlock();

    $caught = null;
    try {
      $lock->unlock();
    } catch (Exception $ex) {
      $caught = $ex;
    }

    $this->assertEqual(
      true,
      ($caught instanceof Exception));
  }

  public function testUnlockAll() {

    // unlockAll() should release all locks.

    $file = new TempFile();
    $lock = PhutilFileLock::newForPath($file);

    $lock->lock();

    $this->assertEqual(false, $this->lockTest($file));

    PhutilFileLock::unlockAll();

    $this->assertEqual(true, $this->lockTest($file));

    // Calling this again shouldn't do anything bad.
    PhutilFileLock::unlockAll();

    $this->assertEqual(true, $this->lockTest($file));

    $lock->lock();
    $lock->unlock();
  }

  public function testIsLocked() {

    // isLocked() should report lock status accurately.

    $file = new TempFile();
    $lock = PhutilFileLock::newForPath($file);

    $this->assertEqual(false, $lock->isLocked());

    $lock->lock();

    $this->assertEqual(true, $lock->isLocked());

    $lock->unlock();

    $this->assertEqual(false, $lock->isLocked());
  }

  private function lockTest($file) {
    list($err) = $this->buildLockFuture('--test', $file)->resolve();
    return ($err == 0);
  }

  private function holdLock($file) {
    $future = $this->buildLockFuture('--hold', $file);

    // We can't return until we're sure the subprocess has had time to acquire
    // the lock. Since actually testing for the lock would be kind of silly
    // and guarantee that we loop forever if the locking primitive broke,
    // watch stdout for a *claim* that it has acquired the lock instead.

    // Make sure we don't loop forever, no matter how bad things get.
    $future->setTimeout(30);

    $buf = '';
    while (!$future->isReady()) {
      list($stdout) = $future->read();
      $buf .= $stdout;
      if (strpos($buf, 'LOCK ACQUIRED') !== false) {
        return $future;
      }
    }

    throw new Exception("Unable to hold lock in external process!");
  }

  private function buildLockFuture($flags, $file) {
    $root = dirname(phutil_get_library_root('phutil'));
    $bin = $root.'/scripts/utils/lock.php';

    $future = new ExecFuture('%s %C %s', $bin, $flags, $file);
    $future->start();
    return $future;
  }

}
