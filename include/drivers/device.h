#ifndef FW_DEVICE_H
#define FW_DEVICE_H
#include "../fireworker/types.h"
#define FW_DEVICE_NAME_MAX 32
struct fw_device { char name[FW_DEVICE_NAME_MAX]; unsigned id; bool bound; void *priv; };
fw_status_t device_register(struct fw_device*); struct fw_device *device_find(const char*); size_t device_count(void);
#endif
