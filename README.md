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
insmod ./azkfs.ko
lsmod | grep azkfs
rmmod azkfs
dmesg | tail
```

# References

- http://kukuruku.co/hub/nix/writing-a-file-system-in-linux-kernel
- http://lxr.free-electrons.com/source/fs/ramfs/
- https://github.com/krinkinmu/aufs
- https://github.com/psankar/simplefs

## License

"Azuki", "Azk" and the Azuki logo are copyright (c) 2013-2015 Azuki Serviços de Internet LTDA.

Azk source code is released under Apache 2 License.

Check LEGAL and LICENSE files for more information.

