#ifndef FW_TYPES_H
#define FW_TYPES_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
typedef int32_t fw_status_t;
#define FW_OK 0
#define FW_EINVAL (-22)
#define FW_ENOMEM (-12)
#define FW_EPERM (-1)
#define FW_EFAULT (-14)
#define FW_EBUSY (-16)
#define FW_ENOENT (-2)
#define FW_EEXIST (-17)
#define FW_EOVERFLOW (-75)
#define FW_EBADF (-9)
#define FW_MIN(a,b) ((a)<(b)?(a):(b))
#define FW_MAX(a,b) ((a)>(b)?(a):(b))
#define FW_ARRAY_SIZE(a) (sizeof(a)/sizeof((a)[0]))
#endif
