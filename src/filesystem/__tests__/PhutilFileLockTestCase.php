<?php

final class PhutilFileLockTestCase extends PhutilTestCase {

  public function testLockTesting() {
    // We should be able to acquire locks.

    $file = new TempFile();

    $this->assertTrue($this->lockTest($file));

    $this->assertTrue($this->lockTest($file));
  }

  public function testLockHolding() {
    // When a process is holding a lock, other processes should be unable
    // to acquire it.

    $file = new TempFile();
    $hold = $this->holdLock($file);

    $this->assertFalse($this->lockTest($file));

    $hold->resolveKill();

    $this->assertTrue($this->lockTest($file));
  }

  public function testInProcessLocking() {
    // Other processes should be unable to lock a file if we hold the lock.

    $file = new TempFile();

    $lock = PhutilFileLock::newForPath($file);
    $lock->lock();

    $this->assertFalse($this->lockTest($file));

    $lock->unlock();

    $this->assertTrue($this->lockTest($file));
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

    $this->assertTrue($caught instanceof PhutilLockException);

    $hold->resolveKill();

    $this->assertTrue($this->lockTest($file));

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

    $this->assertTrue($caught instanceof Exception);
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

    $this->assertTrue($caught instanceof Exception);
  }

  public function testUnlockAll() {
    // unlockAll() should release all locks.

    $file = new TempFile();
    $lock = PhutilFileLock::newForPath($file);

    $lock->lock();

    $this->assertFalse($this->lockTest($file));

    PhutilFileLock::unlockAll();

    $this->assertTrue($this->lockTest($file));

    // Calling this again shouldn't do anything bad.
    PhutilFileLock::unlockAll();

    $this->assertTrue($this->lockTest($file));

    $lock->lock();
    $lock->unlock();
  }

  public function testIsLocked() {
    // isLocked() should report lock status accurately.

    $file = new TempFile();
    $lock = PhutilFileLock::newForPath($file);

    $this->assertFalse($lock->isLocked());

    $lock->lock();

    $this->assertTrue($lock->isLocked());

    $lock->unlock();

    $this->assertFalse($lock->isLocked());
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

    throw new Exception(pht('Unable to hold lock in external process!'));
  }

  private function buildLockFuture($flags, $file) {
    $root = dirname(phutil_get_library_root('phutil'));
    $bin = $root.'/scripts/utils/lock.php';

    // NOTE: Use `exec` so this passes on Ubuntu, where the default `dash` shell
    // will eat any kills we send during the tests.
    $future = new ExecFuture('exec php %s %C %s', $bin, $flags, $file);
    $future->start();
    return $future;
  }

}
