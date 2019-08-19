#include "movie_info.h"

using namespace std;

int movie_info::mcount;

void movie_info::input() {
	num = movie_info::get_count();
	cout << "Enter city name : ";
	cin >> city;
	cout << "Enter movie name : ";
	cin >> movie_name;
	cout << "Enter Ticket Price : ";
	cin >> cost;
	cout << "Number of shows : ";
	cin >> no_of_shows;
	cout << "Enter Show timings : "<<endl;
	for (int i = 0; i < no_of_shows; i++) {
		cout <<i+1<<")";
		movie_time[i].gettime();
	}
	cout << "Enter movie date:" << endl;
	cout << "Start : ";
	start.input();
	cout << "End : ";
	end.input();
}

void movie_info::display() {
	cout << endl << "Movie Number : " << num << endl;
	cout << "City:" << city << endl;
	cout << "Movie name : " << movie_name << endl;
	cout << "Ticket Price : " << cost << endl;
	cout << "Number of shows : " << no_of_shows << endl;
	cout << "Timings : ";
	for (int i = 0; i < no_of_shows; i++) {
		cout << endl << i + 1 << ") ";
		movie_time[i].showtime();
	}

	cout << endl << "Movie date:" << endl;
	cout << "Start : ";
	start.display();
	cout << endl << "End : ";
	end.display();
	cout << endl;
}

void movie_info::display_time() {
	for (int i = 0; i < no_of_shows; i++) {
		cout << endl << i + 1 << ") ";
		movie_time[i].showtime();
	}
}

void movie_info::display_date() {
	cout << "Start : ";
	start.display();
	cout << endl << "End : ";
	end.display();
}

//compare functions
bool compare_city_name(char a[], movie_info b[]) {
	int index = 0;
	for (int i = 0; i < movie_info::get_count(); i++) {
		if (strcmp(a, b[i].city) == 0)
			selected[index] = b[i].num-1, scount++, index++;
	}
	if (scount > 0)
		return true;
	return false;
}

bool compare_movie_name(char a[], movie_info b[]) {
	int sc = scount;
	for (int i = 0; i < sc; i++) {
		int k = selected[i];
		if (strcmp(a, b[k].movie_name) != 0)
			selected[i] = -1, scount--;
	}
	if (scount > 0)
		return true;
	return false;
}

bool compare_movie_time(time& a, movie_info b[],int& cost) {
	int sc = scount;
	for (int i = 0; i < sc; i++) {
		if (selected[i] == -1)
			continue;
		int k = selected[i];
		for (int j = 0; j < 5; j++) {
			if (check_time(a, b[k].movie_time[j])) {
				cost = b[k].cost;//copy the movie cost
				return true;
			}
		}
	}
	return false;
}

bool compare_movie_date(date& a, movie_info b[]) {
	int sc = scount;
	for (int i = 0; i < sc; i++) {
		if (selected[i] == -1)
			continue;
		int k = selected[i];
		if (a.is_date(b[k].start, b[k].end))
			return true;
	}
	return false;
}
