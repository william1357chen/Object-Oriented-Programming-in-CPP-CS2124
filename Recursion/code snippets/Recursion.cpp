#include <iostream>
using namespace std;

// Recursion
// A recursive function must:
// 1) call itself on a reduced task
// 2) know when to stop
// 3) do something SMALL in each call
// 4) Pay attention to the order of 1 and 3.

int factorial (int n);
void printOnetoN(int n);
void printNtoOne(int n);
void printDigits(int n);
void printDigitsInReverse(int n);
void printOctal(int n);
// How many 1's in the binary representation of n?
int parity(unsigned n);
// same as above but as a single line of code
int parity2(unsigned n);
// print n a's followed by n b's.
void printAB(int n);
int sumArray(int arr[], int n);
// same as above but as a single line of code
int sumArray2(int arr[], int n);
int maxArray(int arr[], int n);
bool checkPalindrome(char arr[], int n);
// same as above but as a single line of code
bool checkPalindrome2(char arr[], int n);

int main() {
	cout << "Print 1 to 11: ";
	printOnetoN(11);
	cout << endl;
	cout << "Print 11 to 1: ";
	printNtoOne(11);
	cout << endl;
	cout << "6! = " << factorial(6) << endl;
	cout << "256 in reverse: ";
	printDigitsInReverse(256);
	cout << endl;
	cout << "256 in octal: ";
	printOctal(256);
	cout << endl;
	cout << "5 in binary has " << parity(5) << " ones\n";
	cout << "7 in binary has " << parity(7) << " ones\n";
	cout << "Print 5 a's followed by 5 b's: ";
	printAB(5);
	cout << endl;
	int myArray[] = { 13, 1, 34, 8};
	cout << "myArray[] = { 13, 1, 34, 8}\n";
	cout << "max of myArray = " << maxArray(myArray, 4) << endl;
	cout << "sum of myArray = " << sumArray(myArray, 4) << endl;
	char charArray1[] = "Able was I ere I saw elbA";
	char charArray2[] = "Nothing special";
	cout << "charArray1: " << charArray1 << endl;
	cout << "is" << (checkPalindrome(charArray1, strlen(charArray1)) ? "" : " not") << " a palindrome\n";
	cout << "charArray2: " << charArray2 << endl;
	cout << "is" << (checkPalindrome(charArray2, strlen(charArray2)) ? "" : " not") << " a palindrome\n";

}

// 5! = 5 * 4 * 3 * 2 * 1
//    = 5 * 4!
// n! = n * (n-1)!
// factorial(5) = 5 * factorial(4)
int factorial (int n) {
	if (n == 1)
		return 1;
	else
		return n * factorial(n-1);
}
void printOnetoN(int n) {
	if (  n > 0 ) {
		printOnetoN( n - 1 );
		cout << n << " ";
	}
}
void printNtoOne(int n) {
	if (  n > 0 ) {
		cout << n << " ";
		printNtoOne( n - 1 );
	}
}

void printDigits(int n) {
	if (  n < 10 ) {
		cout << n;
	} else {
		printDigits( n / 10);
		cout << n % 10;
	}
}
void printDigits2(int n) {
	if (n >= 10)
		printDigits2(n / 10);
	cout << n % 10;
}

void printDigitsInReverse(int n) {
	if (  n < 10 ) {
		cout << n;
	} else {
		cout << n % 10;
		printDigitsInReverse( n / 10);
	}
}
void printDigitsInReverse2(int n) {
	cout << n % 10;
	if (  n >= 10 )
		printDigitsInReverse( n / 10);
}
void printOctal(int n) {
	if (  n < 8 ) {
		cout << n;
	} else {
		printOctal( n / 8);
		cout << n % 8;
	}
}
void printOctalReverse(int n) {
	cout << n % 8;
	if (  n >= 8 )
		printOctal( n / 8);
}

int parity(unsigned n) {
	if (n) 
		return (n % 2) + parity(n / 2);
	else
		return 0;
}
int parity2(unsigned n) {
	return (n==0) ? 0 : (n % 2) + parity2(n / 2);
}
void printAB(int n) {
	if (n) {
		cout << "a";
		printAB(n-1);
		cout << "b";
	}
}
int sumArray(int arr[], int n) {
	if (n == 0)
		return 0;
	else
		return arr[0] + sumArray(arr+1, n-1);
}
int sumArray2(int arr[], int n) {
	return (n == 0) ? 0 :(arr[0] + sumArray(arr+1, n-1));
}
int maxArray(int arr[], int n) {
	if (n == 1)
		return arr[0];
	else
		return max(arr[0], maxArray(arr+1, n-1));
}
bool checkPalindrome(char arr[], int n) {
	if (n < 2) 
		return true;
	else if (arr[0] != arr[n-1])
		return false;
	else
		return checkPalindrome(arr+1, n-2);
}
bool checkPalindrome2(char arr[], int n) {
	return (n < 2) ? true : (arr[0] == arr[n-1]) && checkPalindrome2(arr+1, n-2);
}