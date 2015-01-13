CURRENT_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

load $CURRENT_DIR/support/assertions.bash
load $CURRENT_DIR/support/commons.bash

# Global tests setup and teardown
teardown() {
  # unmount test image
  if mount | grep /tmp/test_dir &>/dev/null; then
    run umount_test_image
  fi

  # unload test module
  if lsmod | grep $MODULE_NAME &>/dev/null; then
    rmmod $MODULE_NAME
  fi
}
