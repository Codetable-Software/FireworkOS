#include "fireworker/ipc.h"
#include <stdint.h>
fw_status_t fw_queue_init(struct fw_queue*q,void*storage,size_t item,size_t cap){if(!q||!storage||!item||!cap||cap>1024)return FW_EINVAL;q->storage=storage;q->item_size=item;q->capacity=cap;q->head=q->tail=q->count=0;return FW_OK;}
fw_status_t fw_queue_push(struct fw_queue*q,const void*item){if(!q||!item)return FW_EINVAL;if(q->count==q->capacity)return FW_EBUSY;uint8_t*d=q->storage+q->tail*q->item_size;const uint8_t*s=item;for(size_t i=0;i<q->item_size;i++)d[i]=s[i];q->tail=(q->tail+1)%q->capacity;q->count++;return FW_OK;}
fw_status_t fw_queue_pop(struct fw_queue*q,void*out){if(!q||!out)return FW_EINVAL;if(!q->count)return FW_ENOENT;uint8_t*d=q->storage+q->head*q->item_size;uint8_t*s=out;for(size_t i=0;i<q->item_size;i++)s[i]=d[i];q->head=(q->head+1)%q->capacity;q->count--;return FW_OK;}
size_t fw_queue_count(const struct fw_queue*q){return q?q->count:0;}
