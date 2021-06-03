/*
	textVectorBasics.cpp
	1) read a file of integers into a vector
	2) display the values in the vector
*/

#include <iostream>	// cout, cerr, endl
#include <fstream>	// ifstream
#include <vector>	// vector
using namespace std;

int main() {
	cout << "Program: textVectorBasics.cpp\n\n";

	// Open the data file
	ifstream ifs("integers.txt");
	if (!ifs) {
		cerr << "Couldn't open 'intergers.txt'\n";
		exit(1);
	}

	// Create a vector to put the data into.
	// Note that it is a vector of ints.
	// It is initially empty.
	vector<int> alfred;

	int x;  // Temporary variable to read the data into
	// Usual loop for reading all the items from a file
	while (ifs >> x)
		// push_back increase the length of the vector by one
		// and copies x into this new last slot in the vector.
		alfred.push_back(x);

	// Loop over the vector printing out the values.
	// size_t: Note the use of size_t for the index variable.  
	//         Even if you don't usually use size_t, it's a good idea here, 
	//         because that's what the method size() returns.  
	//         If you don't use size_t you will get a warning.
	// size(): returns the count of how many items there are in
	//         the vector.
	for (size_t i = 0; i < alfred.size(); ++i)
		// Isn't it nice that we can access the elements in the vector
		// the same way we would an array?
		cout << alfred[i] << ' ';

	cout << endl;

}