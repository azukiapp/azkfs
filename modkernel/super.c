#include <linux/init.h>
#include <linux/module.h>

static int __init azkfs_init(void) {
    pr_debug("azkfs module loaded\n");
    return 0;
}

static void __exit azkfs_fini(void) {
    pr_debug("azkfs module unloaded\n");
}

module_init(azkfs_init);
module_exit(azkfs_fini);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("kmu");
