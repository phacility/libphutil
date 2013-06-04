<?php

/**
 * @group storage
 */
interface PhutilQsprintfInterface {
  public function escapeString($string);
  public function escapeColumnName($string);
  public function escapeMultilineComment($string);
  public function escapeStringForLikeClause($string);
}

