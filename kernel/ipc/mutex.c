#include "fireworker/ipc.h"
void fw_mutex_init(struct fw_mutex*m){m->locked=0;m->owner=0;m->owner_priority=0;}
fw_status_t fw_mutex_lock(struct fw_mutex*m,unsigned id,unsigned prio){if(!m)return FW_EINVAL;if(!m->locked){m->locked=1;m->owner=id;m->owner_priority=prio;return FW_OK;}if(m->owner_priority<prio)m->owner_priority=prio;return FW_EBUSY;}
fw_status_t fw_mutex_unlock(struct fw_mutex*m,unsigned id){if(!m||!m->locked||m->owner!=id)return FW_EPERM;m->locked=0;m->owner=0;m->owner_priority=0;return FW_OK;}
