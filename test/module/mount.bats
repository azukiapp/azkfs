#!/usr/bin/env bats

load ../test_helper

@test "$test_label mounting and unmounting a file system" {
  run load_module
  run mount_test_image
  assert_success

  run umount_test_image
  assert_success

  run unload_module
}
