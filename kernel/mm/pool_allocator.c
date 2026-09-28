#include <stddef.h>
#include "fireworker/types.h"
void pool_zero(void*p,size_t n){if(!p)return;unsigned char*b=p;for(size_t i=0;i<n;i++)b[i]=0;}
