#include "fireworker/mm.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#define HEAP_MAGIC 0xF17ECAFEu
#define FREE_MAGIC 0xDEADBEEFu
struct hdr {uint32_t magic; size_t size; bool freed; struct hdr *next;};
static struct hdr *head; static size_t used;
void *kmalloc(size_t size){if(!size||size>1024*1024)return NULL;struct hdr*h=malloc(sizeof(*h)+size);if(!h)return NULL;h->magic=HEAP_MAGIC;h->size=size;h->freed=false;h->next=head;head=h;used+=size;uint8_t*p=(uint8_t*)(h+1);for(size_t i=0;i<size;i++)p[i]=0xAA;return p;}
void kfree(void*p){if(!p)return;struct hdr*h=((struct hdr*)p)-1;if(h->magic!=HEAP_MAGIC||h->freed)return;h->freed=true;uint8_t*b=p;for(size_t i=0;i<h->size;i++)b[i]=0xAA;used-=h->size;h->magic=FREE_MAGIC;}
size_t kheap_used(void){return used;} bool kheap_owns(const void*p){if(!p)return false;for(struct hdr*h=head;h;h=h->next)if((void*)(h+1)==p)return h->magic==HEAP_MAGIC&&!h->freed;return false;}
