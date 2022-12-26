![](https://raw.githubusercontent.com/LafeLabs/trashmagic/main/media/trashmagic/qrcode-github.png)

![](https://raw.githubusercontent.com/LafeLabs/trashmagic/main/media/trashmagic/qrcode-github-array.png)


# [TRASH MAGIC GITHUB](https://github.com/LafeLabs/trashmagic)

# [WWW.SLOANSLAKE.ART](http://www.sloanslake.art)

# [WWW.TRASHROBOT.ORG](https://www.trashrobot.org)

## [http://localhost/](http://localhost/)

## *self-replicating media*

The easiest way to get a Trash Magic server is to pick up a free one from someone who makes them.  And the best way to support people making more servers is to donate an old unused laptop to them so they can install a server on it.

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
sudo curl -o replicator.php https://raw.githubusercontent.com/LafeLabs/trashmagic/main/php/replicator.txt
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


Check the IP address by hovering over the wifi icon, put that into the browser on another machine on the same local wifi network to see and edit the server.  Or open a browser on the pi and point it to [http://localhost](http://localhost).

Now to connect this pi to the outside world you want to forward port 80 traffic to your router to the pi.  To do that, look at your router and see if there is information on how to log on, including login and password and the router IP address. If you can't find that information, try looking up your router make and model in a search and trying to figure out how to log on from there. Then click around and find the port forwarding or do a search for port forwarding and your router type, and forward port 80 traffic.  

People in the network buy domains which represent public shared spaces.  Do not buy .com domains. Do not allow pages to be indexed by Google.  Do not reference a private business or individual person in a name.  We choose domains based on local places which might be bodies of water, streets, parks, neighborhoods, intersections, transit stations, parking lots, truck stops, rest stops, highways, trails, bridges, tunnels, or libraries.


Next, you want to buy a domain name linked to a physical location near where your server is, ending in something other than .com like .net, .org, .xyz or .art.  Edit the DNS entry for your domain to have an "A record" which points to your home IP address which you can get from [www.whatismyip.com](https://www.whatismyip.com/).  Contact other Trash Magic Operators with information on your server so they can link to it.

When your server is live, put files for books in "/var/www/html/media/books", zines in "/var/www/html/media/zines", and images of trash magic objects to share on the network in "/var/www/html/media/trashmagic".  There are other folders for other kinds of media as well.  

Write the domain on trash and place the trash in the physical route you will walk with your cart of physical media(which could just be a bike basket or backpack).  Photograph the trash magic media which points to the domain which points to the server and put those photographs in the trashmagic folder as described above. When you make your local rounds as a Server Operator in the neighborhood, take pictures of others' trash magic along and post to the trash magic feed.

Create web pages for places, people and things on the route of the Operator.

This is what the server home page looks like:

![](https://raw.githubusercontent.com/LafeLabs/trashmagicserver/main/media/trashmagic/server-screenshot.png)

Here is the folder with the sub-folders you drag/drop media into on the Ubuntu Trash Magic Server:

![](https://raw.githubusercontent.com/LafeLabs/trashmagicserver/main/media/trashmagic/drop-folder-ubuntu-screenshot.png)

Put images in "trashmagic", zines in "zines" and books in "books".  Use a thumb drive to carry a copy of the whole set of files to clone from one Trash Magic Server to another when you are in physical proximity.  Carry around 2 thumb drives, one with the Ubuntu install drive described in the installation instructions at the Ubuntu page linked above and one with all your media.  Then anywhere you go you can create a new server and load media onto it, and if you find an existing server you can use your thumb drive to get all their files you want via [sneakernet](https://en.wikipedia.org/wiki/Sneakernet). 


### Replicate the Github using localhost

 - install PHP on your machine
 - create a new github repository on a CC0 PUBLIC DOMAIN license and clone it on your machine
 - copy the file [php/replicator.txt](php/replicator.txt) into a file called replicator.php in the new repo directory
 - run `php replicator.php` on your machine, wait for all the code to copy
 - push all that code up to your github repo
 - in the same directory, type `sudo php -S localhost:80`
 - go to [http://localhost](http://localhost) and you should get back to this screen, edit all elements of the system
 - use [editor.php](editor.php) to edit the file php/replicator.txt so that the two urls are the global url for *your* repo for both dna and replicator
 - after you've edited the code, click [text2php.php](text2php.php) to convert that to php
 - push your code to your github repo
 - use the new replicator code on your github repo to replicate out that instance to all other servers(linux, windows, mac, android) and forks
 - when you figure this out, make youtube videos showing other people how to copy the whole system, tell someone about those videos so that we can all link to them


### Socials

 - [tiktok:@trash_robot](https://www.tiktok.com/@trash_robot)
 - [instagram:@lafelabs](https://www.instagram.com/lafelabs/)
 - [mastodon:@trashrobot@kolektiva.social](https://kolektiva.social/@trashrobot)
 - [github:@lafelabs](https://github.com/LafeLabs/)
 - [anchor.fm podcast](https://anchor.fm/trashrobot/)

# [Trash Robot](https://www.trashrobot.org) Books
 
 
  - [https://www.lulu.com/shop/trash-robot/geometron-magic/paperback/product-y6p96w.html](BUY GEOMETRON MAGIC)
  - [https://raw.githubusercontent.com/LafeLabs/pibrary/main/geometronmagic/main-large.pdf](DOWNLOAD GEOMETRON MAGIC)
  - [https://www.lulu.com/shop/lafe-spietz/geometron/paperback/product-qqk98g.html](BUY GEOMETRON I)
  - [https://github.com/LafeLabs/bookofgeometron/raw/main/main-bigpaper.pdf](DOWNLOAD GEOMETRON I)
  - [https://www.lulu.com/en/us/shop/lafe-spietz/trash-magic-manifesto-and-action-coloring-book/paperback/product-1km4deev.html](BUY TRASH MAGIC MANIFESTO)
  - [https://lafelabs.github.io/Trash_Magic_Manifesto.pdf](DOWNLOAD TRASH MAGIC MANIFESTO)
  - [FIRST BOOK OF GEOMETRON SCROLLS](https://www.trashrobot.org/bookofgeometron/)
  - [GEOMETRON MAGIC SCROLLS](https://www.trashrobot.org/geometronmagic/)
 
# Live Trash Magic Servers

 - [www.sloanslake.art](http://www.sloanslake.art)
 - [zinez.xyz](http://zinez.xyz/)

Sloan's Lake is the location of a trash magic instance.  See map below:

![](https://raw.githubusercontent.com/LafeLabs/trashmagic/main/media/trashmagic/map-lake-denver.png)


## [link to Openstreetmaps at Sloans lake](https://www.openstreetmap.org/#map=19/39.75151/-105.04626)


Server in the field at Sloan's Lake

![](https://github.com/LafeLabs/trashmagic/blob/main/media/trashmagic/lake-server.png)


Location of above image:

![](https://github.com/LafeLabs/trashmagic/blob/main/media/trashmagic/lake-map.png)


Server in the field at the [Edgewater Dunkin Donuts](http://sloanslake.art/web/dunkin.html):

![](https://github.com/LafeLabs/trashmagic/blob/main/media/trashmagic/dunkin.png)



TRASH ROBOT is an Operator of the Sloans Lake node on the TRASH MAGIC NETWORK.

![](https://github.com/LafeLabs/trashmagic/raw/main/media/trashmagic/operator.png)

You can replicate the FREE PANTS by copying the letters from trash and sewing them on black sweatpants you find in the trash:

![](https://raw.githubusercontent.com/LafeLabs/trashmagic/main/media/trashmagic/freepants1.png)

![](https://raw.githubusercontent.com/LafeLabs/trashmagic/main/media/trashmagic/freepants2.png)


This is the home server which hosts sloanslake.art:

![](https://raw.githubusercontent.com/LafeLabs/trashmagic/main/media/trashmagic/server.png)

Here is the flag for the SLOANS LAKE TRASH MAGIC NETWORK NODE:

![](https://raw.githubusercontent.com/LafeLabs/trashmagic/main/media/trashmagic/flag.png)

Here it is on the trash magic cart which has a printer robot on it and a mobile server with solar panel:

![](https://raw.githubusercontent.com/LafeLabs/trashmagic/main/media/trashmagic/cart.png)

![](https://raw.githubusercontent.com/LafeLabs/trashmagic/main/media/trashmagic/cart2.png)

The icosahedron, made from 3 golden rectangles, represents the Water element in the GEOMETRON/TRASH MAGIC cosmology.

![](https://raw.githubusercontent.com/LafeLabs/trashmagic/main/media/trashmagic/water-element1.png)

![](https://raw.githubusercontent.com/LafeLabs/trashmagic/main/media/trashmagic/water-element2.png)

Golden Rectangle cutout to construct icosahedra:

![](https://github.com/LafeLabs/trashmagic/blob/main/media/trashmagic/golden-rectangle.svg) 

Print the above .svg image, then select the rectangle which has a size you want to use for making icoahedra and cut out that rectangle and the zig zag in the middle so that it can be used to generate a cardboard pattern which is replicated into more and more cardboard, creating an endless feed of cardboard icosahedra of all sizes with media printed on them which point back to this set of self-replicating digital media elements.  

When we communicate the idea of replicating icosahedra from cardboard, this leads to discussions of geodesic domes built from trash, which will form the beginning of our trash arcologies that we aim to build in cities across the globe.  If you can build a cardboard icosahedron, you can build one from sticks and boards, and if you can build that you can build a dome from trash and so on.  

The cardboard Golden Rectangles also communicate the core of our philosophy: self-replicating geometry constructed from trash.  They can be used for media of all kinds, with paper glued to them in layers, flowing from person to person and place to place as a the medium in a trash magic economy.  

![](https://github.com/LafeLabs/trashmagic/blob/main/media/trashmagic/icosahedron.svg) 





