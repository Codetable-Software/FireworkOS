#include "fireworker/kernel.h"
#include <stdio.h>
int main(void){int r=fireworker_init();printf("FireworkOS host simulator: init=%d\n",r);return r!=0;}
