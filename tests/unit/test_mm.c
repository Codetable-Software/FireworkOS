#include "fireworker/mm.h"
#include <assert.h>
#include <stdio.h>
int main(void){void*a=kmalloc(64);assert(a);assert(kheap_owns(a));assert(kheap_used()==64);kfree(a);assert(!kheap_owns(a));kfree(a);assert(kheap_used()==0);puts("test_mm: PASS");return 0;}
