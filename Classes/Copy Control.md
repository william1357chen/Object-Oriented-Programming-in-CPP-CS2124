# Copy Control / Big 3
Topics
Concept
Destructor
Copy Constructor
Assignment Operator
Inheritance
## Concept

### What are the "Big 3"?
The Big 3 refers to the **destructor**, the **assignment operator** and the **copy constructor**.

### Why do we care?
Most of the time you don't. At least you haven't so far. But sometimes you need to. Suppose we have a simple class such as the following:

```c++
class SimpleClass {
public:
    SimpleClass() { p = new int(17); }
private:
    int* p;
}; 
Now suppose we create an instance of SimpleClass in a function:

void aFunction() {
    SimpleClass simp;
}
```
What happens when we call `aFunction`? More importantly, what happens when it finishes? The variable `simp` goes "out of scope". What happens to the the memory on the heap that `simp.p` was pointing at? It has become garbage. We now have a **memory leak**.

Solution? Write a **destructor**. But after you write the destructor, it will turn out that you want to write a **copy constructor** and an **assignment operator**, too. These three functions tend to go together - if you need one, you likely need the other two.

## Destructor
The destructor is pretty simple. It's job is to free up whatever resources need to be freed up when an object is about to be "destroyed" (out of scope). For us, the "resources" just refer to items or arrays that were allocated on the heap. If the object being destroyed is *responsible* for the memory on the heap, then it should have a destructor to free it up.

How do you write a destructor? First, what's its name? The destructor's name is the same as the name of the class, execept it starts with one extra character, know as "tilde" `~` .

Is there anything else special about the function? Glad you asked. Like the constructor(s), it does not have a return type. At all. Unlike the constructors, there is only one destructor. You can't overload it based on passing different parameters, because you don't ever pass parameters to a destructor.

In fact, you don't call the destructor. The "system" does.

So, here's a suitable destructor for our simple class.

```c++
~SimpleClass() { delete p; }
```
That's it. Free up the memory that was allocated for this object.

## Copy Constructor

What does a constructor do? *Initializes* the member variables of an object when it is created. Sometimes constructors have parameters so that we can pass arguments to tell the constructor how to initialize the new object.

When the argument is another object of the same type, then we call the constructor a copy constructor. This is a very important constructor. It is called a lot. Here are four somewhat different times that the copy constructor is used:
```c++
1.  SomeClass a;
    SomeClass b(a);

2.  SomeClass a;
    SomeClass b = a;

3.  void someFunc(SomeClass passedByValue) {}

4.  SomeClass anotherFunc () { SomeClass returnedByValue; return returnedByValue; }
```
Items `1` and `2` above are both creating an object and initializing based on another object of the same type. In `both cases`, it is the copy constructor that is called.

Item `3` shows a function with a parameter that is passed by value. Passing by value uses the copy constructor to initialize the parameter.

Item `4` shows a function with a value that is returned by value. Returning by value uses the copy constructor to return a copy of the value that is being returned. (That all looks cyclical, but it actually says the right thing.)

Here's a suitable copy constructor for our simple class:

```c++
SimpleClass(const SimpleClass& rhs) {
     p = new int;  // Allocate
    *p = *rhs.p;   // Initialize (well, actually "set").
}
```

The constructor is allocating space on the heap, and initializing/setting that space to hold a copy of the value in the original. (There's gotta be a simpler way to say these things.).

## Assignment Operator
Now for the last of the Big 3. But it's the biggest.

### Responsibilities
The assignment operator has more responsibility than the copy constructor. Why?

The copy constructor is only *initializing* an object and doesn't have to worry about any information or resources that the object already has.

The assignment operator, on the other hand, is *changing* an object. It has to, possibly:

1. get rid of things the object already has
1. replace them with new things
3. copy over the values from the object on the "right-hand side" to the "left-hand side".

Step 1 is what the destructor does. Steps 2 and 3 together are what the copy constructor does. Sure it would be nice if we could just "call" those two functions - but we can't. However, it sure makes this function easier, knowing that it just consists of the same work we would have done for the other two.

In addition the assignment operator has to:

* return the right thing
* check for self-assignment.

### Member or non-member?

Member. The language doesn't give us a choice.

### Return Type and Value
The assignment operator has a return type. (Neither the destructor nor the copy constructor did, so we didn't have to worry about them.) What should it be? Void? NO! (No matter what you may read in "some" books.)

C++ programmers expect to be able to write things like:
```c++
x = y = z;
```
That means the same as the parenthesized:
```c++
x = ( y = z ) ;
```
Guess what would happen if the value of the expression `y = z` was void. That line up there could not compile! That's why it has to have a value. What value? The same as what's in y after the assignment in parentheses.

That tells us that the type could be `SomeClass`. But should we return it by value or by reference? In other words, should the type be `SomeClass` or `SomeClass&`. The answer is `SomeClass&`. You don't want to return a copy of `y = z` but rather the actual result of `y = z`.

### Self-Assignment
What if a programmer writes:

```c++
x = x;
```

What would the code we've outlined above do? The first thing we've said we should do is "get rid of the things the object already has". Hm, in our example with `SomeClass`, that means get rid (i.e. delete) the int on the heap. Well, that would be bit of a disaster. We could possibly arrange things so that we didn't end up destroying all our information, but we would still be doing a lot of unneccessary work.

We shouldn't be doing much of anything, other than recognizing that this is a simple no-brainer and returning x as the value of the expression.

How do we check for self-assignment? We need to know if the current object, since we said this is a member function, is the same object as the right-hand side. How can we check if two objects are exactly the same object? Check if their addresses are the same! What is the current object's address? `this`.

### Example of an Assignment Operator for `SimpleClass`:
```c++
SimpleClass& operator= (const SimpleClass& rhs) { // rhs means right hand side
    if (this != &rhs) {
        // Free up resources (as needed)
        delete p;
        // Allocate new resources (as needed)
        p = new int;
        // Copy over all data
        *p = *rhs.p;
    }
    return *this;
}
```
## Update Inheritance in Copy Control after finish Inheritance