int fw_signal_pending(unsigned *mask,unsigned bit){if(!mask||bit>=32)return -1;*mask|=1u<<bit;return 0;}
