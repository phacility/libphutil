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
 * Simple event store for service calls, so they can be printed to stdout or
 * displayed in a debug console.
 *
 * @group util
 */
final class PhutilServiceProfiler {

  private static $instance;
  private $listeners = array();
  private $events = array();
  private $logSize = 0;
  private $discardMode = false;

  private function __construct() {
  }

  public function enableDiscardMode() {
    $this->discardMode = true;
  }

  public static function getInstance() {
    if (empty(self::$instance)) {
      self::$instance = new PhutilServiceProfiler();
    }
    return self::$instance;
  }

  public function beginServiceCall(array $data) {
    $data['begin'] = microtime(true);
    $id = $this->logSize++;
    $this->events[$id] = $data;
    foreach ($this->listeners as $listener) {
      call_user_func($listener, 'begin', $id, $data);
    }
    return $id;
  }

  public function endServiceCall($call_id, array $data) {
    $data = ($this->events[$call_id] + $data);
    $data['end'] = microtime(true);
    $data['duration'] = ($data['end'] - $data['begin']);
    $this->events[$call_id] = $data;
    foreach ($this->listeners as $listener) {
      call_user_func($listener, 'end', $call_id, $data);
    }
    if ($this->discardMode) {
      unset($this->events[$call_id]);
    }
  }

  public function getServiceCallLog() {
    return $this->events;
  }

  public function addListener($callback) {
    $this->listeners[] = $callback;
  }

  public static function installEchoListener() {
    $instance = PhutilServiceProfiler::getInstance();
    $instance->addListener(array('PhutilServiceProfiler', 'echoListener'));
  }

  public static function echoListener($type, $id, $data) {
    $is_begin = false;
    $is_end   = false;
    switch ($type) {
      case 'begin':
        $is_begin = true;
        echo '>>> ';
        break;
      case 'end':
        $is_end = true;
        echo '<<< ';
        break;
      default:
        echo '??? ';
        break;
    }
    echo '['.$id.'] ';

    $type = idx($data, 'type', 'mystery');
    echo '<'.$type.'> ';

    if ($is_begin) {
      switch ($type) {
        case 'query':
          echo substr($data['query'], 0, 512);
          break;
        case 'exec':
          echo '$ '.$data['command'];
          break;
        case 'conduit':
          echo $data['method'].'()';
          break;
      }
    }

    if ($is_end) {
      echo number_format((int)(1000000 * $data['duration'])).' us';
    }

    echo "\n";
  }

}
