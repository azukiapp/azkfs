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


#endif /* not defined FILE_H */
