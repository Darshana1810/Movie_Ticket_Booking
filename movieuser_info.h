#pragma once
#include "time_date.h"

//used to store movie info (Admin+user)
class movie_info {

	char movie_name[30], city[15];
	time movie_time[5];
	int no_of_shows;

public:
	//input function
	void input();

	//display functions
/*	void show_movie_name() { cout << movie_name; }
	void show_city_name() { cout << city; }
	void show_movie_time() {
		for (int i = 0; i < no_of_shows; i++)
			movie_time[i].showtime();
	}*/
	void output();

	//compare functions
	friend bool compare_movie_name(char a[],movie_info& b);
	friend bool compare_city_name(char a[], movie_info& b);
	friend bool compare_movie_time(time& a, movie_info& b);

	//constructor
	movie_info() :movie_name(""), city(""), movie_time() {}
};

//store user info
class user_info {
	char user_name[20], movie_name[30], city[15], state[20];
	time movie_time;
public:
	void input(movie_info& mi);
	void display();
};