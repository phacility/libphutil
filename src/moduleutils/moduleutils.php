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

function phutil_get_library_root($library) {
  return __phutil_library_registry('find', $library);
}


function phutil_get_library_root_for_path($path) {
  foreach (Filesystem::walkToRoot($path) as $dir) {
    if (@file_exists($dir.'/__phutil_library_init__.php')) {
      return $dir;
    }
  }
  return null;
}

function phutil_get_library_name_for_root($path) {
  $loaded = false;
  while (true) {
    $libs = __phutil_library_registry('list');
    $path = rtrim(Filesystem::resolvePath($path), '/');
    foreach ($libs as $lib => $root) {
      if (rtrim(Filesystem::resolvePath($root), '/') == $path) {
        return $lib;
      }
    }
    if ($loaded) {
      return null;
    } else {
      phutil_load_library($path);
    }
  } while (true);
}
