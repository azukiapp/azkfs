# azkfs

Build module:

```shell
azk shell
cd modkernel
make
```

Load and test:

```shell
azk shell

# Loading module
insmod ./azkfs.ko
lsmod | grep azkfs

# Mounting an image to a directory using azkfs
cd /tmp
touch test_image
mkdir test_dir
mount -o loop -t azkfs ./test_image ./test_dir

# Umounting that dir
umount ./test_dir

# Unloading module
rmmod azkfs

# Inspecting logs
dmesg | tail
```

# References

- http://kukuruku.co/hub/nix/writing-a-file-system-in-linux-kernel
- http://lxr.free-electrons.com/source/fs/ramfs/
- https://github.com/krinkinmu/aufs
- https://github.com/psankar/simplefs
- https://github.com/zz2/simplefs
- http://www.tldp.org/LDP/tlk/fs/filesystem.html
- http://www.cyberciti.biz/tips/understanding-unixlinux-file-system-part-i.html
- http://teaching.idallen.com/cst8207/13w/notes/450_file_system.html

## License

"Azuki", "Azk" and the Azuki logo are copyright (c) 2013-2015 Azuki Serviços de Internet LTDA.

Azk source code is released under Apache 2 License.

Check LEGAL and LICENSE files for more information.

