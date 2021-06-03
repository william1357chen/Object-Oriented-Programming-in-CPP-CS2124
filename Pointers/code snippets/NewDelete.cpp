#include <iostream>
using namespace std;

int main() {

	// Defining an array of ints.  We have to know how
	// many ints there will be when we write the program.
	int arr[5] = {1, 4, 9, 16, 25};

	// What if we want to ask the user how big an array to use?
	cout << "How big an array do you want? ";
	int arraySize;
	cin >> arraySize;

	// We might like to write:
	// int anotherArray[arraySize];
	// But that would result in a compilation error, complaining that
	// we should use a constant expression for the size of the array.
	// Instead if we want to create an array with a size that we get
	// from the user, then we have to write:
	int* myIntPtr = new int[arraySize];

	// How do we use the pointer called myIntPtr?
	for (int i = 0; i < arraySize; i++)
		myIntPtr[i] = i * i;

	// Let's loop again, this time using pointer arithmetic
	for (int i = 0; i < arraySize; i++)
		cout << *(myIntPtr + i) << ", ";
	cout << endl;

	// Now let's "free up" the memory we used for the array.
	delete [] myIntPtr;

	// We no longer have official permission to use the memory
	// where that array was.  And soon it might get reused for 
	// something else.  But let's just see if it still has our 
	// values there for now.  Our program could crash now...
	cout << "We freed up the memory, let's see what's there now\n";
	for (int i = 0; i < arraySize; i++)
		cout << *(myIntPtr + i) << ", ";
	cout << endl;

	// Of course we could be using array notation in that loop above:
	cout << "Printing it again using array notation\n"
		<< "Should look the same.\n";
	for (int i = 0; i < arraySize; i++)
		cout << myIntPtr[i] << ", ";
	cout << endl;


}