#include<iostream>
#include "date.h"

using namespace std;

bool date::is_date(date& s, date& e) {
	if (year >= s.year && year <= e.year) {
		if (month >= s.month && month <= e.month) {
			if (month == s.month) {
				if (day >= s.day)
					return true;
			}
			else if (month == e.month) {
				if (day <= e.day)
					return true;
			}
			else
				return true;
		}
	}
	return false;
}

bool date::check_date(int d, int m, int y) {
	if (y % 4 == 0) {
		if (m == 2) {
			if (d <= 29 && d > 0)
				return true;
		}
	}
	else {
		if (m == 2) {
			if (d <= 28 && d > 0)
				return true;
		}
	}
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
		if (d <= 31 && d > 0)
			return true;
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11) {
		if (d <= 30 && d > 0)
			return true;
	}
	return false;
}

void date::input() {
	int d, m, y;
	char c1, c2;
	while (true) {
		cin >> d >> c1 >> m >> c2 >> y;
		if (c1 != '\\' || c2 != '\\')
			cout << "Format error." << endl;
		if (!check_date(d, m, y))
			cout << "Unexpected/Worng date entered." << endl;
		else {
			day = d, month = m, year = y;
			return;
		}
		cout << "Please Enter date again." << endl;
	}
}

void date::display() {
	cout << day << "\\" << month << "\\" << year;
}