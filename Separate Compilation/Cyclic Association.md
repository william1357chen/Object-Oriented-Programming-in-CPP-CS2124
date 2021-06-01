# Forward Declarations and Cyclic Association for Classes

## Forward Declarations
Suppose we wrote a class A as follows:
```c++
class A {
private:
   B x;
};
```

What does the compiler need to know about `class B` when it reads this definition of class A? Since the member variable x is of type B, then we *have to know* **how big an object of type B is**. In C++, that means that we have to **define** `class B` first, before we **define** `class A`.

What about the very similar looking case below:
```c++
class C {
private:
   D* y;
};
```
What does the compiler need to know here about `class D`? What is the type of member variable y? It is a pointer to D. All pointers are the same size. We don't need to actually know anything about `class D` to know how much space to allow for the member variable y. All we need to know is that D is a *valid type*, not *how* it is defined. How can we say that D is a valid type without actually giving its full definition?
```c++
class D;

class C {
private:
   D* y;
};
```
Notice the line: `class D;`. That is a **forward declaration** for a class. It promises that we will define the class D later, but meanwhile the compiler can accept that D is a valid type. This is good enough when all we need to do is declare a pointer to D, but not when we want to create an object of type D. To have an actual object we will have to define D.

Why bother with all this? Why not just give D's definition, instead of a "forward declaration"? 

## Cyclic Association
What if the two classes look like:
```c++
class D {
private:
   C* z;
};


class C {
private:
   D* y;
};
```
Now we have a problem. C needs to know something about D and at the same time D needs to know something about C. The solution is to use the forward declaration:

```c++
class C;


class D {
private:
   C* z;
};


class C {
private:
   D* y;
};
```

Remember, the forward delaration does not tell us anything more than the fact that the name *will* be defined as a type. It does not tell us how big an object would be. And it does not tell us what members (variables or functions), the class has.

How will that make a difference? Suppose we add a couple of functions to these classes:

```c++
class C;


class D {
public:
   void dFunc() { z->cFunc(); }
private:
   C* z;
};


class C {
public:
   void cFunc() { }
private:
   D* y;
};
```
Now the compiler is going to be unhappy again. Why? Because the function definition for `dFunc` is calling the member function `cFunc`. But no one has told the compiler yet that there even is such a member function! The compiler won't know that until it sees the actual class definition for the class C. How can we fix this? Well, it would fix itself if we were already using separate compilation. How? Let's move the *definition* of the member function `dfunc` till *after* we the defintion for the class C.

```c++
class C;


class D {
public:
   void dFunc();
private:
   C* z;
};


class C {
public:
   void cFunc() { }
private:
   D* y;
};


void D::dFunc() { z->cFunc(); }
```

How does this fix anything? Now when the compiler reads the definition of the class D, it sees a *prototype* for `dFunc`, not the whole definition. In particular, it does not see that function call to `cFunc`. We have moved `dFunc`'s definition with the call to `cFunc` till *after* Class C's definition. Finally the compiler is happy. And we can go do something more entertaining than worrying about keeping compilers happy.
