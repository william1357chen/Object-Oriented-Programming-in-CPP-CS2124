/*
	Example of association and composition  
	(This does not compile.  Do you understand why?)
	John Sterling
	CS1124
	Polytechnic University
*/

#include <iostream>
#include <string>
using namespace std;

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
	void display(ostream& os = cout) const {
		os << month << '/' << day << '/' << year;
	}

	// earlierThan is a feature we might like to add later.
	// So long as we don't use it, there is no harm in
	// providing a prototype here.
	bool earlierThan(Date) const;

private:
	int day, month, year;
};

class Person {
public:
	// Hm, how do we set the member variables?
	// The following doesn't work because there is
	// no default constructor for the Date class.
	// The Date default constructor is being called in 
	// the "member initialization list".
	// To compile, comment out this definition, and uncomment
	// the next one or the one after (saved the last for best)
	Person(const string& fn, const string& ln, const string& birthday) {
		firstName = fn;
		lastName = ln;
		bday = birthday;  // This actually would work, but...
		spouse = NULL;
	}


	// The Person constructor below works because we tell C++ which 
	// Date constructor to use.  Here we use the Date constructor taking 
	// a string (which is the only one implemented so far).
	// This is still not the best!
	// It first INITIALIZES firstName to the empty string 
	// before it finally ASSIGNS it the value fn.
	// Why initialize firstName to the empty string first?
	// Why not just initialize it to fn correctly right from the start?
	// The same thing ineffieciency occurs with lastName.
	//
	//Person(const string& fn, const string& ln, const string& birthday) : bday(birthday) {
	//	firstName = fn;
	//	lastName = ln;
	//	spouse = NULL;
	//}

	// The Person constructor below is even better.
	// It avoids the inefficiency of first initializing the strings to the empty string.
	// I also use the initialization list to initialize spouse,
	// but that is purely a matter of personal preference.
	//Person(const string& fn, const string& ln, const string& birthday)
	//  : bday(birthday), firstName(fn), lastName(ln), spouse(NULL) {
	//}


	// Here we use a Date constructor that copies another Date.
	// This type of constructor is called a "copy constructor".
	// We didn't have to write the copy constructor as the language always
	// provides one.  Later we will find there are some situations
	// in which we do want to write our own copy constructor.
	Person(const string& fn, const string& ln, const Date& birthday) 
		: bday(birthday), firstName(fn), lastName(ln), spouse(NULL) {
	}

	void display(ostream& os = cout) const {
		os << "Name: " << firstName << ' ' << lastName << ", date of birth: ";
		bday.display(os);
	}

	// marry sets the spouse pointers of the current object and the "intended".
	// Two interesting things here:
	// 
	// First, note that we can access "intended"'s 
	// private member variable: spouse.  That is because 
	// "intended" is a Person and "marry" is a person method.
	//
	// Second, see how we get the address of the "current object".
	// We use the reserved word "this" which always holds the address
	// of the current object.  Naturally, "this" is only meaningful
	// inside a member function.
	// If we were going to marry someone who is NOT a Person, then
	// we would have a small problem...  but we would solve it by 
	// calling a method in that class's public interface.
	void marry(Person& intended) {
		spouse = &intended;
		intended.spouse = this;
	}

	void displayMySpouse(ostream& os = cout) const {
		os << "Spouse: ";
		if (spouse) spouse->display();
		else cout << "NONE";
	}

private:
	string firstName;
	string lastName;
	Date bday;
	// We can't use Person for a spouse.  Why?
	// Besides it doesn't make much sense to "create" the spouse
	// at the same time we create the person.  Don't babies start
	// out single????
	// And what happens if we get divorced?
	// Person spouse;
	// Instead we use a pointer.
	Person* spouse;
};

int main() {
	Date independenceDay("07/04/1776");

	Person me("Alfred", "Newman", independenceDay);
	me.display();
	cout << endl;
	me.displayMySpouse();
	cout << endl;

	Person monroe("Marilyn", "Monroe", "06/01/1926");
	me.marry(monroe);
	me.displayMySpouse();
	cout << endl;
	monroe.displayMySpouse();
	cout << endl;

}

