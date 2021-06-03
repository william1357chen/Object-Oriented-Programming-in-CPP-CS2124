/*
	File: testComplex.cpp
	John Sterling -- jsterling@poly.edu
	CS1124
	Polytechnic University
	Demonstrates the use of overloaded operators for 
	a complex number class.  Focus is on arithmetic
	operators, including the pre/post increment and 
	decrement operators.
*/

#include <iostream>
#include "Complex.h"
#include <string>
using namespace std;
using namespace CS1124;


int main() {

	// create a default complex number and print it.
	Complex a;
	cout << "A default complex number: " << a << endl;

	// create a complex number representing "1+2i".
	Complex b(1,2);

	// create a complex number representing "42+0i".
	Complex theAnswer(42);

	// Ask for a complex number of the form a+bi and print it.
	// Use the overloded >> operaor to read it and the overloaded
	// << operator to print it.
	cout << "Please enter a complex number of the form: a+bi\n";
	Complex x;
	cin >> x;
	cout << "You entered: " << x << endl;

	// Use the overloaded operators + and << to output the
	// sum of two complex numbers.
	cout << "The sum of (" << x << ") and (1+2i): " << x + b << endl;

	// Create a complex number representing "4+4i".
	Complex c(4, 4);

	// Use the overloaded operators + and << to output the
	// difference of two complex numbers.
	cout << "The difference of (" << c << ") and (1+2i): " << c - b << endl;

	// Why does this work???  Hm...  Good test question.
	cout << "The sum of (" << c << ") and 5: " << c + 5 << endl;

	// Show the result of incrementing b
	cout << "If b == " << b << endl;
	cout << "then ++b == " << ++b << endl;

	cout << "If c == " << c << endl;
	--c;
	cout << "then --c == " << c << endl;

}
