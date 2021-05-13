<?php
    include_once "public/include/config.php";
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php

 //$mydb = new PDO("mysql:host=localhost;port=3308;dbname=mvc" , "root","");
// $result = $mydb->query("SELECT * FROM menu_tbl");
// // $result->execute();
// // $row = $result->fetchAll();
// foreach($result as $i)
// {
//     echo $i['title'];
// }
// die;
//agar controller set shod boro be in controller . agar set nashod boro be index controller.
        if(isset($_GET['c']))   
        {
            $controller = $_GET['c'];
        }
        else
        {
            $controller = 'index';
        }
        
        if(file_exists('controller/C'.$controller.'.php'))
        {
            require_once'controller/C'.$controller.'.php';
        }
    ?>
</body>
</html>