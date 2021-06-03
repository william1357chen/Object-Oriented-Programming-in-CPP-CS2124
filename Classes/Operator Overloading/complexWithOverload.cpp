// File: Complex.cpp
// John Sterling -- jsterling@poly.edu
// CS1124
// Polytechnic University
// Brooklyn, NY

#include <iostream>
#include <string>
#include "Complex.h"

using namespace std;

namespace CS1124 {
	
	// CONSTRUCTORS
	// Since we used default arguments, we only have to implement one
	// version of the constructor.
	Complex::Complex(double r, double imag) 
		: real(r), imaginary(imag)
	{
		//real = r;
		//imaginary = imag;
	}

	// Decrement Operators --
	// =================================
	// Overloading the -- pre-increment unary operator.
	// Note the value returned is the "this pointer" dereferenced.
	// operator-- was declared a friend function in the Complex 
	// class.  Must define the parameter as reference, otherwise 
	// no change would be made to the object.

	Complex& operator-- (Complex& x) {
		x.real--;
		return x;
	}
	
	// Overloading the -- post-decrement operator.
	Complex operator-- (Complex& x, int) {
		Complex temp(x);
		x.real--;
		return temp;
	}
	

	// Increment Operators ++
	// ======================
	// Note that they are being defined as
	// member functions.  To do this requires we use "*this" 
	// (known as "the this pointer") to refer to 
	// the object that the member function is acting on.
	// If you are not familiar with the "this pointer", then just
	// use a non-member function definition as we show above
	// for the Decrement Operators.
	// ==========================================================
	// Overloading the ++ pre-increment operator.
	// Note the value returned is the "this pointer" dereferenced.
	Complex& Complex::operator++ () {
		real++;
		return *this;
	}	
	// Overloading the ++ post-increment operator.
	Complex Complex::operator++ (int) {
		Complex temp(*this);
		real++;
		return temp;
	}

	Complex& Complex::operator+=(const Complex& rhs) {
		real += rhs.real;
		imaginary += rhs.imaginary;
		return *this;
	}

	// Overloading the binary + operator to add two complex numbers.
	// This implementation makes use of the += operator and is a
	// commonly used convenient way to implement the + operator.
	// Notice that nothing about the code is unique to Complex
	// numbers and could just as well be written the same way for
	// any class that has the += operator implemented.
	// Also notice that the result is returned by value, meaning that 
	// a copy will be made when it is returned.  This is important.
	// It must NOT be returned by reference because it is a local 
	// variable to this function and won't exist after the function
	// exits.
	Complex operator+ (const Complex& lhs, const Complex& rhs) {
		Complex result = lhs;
		result += rhs;
		return result;
	}

	
	// An alternative way of implementing the + operator 
	// that does not use +=.
	//Complex operator+ (const Complex& left, const Complex& right) {
	//	double realPart = left.getReal() + right.getReal();
	//	double imaginaryPart = left.getImaginary() + right.getImaginary();
	//	Complex c(realPart, imaginaryPart);
	//	return c;
	//}
	
	// Overloading the binary - operator to subtract two complex
	// numbers.  As in operator+ above, we are passing the arguments 
	// by "constant reference" to avoid unnecessary copying.
	// No temporary variables are used inside the function.  All 
	// computation is done inside the constructor.
	// Using a constructor to create the return value avoids an
	// additional copy when returning "by value".
	Complex operator- (const Complex& left, const Complex& right) {
		return Complex(left.getReal() - right.getReal(), 
			left.getImaginary() - right.getImaginary());
	}
	
	// Overloading the output operator for complex numbers.
	// Note that, as usual the complex number is passed by 
	// constant reference for efficiency.  However, the ostream 
	// object is only passed by reference.  Why?  Because the 
	// ostream object will have to change its internal state when 
	// printing out the doubles "real" and "imaginary".
	// Note also that the ostream must be returned by reference.
	ostream& operator<< (ostream& os, const Complex& c) {
		os << c.getReal();
		if (c.getImaginary() >= 0) os << '+';
		os << c.getImaginary() << "i";
		return os;
	}
	
	// Overloading the input operator for complex numbers.
	// Note that the complex number is passed by reference
	// because we need to change it's value. 
	// Also, the istream object is also passed by reference.  
	// Why?  Because the 
	// istream object will have to change its internal state when 
	// reading in the doubles "real" and "imaginary".
	// Note also that the istream must be returned by reference.
	istream& operator>> (istream& is, Complex& c) {
		double real, imaginary;
		// Critcal that we use char instead of string.  Why?
		char sign, i;
		is >> real >> sign >> imaginary >> i;
		c = Complex(real, (sign == '+') ? imaginary : -imaginary);
		return is;
	}
	
}