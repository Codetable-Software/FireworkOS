#include "fireworker/ipc.h"
#include <assert.h>
#include <stdio.h>
int main(void){int s[2],x=7,y=0;struct fw_queue q;assert(fw_queue_init(&q,s,sizeof(int),2)==0);assert(fw_queue_push(&q,&x)==0);assert(fw_queue_count(&q)==1);assert(fw_queue_pop(&q,&y)==0);assert(y==7);assert(fw_queue_pop(&q,&y)==FW_ENOENT);puts("test_queue: PASS");return 0;}
