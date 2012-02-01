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

final class PhutilArgumentParser {

  private $bin;
  private $argv;
  private $specs = array();
  private $results = array();
  private $parsed;

  private $tagline;
  private $synopsis;

  public function __construct(array $argv) {
    $this->bin = $argv[0];
    $this->argv = array_slice($argv, 1);
  }

  public function parsePartial(array $specs) {
    foreach ($specs as $key => $spec) {
      if (is_array($spec)) {
        $specs[$key] = PhutilArgumentSpecification::newQuickSpec(
          $spec);
      }
    }

    $this->mergeSpecs($specs);

    $specs_by_name  = mpull($specs, null, 'getName');
    $specs_by_short = mpull($specs, null, 'getShortAlias');
    unset($specs_by_short[null]);

    $argv = $this->argv;
    $len = count($argv);
    for ($ii = 0; $ii < $len; $ii++) {
      $arg = $argv[$ii];
      $map = null;
      if ($arg == '--') {
        // This indicates "end of flags".
        break;
      } else if ($arg == '-') {
        // This is a normal argument (e.g., stdin).
        continue;
      } else if (!strncmp('--', $arg, 2)) {
        $pre = '--';
        $arg = substr($arg, 2);
        $map = $specs_by_name;
      } else if (!strncmp('-', $arg, 1) && strlen($arg) > 1) {
        $pre = '-';
        $arg = substr($arg, 1);
        $map = $specs_by_short;
      }

      if ($map) {
        $val = null;
        $parts = explode('=', $arg, 2);
        if (count($parts) == 2) {
          list($arg, $val) = $parts;
        }

        if (isset($map[$arg])) {
          $spec = $map[$arg];
          unset($argv[$ii]);

          $param_name = $spec->getParamName();
          if ($val !== null) {
            if ($param_name === null) {
              throw new PhutilArgumentUsageException(
                "Argument '{$pre}{$arg}' does not take a parameter.");
            }
          } else {
            if ($param_name !== null) {
              if ($ii + 1 < $len) {
                $val = $argv[$ii + 1];
                unset($argv[$ii + 1]);
                $ii++;
              } else {
                throw new PhutilArgumentUsageException(
                  "Argument '{$pre}{$arg}' requires a parameter.");
              }
            } else {
              $val = true;
            }
          }

          if (array_key_exists($spec->getName(), $this->results)) {
            throw new PhutilArgumentUsageException(
              "Argument '{$pre}{$arg}' was provided twice.");
          }

          $conflicts = $spec->getConflicts();
          foreach ($conflicts as $conflict => $reason) {
            if (array_key_exists($conflict, $this->results)) {

              if (!is_string($reason) || !strlen($reason)) {
                $reason = '.';
              } else {
                $reason = ': '.$reason.'.';
              }

              throw new PhutilArgumentUsageException(
                "Argument '{$pre}{$arg}' conflicts with argument ".
                "'--{$conflict}'{$reason}");
            }
          }

          $this->results[$spec->getName()] = $val;
        }
      }
    }

    foreach ($specs as $spec) {
      if ($spec->getWildcard()) {
        $this->results[$spec->getName()] = $this->filterWildcardArgv($argv);
        $argv = array();
        break;
      }
    }

    $this->argv = array_values($argv);
    return $this;
  }

  public function parseFull(array $specs) {
    $this->parsePartial($specs);

    if (count($this->argv)) {
      $arg = head($this->argv);
      throw new PhutilArgumentUsageException(
        "Unrecognized argument '{$arg}'.");
    }

    return $this;
  }

  public function parse(array $specs) {
    try {
      $this->parseFull($specs);
    } catch (PhutilArgumentUsageException $ex) {
      file_put_contents(
        'php://stderr',
        $this->format('**Usage Exception:** '.$ex->getMessage()."\n"));
      exit(77);
    }
  }

  public function getArg($name) {
    if (empty($this->specs[$name])) {
      throw new PhutilArgumentSpecificationException(
        "No specification exists for argument '{$name}'!");
    }

    if (idx($this->results, $name) !== null) {
      return $this->results[$name];
    }

    return $this->specs[$name]->getDefault();
  }

  public function getUnconsumedArgumentVector() {
    return $this->argv;
  }

  private function filterWildcardArgv(array $argv) {
    foreach ($argv as $key => $value) {
      if ($value == '--') {
        unset($argv[$key]);
        break;
      } else if (!strncmp($value, '-', 1) && strlen($value) > 1) {
        throw new PhutilArgumentUsageException(
          "Argument '{$value}' is unrecognized. Use '--' to indicate the ".
          "end of flags.");
      }
    }
    return array_values($argv);
  }

  private function mergeSpecs(array $specs) {

    $short_map = mpull($this->specs, null, 'getShortAlias');
    unset($short_map[null]);

    $wildcard = null;
    foreach ($this->specs as $spec) {
      if ($spec->getWildcard()) {
        $wildcard = $spec;
        break;
      }
    }

    foreach ($specs as $spec) {
      $name = $spec->getName();

      if (isset($this->specs[$name])) {
        throw new PhutilArgumentSpecificationException(
          "Two argument specifications have the same name ('{$name}').");
      }

      $short = $spec->getShortAlias();
      if ($short) {
        if (isset($short_map[$short])) {
          throw new PhutilArgumentSpecificationException(
            "Two argument specifications have the same short alias ".
            "('{$short}').");
        }
        $short_map[$short] = $spec;
      }

      if ($spec->getWildcard()) {
        if ($wildcard) {
          throw new PhutilArgumentSpecificationException(
            "Two argument specifications are marked as wildcard arguments. ".
            "You can have a maximum of one wildcard argument.");
        } else {
          $wildcard = $spec;
        }
      }

      $this->specs[$name] = $spec;
    }

    foreach ($this->specs as $name => $spec) {
      foreach ($spec->getConflicts() as $conflict => $reason) {
        if (empty($this->specs[$conflict])) {
          throw new PhutilArgumentSpecificationException(
            "Argument '{$name}' conflicts with unspecified argument ".
            "'{$conflict}'.");
        }
        if ($conflict == $name) {
          throw new PhutilArgumentSpecificationException(
            "Argument '{$name}' conflicts with itself!");
        }
      }
    }

  }

  public function setSynopsis($synopsis) {
    $this->synopsis = $synopsis;
    return $this;
  }

  public function setTagline($tagline) {
    $this->tagline = $tagline;
    return $this;
  }

  public function printHelp() {
    $out = array();

    if ($this->bin) {
      $out[] = $this->format('**NAME**');
      $name = $this->indent(6, '**%s**', basename($this->bin));
      if ($this->tagline) {
        $name .= $this->format(' - '.$this->tagline);
      }
      $out[] = $name;
      $out[] = null;
    }

    if ($this->synopsis) {
      $out[] = $this->format('**SYNOPSIS**');
      $out[] = $this->indent(6, $this->synopsis);
      $out[] = null;
    }

    if ($this->specs) {
      $out[] = $this->format('**OPTION REFERENCE**');
      $out[] = null;
      $specs = msort($this->specs, 'getName');
      foreach ($specs as $spec) {
        if ($spec->getWildcard()) {
          continue;
        }

        $name = $this->indent(6, '__--%s__', $spec->getName());
        $short = null;
        if ($spec->getShortAlias()) {
          $short = $this->format(', __-%s__', $spec->getShortAlias());
        }
        if ($spec->getParamName()) {
          $param = $this->format(' __%s__', $spec->getParamName());
          $name .= $param;
          $short .= $param;
        }
        $out[] = $name.$short;
        $out[] = $this->indent(10, $spec->getHelp());
        $out[] = null;
      }
    }

    $out[] = null;

    return implode("\n", $out);
  }

  private function format($str /*, ... */) {
    $args = func_get_args();
    return call_user_func_array(
      'phutil_console_format',
      $args);
  }

  private function indent($level, $str /*, ... */) {
    $args = func_get_args();
    $args = array_slice($args, 1);
    $text = call_user_func_array(array($this, 'format'), $args);
    return str_repeat(' ', $level).phutil_console_wrap($text, $level);
  }

}
