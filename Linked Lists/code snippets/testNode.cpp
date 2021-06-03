/* 
	FILE: testLinkedList.cpp
	CS 1124
	John Sterling

	Test code for the basic linked list toolkit.

*/

#include <iostream>
#include "Node.h"
using namespace std;
using namespace CS1124;

int main() {
	Node* listOne = NULL;
	cout << "listOne is empty. It's length is: " << listLength(listOne) << endl;

	listInsertHead(1, listOne);
	listInsertHead(2, listOne);
	listInsertHead(3, listOne);
	listInsertHead(5, listOne);
	cout << "Use listInsertHead to insert the values: 1, 2, 3 & 5\n";
	cout << "listOne: ";
	listDisplay(listOne);
	Node* listTwo = listDuplicate(listOne);
	cout << "Use listDuplicate on listOne to create listTwo\n";
	cout << "listTwo: ";
	listDisplay(listTwo);

	listRemoveHead(listOne);
	cout << "Remove listOne's head\n";
	cout << "listOne: ";
	listDisplay(listOne);
	cout << "listTwo: ";
	listDisplay(listTwo);
	cout << "Note that listTwo is unchanged\n";

	Node* p = listSearch(2, listOne);
	cout << "The list starting with the value 2\n";
	listDisplay(p);
	listInsertAfter(17, p);
	cout << "Add 17 following 2\n";
	cout << "listOne: ";
	listDisplay(listOne);

	Node* q = listNodeAtIndex(2, listOne);
	cout << "The list that starts at index 2 of listOne: ";
	listDisplay(q);
	listRemoveAfter(q);
	cout << "Removing the node following listOne's node with an index of 2\n";
	cout << "listOne: ";
	listDisplay(listOne);
	cout << "listOne's length is: " << listLength(listOne) << endl;
	listClear(listOne);
	cout << "Clear listOne\n";
	cout << "listOne: ";
	listDisplay(listOne);
	cout << "listOne's length is: " << listLength(listOne) << endl;
	listClear(listOne);

	Node* listThree = listDuplicate(listTwo);
	cout << "Create listThree as a duplicate of listTwo.\n";
	cout << "listThree: ";
	listDisplay(listThree);
	listAppend(listTwo, listThree);
	cout << "Append listThree onto listTwo.\n";
	cout << "listTwo: ";
	listDisplay(listTwo);
	cout << "listThree: ";
	listDisplay(listThree);
}
