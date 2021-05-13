<?php

$email=$_POST['email'];
mkdir("uploader/".$email);
echo "----------------------------------------------------------------------------------<br/>";
//var_dump($_FILES);
$picname=$_FILES['pic']['name'];
$array=explode(".",$picname);
$ext=end($array);
$new_name=rand().".".$ext;
$from=$_FILES['pic']['tmp_name'];
$to="uploader/".$email."/".$new_name;
move_uploaded_file($from,$to);



//echo $name;
//var_dump($_FILES['pic']);
//p.i.c1.jpg
//$total=count($array);
//var_dump($array[$total-1]);
//echo end($array);
//echo rand();
