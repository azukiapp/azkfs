obj-m := azkfs.o
azkfs-objs := mount.o

CFLAGS_mount.o := -DDEBUG

all:
	make -C /linux-kernel M=$(PWD) modules

clean:
	make -C /linux-kernel M=$(PWD) clean
