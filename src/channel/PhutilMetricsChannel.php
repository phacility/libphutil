<?php

/**
 * A @{class:PhutilChannelChannel} which wraps some other channel and provides
 * metrics about its use (e.g., bytes read and bytes written).
 *
 * @task metrics  Channel Metrics
 * @task impl     Implementation
 */
final class PhutilMetricsChannel extends PhutilChannelChannel {

  private $bytesRead = 0;
  private $bytesWritten = 0;
  private $startTime;


/* -(  Channel Metrics  )---------------------------------------------------- */


  /**
   * Get the number of bytes that have been written to the channel. This
   * includes any bytes which have been buffered but not actually transmitted,
   * and thus may overreport compared to actual activity on the wire.
   *
   * @return int  Bytes written.
   * @task metrics
   */
  public function getBytesWritten() {
    return $this->bytesWritten;
  }

  /**
   * Get the number of bytes that have been read from the channel. This excludes
   * any bytes which have been received but not actually read by anything, and
   * thus may underreport compared to actual activity on the wire.
   *
   * @return int  Bytes read.
   * @task metrics
   */
  public function getBytesRead() {
    return $this->bytesRead;
  }


  /**
   * Get the elapsed wall time since this channel opened.
   *
   * @return float  Wall time, in seconds.
   * @task metrics
   */
  public function getWallTime() {
    return microtime(true) - $this->startTime;
  }


/* -(  Implementation  )----------------------------------------------------- */


  /**
   * @task impl
   */
  protected function didConstruct() {
    $this->startTime = microtime(true);
  }


  /**
   * @task impl
   */
  public function read() {
    $buffer = parent::read();
    $this->bytesRead += strlen($buffer);
    return $buffer;
  }


  /**
   * @task impl
   */
  public function write($message) {
    $this->bytesWritten += strlen($message);
    return parent::write($message);
  }

}
