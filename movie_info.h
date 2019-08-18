#pragma once
#include "time.h"
#include<iostream>

using namespace std;

//used to store movie info (Admin+user)
class movie_info {
	char movie_name[30], city[15];
	time movie_time[5];
	unsigned int no_of_shows, num,cost;


public:
	static int mcount;
	static int get_count() { return mcount; }
	static int get_countp() {
		return mcount++;
	}
	void input();	//takes input for movie

	//output function
	void display();//displays movie info
	void display_city_name() { cout << city << endl; }	//displays city name
	void display_movie_name() { cout << movie_name << endl; }//displays movie name
	void display_time();	//displays all the movie timings

	//compare functions use to select the movie
	friend bool compare_movie_name(char a[], movie_info b[]);
	friend bool compare_city_name(char a[], movie_info b[]);
	friend bool compare_movie_time(time& a, movie_info b[], int& cost);
	//default constructor
	movie_info() :movie_name(""), city(""), movie_time(), num(0) ,no_of_shows(0){}
};

extern int selected[5], scount;
//selected - list of all the indexes of movies which have been selected
//scount - number of selected movies


//friend function forward declation
bool compare_movie_name(char a[], movie_info b[]);
bool compare_city_name(char a[], movie_info b[]);
bool compare_movie_time(time& a, movie_info b[],int& cost);

//friend functions of dat class
void available_cities(movie_info m[5]);
void available_movies(movie_info m[5], int in[5]);
void available_time(movie_info m[5], int in[5]);