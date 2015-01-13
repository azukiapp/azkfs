#!/usr/bin/env bats

load ../test_helper

@test "$test_label listing the root folder contents" {
  list_root () {
    ls /tmp/test_dir
  }

  run load_module
  run mount_test_image
  assert_success

  run list_root
  assert_success

  run umount_test_image
  assert_success

  run unload_module
}
