int fw_bus_match(const char*a,const char*b){if(!a||!b)return 0;while(*a&&*b&&*a==*b){a++;b++;}return *a==*b;}
