<?php

final class PhutilLunarPhaseTestCase extends PhutilTestCase {

  public function testLunarPhases() {

    // Aug 11, 1999
    $moon = new PhutilLunarPhase(934354800);
    $this->assertEqual(false, $moon->isFull());
    $this->assertEqual(true, $moon->isNew());
    $this->assertEqual(true, $moon->isWaxing());
    $this->assertEqual(false, $moon->isWaning());

    // May 22, 2005
    $moon = new PhutilLunarPhase(1116745200);
    $this->assertEqual(true, $moon->isFull());
    $this->assertEqual(false, $moon->isNew());
    $this->assertEqual(true, $moon->isWaxing());
    $this->assertEqual(false, $moon->isWaning());

    // May 23, 2005
    $moon = new PhutilLunarPhase(1116831600);
    $this->assertEqual(true, $moon->isFull());
    $this->assertEqual(false, $moon->isNew());
    $this->assertEqual(false, $moon->isWaxing());
    $this->assertEqual(true, $moon->isWaning());

    // May 30, 2005
    $moon = new PhutilLunarPhase(1117436400);
    $this->assertEqual(false, $moon->isFull());
    $this->assertEqual(false, $moon->isNew());
    $this->assertEqual(false, $moon->isWaxing());
    $this->assertEqual(true, $moon->isWaning());

    // June 05, 2005
    $moon = new PhutilLunarPhase(1117954800);
    $this->assertEqual(false, $moon->isFull());
    $this->assertEqual(false, $moon->isNew());
    $this->assertEqual(false, $moon->isWaxing());
    $this->assertEqual(true, $moon->isWaning());

    // June 06, 2005
    $moon = new PhutilLunarPhase(1118041200);
    $this->assertEqual(false, $moon->isFull());
    $this->assertEqual(true, $moon->isNew());
    $this->assertEqual(false, $moon->isWaxing());
    $this->assertEqual(true, $moon->isWaning());

    // Oct 4, 2013
    $moon = new PhutilLunarPhase(1380897327);
    $this->assertEqual(false, $moon->isFull());
    $this->assertEqual(true, $moon->isNew());
    $this->assertEqual(true, $moon->isWaxing());
    $this->assertEqual(false, $moon->isWaning());

  }


}
