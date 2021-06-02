# Linked List
## Purpose
* What is the most common container that we have in C++?
    * array.
* What are the major downsides of this container?
    * No out-of-bounds check
    * Passing an array to a function usually requires passing its size, too.
    * We have to know the size when we write the program..
    * Can’t add or remove elements.
* Putting our arrays on the heap (i.e., *dynamic arrays*) can help
    * Then we can wait till we run the program to find out how large to make them.
    * If we need more space then we can make a new array and copy the items from the old * array into the new bigger array and add any new items that we need.
* But even using dynamic arrays will be slow if we keep adding or removing elements inside the container.
## Image
Assume we have the following array:
<table cellspacing="0" cellpadding="3" border="1">
  <tbody>
    <tr>
      <td width="40">0</td>
      <td width="40">1</td>
      <td width="40">2</td>
      <td width="40">3</td>
      <td width="40">5</td>
      <td width="40">8</td>
      <td width="40">13</td>
      <td width="40">21</td>
      <td width="40">34</td>
      <td width="40">55</td>
    </tr>
  </tbody>
</table>

Now we’d like to insert another 1 between the first two elements. First create a new dynamic array with enough space.
<table cellspacing="0" cellpadding="3" border="1">
  <tbody>
    <tr>
      <td width="40">&nbsp;</td>
      <td width="40"></td>
      <td width="40"></td>
      <td width="40"></td>
      <td width="40"></td>
      <td width="40"></td>
      <td width="40"></td>
      <td width="40"></td>
      <td width="40"></td>
      <td width="40"></td>
      <td width="40"></td>
    </tr>
  </tbody>
</table>

Then copy the data in:
<table cellspacing="0" cellpadding="3" border="1">
  <tbody>
    <tr>
      <td width="40">0</td>
      <td width="40">&nbsp;</td>
      <td width="40">1</td>
      <td width="40">2</td>
      <td width="40">3</td>
      <td width="40">5</td>
      <td width="40">8</td>
      <td width="40">13</td>
      <td width="40">21</td>
      <td width="40">34</td>
      <td width="40">55</td>
    </tr>
  </tbody>
</table>

And finally put the new value in the free space provided.
<table cellspacing="0" cellpadding="3" border="1">
  <tbody>
    <tr>
      <td width="40">0</td>
      <td width="40">1</td>
      <td width="40">1</td>
      <td width="40">2</td>
      <td width="40">3</td>
      <td width="40">5</td>
      <td width="40">8</td>
      <td width="40">13</td>
      <td width="40">21</td>
      <td width="40">34</td>
      <td width="40">55</td>
    </tr>
  </tbody>
</table>

How about if we separate all the elements from each other. (Note, we can't really do this with an array.)
<table cellspacing="0" cellpadding="3" border="1">
  <tbody>
    <tr>
      <td width="40">0</td>
      <td width="40"></td>
      <td width="40">1</td>
      <td width="40"></td>
      <td width="40">2</td>
      <td width="40"></td>
      <td width="40">3</td>
      <td width="40"></td>
      <td width="40">5</td>
      <td width="40"></td>
      <td width="40">8</td>
      <td width="40"></td>
      <td width="40">13</td>
      <td width="40"></td>
      <td width="40">21</td>
      <td width="40"></td>
      <td width="40">34</td>
      <td width="40"></td>
      <td width="40">55</td>
    </tr>
  </tbody>
</table>

Now its easy to insert a new element in between.
<table cellspacing="0" cellpadding="3" border="1">
  <tbody>
    <tr>
      <td width="40">0</td>
      <td width="40"></td>
      <td width="40">1</td>
      <td width="40"></td>
      <td width="40">1</td>
      <td width="40"></td>
      <td width="40">2</td>
      <td width="40"></td>
      <td width="40">3</td>
      <td width="40"></td>
      <td width="40">5</td>
      <td width="40"></td>
      <td width="40">8</td>
      <td width="40"></td>
      <td width="40">13</td>
      <td width="40"></td>
      <td width="40">21</td>
      <td width="40"></td>
      <td width="40">34</td>
      <td width="40"></td>
      <td width="40">55</td>
    </tr>
  </tbody>
</table>
But there’s no connection between the boxes. We can’t move from one to another as we can with an array. We must put back some form of connection.
<table cellspacing="0" cellpadding="3" border="1">
  <tbody>
    <tr>
      <td width="40">0</td>
      <td width="40">&#x2192;</td>
      <td width="40">1</td>
      <td width="40">&#x2192;</td>
      <td width="40">1</td>
      <td width="40">&#x2192;</td>
      <td width="40">2</td>
      <td width="40">&#x2192;</td>
      <td width="40">3</td>
      <td width="40">&#x2192;</td>
      <td width="40">5</td>
      <td width="40">&#x2192;</td>
      <td width="40">8</td>
      <td width="40">&#x2192;</td>
      <td width="40">13</td>
      <td width="40">&#x2192;</td>
      <td width="40">21</td>
      <td width="40">&#x2192;</td>
      <td width="40">34</td>
      <td width="40">&#x2192;</td>
      <td width="40">55</td>
    </tr>
  </tbody>
</table>

## Implementation
How can we turn such a picture above into code? Well, consider the arrow as part of the box to the left, that is the one that the arrow is starting from. So a box will contain two things, a piece of information (the numbers here) *and* an arrow. Arrow? Like a pointer? Right. The arrow can be implemented as a pointer to … To what? To an integer? No, not really. To a box that *holds* both an integer and another pointer.

What do the arrows/pointers let us do? Move from one box to the next. But what if we wanted to move back? We would need arrows going the other way, too.
<table cellspacing="0" cellpadding="3" border="1">
  <tbody>
    <tr>
      <td width="40">0</td>
      <td width="40">&#x2194;</td>
      <td width="40">1</td>
      <td width="40">&#x2194;</td>
      <td width="40">1</td>
      <td width="40">&#x2194;</td>
      <td width="40">2</td>
      <td width="40">&#x2194;</td>
      <td width="40">3</td>
      <td width="40">&#x2194;</td>
      <td width="40">5</td>
      <td width="40">&#x2194;</td>
      <td width="40">8</td>
      <td width="40">&#x2194;</td>
      <td width="40">13</td>
      <td width="40">&#x2194;</td>
      <td width="40">21</td>
      <td width="40">&#x2194;</td>
      <td width="40">34</td>
      <td width="40">&#x2194;</td>
      <td width="40">55</td>
    </tr>
  </tbody>
</table>

How could we represent such a thing? Each box has to have two arrows/pointers, one pointing left and one pointing right. This is called a **doubly-linked-list**. It is easier to move around such a list, but it is a little more work to maintain the extra pointers.

So we need a “thing” that can hold a piece of data and a pointer (or two pointers if we want a doubly-linked-list). We commonly call such a thing a “node”. How can we implement a node? With a struct.

Nodes are very, very simple. All we do with them is create them, and possibly change their data or pointers. With such an extremely simple structure, we sometimes skip the overhead of coding with accessors and mutators. Instead, everything, even the member variables, is public. In fact there really isn’t anything else except a constructor (and perhaps a display function).
```c++
struct Node {
public:
    int data;
    Node* next;
};
```
## Toolkit
So we can build linked lists with the `Node struct`. But we need to be able to *do* things with lists. For that we need to code up some typically useful functions. Implementations for several of these functions will be provided in the Sample Codes.

* Length
* Find an element that has a particular value.
* Insert a value at beginning / head
* Insert somewhere other than at the beginning / head
* Remove head
* Remove other than head
* Remove the first element in the list that has a particular value.
* Remove all elements with a particular value.
* Remove all elements from a list.
* Create a copy of a list
* Append one list onto another (non-destructive)

## Programming issues

* Looping over a list to do something to every node.
* Looping over a list to find (and perhaps do something with the *last* element).
* Passing a list so that we can add to or remove something to/from the beginning of the list. Why is this special?
* What should we pass to a function if it is to remove a particular node from a list?
* How much harder would these functions be to write for doubly linked lists?
* How to walk down two lists at the same time
    * at the same time creating a new list of the same length.