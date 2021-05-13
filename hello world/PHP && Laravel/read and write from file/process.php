<?php

    $f=fopen("salam.txt","a+");
    $text=$_POST["txt"];
    fwrite($f,$text."\n");
    fclose($f);
    echo "<br/>write in file was successful<br/>";
