<?php
function test($a,$b){
    $num=5*$a+$b;
    echo $num;
}

function uploader_files($name,$dir,$file){
    mkdir($dir.$name);
    $picname=$_FILES[$file]['name'];
    $array=explode(".",$picname);
    $ext=end($array);
    $new_name=rand().".".$ext;
    $from=$_FILES[$file]['tmp_name'];
    $to=$dir.$name."/".$new_name;
    move_uploaded_file($from,$to);
}
function connect_db($user,$pass,$db){
    $server="localhost";
    $username=$user;
    $password=$pass;
    $connection=mysqli_connect($server,$username,$password,$db);
    if(!$connection){
        die("پیغام خطا :".mysqli_connect_error());
    }else{
        echo "<div class='alert'>ارتباط با پایگاه داده به صورت موفقیت آمیز برقرار شد !</div>";
    }
}

