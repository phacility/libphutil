<?php

/**
 * Represent and manipulate IPv6 addresses.
 */
final class PhutilIPv6Address extends PhutilIPAddress {

  private $values;
  private $displayAddress;
  private $bits;

  private function __construct() {
    // <private>
  }

  public function getBitCount() {
    return 128;
  }

  protected static function newFromString($str) {
    $parts = explode(':', $str);
    if (count($parts) > 8) {
      throw new Exception(
        pht(
          'IP address "%s" is not properly formatted: is has too many '.
          'parts. Expected a maximum of 7 colons, like "%s".',
          $str,
          '1:2:3:4:a:b:c:d'));
    }

    if (count($parts) < 3) {
      throw new Exception(
        pht(
          'IP address "%s" is not properly formated: it has too few '.
          'parts. Expected a minimum of 2 colons, like "%s".',
          $str,
          '::1'));
    }

    // Look for leading or trailing empty parts. These are valid if the string
    // begins or ends like "::", "::1", or "1::", but not valid otherwise.
    $has_omission = false;
    if ($str === '::') {
      $parts = array(null);
      $has_omission = true;
    } else if ($parts[0] === '') {
      if ($parts[1] === '') {
        unset($parts[1]);
        $parts[0] = null;
        $parts = array_values($parts);
        $has_omission = true;
      } else {
        throw new Exception(
          pht(
            'IP address "%s" is not properly formatted: an address with '.
            'omitted leading sements must begin with "::".',
            $str));
      }
    } else if (last($parts) === '') {
      if ($parts[count($parts) - 2] === '') {
        array_pop($parts);
        $parts[count($parts) - 1] = null;
        $parts = array_values($parts);
        $has_omission = true;
      } else {
        throw new Exception(
          pht(
            'IP address "%s" is not properly formatted: an address with '.
            'omitted trailing segments must end with "::".',
            $str));
      }
    }

    foreach ($parts as $idx => $part) {
      if ($part !== '') {
        continue;
      }

      if ($has_omission) {
        throw new Exception(
          pht(
            'IP address "%s" is not properly formatted: an address may '.
            'only contain a maximum of one subsequence omitted with "::".',
            $str));
      }

      $has_omission = true;
      $parts[$idx] = null;
    }

    if (!$has_omission) {
      if (count($parts) !== 8) {
        throw new Exception(
          pht(
            'IP address "%s" is not properly formatted: an address must '.
            'contain exactly 8 segments, or omit a subsequence of segments '.
            'with "::".',
            $str));
      }
    }

    $values = array();
    foreach ($parts as $idx => $part) {
      // This is a "::" segment, so fill in any missing values with 0.
      if ($part === null) {
        for ($ii = count($parts); $ii <= 8; $ii++) {
          $values[] = 0;
        }
        continue;
      }

      if (!preg_match('/^[0-9a-fA-F]{1,4}\z/', $part)) {
        throw new Exception(
          pht(
            'IP address "%s" is not properly formatted: the segments of '.
            'an address must be hexadecimal values between "0000" and "ffff", '.
            'inclusive. Segment "%s" is not.',
            $str,
            $part));
      }

      $values[] = (int)hexdec($part);
    }

    $obj = new self();
    $obj->values = $values;

    return $obj;
  }

  public function getAddress() {
    if ($this->displayAddress === null) {
      // Find the longest consecutive sequence of "0" values. We want to
      // collapse this into "::".
      $longest_run = 0;
      $longest_index = 0;
      $current_run = null;
      $current_index = null;
      foreach ($this->values as $idx => $value) {
        if ($value !== 0) {
          $current_run = null;
          continue;
        }

        if ($current_run === null) {
          $current_run = 1;
          $current_index = $idx;
        } else {
          $current_run++;
        }

        if ($current_run > $longest_run) {
          $longest_run = $current_run;
          $longest_index = $current_index;
        }
      }

      // Render the segments of the IPv6 address, omitting the longest run
      // of consecutive "0" segments.
      $pieces = array();
      for ($idx = 0; $idx < count($this->values); $idx++) {
        $value = $this->values[$idx];

        if ($idx === $longest_index) {
          if ($longest_run > 1) {
            $pieces[] = null;
            $idx += ($longest_run - 1);
            continue;
          }
        }

        $pieces[] = dechex($value);
      }

      // If the omitted segment is at the beginning or end of the address, add
      // an extra piece so we get the leading or trailing "::" when we implode
      // the pieces.
      if (head($pieces) === null) {
        array_unshift($pieces, null);
      }

      if (last($pieces) === null) {
        $pieces[] = null;
      }

      $this->displayAddress = implode(':', $pieces);
    }

    return $this->displayAddress;
  }

  public function toBits() {
    if ($this->bits === null) {
      $bits = '';
      foreach ($this->values as $value) {
        for ($ii = 15; $ii >= 0; $ii--) {
          $mask = (1 << $ii);
          if (($value & $mask) === $mask) {
            $bits .= '1';
          } else {
            $bits .= '0';
          }
        }
      }

      $this->bits = $bits;
    }

    return $this->bits;
  }

}
