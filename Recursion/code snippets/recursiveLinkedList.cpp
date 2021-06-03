/* 
	FILE: testRecursiveLinkedList.cpp
	CS 1124
	John Sterling

	Recursive versions of some of the linked list functions
*/

#include <iostream>
using namespace std;

struct Node {
	Node(int d = 0, Node* l = NULL) : data(d), link(l) {}
	int data;
	Node* link;
};

// No this one's not recursive.  Used to create lists to play with.
void listInsertHead(int entry, Node*& headPtr) {
	headPtr = new Node(entry, headPtr);
}

// This one's not recursive, either.  Used for "listClear2".
void listRemoveHead(Node*& headPtr) {
	if (headPtr) {
		Node* second = headPtr->link;
		delete headPtr;
		headPtr = second;
	}
}

// ===========Start of recursive function definitions==================

int listLength(const Node* headPtr) {
	if (headPtr) return 1 + listLength(headPtr->link);
	else return 0;
}

void listDisplay(const Node* headPtr) {
	if (headPtr) {
		cout << headPtr->data << ' ';
		listDisplay(headPtr->link);
	}
	else cout << endl; 
}

Node* listFindLast(Node* headPtr) {
	if (!headPtr) return NULL;	// Be nice if they pass in an empty list.
	else if (!headPtr->link) return headPtr;
	else return listFindLast(headPtr->link);
}

// A good choice for recursion, but we do this in recitation, so I won't solve it here.
Node* listDuplicate(const Node* sourcePtr);

void listClear(Node*& headPtr) {
	if (headPtr) listClear(headPtr->link);
	delete headPtr;
	headPtr = NULL;
}

// another version of listClear.
void listClear2(Node*& headPtr) {
	listRemoveHead(headPtr);
	if (headPtr) listClear2(headPtr);
}

Node* listSearch(int target, Node* headPtr) {
	if (!headPtr) return NULL;
	else if (headPtr->data == target) return headPtr;
	else return listSearch(target, headPtr->link);
}

Node* listNodeAtIndex(int index, Node* headPtr) {
	// if they ask for an index beyond the end of the list, return NULL
	if (!headPtr) return NULL;  
	else if (index) return listNodeAtIndex(index-1, headPtr->link);
	else return headPtr;
}

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
	cout << "listOne's length: " << listLength(listOne) << endl;

	Node* p = listSearch(2, listOne);
	cout << "The list starting with the value 2\n";
	listDisplay(p);

	Node* q = listNodeAtIndex(1, listOne);
	cout << "The list that starts at index 1 of listOne: ";
	listDisplay(q);

	cout << "Clear listOne\n";
	listClear(listOne);
	cout << "listOne: ";
	listDisplay(listOne);
	cout << "listOne's length is: " << listLength(listOne) << endl;
}
