#pragma once
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/* Minimal opaque types so open XNU compiles without Apple firehose */
typedef struct { uint64_t opaque[4]; } firehose_push_reply_t;

#ifdef __cplusplus
extern "C" {
#endif

bool __firehose_merge_updates(firehose_push_reply_t reply);
bool __firehose_kernel_configuration_valid(unsigned long chunk_count, unsigned long io_pages);
void *__firehose_buffer_create(size_t *size_out);

/* extras some versions reference */
void __firehose_allocate(void);
void __firehose_kernel_unused_stub(void);

#ifdef __cplusplus
}
#endif
