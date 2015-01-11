/*
 * Inode functions
 */

#include <linux/fs.h>

#include "inode.h"
#include "file.h"

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

int azkfs_inode_create(struct inode *dir, struct dentry *dentry,
         umode_t mode, bool excl)
{
  return azkfs_create_fs_object(dir, dentry, mode);
}

