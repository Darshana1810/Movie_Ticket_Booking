// Movie_Ticket_Booking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>

using namespace std;

//stores time
class time{
public:
	unsigned int hh, mm;
	time(unsigned int h, unsigned int m, time(&mt)[5]);
	time() :hh(0), mm(0) {}
	time(time& t);
};

//intializes time, used by user(during booking)
time::time(unsigned int h, unsigned int m,time (&mt)[5]) {
	if (h <= 23 && m <= 60) {
		if (check_movie_time(h, m, mt)) {
			hh = h, mm = m;
		}
	}
	else
		cout << "invalid time";
}

//copy constructor (used by admin)
time::time(time& t) {
	if (t.hh <= 23 && t.mm <= 60)
		hh = t.hh, mm = t.mm;
	else
		cout << "Invalid Time";
}

//check if movie is shown during entered time (h:m) (user)
bool check_movie_time(unsigned int h, unsigned int m, time (&mt)[5]) {
	for (time t : mt) {
		if (t.hh == h && t.mm == m) {
			return true;
		}
	}
	return false;
}

//used to store movie info (Admin+user)
class movie_info {
	char movie_name[30], state[20], city[15], location[15];
	time movie_time[5];
public:
	movie_info():movie_name(""),state(""),city(""),location(""),movie_time(){}
	movie_info(char mname[30], char st[20], char ct[15], char loc[15], time mtime[5]);
	friend bool check_movie_time(unsigned int h, unsigned int m, movie_info m_info);
};

//initializes movie info (Admin)
movie_info::movie_info(char mname[30], char st[20], char ct[15], char loc[15], time mtime[5]) {
	strcpy(movie_name, mname);
	strcpy(state, st);
	strcpy(city, ct);
	strcpy(location, loc);
	for (int i = 0; i < 5; i++) {
		movie_time[i] = time(mtime[i]);
	}
}


//list of all the movies (admin+user)
class movie_list {
	movie_info mlist[10];
	friend bool check_movie_name(unsigned int h, unsigned int m, movie_info m_info);
};

//store user info
class user_info {
	char user_name[20],movie_name[30],City[15],State[20],location[15];

};
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
