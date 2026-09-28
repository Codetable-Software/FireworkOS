struct fw_driver{const char*name;int(*probe)(void*);}; int driver_bind(struct fw_driver*d,void*p){return d&&d->probe?d->probe(p):-1;}
