#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

namespace CS1124 {
	
	class Vector {
	public:
		//CONSTRUCTORS
		Vector(const Vector&);	// Copy Constructor	
		Vector(int size = 4);	// Create a vector of a particular size defaulting to 4.
		
		// DESTRUCTOR
		~Vector();

		// Accessor
		int getSize() const {return size;}

		// Change the size of the Vector.
		// If newSize is smaller than the current size, 
		// we will not do anything.
		void resize(int newSize);
		
		// Assignment operator
		// C++ requires that it be a member function.
		Vector& operator=(const Vector&);

		// [] operator.
		// C++ requires that it be a member function.
		// The reference return type is to allow us to assign to it.
		int& operator[](int i);
		// Need a second version, for the times that we
		// are using a const vector.
		int operator[](int i) const;
		
	private:
		int size;
		int* data;
	};
// The output operator can't be a member of the Vector class
// and it doesn't need to be a friend so long as we have an
// accessor for the size and the [] operator to access the items
// in the array.
std::ostream& operator<< (std::ostream&, const Vector&);
}
#endif