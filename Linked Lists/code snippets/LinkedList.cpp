/* 
	FILE: testLinkedList.cpp
	CS 1124
	John Sterling

	Loops: for or while?
	This version of the toolkit will generally use while loops 
	because I think it is easier to explain what we are doing at
	each step that way.  Using for loops would generally make the code a few
	lines shorter, but would do exactly the same thing.  Be sure that you
	can write these functions either way.

	Frequently we have a test such as:
		while (p != NULL)
	In every case, we could have written the line as:
		while (p)
	Both lines mean the same thing and you should be able 
	to read the code whichever style is used.

	When we are walking down a list, we always create a temporary pointer.
	Strictly speaking this is not always necessary, but it does make the
	code easier to understand.  You are not required to create such temporary
	pointers if they are not actually needed.

	Functions provided:
		listLength
		listLengthFor  // Same as listLength but uses for-loop
		listInsertHead	
		listRemoveHead
		listInsertAfter
		listRemoveAfter
		listFindLast
		listAppend
		listDuplicate
		listClear
		listSearch
		listNodeAtIndex
*/



#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* link;
};

// listLength determines the length of the list pointed to by headPtr.
// headPtr is declared as a pointer to a constant node, because we do
// not intend to change anything in the nodes in the list.
int listLength(const Node* headPtr) {

	// Declare a variable to hold the length.  
	// We begin assuming that the length is zero.
	int length = 0;

	// Declare a temporary variable to use to "walk down" the list.
	// As noted above this is not strictly necessary.
	const Node* p = headPtr;

	// Loop through the list.  Note the test condition.  If p is NULL
	// that means that we are not pointing to a node anymore.
	while (p != NULL) {
		// If we came into the loop then we must be pointing to a node
		// so increase the length.
		length++;
		// Now we need to set the pointer to the point to the next node.
		// Be careful to note that we CANNOT just say, "p++;".  Be sure
		// that you know why!
		p = p->link;
	}
	return length;
}

// listLengthFor does the same thing as listLength but uses a for loop
// instead of a while loop. 
int listLengthFor(const Node* headPtr) {
	int length = 0;
	for (const Node* p = headPtr; p != NULL; p = p->link)
		length++;
	return length;
}

// listDisplay displays  the data values in the list.
// All the values are displayed on a single line with blanks separating the values.
// It functions almost exactly like listCount.  The only difference is
// that at each node, we display the data instead of increment the count.
void listDisplay(const Node* headPtr) {
	// Declare a temporary variable to use to "walk down" the list.
	const Node* p = headPtr;
	// Loop through the list.  Note the test condition.  If p is NULL
	// that means that we are not pointing to a node anymore.
	while (p != NULL) {
		// If we came into the loop then we must be pointing to a node
		// so display the data.
		cout << p->data << ' ';
		// Now we need to set the pointer to the point to the next node.
		// Be careful to note that we CANNOT just say, "p++;".  Be sure
		// that you know why!
		p = p->link;
	}
	cout << endl;
}

// listInsertHead adds a new node to the list in front of the original
// first node.  The new node contains the data value "entry".
// NOTE: we must pass the parameter "headPtr" be reference.  Why???
void listInsertHead(int entry, Node*& headPtr) {
	// Create a new node.  Where are we putting it??
	Node* temp = new Node;
	// Place the new entry into the new node.
	temp->data = entry;
	// Make the new node point to the first node of the original list.
	temp->link = headPtr;
	// Make the headPtr point to the new node.
	headPtr = temp;
}

// listRemoveHead removes the first node from a list.
// NOTE: we must pass the parameter "headPtr" be reference.  Why???
void listRemoveHead(Node*& headPtr) {
	// Don't do anything if the the list is empty
	if (headPtr != NULL) {
		// Create a pointer to the second node in the list.
		// It will become the first node of the list after we remove the
		// original first node.
		Node* second = headPtr->link;
		// Now we can get rid of the first node in the list.
		delete headPtr;
		// Set the headPtr to point to the old second node.
		headPtr = second;
	}
}

// listInsert adds a new node to the list, immediately after the
// node that previousPtr is pointing to.  The new node the data value "entry".
// Note that previousPtr is NOT passed by reference.  Why??
void listInsertAfter(int entry, Node* previousPtr) {
	// Create a new node.  Where are we putting it??
	Node* temp = new Node;
	// Place the new entry into the new node.
	temp->data = entry;
	// Make the new node point to the next node after previousPtr.
	temp->link = previousPtr->link;
	// Make previousPtr's node point to the new node.
	previousPtr->link = temp;
}

// listRemove removes from the list the node immediately after previousPtr
void listRemoveAfter(Node* previousPtr) {
	// We need a temporay pointer.  We've set it to point to the node
	// that we will be removing.
	Node* removePtr = previousPtr->link;
	// Now we can make the previous node point to the node after the one
	// that we will be removing.  Once we do this, we will have successfully
	// "removed" the old node from the list.  But not deleted it.
	previousPtr->link = removePtr->link;
	// Finally we can delete the node.
	delete removePtr;
}

// listFindLast returns a pointer to the last node in the list.
// If the list is empty then NULL is returned.
Node* listFindLast(Node* headPtr) {
	Node* p = headPtr;
	if (p != NULL) {
		// The most important part of this function is the while condition.
		// Note that when the loop is over, p points to the last item.
		// If we had tested "while (p != NULL)" then p would be NULL!!!
		while (p->link != NULL)
			p = p->link;
	}
	return p;
}

// The list pointed to by listOne is changed so that it's last node 
// now points to listTwo.
// Why is listOne passed by reference?  Only for the case in which
// listOne was NULL.  Only then does listOne, itself, change!
void listAppend(Node*& listOne, Node* listTwo) {
	if (listOne == NULL)
		listOne = listTwo;
	else {
		Node* p = listFindLast(listOne);
		p->link = listTwo;
	}
}


// listDuplicate creates a new list that is a copy of the original.
// It creates a new node for every node in the original list.
// listDuplicate returns the head pointer of the new list.
Node* listDuplicate(const Node* sourcePtr) {
	// If we pass in an empty list then just return an empty list.
	if (sourcePtr == NULL)
		return NULL;

	// Set up the first node for the new list.
	// Create it.
	Node* newHead = new Node;
	// Copy the data from the head node of the originial list
	newHead->data = sourcePtr->data;
	// The new node should have a NULL "link" pointer.
	newHead->link = NULL;

	// Keep track of the last node of the new list.
	// For now that's the same as the head node.
	Node* last = newHead;
	// Declare a temporary variable to use to "walk down" the list.
	// Since we already made a copy of the first node, we can start
	// we the next one.
	const Node* p = sourcePtr->link;
	// Keep going so long as we have any nodes.
	while (p != NULL) {
		// We have data to add right after "last", so use the toolkit!
		listInsertAfter(p->data, last);
		// Move the last pointer to point to the new last node
		last = last->link;
		// 
		p = p->link;
	}
	return newHead;
}

// listClear frees up all the nodes in a list 
// and sets the head pointer to NULL.
void listClear(Node*& headPtr) {
	// Declare a temporary variable to use to "walk down" the list.
	Node *p = headPtr;
	// We can clear headPtr now that we have our temporary pointing to
	// the head node.
	headPtr = NULL;
	// Keep going so long as we have any nodes.
	while (p != NULL) {
		// Remember where the next node is after the one we're about to delete
		Node *link = p->link;
		// Delete the current node.
		delete p;
		// Set the current pointer to the next node
		// that we were careful to remember.
		p = link;
	}
}

// listSearch returns a pointer to the first node in the list "headPtr"
// that has the value "target".  
// If the target value is not found then NULL is returned.
Node* listSearch(int target, Node* headPtr) {
	// Declare a temporary variable to use to "walk down" the list.
	Node* p = headPtr;
	// Walk down the list so long as we have any nodes left
	// and we haven't found the target.
	while (p != NULL && p->data != target)
		p = p->link;
	// When we are done, either p is NULL meaning that we failed
	// or it points to the desired node.  
	// Either way it is what we want to return.
	return p;
}

// listNodeAtIndex returns a pointer to the node in the list at position "index".
// To be consistent with arrays, the first node in the list has index zero.
Node* listNodeAtIndex(int index, Node* headPtr) {
	int count = 0;
	Node* p = headPtr;
	while (count < index && p != NULL) {
		count++;
		p = p->link;
	}
	return p;
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
