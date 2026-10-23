#include "firehose_kernel_stub.h"

bool __firehose_merge_updates(struct firehose_push_reply_s *reply) {
  (void)reply;
  return false;
}
bool __firehose_kernel_configuration_valid(unsigned long a, unsigned long b) {
  (void)a; (void)b;
  return true;
}
void *__firehose_buffer_create(size_t *size_out) {
  if (size_out) *size_out = 0;
  return (void *)0;
}
