/*
 * Superblock headers
 */

#ifndef SUPER_H
#define SUPER_H

static uint32_t const AZKFS_MAGIC_NUMBER = 0x13131313;

void azkfs_put_super(struct super_block *sb);

static struct super_operations const azkfs_super_ops = {
    .put_super = azkfs_put_super,
};

int azkfs_fill_sb(struct super_block *sb, void *data, int silent);

struct dentry *azkfs_mount(struct file_system_type *type, int flags,
                                      char const *dev, void *data);

#endif /* not defined SUPER_H */
