#pragma once
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Incomplete type OK if we only pass pointers */
struct firehose_push_reply_s;

bool __firehose_merge_updates(struct firehose_push_reply_s *reply);
bool __firehose_kernel_configuration_valid(unsigned long chunk_count, unsigned long io_pages);
void *__firehose_buffer_create(size_t *size_out);

#ifdef __cplusplus
}
#endif
