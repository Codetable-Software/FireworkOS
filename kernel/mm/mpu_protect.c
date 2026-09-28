#include "fireworker/types.h"
#include <stdint.h>
struct fw_mpu_region {uintptr_t base; size_t size; uint32_t attr;};
static struct fw_mpu_region guard;
fw_status_t mpu_stack_guard_configure(void *stack,size_t size){if(!stack||size<32)return FW_EINVAL;guard.base=(uintptr_t)stack;guard.size=32;guard.attr=0;return FW_OK;}
bool mpu_address_allowed(uintptr_t addr,size_t len){if(len>0xFFFFFFFFu-addr)return false;if(addr<guard.base+guard.size&&addr+len>guard.base)return false;return true;}
