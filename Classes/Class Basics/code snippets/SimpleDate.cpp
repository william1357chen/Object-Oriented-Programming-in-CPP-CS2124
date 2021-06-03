/*
	Example of a simple class. 
	(This has three compilation errors.  Can you explain why?)
	John Sterling
	CS1124
	Polytechnic University
*/

#include <iostream>
#include <string>
using namespace std;

// The Date class demonstrates
//   the use of constructors, accessors and mutators.  
//   private vs. public
//   const methods
//   default arguments

class Date {
public:
	// CONSTRUCTORS

	// date is assumed to be in the form mm/dd/yyyy
	Date(const string& date) {
		month = atoi(date.substr(0,2).c_str());
		day = atoi(date.substr(3,2).c_str());
		year = atoi(date.substr(6,4).c_str());
	}

	// Getters (aka Accessors)
	// Remember to make every function const 
	// that doesn't change the member variables.
	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }

	// Setters (aka Mutators)
	void setMonth(int m) {
		if (m > 0 && m <= 12) 
			month = m;
		else {
			cerr << "Date::setMonth: Invalid month: " << m << endl;
			exit(1);
		}
	}

	// display method for printing dates as month/day/year.
	// Note that we used a default argument for the stream
	// so that way we can print to the screen if no argument 
	// is provided, or print to a file stream if we like.
	// Note that there is one little thing wrong here that
	// will cause a problem elsewhere.  Try compiling and see.
	void display(ostream& os = cout)  {
		os << month << '/' << day << '/' << year;
	}

	// earlierThan is a feature we might like to add later.
	// So long as we don't use it, there is no harm in
	// providing a prototype here.
	bool earlierThan(Date) const;

private:
	int day, month, year;
};

// This does not compile.  Why?  
// How do we fix the display function so that this can compile.
void notMuchofaFunction (const Date& sometime) {
	sometime.display();
}

int main() {
	Date d1;	// Compilation error.  Why?  No "default constructor"

	Date independenceDay("07/04/1776");
	independenceDay.display();
	independenceDay.month = 17;    // Won't compile because month is private.
	independenceDay.setMonth(17);  // What will happen?

	Date whatIsThis();   // What is this?
}

