#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

template <class T>
void displayContainer(const T& x) {
	for (T::const_iterator iter = x.begin(); iter != x.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

int main() {
	// create an array to use later.
	int myArray[] = {2, 3, 5, 7, 11, 13, 17};
	cout << "int myArray[] = {2, 3, 5, 7, 11, 13, 17};\n";

	// create an empty list of integers.
	list<int> li;
	
	// create a list of integers that contains
	// six entries all with the value 17.
	list<int> li2(6, 17);
	cout << "Creating: list<int> li2(6, 17)\n";
	// Display the list.
	cout << "Displaying li2\n";
	for (list<int>::iterator iter = li2.begin(); iter != li2.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	// create a list of integers that contains
	// the entries (3, 5, 7, 11) from myArray.
	// Note that we are using the address of the first
	// element and the address of the element just past
	// the last one that we want.
	list<int> li3(myArray+1, myArray+5);
	cout << "Creating: list<int> li3(myArray+1, myArray+5)\n";
	cout << "Displaying li3\n";
	for (list<int>::iterator iter = li3.begin(); iter != li3.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	li3.push_front(28);
	cout << "Pushing 28 on the front of li3\n";
	cout << "Displaying li3\n";
	for (list<int>::iterator iter = li3.begin(); iter != li3.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	
	cout << "Reversing the first six elements of myArray\n";
	reverse(myArray, myArray+6);
	for (int i = 0; i < 7; i++)
		cout << myArray[i] << " ";
	cout << endl;
	cout << "Sorting the last six elements of myArray\n";
	sort(myArray+1, myArray+7);
	for (int i = 0; i < 7; i++)
		cout << myArray[i] << " ";
	cout << endl;

	cout << "Creating a vector to contain a copy of the elements in li2\n";
	vector<int> vi(li3.begin(), li3.end());
	cout << "Sorting the vector\n";
	sort(vi.begin(), vi.end());
	for (int i = 0; i < vi.size(); i++)
		cout << vi[i] << " ";
	cout << endl;


	//  We would like to sort our list the same way, but iterators
	//  for lists don't behave quite the same way as pointers do or
	//  as iterators for vectors do.  So instead of the generic function call:
	//       sort(li3.begin(), li3.end());
	//  we have to call a member function:
	cout << "Sorting list li3:\n";
	li3.sort();
	for (list<int>::iterator iter = li3.begin(); iter != li3.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "Reversing list li3:\n";
	li3.reverse();
	for (list<int>::iterator iter = li3.begin(); iter != li3.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "Using 'find'.  The number 11 is in li3: ";
	cout << boolalpha << (find(li3.begin(), li3.end(), 11) != li3.end()) << endl;
	cout << "Using 'find'.  The number 14 is in li3: ";
	cout << boolalpha << (find(li3.begin(), li3.end(), 14) != li3.end())<< endl;



}
