/*
	Multiple Inheritance
*/

#include <string>
#include <iostream>
using namespace std;

// A simple Person class.
class Person {
public:
	Person(const string& aName): name(aName) {}
protected:
	string name;
};

// Instructor derived from Person.
//    Note the use of "virtual" here.  
//    Try commenting it out here and in Student.
//    (I placed "class Instructor : virtual	public Person" on three lines
//      just to make it easy for you to comment out "virtual" 
class Instructor : 
	//virtual 
	public Person {
public:
	Instructor(const string& aName): Person(aName) {}
};

// Student derived from Person.
//    Again note the use of "virtual" here.
class Student: 
	//virtual 
	public Person {
public:
	Student(const string& aName): Person(aName) {}
};

// a TA is both an Instructor and a Student
// Note that THREE constructors are invoked in the initialization list
class TA : public Instructor, public Student {
public:
	TA(const string& myName) : 
	  Person(myName), 
		  Instructor(myName), Student(myName) {}
	void display(ostream& os = cout) const {
		os << Person::name << endl;
		os << Student::Person::name << endl;
		os << Instructor::Person::name << endl;
	}
private:
};

int main() {
	TA chirag("Chirag Chhatriwala");
	chirag.display();
}