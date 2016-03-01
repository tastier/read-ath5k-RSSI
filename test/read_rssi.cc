#include <iostream>
#include <fstream>
#include <memory.h>
#include <unistd.h>
#include <stdio.h>
using namespace std;

struct recv_rssi {
	int signal;
	unsigned char mac_addr[6];
};

int main()
{
	ifstream infile;
	recv_rssi rssi;

	while(1) {
		memset(&rssi, 0, sizeof(rssi));
		infile.open("/proc/ath5k_rssi", ifstream::binary);
		infile.read((char*)&rssi, sizeof(recv_rssi));
		printf("tx signal level = %d  ", rssi.signal);
		printf("tx mac addr = %x:%x:%x:%x:%x:%x \n",
				rssi.mac_addr[0], rssi.mac_addr[1], rssi.mac_addr[2],
				rssi.mac_addr[3], rssi.mac_addr[4], rssi.mac_addr[5]
				);
		infile.close();
		sleep(1);
	}
}
