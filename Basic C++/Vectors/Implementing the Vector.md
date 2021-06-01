# Implementing the Vector Class
## Topics
* What is a Vector?
* The type of the data pointer
* Destructor
* Copy Constructor
* Assignment Operator
* push_back method
* Looping over the vector
* pop_back and clear methods

Please note that these notes are not yet complete. I hope that they may still useful as as a supplement to the in-class code along with the content of the lectures and the labs.

## What is a Vector?
First of all, what is a vector? By now, we have been using them a lot. They have handy methods, like `push_back`, `pop_back`, `size`, `back` and `clear`. Furthermore, we can use square brackets to access and modify elements in the vector.

### But what does a vector look like *inside*?

Somehow it can "contain" lots of elements. And that number can grow. Hm, if we use the function `sizeof` on a vector, we are going to get the same result no matter how many elements our vector holds. On my machine I just tried it, running the following line:
```c++
    cout << sizeof(vector<int>) << endl;
```
and the result I saw was 24. That means that a vector `object` takes up 24 bytes. And that won't change, no matter how much the vector grows.

So where does all the data go? The answer is that the vector object keeps a pointer to the data, which is stored on the heap. To hold the data, we allocate an **array** on the heap. Because it is on the heap, and so can be created and destroyed, it is often referred to as a dynamic array.

What's an array? Just a contiguous block of memory that can hold a fixed number of things of the same type. We haven't bothered using arrays so far, simply because vectors are so much easier to deal with. Arrays are fairly "dumb". Well perhaps "ignorant" would be a more fair description. For example, you can't ask them how many elements they are holding. You can't make them grow when you add items. Simply put, vectors are easier to use, and that's why we haven't required that you use this more primitive type of thing.

Again, why do we *need* them now? Because we want to understand how that vector thing gets created.

Ok, the data is kept in an array and a *pointer to the array* is kept in the vector object. What else is there? As we noted above, I can't ask a dynamic array how big it is, so the vector object will have to store that information, too. We call this the **capacity**.

It may seem strange right now, be we keep two counters for the vector. How big the dynamic array is and separately how many elements we've placed into it. We'll discuss a little further down why we they aren't the same. (If you remember what you learned in data structures, this actually should be very familiar...)

## The type of the Data Pointer
So what is this data pointer? It is pointing to an array. But what is its **type**? Turns out its type is actually the same as the type of a pointer to a single item in the array. So, if we have a dynamic array of integers, then the data pointer will be an int*. (And if it is an array of int pointers, then it will be an int**, i.e. a pointer of int*'s.)

## Starting the class definition
Now that we know the type of the data pointer, and that we need a field tracking how big the array is and how many items we have placed in it so far, we can get a start on writing the class definition.
```c++
class Vector {
public:
private:
    int* data;
    size_t theSize;
    size_t theCapacity;
};
```

## Creating a dynamic array
If I want a dynamic array that can hold 10 ints, how do I allocate it?

```c++
new int[10]
```

So allocating a dynamic array is very similar to allocating a single item, but we also specify the size in square brackets.

And storing that address away in a pointer variable? We said that if the dynamic array holds ints, then the type of the pointer that points to that array should be int*, resulting in:

```c++
int* p = new int[10]
```

And just one more, if it was to be an array of *int pointers* the our variable would be defined and initialized as:

```c++
int** p = new int*[10]
```

Note the two places that there is an extra asterisk, compared to the prior example.

## Constructor
Now that we know how to create the dynamic array, we are ready to initialize our Vector. Let's start out by defining a constructor that allows us to specify an initial size for the Vector and a common value for all of the entries. Using c++'s vector class, we could write:

```c++
vector<int> v(10, 17) // a c++ vector holding 10 ints, all of which are 17
```

Our Vector class will always hold ints so we won't be specifying what kind of thing. We will talk later on (in a few weeks) about how to give our type the ability of specifying what type it will hold. So, the equivalent line using our class will be:
```c++
Vector v(10, 17) // our vector holding 10 ints, all of which are 17
```

How do we write that constructor? We need to allocate an array of the specified size, fill it with the specified value, and set our fields theSize and theCapacity.
```c++
Vector(size_t size, int value) {
    theSize = size;
    theCapacity = size;
    data = new int[size];
    for (size_t i = 0; i < theSize; ++i) {
        data[i] = value;
    }
}
```

You may not have noticed, but there's a somewhat surprising bit of syntax hiding in that function.

```c++
data[i] = value;
```

Why do I say it is surprising? What is data? It's a pointer. But we are *indexing* off of it, just as if it were a vector itself. (Or as if it were the *name* of an array.) We will talk later about how this actually works, when we discuss **pointer arithmetic**.

However now our line of code to define a "default" Vector no longer works since we no longer have a default constructor. How can we get one back? We could separately define a default constructor. Or we could provide default values for the parameters of the constructor we wrote.
```c++
Vector(size_t size=0, int value=0) {
    theSize = size;
    theCapacity = size;
    data = new int[capacity];
    for (size_t i = 0; i < theSize; ++i) {
        data[i] = value;
    }
}
```
Consider what happens when we use both of the defaults. Then the array that we create has a length of zero. That seems wierd. But C++ can deal with it. There really is a dynamic array. It is *not* the same as using a `nullptr`.

## Destructor
What should the destructor do? The one thing we have on the heap is the dynamic array. How do we free up a dynamic array? With delete, yes, but a little bit more. Look at the next two lines.
```c++
int* p = new int[10];
delete [] p;
```

Above we allocated our array as before. Then when we went to free it up, we used `delete []`. The `[]` tells the compiler that it is not just a single int that we want to delete, but instead a whole array of them.

Therefore the destructor is simply:
```c++
~Vector() {
    delete [] data;
}
```

## Copy Constructor
Now a reminder of what a copy constructor looks like:
```c++
Vector(const Vector& rhs) {  // Work in progress
    // Any copying code that couldn't go in the initialization list
}
```
What does the copy constructor need to do?
* Copy over the values in the size and capacity fields.
* Allocate a dynamic array to hold the data values
* Copy over the values from the original array to the new one.

Notice that all three fields in the class are *primitive*, so it doesn't matter whether we set them in the initialization list or in the body of the constructor.

Handling the first bullet, our constructor will look like:

```c++
Vector(const Vector& rhs) {  // Work in progress
    // Copying over the size and capacity
    theSize = rhs.theSize;
    theCapacity = rhs.theCapacity;
}
```

Next we need to allocate the dynamic array to hold the data
```c++
Vector(const Vector& rhs) {  // Work in progress
    // Copying over the size and capacity
    theSize = rhs.theSize;
    theCapacity = rhs.theCapacity;
    // Allocating the array
    data = new int[theCapacity];
}
```
And finally, a loop to copy the actual values over.
```c++
Vector(const Vector& rhs) {  // Done!!!
    // Copying over the size and capacity
    theSize = rhs.theSize;
    theCapacity = rhs.theCapacity;
    // Allocating the array
    data = new int[theCapacity];
    // Copying the data values
    for (size_t index = 0; index < theSize; ++index) {
        data[index] = rhs.data[index];
    }
}
```

## Assignment Operator
To start, what is the outliine that we developed for assignment operators before?
```c++
Vector& operator=(const Vector& rhs) {  // In progress
    // Check for self assignment
    // Free up the old
    // Allocate new and Copy
    // Return yourself
}
```
How do we check for self-assignment? Compare *addresses*! We compare our address with that of the righthand side. Filling that in, we get:
```c++
Vector& operator=(const Vector& rhs) {  // In progress
    // Check for self assignment
    if (this != &rhs) {
        // Free up the old
        // Allocate new and Copy
    }
    // Return yourself
}
```

Then jumping to the end, how do we return ourself? We need to return the *dereference* of this?
```c++
Vector& operator=(const Vector& rhs) {  // In progress
    // Check for self assignment
    if (this != &rhs) {
        // Free up the old
        // Allocate new and Copy
    }
    // Return yourself
    return *this;
}
```
What is it that we have to "free up"? The dynamic array that is pointed to by data. How do we free it up? We delete it. But remember that it is an array, so use `delete []`. And also, note that this is exactly the same thing that we did in the destructor.
```c++
Vector& operator=(const Vector& rhs) {  // In progress
    // Check for self assignment
    if (this != &rhs) {
        // Free up the old
        delete [] data;
        // Allocate new and Copy
    }
    // Return yourself
    return *this;
}
```
And finally, what does it mean here to "allocate and copy"? Same thing that we did back in the copy constructor, so I am just going to grab that code.
```c++
Vector& operator=(const Vector& rhs) {  // In progress
    // Check for self assignment
    if (this != &rhs) {
        // Free up the old
        delete [] data;
        // Allocate new and Copy
        // Copying over the size and capacity
        theSize = rhs.theSize;
        theCapacity = rhs.theCapacity;
        // Allocating the array
        data = new int[theCapacity];
        // Copying the data values
        for (size_t index = 0; index < theSize; ++index) {
            data[index] = rhs.data[index];
        }
    }
    // Return yourself
    return *this;
}
```
## push_back method
The push_back method is used for a vector to allow us to add an item to the end of the vector. But above I have said that we cannot make our arrays grow. How do we deal with this?

If there isn't enough space in the the old array, then just make a new one that *is* big enough! And of course copy all the values from the old array to the new one. Don't forget to free up the old one...

When we are done ensuring that the array is big enough, we can insert the new item and increase the *size* (as opposed to the capacity that we may have just increased.
```c++
void push_back(int val) {
    // In case we defined a vector with zero capacity
    if (theCapacity == 0) { 
        ++theCapacity;
        data = new int[theCapacity];
    }
    // Have we run out of room?
    if (theSize == theCapacity) {
        int* oldData = data;
        data = new int[2*theCapacity];
        theCapacity *= 2;
        for (size_t i = 0; i < theSize; ++i) {
            data[i] = oldData[i];
        }
        delete [] oldData;
    }

    data[theSize] = val;
    ++theSize;
}
```

## Looping over the vector
Having written the push_back method, we can now build up a vector, as in the following test code:
```c++
int main() {
    Vector v;
    v.push_back(17);
    v.push_back(42);
    v.push_back(6);
    v.push_back(28);
}
```
However, that doesn't give us the ability to see what's now in the vector. We need to be able to write a loop and print out the values.

Later on we will explore what is needed to allow the "ranged-for" on our Vector. For now we will just loop using indices:
```c++
int main() {
    Vector v;
    v.push_back(17);
    v.push_back(42);
    v.push_back(6);
    v.push_back(28);

    for (size_t i = 0; i < v.size(); ++i) {
         cout << v[i] << endl;
    }
}
```
What needs to be implemented? We need:
* a size method
* the ability to use the square brackets.

First the size method. That's just a getter:
```c++
size_t size() const { return theSize; }
```
Next we have to deal with the indexing, i.e. the square brackets: `v[i]`.

* What is it actually doing? It is simply asking the vector for the value at the corresponding entry.
* Also, it is an operator, so we have to understand what the compiler will convert that expressions to.
    * Whenever we overload an operator, we have to know if it should be overloaded as a member function or as a non-member function.
    * For the square-bracket operator, the answer is that C++ requires us to implement it as a member function.
    * v.operator[](i)
    * Yes, it looks a little curious. There's nothing between the square bracket. They're just part of the name of the function. The index shows up as the argument to the function.

Now that we know what the function call will look like, we should be able to define the method.
```c++
int operator[](size_t index) const { return data[index]; }
```

With all of that defined, our loop should correctly print out the contents of the vector.

## pop_back and clear methods
There are two methods that reduce the size of the vector, `pop_back` and `clear`. People are often surprised to learn that in the C++ vector class that these functions do not change how large the dynamic array is, but rather, only modify the value of the field that tracks how many items we are holding, theSize. The pop_back method will decrement it by one and the clear method will zero it.

```c++
void pop_back() { --theSize; }
void clear() { theSize = 0; }
```

It is worth noting that pop_back is "dangerous" as implemented. We could, first check if theSize is already zero, to decide whether or not to decrement. Your call.

### Still to add
* v[index] = 17;
* v = 17;
