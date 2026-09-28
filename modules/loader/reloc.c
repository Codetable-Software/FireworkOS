#include <stdint.h>
int fw_relocate(uintptr_t base,int32_t off){return (base+(intptr_t)off)!=0?0:-1;}
