#include "firehose_kernel_stub.h"

bool __firehose_merge_updates(firehose_push_reply_t reply) {
  (void)reply;
  return false;
}
bool __firehose_kernel_configuration_valid(unsigned long chunk_count, unsigned long io_pages) {
  (void)chunk_count; (void)io_pages;
  return true; /* pretend valid so log path continues */
}
void *__firehose_buffer_create(size_t *size_out) {
  if (size_out) *size_out = 0;
  return (void *)0;
}
void __firehose_allocate(void) {}
void __firehose_kernel_unused_stub(void) {}
