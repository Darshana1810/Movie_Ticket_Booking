#include "movieuser_info.h"
#include "time_date.h"
#include <iostream>
#include <string.h>

using namespace std;

//takes input for movie
void movie_info::input() {
	cout << "Enter city name :";
	cin >> city;
	cout << "Enter movie name : ";
	cin >> movie_name;
	cout << "Number of shows : ";
	cin >> no_of_shows;
	cout << "Enter Show timings";
	for (int i = 0; i < no_of_shows; i++) {
		movie_time[i].gettime();
	}
}

//displays movie info
void movie_info::display() {
	cout << endl << "City:" << city;
	cout << endl << "Movie name : " << movie_name;
	cout << endl << "Number of shows : " << no_of_shows;
	cout << endl << "Timings : ";
	for (int i = 0; i < no_of_shows; i++) {
		cout << i + 1 << ". ";
		movie_time[i].showtime();
	}
}


//compare functions
bool compare_movie_name(char a[], movie_info& b) {
	if (strcmp(a, b.movie_name) == 0) {
		return true;
	}
	return false;
}

bool compare_city_name(char a[], movie_info& b) {
	if (strcmp(a, b.city)==0)
		return true;
	return false;
}

bool compare_movie_time(time& a, movie_info& b) {
	for (int i = 0; i < 5; i++) {
		if(check_time(a,b.movie_time[i]))
			return true;
	}
	return false;
}


//takes input for user_info
void user_info::input(movie_info mi[5]){
	char ct[15],mv[30];
	time t;

	//input user name
	cout << endl << "Enter user name : ";
	cin >> user_name;

	//input city name
	cout << "Enter city name : ";
	cin >> ct;
	for (int i = 0; i < 5; i++) {
		if (compare_city_name(ct, mi[i])) {
			strcpy_s(city, ct);
		}
	}
	//input movie name
	cout << "Enter movie name : ";
	cin >> mv;
	for (int i = 0; i < 5; i++)
	if (compare_movie_name(mv, mi[i]))	strcpy_s(movie_name, mv);

	//input movie timing
	cout << "Enter movie time (hh:mm) : ";
	t.gettime();
	for (int i = 0; i < 5; i++)
	if (compare_movie_time(t, mi[i]))	movie_time = t;
}

//display user info
void user_info::display() {
	cout << endl << "Name : " << user_name;
	cout << endl << "City : " << city;
	cout << endl << "Movie : " << movie_name;
	cout << endl << "Time : ";
	movie_time.showtime();
}