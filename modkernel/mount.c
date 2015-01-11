/*
 * Superblock functions
 */

#include <linux/fs.h>

#include "mount.h"
#include "inode.h"

void azkfs_put_super(struct super_block *sb)
{
  pr_debug("azkfs super block destroyed\n");
}

int azkfs_fill_sb(struct super_block *sb, void *data, int silent)
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

struct dentry *azkfs_mount(struct file_system_type *type, int flags,
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
