/*
	file: Date.cpp
*/

#include "Date.h"
#include <iostream>
#include <cstdlib>	// atoi.  Note we also get it from string.

// When we're not in a header file, it is ok to
// have "using namespace std"
using namespace std;

Date::Date(const string& date) {
	// atoi comes
	month = atoi(date.substr(0,2).c_str());
	day = atoi(date.substr(3,2).c_str());
	year = atoi(date.substr(6,4).c_str());
}
void Date::display(std::ostream& os) const {
	os << month << '/' << day << '/' << year;
}
bool Date::earlierThan(Date d) const {
	if (year > d.year) 	return false;
	else if (year < d.year) return true;
	else if (month > d.month) return false;
	else if (month < d.month) return true;
	else if (day >= d.day) return false;
	else return true;
}
int Date::getYear() const { return year; }

void Date::setYear(int x) { year = x; }