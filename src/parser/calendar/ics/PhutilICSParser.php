<?php

final class PhutilICSParser extends Phobject {

  private $stack;
  private $node;
  private $document;

  public function parseICSData($data) {
    $this->stack = array();
    $this->node = null;
    $this->document = null;

    $lines = $this->unfoldICSLines($data);

    foreach ($lines as $line) {
      $matches = null;
      if (preg_match('(^BEGIN:(.*)\z)', $line, $matches)) {
        $this->beginParsingNode($matches[1]);
      } else if (preg_match('(^END:(.*)\z)', $line, $matches)) {
        $this->endParsingNode($matches[1]);
      } else {
        $this->parseICSProperty($line);
      }
    }

    if (!$this->document) {
      $this->raiseParseFailure(
        pht(
          'Expected ICS document to define a "VCALENDAR" section.'));
    }

    if ($this->stack) {
      $this->raiseParseFailure(
        pht(
          'Expected all "BEGIN:" sections in ICS document to have '.
          'corresponding "END:" sections.'));
    }

    $document = $this->document;
    $this->document = null;

    return $document;
  }

  private function getNode() {
    return $this->node;
  }

  private function unfoldICSLines($data) {
    $lines = phutil_split_lines($data, $retain_endings = false);

    // ICS files are wrapped at 75 characters, with overlong lines continued
    // on the following line with an initial space or tab. Unwrap all of the
    // lines in the file.
    $last = null;
    foreach ($lines as $idx => $line) {
      if (!preg_match('/^[ \t]/', $line)) {
        $last = $idx;
        continue;
      }

      if ($last === null) {
        throw new Exception(
          pht(
            'First line of ICS file begins with a space or tab, but this '.
            'marks a continuation line.'));
      }

      $lines[$last] = $lines[$last].substr($line, 1);
      unset($lines[$idx]);
    }

    return $lines;
  }

  private function beginParsingNode($type) {
    $node = $this->getNode();
    $new_node = $this->newICSNode($type);

    if ($node) {
      if ($node instanceof PhutilCalendarContainerNode) {
        $node->appendChild($new_node);
      } else {
        $this->raiseParseFailure(
          pht(
            'Found unexpected node "%s" inside node "%s".',
            $new_node->getAttribute('ics.type'),
            $node->getAttribute('ics.type')));
      }
    } else {
      if ($new_node instanceof PhutilCalendarDocumentNode) {
        if ($this->document) {
          $this->raiseParseFailure(
            pht(
              'Found multiple "VCALENDAR" nodes in ICS document, '.
              'expected only one.'));
        } else {
          $this->document = $new_node;
        }
      } else {
        $this->raiseParseFailure(
          pht(
            'Expected ICS document to begin "BEGIN:VCALENDAR".'));
      }
    }

    $this->stack[] = $new_node;
    $this->node = $new_node;

    return $this;
  }

  private function newICSNode($type) {
    switch ($type) {
      case 'VCALENDAR':
        $node = new PhutilCalendarDocumentNode();
        break;
      case 'VEVENT':
        $node = new PhutilCalendarEventNode();
        break;
      default:
        $node = new PhutilCalendarRawNode();
        break;
    }

    $node->setAttribute('ics.type', $type);

    return $node;
  }

  private function endParsingNode($type) {
    $node = $this->getNode();
    if (!$node) {
      $this->raiseParseFailure(
        pht(
          'Found unexpected "END" without a "BEGIN".'));
    }

    $old_type = $node->getAttribute('ics.type');
    if ($old_type != $type) {
      $this->raiseParseFailure(
        pht(
          'Found mismatched "BEGIN" ("%s") and "END" ("%s") sections.',
          $old_type,
          $type));
    }

    array_pop($this->stack);
    if ($this->stack) {
      $this->node = last($this->stack);
    } else {
      $this->node = null;
    }

    return $this;
  }

  private function parseICSProperty($line) {
    $matches = null;

    // Properties begin with an alphanumeric name with no escaping, followed
    // by either a ";" (to begin a list of parameters) or a ":" (to begin
    // the actual field body).

    $ok = preg_match('(^([^;:]+)([;:])(.*)\z)', $line, $matches);
    if (!$ok) {
      $this->raiseParseFailure(
        pht(
          'Found malformed line in ICS document: %s',
          $line));
    }

    $name = $matches[1];
    $body = $matches[3];
    $has_parameters = ($matches[2] == ';');

    $parameters = array();
    if ($has_parameters) {
      // Parameters are a sensible name, a literal "=", a pile of magic,
      // and then maybe a comma and another parameter.

      while (true) {
        // We're going to get the first couple of parts first.
        $ok = preg_match('(^([^=]+)=)', $body, $matches);
        if (!$ok) {
          $this->raiseParseFailure(
            pht(
              'Found malformed property in ICS document: %s',
              $body));
        }

        $param_name = $matches[1];
        $body = substr($body, strlen($matches[0]));

        // Now we're going to match zero or more values.
        $param_values = array();
        while (true) {
          // The value can either be a double-quoted string or an unquoted
          // string, with some characters forbidden.
          if (strlen($body) && $body[0] == '"') {
            $is_quoted = true;
            $ok = preg_match(
              '(^"([^\x00-\x08\x10-\x19"]*)")',
              $body,
              $matches);
            if (!$ok) {
              $this->raiseParseFailure(
                pht(
                  'Found malformed double-quoted string in ICS document '.
                  'parameter value: %s',
                  $body));
            }
          } else {
            $is_quoted = false;
            $ok = preg_match(
              '(^([^\x00-\x08\x10-\x19";:,]*))',
              $body,
              $matches);
            if (!$ok) {
              $this->raiseParseFailure(
                pht(
                  'Found malformed unquoted string in ICS document '.
                  'parameter value: %s',
                  $body));
            }
          }

          // NOTE: RFC5545 says "Property parameter values that are not in
          // quoted-strings are case-insensitive." -- that is, the quoted and
          // unquoted representations are not equivalent. Thus, preserve the
          // original formatting in case we ever need to respect this.

          $param_values[] = array(
            'value' => $this->unescapeParameterValue($matches[1]),
            'quoted' => $is_quoted,
          );

          $body = substr($body, strlen($matches[0]));
          if (!strlen($body)) {
            $this->raiseParseFailure(
              pht(
                'Expected ":" after parameters in ICS document property.'));
          }

          // If we have a comma now, we're going to read another value. Strip
          // it off and keep going.
          if ($body[0] == ',') {
            $body = substr($body, 1);
            continue;
          }

          // If we have a colon, this is the last value and also the last
          // property. Break, then handle the colon below.
          if ($body[0] == ':') {
            break;
          }

          // We aren't expecting anything else.
          $this->raiseParseFailure(
            pht(
              'Found unexpected text after reading parameter value: %s',
              $body));
        }

        $parameters[] = array(
          'name' => $param_name,
          'values' => $param_values,
        );

        if ($body[0] == ':') {
          $body = substr($body, 1);
          break;
        }
      }
    }

    $value = $this->unescapeFieldValue($name, $parameters, $body);

    $node = $this->getNode();
    $raw = $node->getAttribute('ics.properties', array());
    $raw[] = array(
      'name' => $name,
      'parameters' => $parameters,
      'value' => $value,
    );
    $node->setAttribute('ics.properties', $raw);
  }

  private function unescapeParameterValue($data) {
    // The parameter grammar is adjusted by RFC6868 to permit escaping with
    // carets. Remove that escaping.

    // This escaping is a bit weird because it's trying to be backwards
    // compatible and the original spec didn't think about this and didn't
    // provide much room to fix things.

    $out = '';
    $esc = false;
    foreach (phutil_utf8v($data) as $c) {
      if (!$esc) {
        if ($c != '^') {
          $out .= $c;
        } else {
          $esc = true;
        }
      } else {
        switch ($c) {
          case 'n':
            $out .= "\n";
            break;
          case '^':
            $out .= '^';
            break;
          case "'":
            // NOTE: This is "<caret> <single quote>" being decoded into a
            // double quote!
            $out .= '"';
            break;
          default:
            // NOTE: The caret is NOT an escape for any other characters.
            // This is a "MUST" requirement of RFC6868.
            $out .= '^'.$c;
            break;
          }
      }
    }

    // NOTE: Because caret on its own just means "caret" for backward
    // compatibility, we don't warn if we're still in escaped mode once we
    // reach the end of the string.

    return $out;
  }

  private function unescapeFieldValue($name, array $parameters, $data) {
    // NOTE: The encoding of the field value data is dependent on the field
    // name (which defines a default encoding) and the parameters (which may
    // include "VALUE", specifying a type of the data.

    $default_types = array(
      'CALSCALE' => 'TEXT',
      'METHOD' => 'TEXT',
      'PRODID' => 'TEXT',
      'VERSION' => 'TEXT',

      'ATTACH' => 'URI',
      'CATEGORIES' => 'TEXT',
      'CLASS' => 'TEXT',
      'COMMENT' => 'TEXT',
      'DESCRIPTION' => 'TEXT',

      // TODO: The spec appears to contradict itself: it says that the value
      // type is FLOAT, but it also says that this property value is actually
      // two semicolon-separated values, which is not what FLOAT is defined as.
      'GEO' => 'TEXT',

      'LOCATION' => 'TEXT',
      'PERCENT-COMPLETE' => 'INTEGER',
      'PRIORITY' => 'INTEGER',
      'RESOURCES' => 'TEXT',
      'STATUS' => 'TEXT',
      'SUMMARY' => 'TEXT',

      'COMPLETED' => 'DATE-TIME',
      'DTEND' => 'DATE-TIME',
      'DUE' => 'DATE-TIME',
      'DTSTART' => 'DATE-TIME',
      'DURATION' => 'DURATION',
      'FREEBUSY' => 'PERIOD',
      'TRANSP' => 'TEXT',

      'TZID' => 'TEXT',
      'TZNAME' => 'TEXT',
      'TZOFFSETFROM' => 'UTC-OFFSET',
      'TZOFFSETTO' => 'UTC-OFFSET',
      'TZURL' => 'URI',

      'ATTENDEE' => 'CAL-ADDRESS',
      'CONTACT' => 'TEXT',
      'ORGANIZER' => 'CAL-ADDRESS',
      'RECURRENCE-ID' => 'DATE-TIME',
      'RELATED-TO' => 'TEXT',
      'URL' => 'URI',
      'UID' => 'TEXT',
      'EXDATE' => 'DATE-TIME',
      'RDATE' => 'DATE-TIME',
      'RRULE' => 'RECUR',

      'ACTION' => 'TEXT',
      'REPEAT' => 'INTEGER',
      'TRIGGER' => 'DURATION',

      'CREATED' => 'DATE-TIME',
      'DTSTAMP' => 'DATE-TIME',
      'LAST-MODIFIED' => 'DATE-TIME',
      'SEQUENCE' => 'INTEGER',

      'REQUEST-STATUS' => 'TEXT',
    );

    $value_type = idx($default_types, $name, 'TEXT');

    foreach ($parameters as $parameter) {
      if ($parameter['name'] == 'VALUE') {
        $value_type = idx(head($parameter['values']), 'value');
      }
    }

    switch ($value_type) {
      case 'BINARY':
        $result = base64_decode($data);
        if ($result === false) {
          $this->raiseParseFailure(
            pht(
              'Unable to decode base64 data: %s',
              $data));
        }
        break;
      case 'BOOLEAN':
        $map = array(
          'true' => true,
          'false' => false,
        );
        $result = phutil_utf8_strtolower($data);
        if (!isset($map[$result])) {
          $this->raiseParseFailure(
            pht(
              'Unexpected BOOLEAN value "%s".',
              $data));
        }
        $result = $map[$result];
        break;
      case 'CAL-ADDRESS':
        $result = $data;
        break;
      case 'DATE':
        // This is a comma-separated list of "YYYYMMDD" values.
        $result = explode(',', $data);
        break;
      case 'DATE-TIME':
        $result = explode(',', $data);
        break;
      case 'DURATION':
        $result = explode(',', $data);
        break;
      case 'FLOAT':
        $result = explode(',', $data);
        foreach ($result as $k => $v) {
          $result[$k] = (float)$v;
        }
        break;
      case 'INTEGER':
        $result = explode(',', $data);
        foreach ($result as $k => $v) {
          $result[$k] = (int)$v;
        }
        break;
      case 'PERIOD':
        $result = explode(',', $data);
        break;
      case 'RECUR':
        $result = $data;
        break;
      case 'TEXT':
        $result = $this->unescapeTextValue($data);
        break;
      case 'TIME':
        $result = explode(',', $data);
        break;
      case 'URI':
        $result = $data;
        break;
      case 'UTC-OFFSET':
        $result = $data;
        break;
      default:
        // RFC5545 says we MUST preserve the data for any types we don't
        // recognize.
        $result = $data;
        break;
    }

    return array(
      'type' => $value_type,
      'value' => $result,
      'raw' => $data,
    );
  }

  private function unescapeTextValue($data) {
    $result = array();

    $buf = '';
    $esc = false;
    foreach (phutil_utf8v($data) as $c) {
      if (!$esc) {
        if ($c == '\\') {
          $esc = true;
        } else if ($c == ',') {
          $result[] = $buf;
          $buf = '';
        } else {
          $buf .= $c;
        }
      } else {
        switch ($c) {
          case 'n':
          case 'N':
            $buf .= "\n";
            break;
          default:
            $buf .= $c;
            break;
        }
      }
    }

    if ($esc) {
      $this->raiseParsFailure(
        pht(
          'ICS document contains TEXT value ending with unescaped '.
          'backslash.'));
    }

    $result[] = $buf;

    return $result;
  }

  private function raiseParseFailure($message) {
    throw new Exception($message);
  }

}
