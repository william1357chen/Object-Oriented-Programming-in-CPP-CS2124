#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

namespace CS1124 {
	
	template <class T>
	class Vector {

		// Within the class definition, any use of "Vector" as a class
		// will be understood by the compiler to mean "Vector<T>".
		// Examples are the second parameter to the << operator
		// and the parameter to the copy constructor.  In any such case
		// you can write "Vector<T>" or "Vector" -- both are correct.

		template <class T>
		friend std::ostream& operator<< (std::ostream&, const Vector<T>&);
	public:
		//CONSTRUCTORS
		Vector();				// Default Constructor		
		Vector(const Vector&);	// Copy Constructor	
		Vector(int);			// Create a vector of a particular size
		
		// DESTRUCTOR
		~Vector();

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
		T& operator[](int i);
		T operator[] (int i) const;		
	private:
		int size;
		T * data;
	};

	// Note the use of the member initialization list.
	template <class T>
	Vector<T>::Vector() : size (4), data (new T[size]) {
	}
	
	template <class T>
	Vector<T>::Vector(int s) : size (s), data (new T[size]){
	}
	
	// Copy Constructor
	// Note the type of the parameter.  
	// Any use of Vector with the scope of the 
	// function name (qualified with Vector<T>)
	// is assumed to mean Vector<T>
	template <class T>
	Vector<T>::Vector(const Vector& v) {
		size = v.size;
		data = new T[size];
		for (int i = 0; i < size; i++)
			data[i] = v.data[i];
	}
	
	// Destructor
	template <class T>
	Vector<T>::~Vector() {
		delete [] data;
	}

	// Change the size of the Vector.
	// If newSize is not larger than the current size, 
	// we will not do anything.
	template <class T>
	void Vector<T>::resize(int newSize) {
		if (newSize > size) {
			T* newData = new T[newSize];
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
	template <class T>
		// Note that the return type is NOT IN THE SCOPE of the function name,
		// so we have to put Vector<T> instead of just Vector.
	Vector<T>& Vector<T>::operator=(const Vector& right) {
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
				data = new T[size];
			}
			for (int i = 0; i < size; i++)
				data[i] = right.data[i];
		}
		return *this;
	}
	
	// operator<< is printing a ", " after each element in
	// the Vector except for the last.
	template <class T>
	std::ostream& operator<< (std::ostream& os, const Vector<T>& v) {
		for (int i = 0; i < v.size; i++) {
			os << v.data[i];
			if (i < v.size - 1) os << ", ";
		}
		return os;
	}
	
	template <class T>
	T& Vector<T>::operator[] (int index) {
			return data[index];
	}
	template <class T>
	T Vector<T>::operator[] (int index) const {
			return data[index];
	}
}
#endif