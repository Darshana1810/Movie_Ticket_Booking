#include "user_info.h"

int selected[5] = { -1,-1,-1,-1,-1 }, scount = 0;

int user_info::ucount;

void user_info::input_cityname(movie_info mi[5]) {
	char ct[15];
	while (true) {
		available_cities(mi);
		cout << endl << "Enter city name : ";
		cin >> ct;
		if (compare_city_name(ct, mi)) {
			strcpy_s(city, ct);
			return;
		}
		else {
			cout << "Enter again" << endl;
		}
	}
}

void user_info::input_moviename(movie_info mi[5]) {
	char mv[30];
	while (true) {
		available_movies(mi, selected);
		cout << endl << "Enter movie name : ";
		cin >> mv;
		if (compare_movie_name(mv, mi)){
			strcpy_s(movie_name, mv);
			return;
		}
		else {
			cout << "Enter again" << endl;
		}
	}
}

void user_info::input_movietime(movie_info mi[5]) {
	time t;
	while (true) {
		available_time(mi, selected);
		cout << endl << "Enter movie time (hh:mm) : ";
		t.gettime();
		if (compare_movie_time(t, mi,cost)){
			movie_time = t;
			return;
		}
		else {
			cout << "Enter again" << endl;
		}
	}
}

void user_info::input_seat(movie_info mi[5]) {
	char l;
	int n;
	cout << endl << "Refer to BookMyShow app and select your seat : ";
	cout << endl << "Enter Seat number (Letter and Number) : " << endl;
	for (int i = 0; i < no_of_tickets; i++) {
		cout << i + 1 << ") ";
		cin >> l >> n;
		S[i]=seat(l, n);
	}
}

void user_info::input(movie_info mi[5]) {
	//input user name
	cout << endl << "Enter user name : ";
	cin >> user_name;

	input_cityname(mi);

	input_moviename(mi);

	input_movietime(mi);

	//input no of tickets
	cout << "Enter number of tickets (max. 10): ";
	cin >> no_of_tickets;

	input_seat(mi);

	display_ticket();
}

void user_info::display() {
	cout << endl << "Customer Number : " << ucount << endl;
	cout<< "Name : " << user_name << endl ;
	cout << "City : " << city << endl;
	cout << "Movie : " << movie_name << endl;
	cout << "Number of tickets : " << no_of_tickets << endl;
	cout << "Price per ticket : " << cost << endl;
	cout << "Total cost : " << get_total_cost() << endl;
	cout << "Time : " << endl;
	movie_time.showtime();
}

double user_info::get_total_cost() {
	total_cost = cost * no_of_tickets;
	return total_cost;
}

void user_info::display_ticket() {
	cout << endl << "------------TICKET------------";
	cout << endl << "Movie Name       : " << movie_name;
	cout << endl << "Time             : ";
	movie_time.showtime();
	cout << "Number of Seats  : " << no_of_tickets;
	cout << endl << "Seats            : ";
	for (int i = 0; i < no_of_tickets; i++) {
		S[i].display();
		cout << endl<<"                   ";
	}
}