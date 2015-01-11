/*
 * Inode headers
 */

#ifndef INODE_H
#define INODE_H

#include <linux/fs.h>

int azkfs_inode_create(struct inode *dir, struct dentry *dentry,
         umode_t mode, bool excl);

static struct inode_operations azkfs_inode_ops = {
  .create = azkfs_inode_create,
  // .lookup = azkfs_inode_lookup,
  // .mkdir = azkfs_inode_mkdir,
};


#endif /* not defined INODE_H */
