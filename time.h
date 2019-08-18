#pragma once

//stores time
class time {
	unsigned int hh, mm;
public:
	time() :hh(0), mm(0) {}
	time(unsigned int a, unsigned int b) :hh(a), mm(b) {}
	time(time& t) :hh(t.hh), mm(t.mm) {}
	void gettime();
	void showtime();
	friend bool check_time(time a, time b);
};

bool check_time(time a, time b);