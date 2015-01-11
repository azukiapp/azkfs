#include <linux/fs.h>
#include <linux/init.h>
#include <linux/module.h>

#include "mount.h"

/*
 * Kernel module setup
 */

static struct file_system_type azkfs_type = {
  .owner = THIS_MODULE,
  .name = "azkfs",
  .mount = azkfs_mount,
  .kill_sb = kill_block_super,
  .fs_flags = FS_REQUIRES_DEV
};

static int __init azkfs_init(void) {
  int ret = register_filesystem(&azkfs_type);

  if (ret != 0) {
    pr_err("cannot register filesystem\n");
    return ret;
  }

  pr_debug("azkfs module loaded\n");
  return 0;
}

static void __exit azkfs_exit(void)
{
  int ret;

  ret = unregister_filesystem(&azkfs_type);

  if (likely(ret == 0))
    printk(KERN_INFO "Sucessfully unregistered azkfs\n");
  else
    printk(KERN_ERR "Failed to unregister azkfs. Error:[%d]",
           ret);
}

module_init(azkfs_init);
module_exit(azkfs_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("kmu");
