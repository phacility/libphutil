<?php

final class PhutilHTTPResponseParser extends Phobject {

  private $followLocationHeaders;
  private $responses = array();
  private $response;
  private $buffer;
  private $state = 'headers';

  public function setFollowLocationHeaders($follow_location_headers) {
    $this->followLocationHeaders = $follow_location_headers;
    return $this;
  }

  public function getFollowLocationHeaders() {
    return $this->followLocationHeaders;
  }

  public function readBytes($bytes) {
    if ($this->state == 'discard') {
      return $this;
    }

    $this->buffer .= $bytes;

    while (true) {
      if ($this->state == 'headers') {
        $matches = null;

        $ok = preg_match(
          "/(\r?\n\r?\n)/",
          $this->buffer,
          $matches,
          PREG_OFFSET_CAPTURE);
        if (!$ok) {
          break;
        }

        $headers_len = $matches[1][1];
        $boundary_len = strlen($matches[1][0]);
        $raw_headers = substr($this->buffer, 0, $headers_len);
        $this->buffer = substr($this->buffer, $headers_len + $boundary_len);

        $header_lines = phutil_split_lines($raw_headers);
        $first_line = array_shift($header_lines);
        $response_valid = true;

        $matches = null;
        $ok = preg_match(
          '(^HTTP/\S+\s+(\d+)(?:\s+(.*))?$)i',
          $first_line,
          $matches);

        if ($ok) {
          $http_code = (int)$matches[1];
          $http_status = phutil_utf8_strtolower($matches[2]);
        } else {
          $response_valid = false;
        }

        $header_list = array();
        $saw_location = false;
        foreach ($header_lines as $header_line) {
          $pos = strpos($header_line, ':');
          if ($pos === false) {
            $response_valid = false;
            break;
          }

          $name = substr($header_line, 0, $pos);
          $value = ltrim(substr($header_line, $pos + 1), ' ');

          if (phutil_utf8_strtolower($name) == 'location') {
            $saw_location = true;
          }

          $header_list[] = array(
            $name,
            $value,
          );
        }

        // If the response didn't start with a properly formatted "HTTP/..."
        // line, or any of the header lines were not formatted correctly, add
        // a malformed response to the response list and discard anything else
        // we're given.
        if (!$response_valid) {
          $malformed = new HTTPFutureParseResponseStatus(
            HTTPFutureParseResponseStatus::ERROR_MALFORMED_RESPONSE,
            $raw_headers);

          $this->newHTTPRepsonse()
            ->setStatus($malformed);

          $this->buffer = '';
          $this->state = 'discard';
          break;
        }

        // Otherwise, we have a valid set of response headers.
        $response_status = new HTTPFutureHTTPResponseStatus(
          $http_code,
          null,
          $header_list);

        $this->newHTTPResponse()
          ->setStatus($response_status)
          ->setHeaders($header_list);

        $is_https_proxy =
          ($http_code === 200) &&
          ($http_status === 'connection established');

        if ($http_code === 100) {
          // If this is "HTTP/1.1 100 Continue", this is just the server
          // telling us that everything is okay. This response won't have
          // a body associated with it.
          $more_headers = true;
        } else if ($is_https_proxy) {
          // If this is "HTTP/1.1 200 Connection Established", this is a
          // response to a CONNECT request made automatically by cURL to
          // an HTTPS proxy. This response won't have a body associated
          // with it, and the real body will follow later.
          $more_headers = true;
        } else if ($saw_location && $this->followLocationHeaders) {
          // If we're following location headers and this response had
          // a location header, cURL will automatically follow it. This
          // response shouldn't have a body.
          $more_headers = true;
        } else {
          $more_headers = false;
        }

        // If we're expecting more headers, we're going to stay in the
        // "headers" state and parse another set of headers. Otherwise,
        // we transition to the "body" state and look for a body.
        if (!$more_headers) {
          $this->state = 'body';
        }

        continue;
      }

      if ($this->state == 'body') {
        if (strlen($this->buffer)) {
          $this->response->appendBody($this->buffer);
          $this->buffer = '';
        }
        break;
      }
    }

    return $this;
  }

  public function getResponses() {
    if ($this->state !== 'body') {
      throw new HTTPFutureParseResponseStatus(
        HTTPFutureParseResponseStatus::ERROR_MALFORMED_RESPONSE,
        $this->buffer);
    }

    return $this->responses;
  }

  private function newHTTPResponse() {
    $response = new PhutilHTTPResponse();
    $this->responses[] = $response;
    $this->response = $response;
    return $response;
  }

}
