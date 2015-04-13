<?php

final class AphrontScopedUnguardedWriteCapability {

  public function __destruct() {
    AphrontWriteGuard::endUnguardedWrites();
  }

}
