<?php
    //include_once "public/include/config.php";
    require_once 'model/Mindex.php';
    $class = new main($mydb);
    $menu = $class->menu_list();
    $news = $class->news_list();

    require_once 'view/index.php';
?>
