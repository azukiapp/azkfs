MODULE_NAME := azkfs
obj-m := ${MODULE_NAME}.o
${MODULE_NAME}-objs := main.o mount.o inode.o file.o

CFLAGS_main.o := -DDEBUG
CFLAGS_mount.o := -DDEBUG
CFLAGS_inode.o := -DDEBUG
CFLAGS_file.o := -DDEBUG

all:
	make -C /linux-kernel M=$(PWD) modules

clean:
	make -C /linux-kernel M=$(PWD) clean
