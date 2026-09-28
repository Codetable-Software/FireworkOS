#ifndef FW_SCHED_H
#define FW_SCHED_H
#include "types.h"
#define FW_MAX_TASKS 32
struct fw_task { unsigned id, priority; bool runnable; uint8_t *stack; size_t stack_size; };
fw_status_t scheduler_init(void); fw_status_t task_create(struct fw_task*, unsigned, unsigned, void*, size_t); struct fw_task *scheduler_pick(void);
#endif
