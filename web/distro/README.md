# [HOME](index.html)

# [http://localhost](http://localhost)

# [TRASH MAGIC](https://github.com/LafeLabs/trashmagic/)

# [TRASH MAGIC RECURSIVE WEB](https://github.com/LafeLabs/trashmagic/tree/main/web)

# [TRASH MAGIC ZINE DISTRO](https://github.com/LafeLabs/trashmagic/tree/main/web/distro)

The purpose of Trash Magic is to create a civilization of free things entirely built from trash.  We will build things from trash, share them freely, and share how to build them with others so that they can replicate.  We call this replication from person to person of the knowhow and desire to make things "magic".  

THE RECURSIVE WEB IS MADE OF WORLDS AND QUESTS. YOU CONSTRUCT, REPLICATE AND DESTROY WORLDS AND QUESTS TO BUILD TRASH MAGIC.

Zine distros in the recursive web are self-replicating.  print zines and put them in physical spaces which you document on the web page which is on the trash server which a domain points to which is on the zine which is about the space where the zine is.  EVERYTHING IS RECURSIVE!  Exchange USB thumb drives in the same physical spaces as you exchange physical zines, and use them to move zine files from one trash server to the next.  Distros include zines on how to make another trash magic server and replicate the whole system.  

the quests of the zine operators are to get people to add zines to the zine distros which bring about full trash magic.  this includes technical documentation, art, culture, organizing, science, magic, politics, agriculture, philosophy, and mathematics we require to bring the entire world into trash magic.  Ask people you know who have skills in making things from trash to contribute zines and then publish those on your distro and share it with other distro operators as well as print and distribute in physical TRASH MAGIC exchanges.

## [GITHUB README](https://github.com/LafeLabs/trashmagic/tree/main/web/distro)

![](https://raw.githubusercontent.com/LafeLabs/trashmagic/main/media/trashmagic/zinedistro.png)

Find any old computer that someone is getting rid of, it could be mac, pc or linux(but not Chromebook).  

You will need a thumb drive.  Follow the instructions below to install Ubuntu and wipe all the old data on the hard drive.

[https://ubuntu.com instructions](https://ubuntu.com/tutorials/install-ubuntu-desktop#1-overview)

Once Ubuntu is installed, open a command line and type:

```
sudo apt update
sudo apt install apache2 -y
sudo apt install php libapache2-mod-php -y
cd /var/www/html
sudo rm index.html
sudo apt install curl
sudo curl -o replicator.php https://raw.githubusercontent.com/LafeLabs/trashmagic/main/web/distro/php/replicator.txt
cd ..
sudo chmod -R 0777 *
cd html
php replicator.php
```

This will clone the trash magic recursive web to your server. 

Now go into the DNS records of a domain you have access to or ask someone else to it for a domain they have access to and add an "A record" with entries "@" and "www" for that domain to the home IP address of wherever the server is located.  Set up port forwarding on ports 80 and 443 on the router for that local network.  These can be subdomains so that one domain can map to an arbitrary number of distros.  We will use this combination of physical and digital zines to spread trash magic, eventually filling all public spaces along the WATERSHEDS and STREETS of the world so that all people can live for free off of trash.

Or just use this on local wifi networks.  Distro can replicate by use of thumb drives.  put a zine folder on the thumb drive and copy from server to server from exchange to exchange and place to place across the world.  

![](https://raw.githubusercontent.com/LafeLabs/trashmagic/main/media/trashmagic/qrcode-pages/distro.png)

