/*
	Example of addresses, pointers and pointer arithmetic.
	Also the use of pointers as array names.
	John Sterling
	CS1124
	Polytechnic University
*/

#include <iostream>
using namespace std;

int main() {

	int x = 6;
	cout << "x = " << x << endl;
	// The address of x is writte &x
	cout << "&x = " << &x << endl;

	// declaring a pointer to an int and initializing it to  the address
	// of an int variable.  Note that pointers always have a type!
	int* px = &x;
	// Print out the contents of a pointer variable.
	cout << "px = " << px << endl;
	// Print out the value that the pointer points to.
	// When you use the * character on the left side of a pointer
	// variable it is called the "dereferencing operator".
	cout << "*px = " << *px << endl;

	int f[] = { 8, 13, 21, 34, 55, 89 };
	int* pf;
	// We will print out the contents of the array f[]
	cout << "f[] = { ";
	// Looping over an array using pointers.
	// Note that the name of an array is the array's address 
	for (pf = f; pf < f + 6; pf++) cout << *pf << ", "; 
	cout << "}\n";

	// Here is a second way of getting the address of an array.
	pf = &f[0];
	cout << "*pf = " << *pf << endl;
	// What is "*pf + 2" ?  In other words, which has higher precedence,
	// the dereferencing operator or the addition operator?
	cout << "*pf + 2 = " << *pf + 2 << endl;
	cout << "*(pf + 2) = " << *(pf + 2) << endl;
	// What is the effect of using dereferencing and pre-increment?
	cout << "*++pf = " << *++pf << endl;
	// What is the effect of using dereferencing and post-increment?
	cout << "*pf++ = " << *pf++ << endl;
	cout << "*(pf + 2) = " << *(pf + 2) << endl;
	// See that f has not changed, even though pf has.
	cout << "*(f + 2) = " << *(f + 2) << endl;
	cout << "f[2] = " << f[2] << endl;
	// Could we do the same with f as we did with pf above?
	// That is, can we use f++?  No.  VC++ complains that "++ needs and l-value".
	// That means we have to be able to assign to f.  But we can't write "f = 5"
	// or any other such assignment expression.  Another way to view it is that
	// f is const.  It may represent an address, but we can't change what that
	// address is.
	// f++;

	// If the name of an array is really just the address of the array
	// and if a pointer to the array holds the address of the array,
	// is there some easy way to use a pointer AS an array?  Yes!
	pf = f;
	cout << "pf[2] = " << pf[2] << endl;


	// What is the type of a and of b?
	int* a, b;

	// How do we define a pointer to a pointer?
	// See the use of two asterisks?  Note that we use an int** to hold the
	// address of an int*.
	int** pp = &px;
	cout << "**pp = " << **pp << endl;

}