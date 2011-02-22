#!/usr/bin/env php
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

// This script just creates a process which is difficult to terminate. It is
// used for daemon resiliance tests.

declare(ticks = 1);
pcntl_signal(SIGTERM, 'ignore');
pcntl_signal(SIGINT,  'ignore');

function ignore($signo) {
  return;
}

echo "Resisting death; sleeping forever...\n";

while (true) {
  sleep(60);
}
