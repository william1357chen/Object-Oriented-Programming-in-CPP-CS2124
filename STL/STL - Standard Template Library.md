Standard Template Library
As the saying goes, books can and have been written about the STL. Anything we say here will, therefore, only be capable of serving as an introduction.

The main purpose of the STL is to provide a set of container classes. A container class is designed to contain or hold things of a given type. These containers include various data structures that may or may not be familiar yet, such as stacks, queues, lists, sets and vectors.

In addition to the containers themselves, STL provides a number of generic algorithms that can work with the different containers. There are algorithms for finding elements, copying from one container to another, sorting, etc. . You will need to:

#include <algorithm>

Also present there are three useful auxiliary functions: max, min and swap. max has essentially the same definition as our maximum example above.

Many of the STL generic algorithms involve making comparisons between two items in a container (or two items in separate containers). To allow these algorithms to work properly for containers holding items of a user defined class, it is necessary for both the operators < and == to be overloaded for the class. It is not necessary to also define the four comparison operators: !=, >, <=, >=. Other member functions that will get used are the assignment operator, the copy constructor and the default constructor. The class can make use of the versions of these provided by the system, or overload them as need be.

Between the container classes themselves and the generic algorithms that we wish to use with them, there is another contribution made by the STL called iterators. An iterator behaves in many ways like a pointer can for an array. Arrays are clearly a kind of container and we can use a pointer to iterate across an array. For example, assuming that we have defined an array called data with size size, then using pointers we can iterate over the array, printing out each element as we go, with the following code:

int size = 6;
int data[size] = {1, 1, 2, 3, 5, 8};
for (int* p = data; p != data + size; ++p) {
  cout << *p << endl;
}
Iterators allow us to follow a similar style of coding with the containers defined in the STL.

Containers
The table below shows the main containers defined in the Standard Template Library. We will focus on the stack and the vector.

stack

Allows access only to the top of the stack. Elements are pushed on the top, popped off the top and accessed while on the top. A stack is known as a LIFO (last in, first out) data structure because the Last item placed In the stack is the First item Out.

queue

Items are added to the back of a queue and removed from the front. A queue is known as a FIFO (first in, first out) data structure because the First item placed In the stack is the First item Out.

vector

Similar to an array, but it is capable of growing.

deque

Pronounced “deck”. It is a “double ended” queue.

list

Provides a doubly linked list.

set

Whether an item is present in the set or not can be fairly quickly determined. Only one instance of an item may be present.

multiset

Like a set, but multiple instances may be in the container.

map

Like a set, except that items are looked up by a key. Only one instance may be present.

multimap

Like a map, but multiple instances may be in the container.

Note that in a book on STL, the containers above would be viewed as fitting into three different groups. First, the stack and queue are actually implemented using one of the other containers, by default the deque. Therefore they are sometimes called a container adaptor.

The vector, deque and list are called sequence containers because they keep things in the same order that we place them in.

The set, multiset, map and multimap are known as associative containers. They make it efficient both to query whether an item is present and to retrieve an item. With a sequence container it would be necessary to traverse the sequence searching for an element.

Other than the stack and the queue, STL containers always make copies of items both when adding them to a container and when removing them.

Common features
All of the STL container types share certain operations in common. We will show some of them in the table below. In the table, the word ContType is used to refer to any of the STL containers. Thus the line:

ContType c;

would mean that we are defining a variable c of type ContType.

The information in the table is taken largely from The C++ Standard Library, by Josutis.


Operation

Effect

ContType c

Default constructor

ContType c1(c2)

Copy constructor. c1 is a new container of type ContType whose elements are copied from the container c2.

ContType c(begin, end)

A constructor that uses the iterators begin and end (from another container) to identify elements to include in c.

c.size()

Returns the actual number of elements in container c.

c.empty()

Returns true if c.size() == 0, otherwise false.

c.begin()

An iterator that points to the beginning of c.

c.end()

An iterator that points just past the last element in c.

c1 == c2

Tests if c1 is equal to c2, i.e, are they the same size and are their elements equal.

c1 < c2

Tests if c1 is “less than” c2. “Less” is defined lexicographically. Other such relation operations are also defined.

c.clear()

Removes all elements, making the container empty.

Stack
STL’s stack may be thought of having a definition that starts like the following:

template <class T>
class stack {
public:
 void push(const T&);
 void pop();
 T& top();
 bool empty() const;
 size_t size() const;
.
};
Thus there are three functions used to access or modify a stack. Items are added with push, removed with pop and accessed with top. Furthermore, as with all STL containers, the stack can be checked to see if it is empty and finally, the number of elements currently on stack can be determined.

Consider the code below, which shows a stack of integers being created, added to, and having elements removed from it (and printed). Note how easy it is to specify what sort of stack is to be created. As noted above, we could just as easily create a stack of elephants, assuming that a class has been defined for Elephant.

stack<int> s;
s.push(1);
s.push(2);
s.push(3);
s.push(5);
s.push(8);
while (!s.empty()) {
 cout << s.top() << “ “;

 s.pop();
}
cout << endl;
The above code would generate the output:

8 5 3 2 1

Vector
The vector provides facilities very much like an array. A major advantage is that a vector can grow as new items are added. Adding elements at the end of a vector is efficient. The function push_back() is used to add elements to the end, as in:

vector<int> v;
v.push_back(3); 
v.push_back(5); 
v.push_back(7); 
for (int i = 0; i<3; i++) {
 cout << v[i] << “ “;
}
cout << endl;
The above code would generate the output:

3 5 7

Like an array, the vector does not provide any array bounds checking when using the square brackets. Since a vector starts out with no elements the following two lines of code will fail in some undefined way:

vector<int> v;
cout << v[0] << endl; 
There is no element at index 0 to print, so we are trying to access an invalid entry. No exception is thrown. We can however use exceptions if we don’t use the square brackets but instead use the member function at():

vector<int> v;
try {
 cout << v.at(0) << endl;
} catch (out_of_range e) {
 cout << “Caught out_of_range error\n”;
}
Iterators
STL’s iterators provide a very powerful generalization of pointers. There are a few types of iterators in STL, but we will only look at the simplest sort, the forward iterator.

The first thing to learn is how to declare an iterator. Each container has its own iterator. To declare an iterator named p for a vector, it would look like:

vector<int>::iterator p;
Where do we get something to assign to an iterator? Every container has two methods, begin and end that return iterators. The iterator returned by begin points to the first element, while the iterator returned by end points past the last element.

How do we access something “pointed to” by an iterator? Same way as with a pointer. Use the dereferencing operator, *. How do we make an iterator point to the “next” element in the container? With the ++ operator.

vector<int> v;
v.push_back(3); 
v.push_back(5); 
vector<int>::iterator p = v.begin();
cout << *p << endl;
++p;
cout << *p << endl;
The above code will print out:

3
5
So what use is the iterator returned by end? If it points past the end of the container then there’s nothing there. And you can not dereference it. So what is its purpose? You use it in a test to see if you’ve gone past the end. Below we show the same code loop as earlier, but using iterators.

vector<int> v;
v.push_back(3);
v.push_back(5);
v.push_back(7);
vector<int>::iterator p;
for (p = v.begin(); p != v.end(); ++p) {
 cout << *p << “ “;
}
cout << endl;
Again, this code will print out:

3 5 7

Generic Algorithms
The generic algorithms allow us to do many things easily with STL’s containers that we would otherwise have had to code up ourselves, such as sorting, searching and making modifications of one type or another to every element in the container (e.g. “square every element that’s even”).

Furthermore, the generic algorithms can work with any container that supports the notion of iterators, even if it’s not built in to STL. We already know one such container. The array. Since we can define a pointer that points to the beginning of an array, and we can identify the location just passed the array, we can do the same kind of coding with arrays that we did above with iterators. One version, a variation of the code we used earlier would look like:

const int size = 9;
int data[size] = {1, 1, 2, 3, 5, 8, 13, 21, 34};
for (int *p = data; p != &data[size]; ++p) {
 cout << *p << “ “;
}
cout << endl;
The above code would print out:

1 1 2 3 5 8 13 21 34

We will just look at just a few of the many generic algorithms here, count, count_if and copy.

count
count counts up all the elements in a range that are equal to a particular value.

count takes three parameters:

An iterator pointing to the beginning of the range.
An iterator pointing to the end of the range (past the last element.
The value.
If we wanted to count the number of positions in the array data, above, that have the value 1, we could:

int countOfOnes = count(data, &data[size], 1);
cout << countOfOnes << endl;
Note in the above code that the first argument, data, gives the address of the beginning of the array. The second argument, &data[6], gives the address of the element just after the last element in the array. The third argument gives the actual value that we are looking to count.

count_if
is very similar to the generic function count. count_if counts up all the elements in a range that have a particular property.

count_if also takes three parameters:

An iterator pointing to the beginning of the range.
An iterator pointing to the end of the range (past the last element.
A boolean function that defines the property..
If we wanted to count how many of the elements are even, then we first need a boolean function that identifies even numbers:

bool isEven(int item) {
 return ((item % 2) == 0);
}
Now we can use our new function isEven as the third argument to the generic algorithm count:

int countOfEven = count_if(data, &data[size], isEven); 
cout << countOfEven << endl;
Here we are using the name of a function as an argument to a function. This is a powerful ability in C++. (A subtle detail is that what is passed here is in fact a pointer to the function, not the whole function itself.)

copy
copy copies the elements from one range, the source, to another, the target.

copy takes three parameters:

An iterator pointing to the beginning of the source range.
An iterator pointing to the end of the source range (past the last element).
An iterator pointing to the beginning of the target range.
If we have two vectors, v1 and v2, we can copy v1 into v2 with:

copy(v1.begin(), v1.end(), v2.begin());
Note that copy does not create the space to store the copied objects. The target had best already have the required capacity.
