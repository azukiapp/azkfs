MODULE_NAME := azkfs
obj-m := ${MODULE_NAME}.o
${MODULE_NAME}-objs := mount.o

CFLAGS_mount.o := -DDEBUG

all:
	make -C /linux-kernel M=$(PWD) modules

clean:
	make -C /linux-kernel M=$(PWD) clean
