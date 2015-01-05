obj-m := azkfs.o
azkfs-objs := super.o

CFLAGS_super.o := -DDEBUG

all:
	make -C /linux-kernel M=$(PWD) modules

clean:
	make -C /linux-kernel M=$(PWD) clean
