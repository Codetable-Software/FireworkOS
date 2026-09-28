#ifndef FW_MODULE_H
#define FW_MODULE_H
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#define FW_ELF_MAGIC 0x464C457FU
struct fw_module {void *image; size_t size; uint32_t arch; bool verified;};
int verify_module_signature(const void*,size_t,const uint8_t*,size_t);
int fw_elf_validate(const void*,size_t,uint32_t);
#endif
