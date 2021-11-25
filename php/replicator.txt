<?php

$dnaurl = "https://raw.githubusercontent.com/LafeLabs/trashmagic/main/data/dna.txt";

if(isset($_GET["dna"])){
    $dnaurl = $_GET["dna"];
}


$baseurl = explode("data/",$dnaurl)[0];
$dnaraw = file_get_contents($dnaurl);
$dna = json_decode($dnaraw);

mkdir("data");
mkdir("php");
mkdir("scrolls");
mkdir("iconsymbols");

mkdir("symbolserver");
mkdir("imageserver");

copy("https://raw.githubusercontent.com/LafeLabs/trashmagic/main/php/replicator.txt","replicator.php");


copy("https://raw.githubusercontent.com/LafeLabs/trashmagic/main/symbolserver/php/replicator.txt","symbolserver/replicator.php");
copy("https://raw.githubusercontent.com/LafeLabs/pi/main/servers/imageserver/php/replicator.txt","imageserver/replicator.php");



foreach($dna->html as $value){
    
    copy($baseurl.$value,$value);

}

foreach($dna->iconsymbols as $value){
    
    copy($baseurl."iconsymbols/".$value,"iconsymbols/".$value);

}

foreach($dna->data as $value){
    
    copy($baseurl."data/".$value,"data/".$value);
    
}

foreach($dna->php as $value){
 
    copy($baseurl."php/".$value,"php/".$value);
    copy($baseurl."php/".$value,explode(".",$value)[0].".php");

}

foreach($dna->scrolls as $value){
    copy($baseurl."scrolls/".$value,"scrolls/".$value);
}


?>
<a href = "index.html">CLICK TO GO TO PAGE</a>
<style>
a{
    font-size:3em;
}
</style>
