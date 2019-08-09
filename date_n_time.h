#pragma once
#include<string.h>

class date {
	int month, day;
	char day_of_week[10];
	bool isTrue(int m, int d, char dw[]);
public:
	date() :month(0), day(0), day_of_week("") {}
	date(int m, int d, char dw[]) {
		if (isTrue(m, d, dw)) {
			month = m, day = d;
			strcpy(day_of_week, dw);
		}
	}
};

class time {
	int hour, minute;
	bool isTure(int h, int m);
public:
	time() :hour(0), minute(0) {}
	time(int h, int m) {
		if (isTure(h, m))
			hour = h, minute = m;
	}
};