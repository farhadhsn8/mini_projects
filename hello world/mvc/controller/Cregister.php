<?php
    require_once 'model/Mregister.php';
    $class1 = new register_user($mydb);
    if(isset($_POST['btn']))
    {
        $data = $_POST['frm'];
        //var_dump($mydb);
        $class1->register_add($data);
    }
    require_once 'view/register.php';
?>