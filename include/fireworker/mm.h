#ifndef FW_MM_H
#define FW_MM_H
#include "types.h"
void *kmalloc(size_t size); void kfree(void *ptr); size_t kheap_used(void); bool kheap_owns(const void *ptr);
#endif
