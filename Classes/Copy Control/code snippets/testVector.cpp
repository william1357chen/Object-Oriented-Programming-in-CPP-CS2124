#include <iostream>
#include "Vector.h"
using namespace std;
using namespace CS1124;

int main() {
	// Define a vector of five elements.
	Vector v(5);
	
	cout << "Setting v to a sequence of squares." << endl;
	
	for (int i = 0; i < 5; i++) 
		v[i] = i * i;
	cout << "v = " << v << endl;
	
	cout << "Initializing w with the copy constructor" << endl;
	Vector w = v;
	
	cout << "v = " << v << endl;
	cout << "w = " << w << endl;
	cout << endl;
	
	cout << "v[0] = 17;" << endl;
	v[0] = 17;
	cout << "v = " << v << endl;
	cout << "w = " << w << endl;
	cout << endl;
	
	cout << "w = v;" << endl;
	w = v;
	cout << "v = " << v << endl;
	cout << "w = " << w << endl;
	cout << endl;

	// We'll make w a little larger and see what happens.  We should get "garbage"
	// in the new entries.
	w.resize(6);
	cout << "w.resize(6)\n" << w << endl;
	// Trying to resize v a smaller size should have no effect.
	v.resize(2);
	cout << "v.resize(2)\nWe hope nothing changes because we don't support resizing 'down'.\n" << v << endl;

	return 0;
}