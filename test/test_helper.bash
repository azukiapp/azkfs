CURRENT_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

load $CURRENT_DIR/support/assertions.bash
load $CURRENT_DIR/support/commons.bash

# Global tests setup and teardown
teardown() {
  # unload module
  if lsmod | grep $MODULE_NAME &>/dev/null; then
    rmmod $MODULE_NAME
  fi
}
