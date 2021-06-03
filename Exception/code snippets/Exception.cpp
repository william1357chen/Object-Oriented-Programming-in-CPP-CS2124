/*
	File: TestException.cpp
	John Sterling
	Demonstrates how to throw / catch exceptions.
*/

#include <iostream>
#include <string>
using namespace std;

/* 
  Issues covered in this code.
  1) throw-list (aka exception specification).  
     a) Purpose: lists all the things a function can throw.
	 b) If it is used, it should appear in both the function
	    prototype and the function definition.
  2) Using a class to represent an exception.
     Here an object of the class IAmAnException might be 
	 spoken of as a "IAmAnException exception".
  3) Creating an "exception object" to throw.
     "throw IAmAnException()"
	 When creating an object to throw using the default constructor
	 you use parentheses after the default constructor name.
*/

void first();
void second();

// Sometimes the best sort of thing
class IAmAnException {};

int main() {
    first();
}

void first () {
	cout << "Before\n";
	try {
		second();
	} catch (string s) {
		cout << "Caught a string: " << s << endl;
	} catch (int n) {
		if (n!=7)
			cout << "Caught an integer: " << n << endl;
		else
			throw; // pass exception "up" -- local objects get extended lifetime.
	} catch (IAmAnException) {
		cout << "Caught an exception object\n";
	} catch (char s[]) {
		cout << "Caught a character array: " << s << endl;
	} catch (...) {}
	cout << "AFTER\n";
}

void second () 
{
	int q;  // Consider the lifetimes of q.
	cin >> q;
	if (q==0) return;
	else if (q == 1) throw 7;
	else if (q == 2) throw "I'm a message";
	else if (q == 3) throw 72.6;
	else if (q == 4) throw q;  // Now what happens to q...
	else if (q == 5) throw IAmAnException();
	else if (q == 6) throw 17;
}
