<?php

/**
 * Convenience function for instantiating a new @{class:FutureIterator}.
 *
 * @param list              List of @{class:Future}s.
 * @return FutureIterator   New @{class:FutureIterator} over those futures.
 */
function Futures($futures) {
  return new FutureIterator($futures);
}
