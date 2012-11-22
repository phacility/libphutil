<?php

/**
 * Execute a command and capture stdout and stderr. If the command exits with
 * a nonzero error code, a @{class:CommandException} will be thrown. If you need
 * to manually handle error conditions, use @{function:exec_manual}.
 *
 *   list ($stdout, $stderr) = execx('ls %s', $file);
 *
 * @param  string  sprintf()-style command pattern to execute.
 * @param  ...     Arguments to sprintf pattern.
 * @return array   List of stdout and stderr.
 * @group exec
 */
function execx($cmd /* , ... */) {
  $args = func_get_args();
  $future = newv('ExecFuture', $args);
  return $future->resolvex();
}


/**
 * Execute a command and capture stdout, stderr, and the return value.
 *
 *   list ($err, $stdout, $stderr) = exec_manual('ls %s', $file);
 *
 * When invoking this function, you must manually handle the error
 * condition. Error flows can often be simplified by using @{function:execx}
 * instead, which throws an exception when it encounters an error.
 *
 * @param  string  sprintf()-style command pattern to execute.
 * @param  ...     Arguments to sprintf pattern.
 * @return array   List of return code, stdout, and stderr.
 * @group exec
 */
function exec_manual($cmd /* , ... */) {
  $args = func_get_args();
  $ef = newv('ExecFuture', $args);
  return $ef->resolve();
}


/**
 * Execute a command which takes over stdin, stdout and stderr, similar to
 * passthru(), but which preserves TTY semantics, escapes arguments, and is
 * traceable.
 *
 * @param  string  sprintf()-style command pattern to execute.
 * @param  ...     Arguments to sprintf pattern.
 * @return int     Return code.
 * @group exec
 */
function phutil_passthru($cmd /* , ... */) {
  $args = func_get_args();
  $command = call_user_func_array('csprintf', $args);

  $profiler = PhutilServiceProfiler::getInstance();
  $call_id = $profiler->beginServiceCall(
    array(
      'type'    => 'exec',
      'subtype' => 'passthru',
      'command' => $command,
    ));

  $spec  = array(STDIN, STDOUT, STDERR);
  $pipes = array();

  if (phutil_is_windows()) {
    // Without 'bypass_shell', things like launching vim don't work properly,
    // and we can't execute commands with spaces in them, and all commands
    // invoked from git bash fail horridly, and everything is a mess in general.
    $options = array(
      'bypass_shell' => true,
    );
    $proc = @proc_open($command, $spec, $pipes, null, null, $options);
  } else {
    $proc = @proc_open($command, $spec, $pipes);
  }

  if ($proc === false) {
    $err = 1;
  } else {
    $err = proc_close($proc);
  }

  $profiler->endServiceCall(
    $call_id,
    array(
      'err' => $err,
    ));

  return $err;
}
