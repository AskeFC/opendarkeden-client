# client

## compile

The code compiles on Win10, VC6 is used.

Get the xerces-c lib 3.2.3, unzip it to the client project root path.
You can get it from the internet or here is a [mirror file](https://github.com/opendarkeden/client/raw/data/xerces-c-3.2.3.zip).

The directory then looks like this:

```
$ ls -lah
total 202K
drwxr-xr-x 1 genius 197121   0 Jun  9 10:21 ./
drwxr-xr-x 1 genius 197121   0 Jun  9 09:53 ../
drwxr-xr-x 1 genius 197121   0 Jun  9 10:21 .git/
-rw-r--r-- 1 genius 197121 384 Jun  9 10:13 .gitignore
...
drwxr-xr-x 1 genius 197121   0 Oct 10  2015 xerces/
```

Get the directx9 lib, it's staled and hard to find, here is a [mirror file](https://github.com/opendarkeden/client/raw/data/dx90bsdk.zip).
Extract it to someplace, and add it to the VC6 Include & Library directory:

![image](https://user-images.githubusercontent.com/1420062/121283362-8949b900-c90d-11eb-8a7e-eeac6eb4135b.png)
![image](https://user-images.githubusercontent.com/1420062/121283745-3a505380-c90e-11eb-91cc-2c6ecfd76479.png)

You can put it to any path, not necessarily Game(800)


Open workspace client/Client/Client.dsw in VC6, everything should work.

## run

Download the [Data files](https://pan.baidu.com/s/1-DufSEmnydMbOtTwOo_h8A) 6bcl (TODO: put it somewhere else?), extract it to `client/DARKEDEN`, run "window.bat"

Modify the IP/Port in `DARKEDEN/Data/GameClientInfo.inf` to your own login server IP/Port.

You can see "window.bat" is a simple script that run "fengshen.exe" with a argument:

```
fengshen.exe 0000000001 
```

The meaning of the argument:

- 0000000001 windowmode
- 0000000002 fullscreen
- 0000000003 windowmode 1024
- 0000000004 fullscreen 1024


You need the [server](https://github.com/opendarkeden/server) to get it run. (TODO: pack the server in docker so run the standalone on Win10 become easy)
