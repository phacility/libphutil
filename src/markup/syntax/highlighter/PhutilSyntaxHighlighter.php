<?php

abstract class PhutilSyntaxHighlighter {
  abstract public function setConfig($key, $value);
  abstract public function getHighlightFuture($source);
}
