/*
	Example of very basic class using separate compilation. 
	John Sterling
	CS1124
	Polytechnic University
*/

// This program uses essentially the same Date class as used in the example of
// separate compilation, with the addition ofcomparison and output operators.  
// The display and earlierThan methods were removed as they are no longer needed.

#include "Date.h"
#include <string>
#include <iostream>
using namespace std;
using namespace CS1124;


int main() {

	Date d1("03/14/1592");
	cout << "Displaying d1: ";
	cout << d1 << endl;

	Date d2("11/23/5813");
	cout << "Displaying d2: ";
	cout << d2 << endl;

	cout << "Is date d1 earlier than date d2?\n";
	if (d1 < d2)
		cout << "Yes\n";
	else
		cout << "No\n";
	cout << "Is date d1 later than date d2?\n";
	if (d1 > d2)
		cout << "Yes\n";
	else
		cout << "No\n";
	cout << "Is date d1 the same as date d2?\n";
	if (d1 == d2)
		cout << "Yes\n";
	else
		cout << "No\n";
	cout << "Is date d1 the same as date d1?\n";
	if (d1 == d1)
		cout << "Yes\n";
	else
		cout << "No\n";

}
