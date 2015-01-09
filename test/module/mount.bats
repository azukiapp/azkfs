#!/usr/bin/env bats

load ../test_helper

@test "$test_label mounting and unmounting a file system" {
  mount_test_image () {
    touch /tmp/test_image
    mkdir -p /tmp/test_dir
    mount -o loop -t azkfs /tmp/test_image /tmp/test_dir
  }

  umount_test_image () {
    umount /tmp/test_dir
  }

  run load_module
  run mount_test_image
  assert_success

  run umount_test_image
  assert_success

  run unload_module
}
