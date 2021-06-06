<?php

namespace App\DesignPatterns\States\Elevator;

use App\DesignPatterns\States\Elevator\State\Open;
use App\DesignPatterns\States\Elevator\State\Stop;
require_once("satates/Stop.php");


class Elevator
{
    private $state;

    private function setState(ElevatorStateInterface $state)
    {
        $this->state = $state;
        echo "set state to : " . $this->state->getName() ."<br>";
    }

    public function __construct()
    {
        $this->setState(new Stop());
    }

    public function open()
    {
        $this->setState($this->state->open());
    }

    public function close()
    {
        $this->setState($this->state->close());
    }

    public function move()
    {
        $this->setState($this->state->move());
    }

    public function stop()
    {
        $this->setState($this->state->stop());
    }
}