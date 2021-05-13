<?php
$data=$_POST['frm'];
//var_dump($data);


$dir='uploader/';

mkdir($dir.$data['name']);
$picname=$_FILES['image']['name'];
$array=explode(".",$picname);
$ext=end($array);
$new_name=rand().".".$ext;
$from=$_FILES['image']['tmp_name'];
$to=$dir.$data['name']."/".$new_name;
move_uploaded_file($from,$to);

$conn=mysqli_connect('localhost','root','','bye','3308');
$sql="INSERT INTO users_tbl (name,lastname,age,field,comment,picture) VALUES ('$data[name]','$data[lastname]','$data[age]','$data[field]','$data[comment]','$to')";
mysqli_query($conn,$sql);

echo "operation was successfull<br/>";
header("location:list.php");    