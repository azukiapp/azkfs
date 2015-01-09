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

