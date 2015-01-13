p() {
  echo "$@" >&2
  exit 1000
}

load_module () {
  insmod modkernel/$MODULE_NAME.ko
  lsmod | grep $MODULE_NAME
}

unload_module () {
  rmmod $MODULE_NAME
}

check_module_loaded () {
  lsmod | grep $MODULE_NAME
}

mount_test_image () {
  touch /tmp/test_image
  mkdir -p /tmp/test_dir
  mount -o loop -t azkfs /tmp/test_image /tmp/test_dir
}

umount_test_image () {
  umount /tmp/test_dir
}

