#pragma once
#include "user_info.h"

using namespace std;

class dat {
	short int m_max, u_max;//max number of movie and user slots
	movie_info mlist[5];//list of movies
	user_info ulist[5];//list of movies booked
	public:
	void Options();//presents user with options
	void admin_menu();
	void user_menu();

	//display selected info
	friend void available_cities(movie_info m[5]);
	friend void available_movies(movie_info m[5], int in[5]);
	friend void available_time(movie_info m[5], int in[5]);
	friend void available_date(movie_info m[5], int in[5]);
	//default constructor
	dat() {
		m_max = 5, u_max = 5;
	}
};
