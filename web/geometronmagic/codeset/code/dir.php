<?php

// list files and or directories in a directory


$files = scandir(getcwd());
$dirs = [];
foreach($files as $value){
    if($value[0] != "."){
        array_push($dirs,$value);
    }
}
echo json_encode($dirs);


?>
