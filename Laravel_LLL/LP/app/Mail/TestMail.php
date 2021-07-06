<?php

namespace App\Mail;

use Illuminate\Bus\Queueable;
use Illuminate\Contracts\Queue\ShouldQueue;
use Illuminate\Mail\Mailable;
use Illuminate\Queue\SerializesModels;

class TestMail extends Mailable
{
    use Queueable, SerializesModels;

    private $warehouse ;
    /**
     * Create a new message instance.
     *
     * @return void
     */
    public function __construct($warehouse)
    {
        $this->warehouse = $warehouse;
    }

    /**
     * Build the message.
     *
     * @return $this
     */
    public function build()
    {
        return $this->view('mail.testMail')->subject('delete_warehouse')->with('warehouse',$this->warehouse);
    }
}
