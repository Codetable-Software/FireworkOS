#include "fireworker/sched.h"
static struct fw_task tasks[FW_MAX_TASKS]; static unsigned nextid;
fw_status_t task_create(struct fw_task*t,unsigned prio,unsigned id,void*stack,size_t size){if(!t||!stack||size<64)return FW_EINVAL;t->id=id?id:++nextid;t->priority=prio;t->runnable=true;t->stack=stack;t->stack_size=size;tasks[t->id%FW_MAX_TASKS]=*t;return FW_OK;}
struct fw_task *task_table(void){return tasks;}
