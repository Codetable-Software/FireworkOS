#ifndef FW_IPC_H
#define FW_IPC_H
#include "types.h"
#define FW_QUEUE_CAPACITY 16
struct fw_queue { uint8_t *storage; size_t item_size, capacity, head, tail, count; };
fw_status_t fw_queue_init(struct fw_queue*, void*, size_t, size_t); fw_status_t fw_queue_push(struct fw_queue*, const void*); fw_status_t fw_queue_pop(struct fw_queue*, void*); size_t fw_queue_count(const struct fw_queue*);
struct fw_mutex { int locked; unsigned owner; unsigned owner_priority; };
void fw_mutex_init(struct fw_mutex*); fw_status_t fw_mutex_lock(struct fw_mutex*, unsigned task_id, unsigned priority); fw_status_t fw_mutex_unlock(struct fw_mutex*, unsigned task_id);
#endif
