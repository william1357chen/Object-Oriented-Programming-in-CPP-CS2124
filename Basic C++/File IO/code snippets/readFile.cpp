
#include <iostream>	// cin, cout, cerr, endl
#include <fstream>	// ifstream
#include <string>	// string

using namespace std;

// main always has an int return type.
int main() {

	ifstream nameStream;
	cout << "What is the name of the file? ";
	string fileName;
	cin >> fileName;
	// We can not pass a string object to the 
	// method "open".
	// We have to pass a "C string".  
	// (C strings are just arrays of characters 
	// with a NULL character at the end.)
	// The method "c_str()" returns a C string 
	// version of a string object.
	nameStream.open(fileName.c_str());

	// We do not have to explicitly invoke the 
	// "fail" method here, though we could if we 
	// want.  When we test the stream object nameStream, 
	// it returns false if the stream is broken and true otherwise.
	// Note that it is perfectly ok to write "nameStream.fail()" instead 
	// of "!nameStream".
	if (!nameStream) {
		// Using the stream object cerr since this is an error message.
		cerr << "Couldn't open the names file.\n";
		return 1;
	}

	string name;

	// if nameStream is already broken before the read or breaks 
	// during the read then the test for the while will fail.
	// What does "broken" mean?  That we failed to do something that
	// we tried to do with the stream.
	while ( nameStream >> name ) {
		cout << name << endl;
	}

	nameStream.close();

	// Note that the following line, "return 0;" is optional. 
	// VC++6 used to give a warning 
	// but .Net does a better job of conforming to the standard.
	return 0;
}