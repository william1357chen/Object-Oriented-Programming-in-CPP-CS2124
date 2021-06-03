// File: Complex.h
// John Sterling -- jsterling@poly.edu
// CS1124
// Polytechnic University
// Brooklyn, NY

#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

namespace CS1124 {
	
	class Complex {
	public:
		// Constructors.
		Complex(double r = 0, double imag = 0);
		
		// ACCESSORS
		// The "getter" functions are declared as "const".  You 
		// might want to try taking off the const modifier and 
		// see what happens when you compile.  Where do you think 
		// a problem might occur??
		double getReal() const {return real;}
		double getImaginary() const {return imaginary;}

		// "Setters"
		void setReal(double r) {real = r;}
		void setImaginary(double i) {imaginary = i;}

		// Pre- and pos- increment and decrement operators
		// The decrement operators will be defined as friends
		// and the increment operators will be defined as
		// members.
		// ================================================		
		// Pre-decrement operator.  Allows us to write:
		//  Complex c;  
		//  --c;
		// What do we want it to mean?  I assume we would like to 
		// subtract one to the real part of the number.  The value
		// of the expression is the same as the new value of c.
		// Note that overloading operator-- this way does not allow 
		// "c--".  We have to declare that separately.  
		// Defined as a non-member function.  The prototype
		// is here inside the class definition because we have
		// chosen to make it a friend.
		// Note that the return type should be a reference.
		friend Complex& operator-- (Complex&);
		
		// Post-decrement operator.  Allows us to write:
		//   Complex c:
		//   c--;
		// This is similar to --c in that one is subtracted from
		// the real part of c.  However, the value of the expression
		// is the same as what c was before subtracting one.
		// The post-decrement function must take a dummy second
		// argument.  The purpose of this dummy argument is
		// simply to distinguish the definition of the post-decrement
		// operator from that of the pre-increment operator.
		// Note also that the return type is not a reference!!!!
		// (Good test question as to why it isn't.)
		friend Complex operator-- (Complex&, int);
		
		// Pre-increment operator.  Allows us to write:
		//   Complex c;
		//   ++c;
		// What do we want it to mean?  I assume we would like to 
		// add one to the real part of the number.  Note that 
		// overloading operator++ this way does not allow "c++".
		// Since are implementing this as a member function,
		// we don't need to pass an argument.
		Complex& operator++ ();
		
		// Post-increment operator.  Allows us to write:
		//   Complex c:
		//   c++;
		// This is similar to ++c.  Its value is whatever c 
		// was, but then it changes c by adding one to it.
		// The function shows one argument, an int.  This
		// is a "dummy" argument, used by C++ to distinguish 
		// between the pre- and post- increment operators.
		// Note that the return type is NOT a reference!!!!   
		Complex operator++ (int);

		Complex& operator+=(const Complex&);
				
	private:
		double real;
		double imaginary;
	};  // end of Complex class definition.
	
	// These operators are not defined inside the class but the 
	// Complex.h header file is still a good place for their 
	// prototypes.
	// All paramaters are passed by constant reference for efficiency
	// and because we do not need to modify them.
	Complex operator+ (const Complex& left, const Complex& right);
	Complex operator- (const Complex& left, const Complex& right);
	
	// NB: ostream must be qualified here by the namespace std.
	// Why didn't I just have a "using namespace std" line above?
	// Also note that the ostream and istream parameters are 
	// NOT const.
	std::ostream& operator<<(std::ostream& os, const Complex& c);
	std::istream& operator>>(std::istream& is, Complex& c);

}  // end of namespace CS1124 definition

#endif