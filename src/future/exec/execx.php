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

  if ($command instanceof PhutilCommandString) {
    $unmasked_command = $command->getUnmaskedString();
  } else {
    $unmasked_command = $command;
  }

  if (phutil_is_windows()) {
    // Without 'bypass_shell', things like launching vim don't work properly,
    // and we can't execute commands with spaces in them, and all commands
    // invoked from git bash fail horridly, and everything is a mess in general.
    $options = array(
      'bypass_shell' => true,
    );
    $proc = @proc_open($unmasked_command, $spec, $pipes, null, null, $options);
  } else {
    $proc = @proc_open($unmasked_command, $spec, $pipes);
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


/**
 * Return a human-readable signal name (like "SIGINT" or "SIGKILL") for a given
 * signal number.
 *
 * @param   int     Signal number.
 * @return  string  Human-readable signal name.
 */
function phutil_get_signal_name($signo) {

  // These aren't always defined; try our best to look up the signal name.
  $constant_names = array(
    'SIGHUP',
    'SIGINT',
    'SIGQUIT',
    'SIGILL',
    'SIGTRAP',
    'SIGABRT',
    'SIGIOT',
    'SIGBUS',
    'SIGFPE',
    'SIGUSR1',
    'SIGSEGV',
    'SIGUSR2',
    'SIGPIPE',
    'SIGALRM',
    'SIGTERM',
    'SIGSTKFLT',
    'SIGCLD',
    'SIGCHLD',
    'SIGCONT',
    'SIGTSTP',
    'SIGTTIN',
    'SIGTTOU',
    'SIGURG',
    'SIGXCPU',
    'SIGXFSZ',
    'SIGVTALRM',
    'SIGPROF',
    'SIGWINCH',
    'SIGPOLL',
    'SIGIO',
    'SIGPWR',
    'SIGSYS',
    'SIGBABY',
  );

  $signal_names = array();
  foreach ($constant_names as $constant) {
    if (defined($constant)) {
      $signal_names[constant($constant)] = $constant;
    }
  }

  return idx($signal_names, $signo);
}
