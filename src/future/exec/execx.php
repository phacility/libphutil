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
 * Execute a command and capture stdout and stderr. If the command exits with
 * a nonzero error code, a CommandException will be thrown. If you need to
 * manually handle error conditions, use exec_manual().
 *
 *   list ($stdout, $stderr) = execx('ls %s', $file);
 *
 * @param  string  sprintf()-style command pattern to execute.
 * @param  ...     Arguments to sprintf pattern.
 * @return array   List of stdout and stderr.
 */
function execx($cmd /*, ... */) {
  $args = func_get_args();
  $future = newv('ExecFuture', $args);
  return $future->resolvex();
}


/**
 * Execute a command and capture stdout, stderr, and the return value.
 *
 *   list ($err, $stdout, $stderr) = exec_manual('ls %s', $file);
 *
 * When invoking this function, you MUST **manually** handle the error
 * condition. Error flows can often be simplified by using execx() instead,
 * which throws an exception when it encounters an error.
 *
 * @param  string  sprintf()-style command pattern to execute.
 * @param  ...     Arguments to sprintf pattern.
 * @return array   List of return code, stdout, and stderr.
 */
function exec_manual($cmd /*, ... */) {
  $args = func_get_args();

  if (ExecFuture::peekEchoMode()) {
    ExecFuture::pushEchoMode(false);

    echo "  >>> \$ {$cmd} ... ";
    $t_start = microtime(true);

      $ef = newv('ExecFuture', $args);
      $result = $ef->resolve();

    $t_end = microtime(true);
    $duration = number_format((int)(1000 * ($t_end - $t_start))).' ms';
    echo " {$duration}\n";

    ExecFuture::popEchoMode();
  } else {
    $ef = newv('ExecFuture', $args);
    $result = $ef->resolve();
  }

  return $result;
}
