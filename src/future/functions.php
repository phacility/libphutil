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
 * Convenience function for instantiating a new @{class:FutureIterator}.
 *
 * @param list              List of @{class:Future}s.
 * @return FutureIterator   New @{class:FutureIterator} over those futures.
 * @group futures
 */
function Futures($futures) {
  return new FutureIterator($futures);
}
