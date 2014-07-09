<?php

/**
 * Execute a command which takes over stdin, stdout and stderr, similar to
 * `passthru()`, but which preserves TTY semantics, escapes arguments, and is
 * traceable.
 *
 * Passthru commands use the `STDIN`, `STDOUT` and `STDERR` of the parent
 * process, so input can be read from the console and output is printed to it.
 * This is primarily useful for executing things like `$EDITOR` from command
 * line scripts.
 *
 *   $exec = new PhutilExecPassthru('ls %s', $dir);
 *   $err = $exec->execute();
 *
 * You can set the current working directory for the command with
 * @{method:setCWD}, and set the environment with @{method:setEnv}.
 *
 * @task command  Executing Passthru Commands
 * @task config   Configuring Passthru Commands
 */
final class PhutilExecPassthru extends Phobject {

  private $command;
  private $env;
  private $cwd;


/* -(  Executing Passthru Commands  )---------------------------------------- */


  /**
   * Build a new passthru command.
   *
   *   $exec = new PhutilExecPassthru('ls %s', $dir);
   *
   * @param string Command pattern. See @{function:csprintf}.
   * @param ...    Pattern arguments.
   *
   * @task command
   */
  public function __construct($pattern /* , ... */) {
    $args = func_get_args();
    $this->command = call_user_func_array('csprintf', $args);
  }


  /**
   * Execute this command.
   *
   * @return int  Error code returned by the subprocess.
   *
   * @task command
   */
  public function execute() {
    $command = $this->command;

    $profiler = PhutilServiceProfiler::getInstance();
    $call_id = $profiler->beginServiceCall(
      array(
        'type'    => 'exec',
        'subtype' => 'passthru',
        'command' => $command,
      ));

    $spec  = array(STDIN, STDOUT, STDERR);
    $pipes = array();

    if ($command instanceof PhutilCommandString) {
      $unmasked_command = $command->getUnmaskedString();
    } else {
      $unmasked_command = $command;
    }

    $env = $this->env;
    $cwd = $this->cwd;

    $options = array();
    if (phutil_is_windows()) {
      // Without 'bypass_shell', things like launching vim don't work properly,
      // and we can't execute commands with spaces in them, and all commands
      // invoked from git bash fail horridly, and everything is a mess in
      // general.
      $options['bypass_shell'] = true;
    }

    $trap = new PhutilErrorTrap();
      $proc = @proc_open(
        $unmasked_command,
        $spec,
        $pipes,
        $cwd,
        $env,
        $options);
      $errors = $trap->getErrorsAsString();
    $trap->destroy();

    if (!is_resource($proc)) {
      throw new Exception("Failed to passthru proc_open(): {$errors}");
    }

    $err = proc_close($proc);

    $profiler->endServiceCall(
      $call_id,
      array(
        'err' => $err,
      ));

    return $err;
  }


/* -(  Configuring Passthru Commands  )-------------------------------------- */


  /**
   * Set environmental variables for the subprocess.
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
   * @param dict  Dictionary of environmental variables.
   * @param bool  Optionally, pass true to wipe the existing environment clean.
   * @return this
   *
   * @task config
   */
  public function setEnv(array $env, $wipe_process_env = false) {
    if ($wipe_process_env) {
      $this->env = $env;
    } else {
      $this->env = $env + $_ENV;
    }
    return $this->env;
  }


  /**
   * Set the current working directory for the subprocess (that is, set where
   * the subprocess will execute). If not set, the default value is the parent's
   * current working directory.
   *
   * @param string  Directory to execute the subprocess in.
   * @return this
   *
   * @task config
   */
  public function setCWD($cwd) {
    $this->cwd = $cwd;
    return $this;
  }

}
