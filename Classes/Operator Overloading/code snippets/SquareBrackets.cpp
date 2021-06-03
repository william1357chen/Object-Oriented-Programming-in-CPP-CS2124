/*
	SquareBrackets.cpp
	CS1124 Sample Code
	John Sterling
	Brooklyn Polytech

    Demonstrate the use of the "square bracket" operator.
*/

#include <iostream>
using namespace std;

// Calling this class "Vector" is certainly an overstatement right now.
// In fact, it's not even as general as a basic array.
// But it does serve the purpose of demonstrating the [] operator.
// Later we can build on it to add some of the functionality that we
// would expect of a vector class.
class Vector {

	// It's not the point of this project, but it's hard to resist
	// overloading the output operator, once you know how.
	friend ostream& operator<< (ostream& os, const Vector& vec) {
		for (int i = 0; i < Vector::MAX; ++i) os << vec[i] << ' ';
		return os;
	}

public:
	static const int MAX = 10;
	// Not all compilers accept static constant ints, initialized this way.
	// An alternative is to use an enum, as in the next line.
	// enum {MAX = 10};

	// Seems a shame to leave the data in the vector uninitialized.
	Vector() {	for (int i = 0; i < Vector::MAX; ++i) data[i] = 0; }

	// Here is the focus of this project.
	// Two simple lines of code.
	// The compiler will use this one when the vector is constant.
	int operator[](size_t i) const {return data[i];}
	int& operator[](size_t i) {return data[i];}

private:
	int data[MAX];
};

// Try putting "const" before "Vector" in the parameter list.
// Why does the compiler complain?
void f( Vector& v) {int &x = v[7];}

int main() {

	// Create an instance of a Vector.
	// Unfortunately, we can't say how big the vector is
	// or pick what kind of thing it holds.  Later.
	Vector v;	

	// Put some interesting data in the vector
	for (int i = 0; i < Vector::MAX; ++i) v[i] = i*i;

	// Display the vector.  
	// Of course this only works because we overloaded the output operator.
	// (Otherwise known as the "insertion" operator for those who like such words.)
	cout << v << endl;

}