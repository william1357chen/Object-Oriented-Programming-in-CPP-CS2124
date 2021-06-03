/*
	vectorOfClass.cpp
	1) read a file into a vector of class objects.
	2) display the values in the vector

*/

#include <iostream>	// cout, cerr, endl
#include <fstream>	// ifstream
#include <vector>
#include <string>
using namespace std;

class Car {
public:
	Car(const string& theMake, const string& theModel, int theYear)
		: make(theMake), model(theModel), year(theYear)
	{}
	void display() const { 
		cout << "Make: " << make 
			<< "; Model: " << model 
			<< "; Year: " << year << endl;
	}
private:
	string make;
	string model;
	int year;
};  // Remember the semi-colon.  I forgot it.  Again.

int main() {
	cout << "Program: vectorOfClass.cpp\n\n";

	// Open the data file
	ifstream ifs("cars.txt");
	if (!ifs) {
		cerr << "Couldn't open 'cars.txt'\n";
		exit(1);
	}

	// Create a vector to put the data into.
	// The vector is initially empty.
	vector<Car> myCars;

	string make;	// Temporary variable to read the make into
	string model;	// Temporary variable to read the model into
	int year;	// Temporary variable to read the year into
	// Usual loop for reading all the items from a file
	while (ifs >> make >> model >> year) {
		// Create a car
		Car aCar(make, model, year);
		// Push a COPY of aCar onto the end of the vector
		myCars.push_back(aCar);
	}

	// Loop over the vector printing out the values.
	for (size_t i = 0; i < myCars.size(); ++i) {
		myCars[i].display();
	}
}