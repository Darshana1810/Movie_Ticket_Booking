#pragma once
class seat {
	unsigned short int number;
	char letter;
public:
	seat() :letter(' '), number(0) {}
	seat(seat& x):number(x.number),letter(x.letter){}
	seat(char l,unsigned short int n):letter(l),number(n){}
	void display() {
		std::cout << letter << number;
	}
};