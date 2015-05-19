<?php

final class PhutilLunarPhaseTestCase extends PhutilTestCase {

  public function testLunarPhases() {
    // Aug 11, 1999
    $moon = new PhutilLunarPhase(934354800);
    $this->assertFalse($moon->isFull());
    $this->assertTrue($moon->isNew());
    $this->assertTrue($moon->isWaxing());
    $this->assertFalse($moon->isWaning());

    // May 22, 2005
    $moon = new PhutilLunarPhase(1116745200);
    $this->assertTrue($moon->isFull());
    $this->assertFalse($moon->isNew());
    $this->assertTrue($moon->isWaxing());
    $this->assertFalse($moon->isWaning());

    // May 23, 2005
    $moon = new PhutilLunarPhase(1116831600);
    $this->assertTrue($moon->isFull());
    $this->assertFalse($moon->isNew());
    $this->assertFalse($moon->isWaxing());
    $this->assertTrue($moon->isWaning());

    // May 30, 2005
    $moon = new PhutilLunarPhase(1117436400);
    $this->assertFalse($moon->isFull());
    $this->assertFalse($moon->isNew());
    $this->assertFalse($moon->isWaxing());
    $this->assertTrue($moon->isWaning());

    // June 05, 2005
    $moon = new PhutilLunarPhase(1117954800);
    $this->assertFalse($moon->isFull());
    $this->assertFalse($moon->isNew());
    $this->assertFalse($moon->isWaxing());
    $this->assertTrue($moon->isWaning());

    // June 06, 2005
    $moon = new PhutilLunarPhase(1118041200);
    $this->assertFalse($moon->isFull());
    $this->assertTrue($moon->isNew());
    $this->assertFalse($moon->isWaxing());
    $this->assertTrue($moon->isWaning());

    // Oct 4, 2013
    $moon = new PhutilLunarPhase(1380897327);
    $this->assertFalse($moon->isFull());
    $this->assertTrue($moon->isNew());
    $this->assertTrue($moon->isWaxing());
    $this->assertFalse($moon->isWaning());

  }


}
