# Separate Compilation
Let's start with a simple program that defines and uses one class, Thing. We'll call it testThing.cpp.

Our goal is to split this one file up, so that other programmers can more easily use our `Thing` class. We will take the `Thing` class itself and put it into two files, one that just has the class definition and any related prototypes. Note that our class definition will not have any method *definitions*, just their prototypes. The other file will hold the actual definitions of the methods and again, associated functions.

## Starting Point
Below is our starting program, named testThing.cpp. Yeah, it's really simple. [To avoid clutter, after this I will leave out the file comment, #includes and using namespace statement, unless relevant.]
```c++
// testThing.cpp

#include <iostream>
using namespace std;

class Thing {
    friend ostream& operator<<(ostream& os, const Thing& theThing) {
        os << "Thing: val = " << theThing.val;
        return os;
    }
public:
    Thing(int val) : val(val) {}
    void setVal(int val) { this->val = val; }
    int getVal() const { return val; }
private:
    int val;
};

int main() {
    Thing thingOne(17);
    cout << thingOne << endl;
    thingOne.setVal(42);
    cout << thingOne << endl;
    cout << "thingOne's val: " << thingOne.getVal() << endl;
}
```
## Moving the definitions
Our first step is to rewrite this program so that all of the fuction definitions in the class are moved outside of it, a put at the end of the file. Let's do them one at a time.

### Moving the output operator
First the output operator. That's pretty easy and you have likely seen this function defined outside of the class before. Two things to pay attention to. Inside the class we still need the friend declaration, but it will only hold the prototype. And then when we move the definition outside, we do not keep the keyword friend with the definition, only with the prototype.
The changes are **commented**
```C++
class Thing {
    // Change
    friend ostream& operator<<(ostream& os, const Thing& theThing);
public:
    Thing(int val) : val(val) {}
    void setVal(int val) { this->val = val; }
    int getVal() const { return val; }
private:
    int val;
};

int main() {
    Thing thingOne(17);
    cout << thingOne << endl;
    thingOne.setVal(42);
    cout << thingOne << endl;
    cout << "thingOne's val: " << thingOne.getVal() << endl;
}
// Change
ostream& operator<<(ostream& os, const Thing& theThing) {
    os << "Thing: val = " << theThing.val;
    return os;
}
```

### Moving the setter
Next we will move the method setVal. What will get left behind? Just the prototype. In this case, that means we just have to "lop off" the body of the function, replacing it with a semi-colon.

And then there's the function definition, that we will put at the end. Let's take a look at what we will have if we just move it as is:
```c++
class Thing {
    friend ostream& operator<<(ostream& os, const Thing& theThing);
public:
    Thing(int val) : val(val) {}
    // Change
    void setVal(int val);
    int getVal() const { return val; }
private:
    int val;
};

int main() {
    Thing thingOne(17);
    cout << thingOne << endl;
    thingOne.setVal(42);
    cout << thingOne << endl;
}

ostream& operator<<(ostream& os, const Thing& theThing) {
    os << "Thing: val = " << theThing.val;
    return os;
}

// Change: This doesn't quite work!
void setVal(int val) { this->val = val; }
```
When the compiler see the definition for setVal, it will be confused. It doesn't know that you had in mind providing the definition for the method setVal. It will figure this is just some regular non-method function you are defining. But in that case, there shouldn't be a `this`. With my compiler, this generates the following error message:
```c++
testThing.cpp:28:24: error: invalid use of 'this' outside of a non-static member
      function
void setVal(int val) { this->val = val; }
                       ^
1 error generated.
```
How to fix that? We tell the compiler that the function we are defining is actually part of the Thing class. To do that, we *qualify* the method name with the name of the class. The new function definition will look like:
```c++
void Thing::setVal(int val) { this->val = val; }
```
### Moving the getter
Next we will do the same thing except with th getter, getVal. However, there is one more thing to concern us here, what to do with the `const` on the method?

The question to answer is, whether the `const` is part of the *implementation* of the method, or does it identify *which method* we are talking about. If you have seen that methods can be overloaded, purely based on whether or not they are const, then you will realize that the const does indeed identify which method.

The result then of movng the defintion to the end, qualifying the function name in the definition, and leaving behind just a prototype is:
```c++
class Thing {
    friend ostream& operator<<(ostream& os, const Thing& theThing);
public:
    Thing(int val) : val(val) {}
    void setVal(int val);
    int getVal() const;
private:
    int val;
};

int main() {
    Thing thingOne(17);
    cout << thingOne << endl;
    thingOne.setVal(42);
    cout << thingOne << endl;
    cout << "thingOne's val: " << thingOne.getVal() << endl;
}

ostream& operator<<(ostream& os, const Thing& theThing) {
    os << "Thing: val = " << theThing.val;
    return os;
}

void Thing::setVal(int val) { this->val = val; }
// Change
int Thing::getVal() const { return val; }
```
### Moving the Constructor
That leaves us with just the constructor to move. Moving the definition to the end is not a problem. Just remember to qualify the constructor's name, as we did with the other methods.

But there is a question as to how we should specify the prototype. What's the question? Should the *initialization list* be part of the prototype or not? The answer comes down to, is it part of the implementation or does it identify which constructor we are using. As you know, it is possible to set the field val insice the constructor body. And it would still be the "same" constructor. Conclusion? The initializatin list should *not* be part of the prototype. Below is the result, and the end of the first stage in our efforts towards separate compilation.
```c++
class Thing {
    friend ostream& operator<<(ostream& os, const Thing& theThing);
public:
    // Change
    Thing(int val);
    void setVal(int val);
    int getVal() const;
private:
    int val;
};

int main() {
    Thing thingOne(17);
    cout << thingOne << endl;
    thingOne.setVal(42);
    cout << thingOne << endl;
    cout << "thingOne's val: " << thingOne.getVal() << endl;
}

ostream& operator<<(ostream& os, const Thing& theThing) {
    os << "Thing: val = " << theThing.val;
    return os;
}

void Thing::setVal(int val) { this->val = val; }

int Thing::getVal() const { return val; }
// Change
Thing::Thing(int val) : val(val) {}
```

## Header and implementation files
On to the next step. We will create **two new files**, a *header file* that we will call Thing.h, and an *implementation file* that we will call Thing.cpp.

The header file will basically just hold the class defintion as shown above. Yes, it will need a little more bookkeeping stuff, like include files.

The implementaton file will hold those four function definitions that we put at the end of the program.

### Modified testThing.cpp
Oh, let's not forget testThing.cpp! What will be left? Not the class definition. And not those four function defintions. Let's look at what the testThing.cpp would look like then:
```c++
// testThing.cpp
#include <iostream>
using namespace std;

// We have a small problem...
int main() {
    Thing thingOne(17);
    cout << thingOne << endl;
    thingOne.setVal(42);
    cout << thingOne << endl;
    cout << "thingOne's val: " << thingOne.getVal() << endl;
}
```
What's the small problem mentioned in the comment?

When the compiler is compiling this file, it has never heard of `Thing`, doesn't now it has a constructor, or method getVal and setVal, or an output operator.

We fix that problem by putting in a #include for the new header file:
```c++
// testThing.cpp
#include <iostream>
// Change
#include "Thing.h"
using namespace std;

int main() {
    Thing thingOne(17);
    cout << thingOne << endl;
    thingOne.setVal(42);
    cout << thingOne << endl;
    cout << "thingOne's val: " << thingOne.getVal() << endl;
}
```
Notice that when we write #include's for our own header files, we put the file's name in quotes, instead of in angle brackets.

### Thing.cpp, the implementation file
What about the implementation file? So far all we have put in it are the definitions of those four functions. I'll throw a comment at the beginning of the file to identify it:

```c++
// Thing.cpp

ostream& operator<<(ostream& os, const Thing& theThing) {
    os << "Thing: val = " << theThing.val;
    return os;
}

void Thing::setVal(int val) { this->val = val; }

int Thing::getVal() const { return val; }

Thing::Thing(int val) : val(val) {}
```

When the compiler looks at that file, trying to compile the functions, it is going to have a few problems. First, looking only at it and nothing else, it won't know about ostream or string. Or even the class Thing, itself! So, let's put in #includes for those headers, along with our usual "using namespace".

```c++
// thing.cpp

// 4 Changes
#include "Thing.h"
#include <iostream>
#include <string>
using namespace std;

ostream& operator<<(ostream& os, const Thing& theThing) {
    os << "Thing: val = " << theThing.val;
    return os;
}

void Thing::setVal(int val) { this->val = val; }

int Thing::getVal() const { return val; }

Thing::Thing(int val) : val(val) {}
```

That's about all we need for the implementation file. We will come back to it later when we want to discuss putting out code in a namespace.

### Thing.h, the header file
Before we more completely away from that implementation file, consider the first line, aside from the comment. It includes the implementation file. So, the first thing the compiler is actually going to look at before it gets to the rest of the implementation file, is the header file. What have we got there? Just the class definition what we took out of testThing.cpp.
```c++
// Thing.h
class Thing {
    friend ostream& operator<<(ostream& os, const Thing& theThing);
public:
    Thing(int val);
    void setVal(int val);
    int getVal() const;
private:
    int val;
};    
```

Consider that now these lines of code are being read by the compiler before it has seen anything else about the program. As before, you can see that the compiler will be wondering what some of the symbols mean. Well, ok, just one symbol, `ostream`. Yes we need a #include.
```c++
// Thing.h

// Change
#include <iostream>

class Thing {
    friend ostream& operator<<(ostream& os, const Thing& theThing);
public:
    Thing(int val);
    void setVal(int val);
    int getVal() const;
private:
    int val;
};
```
Of course, that's not quite enough. However, for reasons we will discuss later, we *do* not put `using namespace` statements in header files. Yeah, it makes for a minor hassle. What do we do instead? *Qualify* the symbols, such as `ostream`, with their namespace. Anywhere we have `ostream`, we will replace it with `std::ostream`. That changes our header file to
```c++
// Thing.h
#include <iostream>

class Thing {
    // Change
    friend std::ostream& operator<<(std::ostream& os, const Thing& theThing);
public:
    Thing(int val);
    void setVal(int val);
    int getVal() const;
private:
    int val;
};
```
With that, our files will work. Assuming you have correctly added them to your IDE, or compile them correctly with your command-line compiler, tje program should build and run fine.

There are still a couple of issues we should address. The first is "include guards". And the second is namespaces. We'll get to them...