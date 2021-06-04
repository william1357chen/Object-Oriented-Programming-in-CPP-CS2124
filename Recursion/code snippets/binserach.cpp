//Program to demonstrate the recursive function for binary search.
#include <iostream>
using namespace std;


// binarySearch takes four arguments:
//   searchfor is the thing we are looking for
//   a[] is the array to search in.  It must be already sorted (i.e., in order)
//   left is the index in the array that we are startting at.
//   right is the index of the array that we are ending at.
// This version of binarySearch returns array index if the number was found
//       and -1 otherwise.

int binarySearch(int searchfor, int a[], int left, int right) {
  // we'll need the midpoint, so let's figure it out now.
  int mid = (left + right) / 2;
  // Did we miss it?
  // If the index "on the left" has gone passed the index "on the right" then 
  //    the number we want just isn't in the array.
  if (left > right) return -1;
  //  check to see if our target is at the index mid.
  //  If it is, then we have success!
  else if (searchfor == a[mid]) return mid;
  //  If our target is bigger than the value at mid then we need to search 
  //     to the right in the array. and return that result.
  else if (searchfor > a[mid])
    return binarySearch(searchfor, a, mid + 1, right);
  //  The only other possibility is that it is to the left, so we return 
  //  the result of searching there.
  else
    return binarySearch(searchfor, a, left, mid - 1);
}

int main( ) {
  const int ARRAY_SIZE = 14;
  int a[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
  int key = 0;
  cout << "a[] == {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610}\n";
  while (true) {
    cout << "Enter number to be located or -1 to exit: ";
    int key;
    cin >> key;
    if (key == -1) 
      break;
    else {
      int found = binarySearch(key, a, 0, ARRAY_SIZE - 1);
      if (found >= 0)
	cout << key << " is in index location "
	     << found << endl;
      else
	cout << key << " is not in the array." << endl;
    }
  }	   
  return 0;
}
