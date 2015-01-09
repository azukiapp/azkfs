#!/usr/bin/env bats

load ../test_helper

@test "$test_label module loading and unloading" {
  run load_module
  assert_success

  run check_module_loaded
  assert_success

  run unload_module
  assert_success

  run check_module_loaded
  assert_failure
}
