/*
	Example of how NOT to read a file. 
	John Sterling
	CS1124
	Polytechnic University
*/

// This program has been stripped down to focus on a common 
// student programming error when reading files.  The part of
// the code to pay attention to is the loop.  

#include <iostream>	// cin, cout, cerr, endl
#include <fstream>	// ifstream
#include <string>	// string

using namespace std;

int main() {
	ifstream payrollStream;
	payrollStream.open("payroll.txt");

	string name;
	int money;
	// This loop is WRONG!!  The only person who would approve is whoever is
	// the person at the end of payroll file.  WHY does this code fail to work
	// properly?

    // The problem happens when you have any additional characters at the end
    // of the file
	while (!payrollStream.eof()) {
		payrollStream >> name >> money;
		cout << "Pay to the order of "<< name << " $" << money << endl;
	}

	return 0;
}