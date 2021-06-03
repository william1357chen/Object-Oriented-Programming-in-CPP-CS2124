#ifndef DATE_H
#define DATE_H
// This use of #ifndef, #define and #endif is called "an include 
// guard".  It avoids problems with people including header files
// more than once and then having symbols defined more than once.
#include <string>
#include <iostream>
// Note that in header files its considered bad form to have
// "using namespace std;"

class Date {
public:
	// Since we don't have "using namespace std;"
	// we have to qualify the symbol "string" to show
	// that it comes from the std namespace.
	Date(const std::string& date);
	void setYear(int y);

	int getYear() const;

	void display(std::ostream& = std::cout) const;
	bool earlierThan(Date) const;
	int daysBetween(Date) const;	// We haven't implemented this yet
	void addDays(int days);			// We haven't implemented this yet

private:
	int day, month, year;
};

// This endif matches up with the ifndef above.
#endif