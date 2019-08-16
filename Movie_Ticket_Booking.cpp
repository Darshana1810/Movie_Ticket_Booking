// Movie_Ticket_Booking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include "time_date.h"
#include "movieuser_info.h"

using namespace std;

class dat {
	movie_info mlist[5];
	user_info ulist[5];
	int movie_count, user_count;
public:
	void Options();
	dat() :movie_count(0), user_count(0) {}
};

void dat::Options() {
	int opt;
	cout << endl << "1.Add movie";
	cout << endl << "2.Display movies";
	cout << endl << "3.Book Ticket";
	cout << endl << "4.View booked tickets";
	cout << endl << "5.Exit";
	cin >> opt;
	switch (opt) {
	case 1:
		mlist[movie_count++].input();
		break;
	case 2:
		for (int i = 0; i < movie_count; i++)
			mlist[i].display();
		break;
	case 3:
		ulist[user_count++].input(mlist);
		break;
	case 4:
		for (int i = 0; i < user_count; i++)
			ulist[i].display();
		break;
	case 5:
		exit(0);
	}
}

int main(){
	dat d;
	while(true)
	d.Options();
}