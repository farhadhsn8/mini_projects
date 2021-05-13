<?php
    class register_user
    {
       public $db;
       public function __construct($mydb)
       {
           
           $this->db=$mydb;
           //var_dump($mydb);
       }

       public function register_add($data)
       {
           $q=$this->db->query("INSERT INTO
                        user_tbl (username,lastname,city,password) 
                        values ('$data[username]','$data[lastname]',
                        '$data[city]','$data[password]')");
           //$q->execute();   ----------->>> 2 bar vared mikone...
       }

    }