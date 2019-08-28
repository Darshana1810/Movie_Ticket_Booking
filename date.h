#pragma once
#include <iostream>

using namespace std;

class date {
	int day, month, year;
public:
	date():day(0),month(0),year(0){}
	void input();
	void display();
	bool check_date(int d, int m, int y);
	bool is_date(date& a, date& b);
};