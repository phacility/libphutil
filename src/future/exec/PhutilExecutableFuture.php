<?php

/**
 * @task config Configuring the Command
 */
abstract class PhutilExecutableFuture extends Future {


  private $env;
  private $cwd;


  /**
   * Set environmental variables for the command.
   *
   * By default, variables are added to the environment of this process. You
   * can optionally wipe the environment and pass only the specified values.
   *
   *   // Env will have "X" and current env ("PATH", etc.)
   *   $exec->setEnv(array('X' => 'y'));
   *
   *   // Env will have ONLY "X".
   *   $exec->setEnv(array('X' => 'y'), $wipe_process_env = true);
   *
   * @param map<string, string> Dictionary of environmental variables.
   * @param bool Optionally, pass `true` to replace the existing environment.
   * @return this
   *
   * @task config
   */
  final public function setEnv(array $env, $wipe_process_env = false) {
    // Force values to strings here. The underlying PHP commands get upset if
    // they are handed non-string values as environmental variables.
    foreach ($env as $key => $value) {
      $env[$key] = (string)$value;
    }

    if (!$wipe_process_env) {
      $env = $env + $this->getEnv();
    }

    $this->env = $env;

    return $this;
  }


  /**
   * Set the value of a specific environmental variable for this command.
   *
   * @param string Environmental variable name.
   * @param string|null New value, or null to remove this variable.
   * @return this
   * @task config
   */
  final public function updateEnv($key, $value) {
    $env = $this->getEnv();

    if ($value === null) {
      unset($env[$key]);
    } else {
      $env[$key] = (string)$value;
    }

    $this->env = $env;

    return $this;
  }


  /**
   * Returns `true` if this command has a configured environment.
   *
   * @return bool True if this command has an environment.
   * @task config
   */
  final public function hasEnv() {
    return ($this->env !== null);
  }


  /**
   * Get the configured environment.
   *
   * @return map<string, string> Effective environment for this command.
   * @task config
   */
  final public function getEnv() {
    if (!$this->hasEnv()) {
      $default_env = $_ENV;

      // If `variables_order` does not include "E", the $_ENV superglobal
      // does not build and there's no apparent reasonable way for us to
      // rebuild it (we could perhaps parse the output of `export`).

      // For now, explicitly populate variables which we rely on and which
      // we know may exist. After T12071, we should be able to rely on
      // $_ENV and no longer need to do this.

      $known_keys = array(
        'PHABRICATOR_ENV',
        'PHABRICATOR_INSTANCE',
      );

      foreach ($known_keys as $known_key) {
        $value = getenv($known_key);
        if (strlen($value)) {
          $default_env[$known_key] = $value;
        }
      }

      $this->setEnv($default_env, $wipe_process_env = true);
    }

    return $this->env;
  }


  /**
   * Set the current working directory for the subprocess (that is, set where
   * the subprocess will execute). If not set, the default value is the parent's
   * current working directory.
   *
   * @param string Directory to execute the subprocess in.
   * @return this
   * @task config
   */
  final public function setCWD($cwd) {
    $cwd = phutil_string_cast($cwd);

    try {
      Filesystem::assertExists($cwd);
    } catch (FilesystemException $ex) {
      throw new PhutilProxyException(
        pht(
          'Unable to run a command in directory "%s".',
          $cwd),
        $ex);
    }

    if (!is_dir($cwd)) {
      throw new Exception(
        pht(
          'Preparing to run a command in directory "%s", but that path is '.
          'not a directory.',
          $cwd));
    }

    // Although you don't technically need read permission to "chdir()" into
    // a directory, it is almost certainly a mistake to execute a subprocess
    // in a CWD we can't read. Refuse to do this. If callers have some
    // exceptionally clever scheme up their sleeves they can always have the
    // subprocess "cd" or "chdir()" explicitly.

    if (!is_readable($cwd)) {
      throw new Exception(
        pht(
          'Preparing to run a command in directory "%s", but that directory '.
          'is not readable (the current process does not have "+r" '.
          'permission).',
          $cwd));
    }


    if (phutil_is_windows()) {
      // Do nothing. On Windows, calling "is_executable(...)" on a directory
      // always appears to return "false". Skip this check under Windows.
    } else if (!is_executable($cwd)) {
      throw new Exception(
        pht(
          'Preparing to run a command in directory "%s", but that directory '.
          'is not executable (the current process does not have "+x" '.
          'permission).',
          $cwd));
    }

    $this->cwd = $cwd;

    return $this;
  }


  /**
   * Get the command's current working directory.
   *
   * @return string Working directory.
   * @task config
   */
  final public function getCWD() {
    return $this->cwd;
  }

}
