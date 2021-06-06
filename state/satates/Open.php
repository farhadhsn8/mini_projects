<?php

namespace App\DesignPatterns\States\Elevator\State;

use App\DesignPatterns\States\Elevator\ElevatorStateInterface;
require_once("Close.php");
require_once("Stop.php");
require_once("Move.php");

class Open implements ElevatorStateInterface
{
    public function getName()
    {
        return "Open";
    }


    public function open()
    {
        echo "Already Opened <br>";
        return new Open();
    }

    public function close()
    {
        return new Close();
    }

    public function move()
    {
        echo "cannot change state from open to move <br>";
        return new Open();

    }

    public function stop()
    {
        echo "cannot change state from open to stop<br>";
        return new Open();
    }
}