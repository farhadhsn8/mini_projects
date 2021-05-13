<!doctype html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Document</title>
    <style>
        .alert{
            color:red;
            font-family: tahoma;
            text-align: center;
        }
    </style>
</head>
<body>
<?php
$server="localhost";
$username="root";
$password="";
$db="php_test";
$connection=mysqli_connect($server,$username,$password,$db);
//var_dump($connection);
if(!$connection){
    die("پیغام خطا :".mysqli_connect_error());
}else{
    echo "<div class='alert'>ارتباط با پایگاه داده به صورت موفقیت آمیز برقرار شد !</div>";
}
?>
</body>
</html>

