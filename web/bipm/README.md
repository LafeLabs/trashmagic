### [HOME](index.html)

# BARTERTOWN INTSITUTE OF PRACTICAL METROLOGY

## TRASH PHYSICS DOT ORG RECURSIVE WEB SERVER
    
## TRASH MAGIC RECURSIVE WEB

## BARTERTOWN INSTITUTE OF PRACTICAL METROLOGY

## *THE OTHER BIPM*


# QUESTS

This README file is to replicate the set of BIPM. 

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
sudo curl -o replicator.php https://bipm.trashphysics.org/php/replicator.txt
cd ..
sudo chmod -R 0777 *
cd html
php replicator.php
sudo chmod -R 0777 *
sudo apt-get install arduino
sudo apt-get install python3-scipy
sudo apt install python3-pip
sudo pip3 install jupyter
```

This will clone the main BIPM to your server. Now go into the DNS records of a domain you have access to or ask someone else to it for a domain they have access to and add an "A record" with entry "bipm" for that domain to the home IP address of wherever the server is located.  Set up port forwarding on ports 80 and 443 on the router for that local network.  Fork down with replicators to make different divisions for specific measurements like dark matter or spectrum.





 