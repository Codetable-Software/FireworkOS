#ifndef FW_SYSCALL_H
#define FW_SYSCALL_H
#include "../fireworker/types.h"
fw_status_t fw_sys_read_user(void*, const void*, size_t); bool is_valid_user_address(const void*, size_t);
#endif
