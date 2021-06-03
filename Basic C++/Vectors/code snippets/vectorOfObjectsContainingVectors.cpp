/*
	vectorOfStructsContainingVectors.cpp

	Demonstrate the use of arrays that hold
	struct objects that hold arrays

	John Sterling
	CS1124
	Polytechnic University
*/


#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

//const int BREED_MAX = 20;		// Maximum number of breeds that can be stored for a Dog.
//								// This should be a static const int inside the Dog struct, 
//								// but we haven't covered that.
//
struct Dog {
	string name;				// The name of the dog
	vector<string> breed;	// A dog may be a combination of several breeds
//	int countOfBreeds;			// How many breeds for this dog?
	int age;					// Age of the dog.  (Probably better to use date of birth).

};
void displayDog(const Dog&);

void fillKennel(ifstream&, vector<Dog>&);

int main() {
	//const int KENNEL_SIZE = 10;
	vector<Dog> kennel;
	ifstream ifs;
	ifs.open("dogs.txt");
	if (!ifs) {		// equivalent to:  if (ifs.fail()) {
		cerr << "Idiot!  I can't open the file!\n";
		exit(17);
	}

	fillKennel(ifs, kennel);

	// Note that we use the method size here.
	cout << "Total number of dogs read in: " << static_cast<unsigned>(kennel.size()) << endl;

	// Display the dogs that were read in
	for (size_t i = 0; i < kennel.size(); ++i) displayDog(kennel[i]);
}

// fillKennel is passed a stream to read descriptions of dogs from,
//                      a vector of dogs to fill
// Each line of the file describes a single dog.
// Each line consists of:
//     name age breed1 breed2 ...
void fillKennel(ifstream& dogStream, vector<Dog>& myDogs) {
	// Fill the array.
	// Use the && operator's "short circuiting" 
	// to prevent more than sizeOfDogs number of Dogs to be read
	string name;
	while (dogStream >> name) {
		Dog aDog;
		aDog.name = name;
		dogStream >> aDog.age;

		string breeds;
		getline(dogStream, breeds);	// Get the remainder of the line containing thebreeds
		istringstream iss(breeds);	// Set up a stream to read the breeds from

		string aBreed;
		//aDog.breed.clear();  // Need this if aDog is defined outside the loop
		// Fill the Dog's vector of breeds.
		while( iss >> aBreed ) aDog.breed.push_back(aBreed);

		myDogs.push_back(aDog);
	}
}

// Display a dog
void displayDog(const Dog& d) {
	cout << "Name: " << d.name 
		<< "; Age: " << d.age
		<< "; Breeds: ";
	// Display all but the last breed followed by ", ".
	for (size_t i = 0; i < d.breed.size()-1; ++i)	cout << d.breed[i] << ", ";
	// Display the last breed followed by a newline.
	if (d.breed.size()> 0) cout << d.breed.back() << endl;
}