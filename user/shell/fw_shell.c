#include <stddef.h>
#include <stdio.h>
extern int ksnprintf(char*,size_t,const char*,...);
static int eq(const char*a,const char*b){while(*a&&*b&&*a==*b){a++;b++;}return *a==*b;}
int fw_shell_execute(const char*line,char*out,size_t cap){if(!line||!out||!cap)return -1;if(eq(line,"help"))return ksnprintf(out,cap,"help ps mem loadmod sysinfo");if(eq(line,"ps"))return ksnprintf(out,cap,"PID 0 idle");if(eq(line,"mem"))return ksnprintf(out,cap,"heap available");if(eq(line,"sysinfo"))return ksnprintf(out,cap,"FireworkOS/fireworker host");if(eq(line,"loadmod"))return ksnprintf(out,cap,"module verification required");return ksnprintf(out,cap,"unknown command");}
