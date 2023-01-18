<!doctype html>
<html lang="en">
<head>
    <meta charset="utf-8">
</head>
<body>
    <h1>
        <a href = "index.html">index.html</a>
    </h1>

    <h1>IP Address:  
    <span id = "ipaddress"><?php
    
        $foo =  shell_exec("hostname -I");//run linux commands from PHP
        $bar = explode(" ",$foo)[0];//explode splits strings by a delimiter
        echo $bar;
    
    ?></span>
    </h1>

</script>
<style>

</style>
</body>
</html>