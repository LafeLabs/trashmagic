<pre>
<?php


$localimagesetraw = file_get_contents("data/imageset.txt");
$localimageset = json_decode($localimagesetraw);

$server = $localimageset->server;

$remoteimagesetraw = file_get_contents($server."data/imageset.txt");
$remoteimageset = json_decode($remoteimagesetraw);
$images = $remoteimageset->images;

foreach($images as $value){

    copy($server."uploadimages/".$value,"uploadimages/copy-".$value);

}

echo json_encode($images,JSON_PRETTY_PRINT);
    
?>
</pre>
<a href = "index.html">HOME</a>
<style>
a{
    font-size:3em;
}
body{
    font-size:1em;
    font-family:courier;
}
</style>
