<?php
//mkdir.php?dir=[dirname]

$dirname = $_GET["dir"];//get dir
mkdir($dirname);

if(isset($_GET["replicator"])){

    $replicatorurl = $_GET["replicator"];
    copy($replicatorurl,$dirname."/replicator.php");
    
}
else{
    copy("php/replicator.txt",$dirname."/replicator.php");    
}



echo "<a href = \"".$dirname."/replicator.php\">".$dirname."/replicator.php</a>";

?>
<style>
body{
    background-color:black;
}
a{
    text-align:center;
    font-family:helvetica;
    font-size:3em;
    width:80%;
    margin:auto;
    display:block;
    border:solid;
    border-radius:0.5em;
    border-width:0.5em;
    color:black;
    margin-top:1em;
    margin-bottom:0.5em;
    overflow-x:scroll;
    background-color:red;
    border-color:red;
}
</style>