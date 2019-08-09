// Movie_Ticket_Booking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include "date_n_time.h"
#include "language.h"

using namespace std;

class Seat {
	char letter;
	int num;
public:
	Seat():letter(' '),num(0){}
	Seat(char l, int n):letter(l),num(n){}
};

class T_info {
	char movie_name[25], location[10];
	int no_of_seats;
	Language language;
	Seat seat[10];
	time tm;
	date dt;
};

int main(){
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
