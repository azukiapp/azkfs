/*
 * File headers
 */

#ifndef FILE_H
#define FILE_H

#include <linux/fs.h>

static struct file_operations azkfs_file_operations = {
  // .read = azkfs_read,
  // .write = azkfs_write,
};

int azkfs_iterate(struct file *filp, struct dir_context *ctx);

static struct file_operations azkfs_dir_operations = {
  .owner = THIS_MODULE,
  .iterate = azkfs_iterate,
};

#endif /* not defined FILE_H */
