#include "module.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
int main(void){uint8_t e[32]={0x7f,'E','L','F',1,1};e[18]=0xF3;e[19]=0;assert(fw_elf_validate(e,sizeof(e),0xF3)==0);e[0]=0;assert(fw_elf_validate(e,sizeof(e),0xF3)!=0);puts("test_elf_loader: PASS");return 0;}
