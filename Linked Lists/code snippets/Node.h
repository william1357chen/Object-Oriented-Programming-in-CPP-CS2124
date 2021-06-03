/*
	File: Node.h
	The header file for the linked list toolkit
*/

#include <iostream>
#ifndef NODE_H
#define NODE_H
namespace CS1124 {

	// This version of Node provides a constructor which allows some functions
	// to be written more simply.  Notice that default arguments are provided
	// for both fields, NULL for the link and zero for the data.
	struct Node {
		Node(int x = 0, Node* l = NULL) : data(x), link(l) {}
		int data;
		Node* link;
	};

	// listDisplay displays the data values in the list.
	void listDisplay(const Node* headPtr, std::ostream& = std::cout) ;

	// listLength returns the length of the list pointed to by headPtr.
	int listLength(const Node* headPtr) ;

	// listInsertHead adds a new node to the list in front of the original head.
	void listInsertHead(int entry, Node*& headPtr) ;

	// listRemoveHead removes the first node from a list.
	void listRemoveHead(Node*& headPtr) ;

	// listInsert adds a new node to the list, immediately after the
	// node that previousPtr is pointing to.  
	void listInsertAfter(int entry, Node* previousPtr) ;

	// listRemove removes from the list the node immediately after previousPtr
	void listRemoveAfter(Node* previousPtr) ;

	// listFindLast returns a pointer to the last node in the list.
	// If the list is empty then NULL is returned.
	Node* listFindLast(Node* headPtr) ;

	// listAppend assumes that listOne has at least one node.
	// listOne is changed so that it's last node now points to listTwo.
	// If listOne was NULL, it now points at listTwo
	void listAppend(Node*& listOne, Node* listTwo);

	// listDuplicate creates a new list that is a copy of the original.
	// It creates a new node for every node in the original list.
	// listDuplicate returns the head pointer of the new list.
	Node* listDuplicate(const Node* sourcePtr) ;

	// listClear frees up all the nodes in a list, setting the head pointer to NULL.
	void listClear(Node*& headPtr) ;

	// listSearch returns a pointer to the first node in the list "headPtr"
	// that has the value "target".  
	// If the target value is not found then NULL is returned.
	Node* listSearch(int target, Node* headPtr) ;

	// listNodeAtIndex returns a pointer to the node in the list at position "index".
	// To be consistent with arrays, the first node in the list has index zero.
	Node* listNodeAtIndex(int index, Node* headPtr) ;
}
#endif