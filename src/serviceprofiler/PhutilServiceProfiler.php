<?php

/**
 * Simple event store for service calls, so they can be printed to stdout or
 * displayed in a debug console.
 */
final class PhutilServiceProfiler extends Phobject {

  private static $instance;

  private $listeners = array();
  private $events = array();
  private $logSize = 0;

  private $discardMode = false;
  private $collectStackTraces;
  private $zeroTime;

  private function __construct() {}

  public function enableDiscardMode() {
    $this->discardMode = true;
  }

  public function setCollectStackTraces($collect_stack_traces) {
    $this->collectStackTraces = $collect_stack_traces;
    return $this;
  }

  public function getCollectStackTraces() {
    return $this->collectStackTraces;
  }

  public static function getInstance() {
    if (empty(self::$instance)) {
      self::$instance = new PhutilServiceProfiler();
    }
    return self::$instance;
  }

  public function beginServiceCall(array $data) {
    $data['begin'] = microtime(true);

    if ($this->collectStackTraces) {
      $trace = debug_backtrace();
      $trace = PhutilErrorHandler::formatStacktrace($trace);
      $data['trace'] = $trace;
    }

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
    $instance = self::getInstance();
    $instance->addListener(array(__CLASS__, 'echoListener'));
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
            $desc  = $data['method'].'() ';
            $desc .= pht('<bytes = %s>', new PhutilNumber($data['size']));
          } else {
            $desc = $data['method'].'()';
          }
          break;
        case 'http':
          if (isset($data['proxy'])) {
            $proxy = phutil_censor_credentials($data['proxy']);
          } else {
            $proxy = null;
          }

          $uri = phutil_censor_credentials($data['uri']);

          if (strlen($proxy)) {
            $desc = "{$proxy} >> {$uri}";
          } else {
            $desc = $uri;
          }

          break;
        case 'lint':
          $desc = $data['linter'];
          if (isset($data['paths'])) {
            $desc .= ' '.pht('<paths = %s>', phutil_count($data['paths']));
          }
          break;
        case 'lock':
          $desc = $data['name'];
          break;
        case 'event':
          $desc  = $data['kind'].' ';
          $desc .= pht('<listeners = %s>', new PhutilNumber($data['count']));
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
      $desc = pht(
        '%s us',
        new PhutilNumber((int)(1000000 * $data['duration'])));
    }

    $instance = self::getInstance();
    if (!$instance->zeroTime) {
      $instance->zeroTime = microtime(true);
    }
    $elapsed = microtime(true) - $instance->zeroTime;

    $console = PhutilConsole::getConsole();
    $console->writeLog(
      "%s [%s] (+%s) <%s> %s\n",
      $mark,
      $id,
      pht('%s', new PhutilNumber((int)(1000 * $elapsed))),
      $type,
      self::escapeProfilerStringForDisplay($desc));
  }

  private static function escapeProfilerStringForDisplay($string) {
    // Convert tabs and newlines to spaces and collapse blocks of whitespace,
    // most often formatting in queries.
    $string = preg_replace('/\s{2,}/', ' ', $string);

    // Replace sequences of binary characters with printable text. We allow
    // some printable characters to appear in between unprintable characters
    // to try to collapse the entire run.
    $string = preg_replace(
      '/[\x00-\x1F\x7F-\xFF](.{0,12}[\x00-\x1F\x7F-\xFF])*/',
      '<...binary data...>',
      $string);

    return $string;
  }


}
