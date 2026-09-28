#include "fireworker/sched.h"
extern struct fw_task *task_table(void); static bool initialized;
fw_status_t scheduler_init(void){initialized=true;return FW_OK;}
struct fw_task *scheduler_pick(void){if(!initialized)return 0;struct fw_task*t=task_table(),*best=0;for(unsigned i=0;i<FW_MAX_TASKS;i++)if(t[i].runnable&&(!best||t[i].priority>best->priority))best=&t[i];return best;}
