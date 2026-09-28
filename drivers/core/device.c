#include "drivers/device.h"
static struct fw_device devs[64]; static size_t n;
extern size_t kstrlcpy(char*,const char*,size_t);
fw_status_t device_register(struct fw_device*d){if(!d||!d->name[0]||n>=64)return FW_EINVAL;if(device_find(d->name))return FW_EEXIST;devs[n]=*d;devs[n].id=(unsigned)n+1;devs[n].bound=true;n++;return FW_OK;}
struct fw_device *device_find(const char*name){if(!name)return 0;for(size_t i=0;i<n;i++){size_t j=0;while(devs[i].name[j]&&name[j]&&devs[i].name[j]==name[j])j++;if(!devs[i].name[j]&&!name[j])return &devs[i];}return 0;}
size_t device_count(void){return n;}
