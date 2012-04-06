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
 * @group library
 */
final class PhutilMissingSymbolException extends Exception {
  public function __construct($symbol) {
    parent::__construct(
      "Failed to load symbol '{$symbol}'. ".
      "If this symbol was recently added or moved, your library map may ".
      "be out of date. You can rebuild the map by running 'arc liberate'. ".
      "For more information, see: ".
      "http://www.phabricator.com/docs/phabricator/article/".
      "libphutil_Libraries_User_Guide.html");
  }
}
