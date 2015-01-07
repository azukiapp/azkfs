#include <linux/fs.h>
#include <linux/init.h>
#include <linux/module.h>

static uint32_t const AZKFS_MAGIC_NUMBER = 0x13131313;

/*
 * File functions
 */

const struct file_operations azkfs_file_operations = {
  // .read = azkfs_read,
  // .write = azkfs_write,
};

/*
 * Inode functions
 */
static int azkfs_inode_create(struct inode *dir, struct dentry *dentry,
         umode_t mode, bool excl);

static struct inode_operations azkfs_inode_ops = {
  .create = azkfs_inode_create,
  // .lookup = simplefs_lookup,
  // .mkdir = simplefs_mkdir,
};

void azkfs_inode_add(struct super_block *vsb, struct inode *inode)
{
}

static int azkfs_create_fs_object(struct inode *parent_dir_inode,
                                  struct dentry *dentry,
                                  umode_t mode)
{
  pr_debug("creating azkfs object");

  struct inode *inode;
  struct super_block *sb;

  sb = parent_dir_inode->i_sb;
  inode = new_inode(sb);

  inode->i_sb = sb;
  inode->i_op = &azkfs_inode_ops;
  inode->i_atime = inode->i_mtime = inode->i_ctime = CURRENT_TIME;
  inode->i_fop = &azkfs_file_operations;

  /* First get a free block and update the free map (TODO),
   * Then add inode to the inode store and update the sb inodes_count,
   * Then update the parent directory's inode with the new child.
   *
   * The above ordering helps us to maintain fs consistency
   * even in most crashes
   */
  azkfs_inode_add(sb, inode);
  // parent_dir_inode = AZKFS_INODE(dir);

}

static int azkfs_inode_create(struct inode *dir, struct dentry *dentry,
         umode_t mode, bool excl)
{
  return azkfs_create_fs_object(dir, dentry, mode);
}

/*
 * Superblock functions
 */

static void azkfs_put_super(struct super_block *sb)
{
  pr_debug("azkfs super block destroyed\n");
}

static struct super_operations const azkfs_super_ops = {
    .put_super = azkfs_put_super,
};

static int azkfs_fill_sb(struct super_block *sb, void *data, int silent)
{
  struct inode *root = NULL;

  sb->s_magic = AZKFS_MAGIC_NUMBER;
  sb->s_op = &azkfs_super_ops;

  root = new_inode(sb);
  if (!root)
  {
    pr_err("inode allocation failed\n");
    return -ENOMEM;
  }

  root->i_ino = 0;
  root->i_sb = sb;
  root->i_op = &azkfs_inode_ops;
  root->i_atime = root->i_mtime = root->i_ctime = CURRENT_TIME;
  inode_init_owner(root, NULL, S_IFDIR);

  sb->s_root = d_make_root(root);
  if (!sb->s_root)
  {
    pr_err("root creation failed\n");
    return -ENOMEM;
  }

  return 0;
}

static struct dentry *azkfs_mount(struct file_system_type *type, int flags,
                                      char const *dev, void *data)
{
  struct dentry *const entry = mount_bdev(type, flags, dev,
                                              data, azkfs_fill_sb);
  if (IS_ERR(entry))
      pr_err("azkfs mounting failed\n");
  else
      pr_debug("azkfs mounted\n");
  return entry;
}

static struct file_system_type azkfs_type = {
  .owner = THIS_MODULE,
  .name = "azkfs",
  .mount = azkfs_mount,
  .kill_sb = kill_block_super,
  .fs_flags = FS_REQUIRES_DEV
};

/*
 * Kernel module setup
 */

static int __init azkfs_init(void) {
  int ret = register_filesystem(&azkfs_type);

  if (ret != 0) {
    pr_err("cannot register filesystem\n");
    return ret;
  }

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
