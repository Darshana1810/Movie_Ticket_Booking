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

int selected[5] = { -1,-1,-1,-1,-1 },cnt,xc;

//compare functions

bool compare_city_name(char a[], movie_info b[]) {
	cnt = 0;
	for (int i = 0; i < 5; i++) {
		if (strcmp(a, b[i].city) == 0)
			selected[cnt] = i, cnt++;
	}
	if (cnt > 0)
		return true;
	return false;
}

bool compare_movie_name(char a[], movie_info b[]) {
	xc = cnt;
	for (int i = 0; i < cnt; i++){
		int k = selected[cnt];
		if (strcmp(a, b[k].movie_name) != 0)
			selected[cnt] = -1,xc--;
	}
	if(xc>0)
		return true;
	return false;
}

bool compare_movie_time(time& a, movie_info b[]) {
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (check_time(a, b[i].movie_time[j]))
				return true;
		}
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
		if (compare_city_name(ct, mi)) 
			strcpy_s(city, ct);

	//input movie name
	cout << "Enter movie name : ";
	cin >> mv;
	if (compare_movie_name(mv, mi))
		strcpy_s(movie_name, mv);

	//input movie timing
	cout << "Enter movie time (hh:mm) : ";
	t.gettime();
	if (compare_movie_time(t, mi)
		movie_time = t;
}

//display user info
void user_info::display() {
	cout << endl << "Name : " << user_name;
	cout << endl << "City : " << city;
	cout << endl << "Movie : " << movie_name;
	cout << endl << "Time : ";
	movie_time.showtime();
}