<?php

/**
 * Simple event store for service calls, so they can be printed to stdout or
 * displayed in a debug console.
 */
final class PhutilServiceProfiler {

  private static $instance;
  private $listeners = array();
  private $events = array();
  private $logSize = 0;
  private $discardMode = false;

  private function __construct() {}

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
        $mark = '>>>';
        break;
      case 'end':
        $is_end = true;
        $mark = '<<<';
        break;
      default:
        $mark = null;
        break;
    }

    $type = idx($data, 'type', 'mystery');

    $desc = null;
    if ($is_begin) {
      switch ($type) {
        case 'connect':
          $desc = $data['database'];
          break;
        case 'query':
          $desc = substr($data['query'], 0, 512);
          break;
        case 'multi-query':
          $desc = array();
          foreach ($data['queries'] as $query) {
            $desc[] = substr($query, 0, 256);
          }
          $desc = implode('; ', $desc);
          break;
        case 'exec':
          $desc = '$ '.$data['command'];
          break;
        case 'conduit':
          if (isset($data['size'])) {
            $desc = $data['method'].'() <bytes = '.$data['size'].'>';
          } else {
            $desc = $data['method'].'()';
          }
          break;
        case 'http':
          $desc = phutil_censor_credentials($data['uri']);
          break;
        case 'lint':
          $desc = $data['linter'];
          if (isset($data['paths'])) {
            $desc .= ' <paths = '.count($data['paths']).'>';
          }
          break;
        case 'lock':
          $desc = $data['name'];
          break;
        case 'event':
          $desc = $data['kind'].' <listeners = '.$data['count'].'>';
          break;
        case 'ldap':
          $call = idx($data, 'call', '?');
          $params = array();
          switch ($call) {
            case 'connect':
              $params[] = $data['host'].':'.$data['port'];
              break;
            case 'start-tls':
              break;
            case 'bind':
              $params[] = $data['user'];
              break;
            case 'search':
              $params[] = $data['dn'];
              $params[] = $data['query'];
              break;
            default:
              $params[] = '?';
              break;
          }
          $desc = "{$call} (".implode(', ', $params).")";
          break;
      }
    } else if ($is_end) {
      $desc = number_format((int)(1000000 * $data['duration'])).' us';
    }

    $console = PhutilConsole::getConsole();
    $console->writeLog(
      "%s [%s] <%s> %s\n",
      $mark,
      $id,
      $type,
      $desc);
  }

}
