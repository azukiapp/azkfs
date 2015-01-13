/*
 * File functions
 */

#include "file.h"

int azkfs_iterate(struct file *filp, struct dir_context *ctx)
{
  pr_debug("azkfs: azkfs_iterate\n");

  if (ctx->pos) {
    /* Comment from simplefs source code:
     *
     * FIXME: We use a hack of reading pos to figure if we have filled in all data.
     * We should probably fix this to work in a cursor based model and
     * use the tokens correctly to not fill too many data in each cursor based call */
    return 0;
  }

  int i;
  char file_name[6];

  /*
   * Generating some fake entries to make `ls` works
   */
  for(i = 0; i < 10; i++) {
    sprintf(file_name, "file_%d", i);
    dir_emit(ctx, file_name, 6, 10 + i, DT_UNKNOWN);
    ctx->pos += 1;
  }

  return 0;
}
