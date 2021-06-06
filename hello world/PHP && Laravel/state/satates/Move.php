<?php

namespace App\DesignPatterns\States\Elevator\State;

use App\DesignPatterns\States\Elevator\ElevatorStateInterface;

require_once("Close.php");
require_once("Stop.php");
require_once("Open.php");


class Move implements ElevatorStateInterface
{
    public function getName()
    {
        return "Move";
    }

    public function move()
    {
        echo "Already Moving <br> ";
        return new Move();
    }

    public function stop()
    {
        return new Stop();
    }

    public function close()
    {
        echo "cannot change state from move to close <br>";
        return new Move();

    }

    public function open()
    {
        echo "cannot change state from move to open <br>";
        return new Move();

    }
}