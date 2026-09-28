#include <stdio.h>
#include <stdarg.h>
int fw_printf(const char *fmt,...){va_list ap;va_start(ap,fmt);int r=vprintf(fmt,ap);va_end(ap);return r;}
