#pragma once
#include "movie_info.h"
#include "seat.h"

//store user info
class user_info {
	int num;//store user number
	int no_of_tickets, total_cost,cost;
	char user_name[20], movie_name[30], city[15];
	time movie_time;
	date movie_date;
	seat S[10];
public:
	//default constructor
	user_info() :user_name(""), movie_name(""), city(""), movie_time(),movie_date(), num(0){}

	static int ucount;//keeps count of user

	void input(movie_info mi[5]);//takes input for user_info

	void input_cityname(movie_info mi[5]);	//input city name
	void input_moviename(movie_info mi[5]); //input movie name
	void input_movietime(movie_info mi[5]); //input movie timing
	void input_moviedate(movie_info mi[5]); //input movie date
	void input_seat(movie_info mi[5]);		//input seat

	void display();	//display user info
	void display_ticket();
	double get_total_cost();
};