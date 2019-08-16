#pragma once
#include "time_date.h"

//used to store movie info (Admin+user)
class movie_info {
	char movie_name[30], city[15];
	time movie_time[5];
	int no_of_shows,num;

public:
	//input function
	void input();

	//output function
	void display();

	//compare functions
	friend bool compare_movie_name(char a[],movie_info b[]);
	friend bool compare_city_name(char a[], movie_info b[]);
	friend bool compare_movie_time(time& a, movie_info b[]);

	//constructor
	movie_info() :movie_name(""), city(""), movie_time(), num(0){}
};

//store user info
class user_info {
	char user_name[20], movie_name[30], city[15], state[20];
	time movie_time;
public:
	void input(movie_info mi[5]);
	void display();
};