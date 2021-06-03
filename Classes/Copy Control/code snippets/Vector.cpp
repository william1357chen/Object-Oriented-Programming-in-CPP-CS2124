#include "Vector.h"
#include <iostream>
using namespace std;

namespace CS1124 {
	
	Vector::Vector(int s) : size(s), data (new int[size]){
	}
	
	// Copy Constructor
	// Note the type of the parameter.
	Vector::Vector(const Vector& v) {
		size = v.size;
		data = new int[size];
		for (int i = 0; i < size; i++)
			data[i] = v.data[i];
	}
	
	// Destructor
	Vector::~Vector() {
		delete [] data;
	}

	// Change the size of the Vector.
	// If newSize is not larger than the current size, 
	// we will not do anything.
	// Note that we did not initialize the new array elements.
	// Should we?
	void Vector::resize(int newSize) {
		if (newSize > size) {
			int* newData = new int[newSize];
			for (int i = 0; i < size; ++i)
				newData[i] = data[i];
			delete [] data;
			data = newData;
			size = newSize;
		}
	}

	
	// Assignment operator.
	// MUST BE defined as a member function.
	// The text chooses to return void, however it is
	// the usual practice to return a reference to the 
	// class.
	Vector& Vector::operator=(const Vector& right) {
		// Assignment operators should begin
		// with a check that you're not being
		// asked to do a "self-assignment" as in:
		// x = x;
		// Here we look to see if the "this" pointer
		// contains the same address as the address
		// of the argument.
		if (this != &right) {
			if (size != right.size) {
				// if our target array isn't the same size
				// as the target's, then we delete ours and
				// get one that is the correct size.
				delete [] data;
				size = right.size;
				data = new int[size];
			}
			for (int i = 0; i < size; i++)
				data[i] = right.data[i];
		}
		return *this;
	}
	
	// operator<< is printing a space after each element in
	// the Vector.  Note that this did not need to be a friend.
	ostream& operator<< (ostream& os, const Vector& v) {
		for (int i = 0; i < v.getSize(); i++)
			os << v[i] << ' ';
		return os;
	}
	
	// operator[].  Simple version that does not do range checking 
	// Two versions.  The first is when we are using a const vector
	// The second is when we want to be able to change the value
	// inside the vector.
	int Vector::operator[] (int index) const {
			return data[index];
	}
	int& Vector::operator[] (int index) {
			return data[index];
	}
}