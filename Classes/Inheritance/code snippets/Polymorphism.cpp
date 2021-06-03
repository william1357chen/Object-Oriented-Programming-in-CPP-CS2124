/*
	File: Inheritance2.cpp
	John Sterling -- jsterling@poly.edu
	CS1124
	Polytechnic University

    1) Builds on the project Inheritance1.  Look there for the basics.  Some
	   comments from Inheritance1 have been removed for clarity.
	2) Cat redefines the displayDetailed function from the Pet class.
	3) The test program explores what happens when we call displayDetailed
	   with different Pets and in different ways.  What do we have to do
	   in order to use the "right" definition of the function?
	4) Note the way the array myPets is initialized.  Which constructor is
	   used?
*/

#include <iostream>
#include <string>
using namespace std;

// A class to hold pets.
class Pet {
public:

	// CONSTRUCTORS 
	Pet(const string& s) { name = s; }

	// displayDetailed does a little more than just display the name.
	// Try running with and without the word "virtual".
	//virtual
	void displayDetailed() const {
		cout << "Pet: " << name << endl;
	}
protected:
	string name;
};

// Cats are Pets, at least for the purpose of our program.
class Cat : public Pet {
public:
	Cat (const string& s) : Pet(s) { }

	// displayDetailed does things a little differently for Cats than
	// for other Pets in general, so we redefine it here.
	void displayDetailed() const {
		cout << "Cat: " << name << endl;
	}
};

int main() {
	Pet p("Felix");
	p.displayDetailed();
	Cat c("Heathcliffe");
	c.displayDetailed();

	cout << endl << "Playing with containers of Pets\n\n";
	// Here we've created an array holding two Pets.
	// What happens when we call displayDetails?  Look closely.
	// An aside, what constructor is being used here for the elements 
	// of the array?
	Pet myPets[2] = {p, c};
	for (int i = 0; i < 2; i++)
		myPets[i].displayDetailed();

	// Here we've created an array holding two pointers to Pets.
	// What happens now when we call displayDetails?
	// Try this without the word "virtual" in the declaration for
	// displayDetailed in the Pet class.
	Pet* myPetPtrs[2];
	myPetPtrs[0] = &p;
	myPetPtrs[1] = &c;
	for (int j = 0; j < 2; j++)
		myPetPtrs[j]->displayDetailed();
	return 0;
}