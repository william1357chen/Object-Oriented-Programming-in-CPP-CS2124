/*
	testIncreasingArraySize.cpp
	John Sterling
	CS1124
	Demonstrate how to "Expand" the array, as needed,
	in order to hold the contents of a file.	.
*/


#include <iostream>
#include <fstream>
using namespace std;

const size_t INITIAL_SIZE = 3;

void fillArray(int*& arr, size_t& count, size_t& size, ifstream& ifs);

int main() {

	size_t size = INITIAL_SIZE;
	size_t count = 0;	// index for next entry.  Also count of entries.
	int* arr = new int[size];	// Initial array.

	ifstream ifs("data.txt");  // We should check if the file opened correctly.

	fillArray(arr, count, size, ifs);

	// Let's just see what's in the array, to make sure the code worked.
	for (size_t i = 0; i < count; ++i)
		cout << arr[i] << endl;

}

// Pass the array and the size by reference because they are both going to change.
void expandArray(int*& arr, size_t& size) {
	size_t newSize = 2 * size;	// The size for the new array.
	int* temp = new int[newSize];	// This is the new array.
	// Loop to copy the data from the old array to the new one
	for (size_t i = 0; i < size; ++i)
		temp[i] = arr[i];
	delete [] arr;  // Now we can get rid of the old array.
	arr = temp;		// Our array pointer needs to point to the new array
	size = newSize;	// and our size needs the expanded size.
}

// fillArray fill the array arr from the stream ifs.
// count is how many entries in the array are already used.
// size is the size of the array.
// The array may have to be resized, so it and the size are passed by reference.
// The count will also change as we add entries so it is also passed by reference.
// We already know that streams are always passed by reference, because they 
// change whenever we read or write them.
void fillArray(int*& arr, size_t& count, size_t& size, ifstream& ifs) {
	int x;	// Some place to read the information into
	while (ifs >> x) { // Get the next item from the file
		if (count == size) // Is our array already full?
			expandArray(arr, size);  // then "expand" it.
		arr[count++] = x;	// Put the item into the array since we now have room.
	}
}

