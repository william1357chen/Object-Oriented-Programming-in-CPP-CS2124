#include "Date.h"
#include <iostream>
// When we're not in a header file, it is ok to
// have "using namespace std"
using namespace std;

namespace CS1124 {
	Date::Date(const string& date) {
		month = atoi(date.substr(0,2).c_str());
		day = atoi(date.substr(3,2).c_str());
		year = atoi(date.substr(6,4).c_str());
	}

	int Date::getYear() const { return year; }
	int Date::getMonth() const { return month; 	}
	int Date::getDay() const { return day; }

	void Date::setYear(int x) {	year = x; }

	// operator< implemented as a member.
	bool Date::operator<(const Date& rhs) const {
		if (year > rhs.year) return false;
		else if (year < rhs.year) return true;
		else if (month > rhs.month) return false;
		else if (month < rhs.month) return true;
		else if (day >= rhs.day) return false;
		else return true;
	}

	// operator==.  Implemented as a friend, so we don't have to use accessor functions.
	bool operator==(const Date& lhs, const Date& rhs) {
		return (rhs.year == lhs.year && rhs.month == lhs.month && rhs.day == lhs.day);
	}
	// operator>.  Implemented as a non-member, non-friend.  Using other operators
	// that were already implemented makes this one easy.
	bool operator>(const Date& lhs, const Date& rhs) {
		return (!(lhs < rhs) && !(lhs == rhs));
	}
	// operator<<.  Since we didn't make it a friend, we had to add some accessors.
	ostream& operator<<(ostream& os, const Date& rhs) {
		os << "Month: " << rhs.getMonth() 
			<< "; Day: " << rhs.getDay() 
			<< "; Year: " << rhs.getYear();
		return os;
	}
}