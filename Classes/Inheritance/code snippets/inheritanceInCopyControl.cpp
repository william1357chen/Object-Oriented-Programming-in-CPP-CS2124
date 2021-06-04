/*
	File: TestConstructorDestructorOrder.cpp
	John Sterling -- jsterling@poly.edu
	CS1124
	Polytechnic University
*/

#include <iostream>
using namespace std;

// The purpose of this code is to see the order in which the
// bodies of the constructors and destructors get called
// even when we don't tell C++ what to do.
// We can't change the order of those calls, though we can
// tell C++ which constructor for a class to use, if we prefer
// not to use the default ones.

class A {
public:
	A() {cout << "In A's constructor\n";}
	~A() {cout << "In A's destructor\n";}
private:
};

class C {
public:
	C() {cout << "In C's constructor\n";}
	~C() {cout << "In C's destructor\n";}
private:
};

class B : public A {
public:
	B() {cout << "In B's constructor\n";}
	~B() {cout << "In B's destructor\n";}
private:
	C c;
};




int main() {
	B* bPtr = new B;
	delete bPtr;
	cout << "------------------------------\n";
	A* aPtr = new B;	
	delete aPtr;		// Hm, something odd happens here.
						// What?  What do we do to fix it?
						// Answer below.

	return 0;
}



/*
	The problem above is that the destructor for the class B did
	not get called when the line:
		delete aPtr;
	was executed.  Even though the object that is being deleted *is*
	an object of type B.  That also kept C's destructor from being called.

	The reason is that aPtr is a variable of type
	"pointer to A".  Only methods for class A will be called, unless
	they were marked as virtual.  What method do we want to call?  B's
	destructor.  What to we have to do?  Mark the destructor "virtual".
	Where?  In class A.

	Got all that?
*/