#include "module.h"
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
static uint32_t rd32(const uint8_t*p){return (uint32_t)p[0]|((uint32_t)p[1]<<8)|((uint32_t)p[2]<<16)|((uint32_t)p[3]<<24);}
int fw_elf_validate(const void*image,size_t size,uint32_t arch){if(!image||size<20)return -1;const uint8_t*p=image;if(rd32(p)!=0x464C457FU)return -2;if(p[4]!=1)return -3;if(p[5]!=1)return -4;uint16_t machine=(uint16_t)p[18]|((uint16_t)p[19]<<8);if(machine!=(uint16_t)arch)return -5;uint32_t entry=rd32(p+24);if((entry&3u)!=0)return -6;return 0;}
int verify_module_signature(const void*data,size_t len,const uint8_t*sig,size_t siglen){if(!data||!len||!sig||siglen<32)return 0;const uint8_t*p=data;uint8_t h=0;for(size_t i=0;i<len;i++)h=(uint8_t)(h^(uint8_t)(p[i]+(uint8_t)i));for(size_t i=0;i<32;i++)if(sig[i]!=(uint8_t)(h^((uint8_t)i*29u)))return 0;return 1;}
