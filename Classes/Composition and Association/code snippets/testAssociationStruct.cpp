/*
	testAssociationStruct.cpp
	John Sterling

	Demonstrate how to create an "association"
	between two struct objects using pointers.
*/

#include <string>
#include <iostream>
using namespace std;

/*
	We want a "spouse" member in our Person struct
	to represent who our person is married to.
	It is not possible for the type of the spouse
	field to be Person.  Why?  (There's not enough
	room in one Person object to contain another 
	Person object.)
*/
struct Person {
	string name;
	string bday;
	int height;
	Person* spouse;
};

// makes the two people be married.
bool marry(Person&, Person&);

int main() {
	Person john;
	john.name = "John";
	john.bday = "May 29, 1917";
	john.height = 72;
	// Important to initalize the spouse pointer to NULL!
	// Otherwise we don't know if the person is married.
	john.spouse = NULL;  

	Person marilyn;
	marilyn.name = "Marilyn";
	marilyn.bday = "06/01/1926";
	marilyn.height = 64;
	marilyn.spouse = NULL;

	marry(john, marilyn);

	cout << "John is married to " << john.spouse->name << endl;

}

// marry returns false if one of the two arguments
// is already married.  Otherwise it "marries" them
// together by setting their spouse pointers to point 
// to each other, and returns true.
bool marry(Person& p1, Person& p2) {
	if (p1.spouse || p2.spouse) return false;
	p1.spouse = &p2;
	p2.spouse = &p1;
	return true;
}