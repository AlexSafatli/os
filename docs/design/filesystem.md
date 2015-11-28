## Filesystem

In line with [a philosophy](http://suckless.org/philosophy) documented at 
the [**suckless**](http://suckless.org) project site, some ideas will be 
borrowed from brainstorming for a filesystem found 
[here](http://sta.li/filesystem).

### Hierarchy

Like in **Linux**, there will be a `/` (*root*) directory which serves as the 
root of the filesystem. Within that directory, the essential components of the 
operating systems will be found, and detailed below.

    /
        /bin/
        /sys/
            /cfg/
            /boot/
            /proc/
            /dev/
        /inc/
        /lib/
        /mount/
        /docs/
        /logs/
        /home/

The user directories would be located within `/home/`, keeping the name as 
found in UNIX-based operating systems to prevent confusion amongst current 
system users. No `/usr/` directory will be present in the system.
