<?php

namespace App\DesignPatterns\States\Elevator\State;

use App\DesignPatterns\States\Elevator\ElevatorStateInterface;
require_once("ElevatorStateInterface.php");
require_once("Close.php");
require_once("Open.php");
require_once("Move.php");



class Stop implements ElevatorStateInterface
{
    public function getName()
    {
        return "Stop";
    }


    public function open()
    {
        return new Open();
    }

    public function close()
    {
        return new Close();
    }

    public function move()
    {
        return new Move();
    }

    public function stop()
    {
        echo "Already Stopped <br>" ;
        return new Stop();
    }
}