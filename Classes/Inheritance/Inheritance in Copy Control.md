# Inheritance in Copy Control
How does copy control work when we mix it with inheritance?

## If Derived Does Not Do Copy Control?
The first question really is, if I am writing a derived class, let's call it `Derived`, and my class does not need to do copy control for itself, is there anything special I need to do in Derived? Does it depend on whether or not my parent class, call it Base, does do its own copy control?

Happily the answer is no. Assuming your parent class was written correctly, you don't have to know what your parent class is actually doing. All the right stuff gets done for you in that case. (Note, further down we will discuss a responsibility of the parent class...)

So how does inheritance effect how you implement copy control in your derived class? Let's give ourselves a Base and Derived class to discuss. In the Base class, I will just put some print statements for the bodies of the Big 3. This will help in tracking what's going on. In the Derived class, I will just put a default constructor, again containing only a print statement.
```c++
class Base {
public:
    Base() {
        cerr << "Base()\n";
    }
    Base(const Base& rhs) {
        cerr << "Base(const Base&)\n";
    }
    ~Base() {
        cerr << "~Base()\n";
    }
    Base& operator=(const Base& rhs) {
        cerr << "Base op=\n";
        return *this;
    }
};

class Derived : public Base {
public:
    Derived() {
        cerr << "Derived()\n";
    }
};
```

What happens if we create a Derived object
```c++
int main() {
    cerr << "Derived der:" << endl;
    Derived der;
    cerr << "main finished." << endl;
}
```

The output will be:
```
Derived der:
Base()
Derived()
main finished.
~Base()
```
### What happened?
* We created a Derived object. As we already knew, in its constructor's initialization list it calls the Base constructor. That's why the first thing we see is `Base()` and after that `Derived()`.
* The Derived object gets "destroyed" when its scope, main, is finished. Then, even though we didn't write any code to call it, the Base destructor gets called, resulting in the output `~Base()`.


## Derived Destructor
Ok, so what's next? Let's start with the easiest of the Big 3, the destructor. We will add a destructor to Derived and observe what changes in the output. I won't repeat the Base class as it is not changing (for now).
```c++
class Derived : public Base {
public:
    Derived() {
        cerr << "Derived()\n";
    }
    // Added destructor
    ~Derived() {
        cerr << "~Derived()\n";
    }
};
```

Using the same test code as before, now the output will be:
```
Derived der:
Base()
Derived()
main finished.
~Derived()
~Base()
```

What happened this time? Simple, when the Derived object was being destroyed, its destructor was called, resulting in the output `~Derived()`. The Derived destructor, when it was done, automatically called the Base class destructor. We didn't have to do a thing!

## Derived Copy Constructor
Ok, so what's next? Next we will implement a copy constructor for the Derived class. To begin with, let's just write Derived's copy constructor as we did Base's copy constructor. Then we'll want to write some test code to see how well it worked.
```c++
class Derived : public Base {
public:
    Derived() {
        cerr << "Derived()\n";
    }
    ~Derived() {
        cerr << "~Derived()\n";
    }
    // Added Copy Constructor. There is a problem
    Derived(const Derived& rhs) {
        cerr << "Derived(const Derived&)\n";
    }
};

int main() {
    cerr << "Derived der;" << endl;
    Derived der;
    // Testing Out Copy Constructor
    cerr << "Derived der2(der);" << endl;
    Derived der2(der);
    cerr << "main finished." << endl;
}
```

The output will be:
```
Derived der;
Base()
Derived()
Derived der2(der);
Base()
Derived(const Derived&)
main finished.
~Derived()
~Base()
~Derived()
~Base()
```

How should a Derived object get copied? Same idea here as when we asked how a Derived object should get initialized back when we started talking about inheritance. Always take care of the Base portion first. Idea is that we want a "**firm foundation**" to build the Derived portion on top of.

But how did the Base portion get initialized here? Notice the call to `Base()`. The Base portion got initialized using the Base class's *default constructor*. 

**But that can't be right!** The Base portion of the new object is supposed to be a *copy* of the Base portion of the original. We needed to use the Base's *copy constructor*!

Where does the parent's constructor get called? Same as in our previous discussions of inheritance. It gets called in initialization list of the child's constructor. Since we did not specify which constructor in Base to use, it used Base's default constructor. To fix this, we just have to ***put a call to Base's copy constructor in the initialization list*** of Derived's copy constructor. (That's a lot to say but not much to actually do.)

Fixing our Derived copy constructor:
```c++
class Derived : public Base {
public:
    Derived() {
        cerr << "Derived()\n";
    }
    ~Derived() {
        cerr << "~Derived()\n";
    }
    // Added Base class's copy constructor in initilization list
    Derived(const Derived& rhs) : Base(rhs) {
        cerr << "Derived(const Derived&)\n";
    }
};
```

Using the same test code, our output becomes:
```
Derived der;
Base()
Derived()
Derived der2(der);
Base(const Base&)
Derived(const Derived&)
main finished.
~Derived()
~Base()
~Derived()
~Base()
```

The only change is that now we get the correct consturctor for Base being called when we make a copy of our Derived object.

## Derived Assignment Operator
One more of the Big 3 to go, the assignment operator. As we did with the copy constructor, first we will write our Derived assignment operator the same way we did the one in the Base class and provide a test program.
```c++
class Derived : public Base {
public:
    Derived() {
        cerr << "Derived()\n";
    }
    ~Derived() {
        cerr << "~Derived()\n";
    }
    Derived(const Derived& rhs) : Base(rhs) {
        cerr << "Derived(const Derived&)\n";
    }
    // Added Assignment Operator. This is incorrect
    Derived& operator= (const Derived& rhs) {
        cerr << "operator=(const Derived&)\n";
        return *this;
    }
};

int main() {
    cerr << "Derived der;" << endl;
    Derived der;
    cerr << "Derived der2;" << endl;
    Derived der2;
    // Testing out the Assignment Operator
    cerr << "der = der2;" << endl;
    der = der2;
    cerr << "main finished." << endl;
}
```
The output will now be:
```
Derived der;
Base()
Derived()
Derived der2;
Base()
Derived()
der = der2;
operator=(const Derived&)
main finished.
~Derived()
~Base()
~Derived()
~Base()
```
What happened? The Derived assignment operator was called, so that part worked. But what happened to the Base portion of the target object, der? ***Nothing! No code was run to copy the Base portion of der2 into the Base portion of der.*** How can we fixt that? As with the copy constructor, we have to make our Derived assignment operator *call* the corresponding function in the Base class.

But how?

In this case, there are a few ways we can do it. I think the most obvious way is to explicitly call the Base class's assignment operator. How exactly? Since an operator is implemented by a function we will just call the function `operator=` in the Base class. Remember that when we want to call a function from the parent that has the same name as a function in the child class, we need to qualify the function name. Therefore, in this example, the function we want to call is `Base::operator=`.

Our modified class definition becomes:
```c++
class Derived : public Base {
public:
    Derived() {
        cerr << "Derived()\n";
    }
    ~Derived() {
        cerr << "~Derived()\n";
    }
    Derived(const Derived& rhs) : Base(rhs) {
        cerr << "Derived(const Derived&)\n";
    }
    Derived& operator= (const Derived& rhs) {
        cerr << "operator=(const Derived&)\n";
        Base::operator=(rhs);
        return *this;
    }
};
```
And the corresponding output, using the same test program, is:
```
Derived der;
Base()
Derived()
Derived der2;
Base()
Derived()
der = der2;
operator=(const Derived&)
operator=(const Base&)
main finished.
~Derived()
~Base()
~Derived()
~Base()
```
We wee the same call to Derived's assignment operator and an additional call to Base's assignment operator.

## Polymorphism for Destructor
We have one more job to take care of. Consider the following test code, using our current class definitions:
```c++
int main() {
    cerr << "Derived* p = new Derived();" << endl;
    Derived* p = new Derived();
    cerr << "delete p;" << endl;
    delete p;			   
    cerr << "main finished." << endl;
}
```

The output shows that all the necessary functions get called as we would expect:
```
Derived* p = new Derived();
Base()
Derived()
delete p;
~Derived()
~Base()
main finished.
```

But what happens if we change our test program just slightly? Instead of storing the address of our Derived object in a Derived pointer variable we will use a Base pointer variable.
```c++
int main() {
    // Changed the following two lines
    cerr << "Base* p = new Derived();" << endl;
    Base* p = new Derived();

    cerr << "delete p;" << endl;
    delete p;			   
    cerr << "main finished." << endl;
}
```

The resulting output is:
```
Base* p = new Derived();
Base()
Derived()
delete p;
~Base()
main finished.
```

The output has changed. How? There's a line missing! Only the Base destructor got called, not the Derived constructor. This could be really bad. If the Derived class needed a destructor, then whatever it was supposed to be doing is not getting done.

How can we fix this? Well, why is it happening? Consider the line `delete p`. What is the type of `p`? It is a `Base*`. From the compiler's point of view we are destroying something whose type is `Base` and so it calls the Base destructor. We instead want the Derived destructor to get called, which in turn would call the Base destructor.

Does this situation look familiar? We have a Base pointer that is pointing to a Derived object. When we try to have a function called, here the destructor, instead of the Derived version getting called, it's the Base version that is used. This situation should remind you of when we introduced polymorphism. Base pointer. Derived object. Base method gets called instead of Derived object. What was the solution? Mark the method as `virtual` in the Base class. What method are we discussing here? The destructor. So, that's the solution. In the Base class, mark its destructor as `virtual`. No change at all is required in the Derived class.

So, here is the modified Base class:
```c++
class Base {
public:
    Base() {
        cerr << "Base()\n";
    }
    Base(const Base& rhs) {
        cerr << "Base(const Base&)\n";
    }
    virtual ~Base() {
        cerr << "~Base()\n";
    }
    Base& operator=(const Base& rhs) {
        cerr << "Base op=\n";
        return *this;
    }
};
```

With no change to our last test program, the output is now (correctly):
```
Base* p = new Derived();
Base()
Derived()
delete p;
~Derived()
~Base()
main finished.
```

### Conclusion
There are the key points for dealing with copy control and inheritance:

* Derived:
    * **destructor**: no need to do anything
    * **copy constructor**: in the initialization list, call the Base copy contructor
    * **assingment operator**: before doing anything else, explicitly call the Base assignment operator.
* Base:
    * destructor: mark it `virtual`.