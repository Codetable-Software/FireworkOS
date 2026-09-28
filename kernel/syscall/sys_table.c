typedef long (*sys_fn)(long,long,long,long); long sys_nosys(long a,long b,long c,long d){(void)a;(void)b;(void)c;(void)d;return -38;} sys_fn fw_sys_table[]={sys_nosys};
