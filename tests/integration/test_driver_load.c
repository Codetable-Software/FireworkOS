#include "drivers/device.h"
#include <assert.h>
#include <stdio.h>
int main(void){struct fw_device d={0};d.name[0]='u';d.name[1]='a';d.name[2]='r';d.name[3]='t';assert(device_register(&d)==0);assert(device_find("uart")!=0);assert(device_count()==1);puts("test_driver_load: PASS");return 0;}
