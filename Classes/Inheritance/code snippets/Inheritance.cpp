/*
	File: Inheritance1.cpp
	John Sterling -- jsterling@poly.edu
	CS1124
	Polytechnic University

    1) The class Cat "inherits" from the class Pet.  Pet is called
	   the "base" class and Cat is called the "derived" class.
	2) The function display only needs to be implemented in Pet, 
	   but it can still be used from Cat.  
	3) Constructors for the 
	4) Cats can do things that Pets can't.
*/

#include <iostream>
#include <string>
using namespace std;

// A class to represent pets.
class Pet {
public:

	// We want a constructor that initializes the pet's name.
	Pet(const string& s) : name(s) { }

	// Notice that we define "display" in Pet but don't in Cat.
	void display() const { cout << name << endl; }

protected:
	string name;
};

// Cats are Pets, at least for the purpose of our program.  To let C++
// know that, we put the " : public Pet" in between "class Cat" and the 
// curly brace.
class Cat : public Pet {
public:
	// The Cat constructor shown in the comment below didn't work. 
	// We got acompilation error
	// saying that there was no default constructor for the Pet 
	// class.  That was true, but we didn't try calling the
	// Pet default constructor.  At least not that we knew about.  But C++
	// tried to call it for us.  Where?  In the initialization list.  We
	// didn't write an initialization list!  C++ pretends that we
	// wrote "Cat (string s) : Pet() {".   If we want to avoid it, we
	// *have to* invoke some other Pet constructor in the intialization
	// list.
	// Cat (const string& s) { name = s; }

	// Here is a working version of the Cat constructor.  By calling the 
	// Pet constructor, it will initialize the cat's name.
	Cat (const string& s) : Pet(s) { }

	void meow() {}
};

int main() {
	Pet p("Felix");
	p.display();
	// If we try to make a pet "meow", then we will get a compilation error:
	//p.meow();

	Cat c("Heathcliffe");
	// We are using a member function that we never explicitly defined,
	// the "display" member function for a Cat.  Code reuse in action!
	c.display();
	// Cats can do something that other Pets cannot, the can meow.
	c.meow();
	return 0;
}