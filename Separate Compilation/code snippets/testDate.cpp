/*
	Example of very basic class using separate compilation. 
	John Sterling
	CS1124
	Polytechnic University
*/

// This is the same code as was used in the earlier program to implement
// and test the Date class, except that the class definition was moved 
// to the header file Date.h and the implementations of Date's member 
// functions have been moved to Date.cpp.  

// Comments have generally been removed these files if they don't relate 
// to separate compilation.

#include "Date.h"
#include <string>
#include <iostream>
using namespace std;


int main() {

	Date d1("03/14/1592");
	cout << "d1's year is: " << d1.getYear() << endl;
	cout << "Change d1's year to 17\n";
	d1.setYear(17);
	cout << "Checking d1's year: " << d1.getYear() << endl;
	cout << "Displaying d1: ";
	d1.display();
	cout << endl;
	cout << "Displaying d2: ";
	Date d2("11/23/5813");
	d2.display();
	cout << endl;
	cout << "Is date d1 earlier than date d2?\n";
	if (d1.earlierThan(d2))
		cout << "Yes\n";
	else
		cout << "No\n";
}
