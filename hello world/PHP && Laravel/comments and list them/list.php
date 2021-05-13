<?php

    $conn=mysqli_connect('localhost','root','','bye','3308');
    $sql="SELECT * FROM users_tbl";
    $result = mysqli_query($conn,$sql);



     

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="style1.css">
</head>
<body>

    <table class="maintbl">
        <tr>
            <th>name</th>
            <th>last name</th>
            <th>age</th>
            <th>field</th>
            <th>comment</th> 
            <th>picture</th>

        </tr>
        <?php
            while($row = mysqli_fetch_assoc($result))
            {
        ?>
                <tr>
                    <td><?php echo $row["name"] ?></td>
                    <td><?php echo $row["lastname"] ?></td>
                    <td><?php echo $row["age"] ?></td>
                    <td><?php echo $row["field"] ?></td>
                    <td><?php echo $row["comment"] ?></td>
                    <td> <img src="<?php echo $row["picture"] ?>" height="40" /></td> 
                </tr>  
        <?php
            }
        ?>
    </table>
    
</body>
</html>
