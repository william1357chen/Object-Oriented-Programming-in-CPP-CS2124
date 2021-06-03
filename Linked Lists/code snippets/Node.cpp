/*
	File: Node.cpp
	John Sterling
	This implementation makes use of a constructor for Node.
	If you want detailed comments see the original version.
	This version takes additional "shortcuts":
		Temporary pointers are ONLY created where necessary:
			e.g., a pointer parameter is (re)used for walking 
			down the list.
		We use "while(p)" instead of "while(p != NULL)"
*/

#include "Node.h"
using namespace std;

namespace CS1124 {

	void listDisplay(const Node* p, ostream& os) {
		while (p) {
			os << p->data << ' ';
			p = p->link;
		}
		os << endl;
	}

	int listLength(const Node* p) {
		int length = 0;
		while (p != NULL) {
			length++;
			p = p->link;
		}
		return length;
	}

	void listInsertHead(int data, Node*& headPtr) {
		// Create a new node, holding data and pointing to headPtr.
		// Put the address of this new node back into headPtr.
		headPtr = new Node(data,  headPtr);
	}

	void listRemoveHead(Node*& headPtr) {
		if (headPtr) {
			Node* second = headPtr->link;
			delete headPtr;
			headPtr = second;
		}
	}

	void listInsertAfter(int entry, Node* previousPtr) {
		// Create a new node, holding data and pointing to the node
		// that comes after the node pointed to by previousPtr.
		// Store the address of the new Node back into that same link.
		previousPtr->link = new Node(entry,  previousPtr->link);
	}

	void listRemoveAfter(Node* previousPtr) {
		Node* removePtr = previousPtr->link;
		previousPtr->link = removePtr->link;
		delete removePtr;
	}

	Node* listFindLast(Node* p) {
		if (p)
			while (p->link) p = p->link;
		return p;
	}

	void listAppend(Node*& listOne, Node* listTwo) {
		if (listOne) {
			Node* p = listFindLast(listOne);
			p->link = listTwo;
		} else
			listOne = listTwo;
	}

	Node* listDuplicate(const Node* sourcePtr) {
		if (sourcePtr == NULL)
			return NULL;

		Node* newHead = new Node(sourcePtr->data);
		Node* newTail = newHead;

		const Node* p = sourcePtr->link;
		while (p) {
			listInsertAfter(p->data, newTail);
			newTail = newTail->link;
			p = p->link;
		}
		return newHead;
	}

	void listClear(Node*& p) {
		while (p) {
			Node *temp = p->link;
			delete p;
			p = temp;
		}
	}

	// As far as understanding pointer manipulation,
	// it is better that you understand the code 
	// above for listClear.
	// But this certainly is a tidier way to do the job.
	void listClear2(Node*& p) {
		while (p) listRemoveHead(p);
	}

	Node* listSearch(int target, Node* p) {
		while (p && p->data != target) 
			p = p->link;
		return p;
	}

	Node* listNodeAtIndex(int index, Node* p) {
		int count = 0;
		while (count < index && p != NULL) {
			count++;
			p = p->link;
		}
		return p;
	}
}