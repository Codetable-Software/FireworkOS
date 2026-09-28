#include "sys/syscall.h"
#include <stdint.h>
#include <stddef.h>
static uintptr_t user_lo=0x1000, user_hi=0x0000800000000000ULL;
bool is_valid_user_address(const void*p,size_t n){uintptr_t a=(uintptr_t)p;if(!p||a<user_lo||a>user_hi)return false;if(n>user_hi-a)return false;return true;}
extern int safe_memcpy(void*,size_t,const void*,size_t);
fw_status_t fw_sys_read_user(void*dst,const void*user,size_t n){if(!dst||!is_valid_user_address(user,n)||n>65536)return FW_EFAULT;return safe_memcpy(dst,n,user,n)==0?FW_OK:FW_EFAULT;}
