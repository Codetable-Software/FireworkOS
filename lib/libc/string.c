#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
static size_t fw_len(const char*s){size_t n=0;if(!s)return 0;while(s[n])n++;return n;}
size_t kstrlcpy(char *dst,const char*src,size_t cap){size_t n=fw_len(src);if(cap){size_t c=n<cap-1?n:cap-1;for(size_t i=0;i<c;i++)dst[i]=src[i];dst[c]=0;}return n;}
size_t kstrlcat(char *dst,const char*src,size_t cap){size_t d=fw_len(dst),s=fw_len(src);if(d<cap){size_t c=s<cap-d-1?s:cap-d-1;for(size_t i=0;i<c;i++)dst[d+i]=src[i];dst[d+c]=0;}return d+s;}
int safe_memcpy(void *dst,size_t dstsz,const void*src,size_t n){if(!dst||!src||n>dstsz)return -1;uint8_t*d=dst;const uint8_t*s=src;for(size_t i=0;i<n;i++)d[i]=s[i];return 0;}
int safe_memset(void*dst,size_t dstsz,int v,size_t n){if(!dst||n>dstsz)return -1;uint8_t*d=dst;for(size_t i=0;i<n;i++)d[i]=(uint8_t)v;return 0;}
int ksnprintf(char*out,size_t cap,const char*fmt,...){if(!out||!cap||!fmt)return -1;va_list ap;va_start(ap,fmt);size_t p=0;for(size_t i=0;fmt[i]&&p+1<cap;i++){if(fmt[i]!='%'){out[p++]=fmt[i];continue;}i++;if(!fmt[i])break;if(fmt[i]=='s'){const char*s=va_arg(ap,const char*);if(!s)s="(null)";while(*s&&p+1<cap)out[p++]=*s++;}else if(fmt[i]=='d'){int v=va_arg(ap,int);char b[16];size_t n=0;unsigned x=(v<0)?(unsigned)(-v):(unsigned)v;if(v<0&&p+1<cap)out[p++]='-';do{b[n++]=(char)('0'+x%10U);x/=10U;}while(x);while(n&&p+1<cap)out[p++]=b[--n];}else if(fmt[i]=='%'){out[p++]='%';}else {if(p+1<cap)out[p++]='?';}}
out[p]=0;va_end(ap);return (int)p;}
