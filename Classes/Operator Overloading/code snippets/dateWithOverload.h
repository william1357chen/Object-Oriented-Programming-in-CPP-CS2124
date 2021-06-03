#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>

namespace CS1124 {
	class Date {
		// Equality test operator implemented as a friend function.
		// Remember that friend functions are non-member functions,
		// however we have to place their prototype in the class definition.
		// It doesn't matter where in the class definition we place it.
		// I like to put them here, right at the beginning.
		friend bool operator==(const Date& lhs, const Date& rhs);
	public:
		Date(const std::string& date);
		void setYear(int y);
		int getYear() const;
		int getMonth() const;
		int getDay() const;
		// Less than operator implemented as a member function.
		bool operator<(const Date& rhs) const;

	private:
		int day, month, year;
	};

	// Greater than operator implemented as a non-member function.
	bool operator>(const Date& lhs, const Date& rhs);
	// Output operator implemented, of course, as a non-member function.
	std::ostream& operator<< (std::ostream& os, const Date& d);
}
#endif