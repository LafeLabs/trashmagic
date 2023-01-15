# [HOME](index.html)

# Recursive Web

## [Trash Physics zine distro](http://distro.trashphysics.org)

## [GITHUB README](https://github.com/LafeLabs/trashmagic/tree/main/web/distro)

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

Now go into the DNS records of a domain you have access to or ask someone else to it for a domain they have access to and add an "A record" with entries "@" and "www" for that domain to the home IP address of wherever the server is located.  Set up port forwarding on ports 80 and 443 on the router for that local network.  To add subdomains, use virtual hosts on apache(check [top level trash magic readme](https://github.com/LafeLabs/trashmagic/blob/main/README.md) or ask for help).

![](https://github.com/LafeLabs/trashmagic/blob/main/media/trashmagic/qrcode-pages/distro.png)
