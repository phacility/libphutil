<?php

/**
 * Concrete subclass of @{class:AbstractDirectedGraph} which can not load any
 * data from external sources.
 */
final class PhutilDirectedScalarGraph extends AbstractDirectedGraph {

  protected function loadEdges(array $nodes) {
    throw new Exception(
      'PhutilDirectedScalarGraph can not load additional nodes at runtime. '.
      'Tried to load: '.implode(', ', $nodes));
  }

}
