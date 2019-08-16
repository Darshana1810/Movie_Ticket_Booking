#include "time_date.h"
#include <iostream>

using namespace std;

//intializes time
void time::gettime() {
	unsigned int h, m;
	char c;
	while (true) {
		cin >> h >> c >> m;
		if (h > 23 || m > 59 || c != ':') {
			cout << endl << "Error while reading time";
		}
		else {
			hh = h, mm = m;
			return;
		}
	}
}

void time::showtime(){
	cout << hh << ":" << mm;
}

bool check_time(time a,time b){
	if (a.hh == b.hh && a.mm == b.mm) {
		return true;
	}
	return false;
}
