#pragma once
/* Do NOT redefine firehose_push_reply_t — XNU provides it. */
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Real type comes from firehose_types_private.h when included.
   Use the XNU name only after that header, or accept void* for link stubs. */
struct firehose_push_reply_s; /* forward, matches XNU */

bool __firehose_merge_updates(struct firehose_push_reply_s reply);
bool __firehose_kernel_configuration_valid(unsigned long chunk_count, unsigned long io_pages);
void *__firehose_buffer_create(size_t *size_out);

#ifdef __cplusplus
}
#endif
