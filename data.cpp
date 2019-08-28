#include "data.h"

//gives options to the user to choose from

void dat::admin_menu() {
	int opt;
	while (true) {
		cout << endl << "-----ADMINISTRATORS'S MENU-----";
		cout << endl << "1.Add movie";
		cout << endl << "2.Display movies";
		cout << endl << "3.View booked tickets";
		cout << endl << "4.Go back to the main menu";
		cout << endl << ">";
		cin >> opt;
		switch (opt) {
		case 1:
			if (movie_info::get_count() < m_max) {
				mlist[movie_info::get_countp()].input();
			}
			else {
				cout << "Movie Slots are full" << endl;
			}
			break;

		case 2:
			if (movie_info::mcount > 0) {
				for (int i = 0; i < movie_info::get_count(); i++)
					mlist[i].display();
			}
			else {
				cout << "No movies are available" << endl;
			}
			break;

		case 3:
			if (user_info::ucount > 0) {
				for (int i = 0; i < user_info::ucount; i++)
					ulist[i].display();
			}
			else {
				cout << "No movies have been booked yet." << endl;
			}
			break;

		case 4:
			return;
		default:
			cout << "Error!!!" << endl << "Enter again." << endl;
		}
	}
}

void dat::user_menu() {
	int opt;
	while (true) {
		cout << endl << "-----USERS'S MENU-----";
		cout << endl << "1.Book Ticket";
		cout << endl << "2.Go back to the main menu";
		cout << endl << ">";
		cin >> opt;
		switch (opt) {
		case 1:
			if (movie_info::mcount == 0) {
				cout << "No movies to book!!!" << endl;
			}
			else if (user_info::ucount > u_max) {
				cout << "Booking slots are full." << endl;
			}
			else {
				ulist[user_info::ucount++].input(mlist);
			}
			break;

		case 2:
			return;
		default:
			cout << "Error!!!" << endl << "Enter again." << endl;
		}
	}
}

void dat::Options() {
	int opt;
	cout << endl << "-----MAIN MENU-----";
	cout << endl << "1.Administrator Menu";
	cout << endl << "2.User Menu";
	cout << endl << "3.Exit";
	cout << endl << ">";
	cin >> opt;
	switch (opt) {
	case 1:
		admin_menu();
		break;
	case 2:
		user_menu();
		break;
	case 3:
		exit(0);
	default:
		cout << "Error!!!" << endl << "Enter again." << endl;
	}
}

//displays availabe cities might repeate
void available_cities(movie_info m[5]) {
	cout << endl << "List of all the available cities : " << endl;
	for (int i = 0; i < movie_info::get_count(); i++) {
		m[i].display_city_name();
	}
}

//list of selected movies less likely to repitative
void available_movies(movie_info m[5], int in[5]) {
	cout << endl << "List of all the available movie in the city : "<<endl;
	for (int i = 0; i < movie_info::get_count(); i++) {
		if (in[i] != -1) {
			m[in[i]].display_movie_name();
		}
	}
}

//list of selected show timings less likely to repitative
void available_time(movie_info m[5], int in[5]) {
	cout << endl << "List of all the available shows : ";
	for (int i = 0; i < movie_info::get_count(); i++) {
		if (in[i] != -1) {
			m[in[i]].display_time();
		}
	}
}

void available_date(movie_info m[5], int in[5]) {
	cout << endl << "Movie dates : " << endl;
	for (int i = 0; i < movie_info::get_count(); i++) {
		if (in[i] != -1) {
			m[in[i]].display_date();
		}
	}
}