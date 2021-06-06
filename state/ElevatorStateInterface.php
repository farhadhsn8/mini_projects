<?php

namespace App\DesignPatterns\States\Elevator;

interface ElevatorStateInterface
{
    public function getName();

    public function open();
    public function close();
    public function move();
    public function stop();
}