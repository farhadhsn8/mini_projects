<?php

namespace App\DesignPatterns\States\Elevator\State;

use App\DesignPatterns\States\Elevator\ElevatorStateInterface;

require_once("Stop.php");
require_once("Open.php");
require_once("Move.php");

class Close implements ElevatorStateInterface
{
    public function getName()
    {
        return "Close";
    }

    public function close()
    {
        echo "Already Closed <br>";
        return new Close();
    }

    public function open()
    {
        return new Open();
    }

    public function move()
    {
        return new Move();
    }

    public function stop()
    {
        echo "cannot change position from close to stop <br>" ;
        return new Close();
    }
}