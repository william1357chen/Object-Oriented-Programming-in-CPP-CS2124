# Inheritance
* Idea of Inheritance
* Representing Inheritance in Code
* Inheriting Methods
* Overriding Methods
* Constructors
* What can be assigned to what?
* Polymorphism
* Protected
* Calling a Base Class Method
* Function Overloading with Inheritance
* Abstract Classes
* Multiple Inheritance
* Other stuff

## The Idea of Inheritance
If we have several classes that have various attributes and functionality (i.e. fields and methods) in common, it can be convenient to put all the things that they share into a single class and have the other classes "inherit" the things they have in common from this one new class. The fact that we only have to write the parts the classes have in common once, results in many people describing the benefits of inheritance as **code reuse**.

We will see that another very important advantage of inheritance is that it makes it easier to create a collection (e.g. vector) that can group together instances of our different classes.

An example? Suppose we have a number of classes that represent different types of animals. Certainly they must have a lot in common. If we take all that they have in common and put it in a single class `Animal`, then the other classes (`Lion`, `Tiger`, `Bear`, etc.) will be much simpler to write.

When we discuss inheritance, we say that the class that holds all the common information is the **base** or **parent** class. (Some people say super class, but that always makes me think of something wearing a cape and tights.) The classes that inherit from the base (or parent class) are called **derived** or **child** classes. An inheritance *hierachy* can be multiple levels. If it is, we might also refer to an **ancestor** class or a **descendant** class.

Inheritance is sometimes referred to as an **IS-A** relationship, because effectively any derived object **is a** base object, in the sense that anywhere you could use a base object, you should also be able to use any of the derived objects. (This is also known as the *Principle of Substitutability*.) Sometimes people refer to IS-A as a test. If you cannot comfortably say: "My derived class is a base class", then something maybe wrong in your design. Using our example above of animals, we can say "a cat *is* a(n) animal," which helps verify that the Animal hierarchy makes sense.

Sometimes it is good to compare the IS-A relationship with the **HAS-A** relationship. In a HAS-A relation, one object has (or contains) an instance of another. Occasionally people will confuse the two. For example, which should we use for the relationship between a point and a circle? In some sense, you might view a circle as a point that has the added attribute of a non-zero radius. But would we want to say that we can *substitute* a circle anywhere we would use a point? Is a line defined by two circles? Doesn't sound good. On the other hand, a circle certainly has a point that defines where its center is. Thus, representing a circle as *having* a field that is a point sounds better than saying that a circle *is a* point.

## Representing Inheritance in Code
So, if we had three classes, `Lion`, `Tiger` and `Bear`, we could define a base class `Animal` to hold the stuff they have in common.
```c++
class Animal { };
class Lion : public Animal { };
class Tiger : public Animal { };
class Bear : public Animal { };
```
Note the use of "` : public Animal`" after `Lion`. That is the way to say that `Lion` inherits from `Animal`.

Why do we have to say public. Please don't ask. Ok, I'll answer anyway but I did tell you not to ask. If you leave off the "public" then we have what's called "private inheritance" (yeah, private is the default). Private inheritance means that everything that was *public* in the base class becomes *private* in the derived class.

## Inheriting Methods
Let's add a method called eat to the Animal class and then try it out with one of our derived classes.
```c++
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() { cout << "Animal eating\n"; }
};

class Lion : public Animal {};

class Tiger : public Animal {};

class Bear : public Animal {};

int main() {
    Bear yogi;
    yogi.eat();
}
```
If we run this, we will get the output:
```c++
Animal eating
```
Note that we did not put anything at all in the `Bear` class, just in the `Animal` class, but we still have the ability to call the eat method for a bear. This is known as **code reuse**.

## Overriding
What if we don't like what we have inherited? In our example, what if a tiger wants to eat in a different way than other animals. Simple! In the `Tiger` class, we just override the definition of the eat method. I will just show the `Tiger` class and the revised main, but [The complete program is here]().
```c++
class Tiger : public Animal {
public:
    void eat() { cout << "Tiger eating\n"; }
};

int main() {
    Bear yogi;
    yogi.eat();
    Tiger tigger;
    tigger.eat();
}
```
The output is now
```c++
Animal eating
Tiger eating
```

## Inheriting Fields
Fields are also inherited. However, even though our parent class may have a field, we still have to respect access permissions. If the field is private in the base class, the derived class can only access it through methods provided by the base class.

## Constructors
Let's add a name field to the base class. Naturally if we add a field, we need a constructor to initialize it. And, the animals that we have created so far will need to be provided with names. The revised Animal class and main are below. [The complete program is here]().
```c++
// Attempt at adding a name to all Animals and initializing it using a constructor in Animal.
class Animal {
public:
    Animal(const string& name) : name(name) {}
    void eat() { cout << "Animal eating\n"; }
private:
    string name;
};


int main() {
    Bear yogi("Yogi");
    yogi.eat();
    Tiger tigger("Tigger");
    tigger.eat();
}
```
However, this did not work. Why? The answer is simply that *constructors are not inherited*. That's right, if we want the `Lion`, `Tiger` and `Bear` classes to have constructors that take a name, then we have to write those constructors ourselves.

The question then is *how* should we write the constructor for the derived class? In particular, how do we initialize the name field? A naive approach is to try something like:
```c++
// Attempt to add a constructor for a derived class that initializes a field in the base class
class Tiger : public Animal {
public:
    // Note that the field name is in Animal
    Tiger(const string& name) : name(name) {} // Compilation error
};
```
But that doesn't work either. The compiler will give you a few error messages. One of them says that the Tiger does not have a field called name. We can only initialize things that are actually defined as being insider our class. How then do we get the Tiger's name initialized? By asking the base class to do so. In the initialization list, we put a call to the Animal constructor:
```c++
class Tiger : public Animal {
public:
    // Now we are asking Animal to initialize name.
    Tiger(const string& name) : Animal(name) {} // Right!
};
```
Finally we have an approach that works! [The complete program is here]().

It's important to be aware that a derived class's constructor is *always* calling a base class constructor, even if we don't specify one in the derived constructor's initialization list. So what constructor is being called if we don't specify one? Pretty obviously, it has to be the default constructor. If you tried our first failed attempts at initializing the field, you might have noticed a compiler error that complained that the Animal class didn't have a constructor that took no arguments. Of course we know Animal doesn't have one. We just didn't know that the derived constructor was trying to call it. But that's what happens if we don't explicitly say which base constructor to use.

So, bottom line is you need to be aware that:

* A derived class’s constructor will ***always*** invoke one of the Base class’s constructors.  This takes place in the *initialization section* of the constructor (i.e., before the body of the constructor), ***before*** any other initialization.
* The only things that can appear in the initialization section are base classes and member variables declared in *this* class. Not member variables declared in a base class, regardless of whether they were declared public, protected or private.
* The programmer can specify **in the initialization list** which base class constructor to use.  If unspecified then the default constructor will be used (except as noted below for the copy constructor).  Note that a compilation error will result if the specified Base class constructor is not available.

## Assigning `Derived` objects to variable with type `Base`
Suppose you have a Derived object and you try to assign (or copy) it to a Base object. I.e.:
```c++
int main() {
    Base base;
    Derived derived;
    base = derived;
}
```
Does it compile? What will be the result?

First, yes indeed, it does compile. C++ is very careful about static typing as we know, but one of the main ideas of inheritance is that wherever you are expecting a base object, you can instead use a derived object.

And it runs. But what does it do? It takes the **Base portion of derived and copies just that portion into base**. After all, base cannot hold anything else. It's only a Base object itself. So everything about derived that is in any sense "more" than a Base object does not get copied over. This "failure" to copy everything over from base to derived is known as the **Slicing Problem**.

Besides seeing the slicing problem in assignments, we also see it whenever we make a copy using a pass-by-value. [Later we will discuss the "copy constructor" and we'll see that the slicing problem can come up whenever the copy constructor is used.]

So, what are we allowed to assign to what? In terms of base classes, derived classes and pointers to either type of class? To make things as clear as possible, I will refer to a class Base and as class Derived, where Derived derives from Base.

Given:
```c++
Derived der;
Base base;
base = der;  // Slicing
der = base;  // Not permitted.
Base* bp;
Derived* dp;
bp = &base;  // Sure, fine.
dp = &der;   // Sure, fine.
bp = &der;   // Definitely.  Without it polymorphism would not work.
dp = &base;  // No.
```
So what can we assigned where...

* Derived to Base? Yes, but remember the *slicing problem*).
* Base to Derived? No, illegal. Results in compilation error.
* Address of derived object (e.g., value of a derived pointer) to a base pointer? Fine.
* Address of base object (e.g., value of a base pointer) to a derived pointer? No, illegal. Results in compilation error.

## Polymorphism (Virtual Methods)
If polymorphism is the answer, what was the question?
* Suppose we have a menagerie (or other collection) of animals and it is feeding time. We want all of those animals to eat. But they don't all eat in the same way and it is important that the gerbils don't start eating like lions.
* Polymorphism will be part of the solution, but how will we represent the collection? A first stab might be:

    ```c++
    Lion fred;
    Tiger tigger;
    Bear pooh;
    vector<Animal> menagerie;
    menagerie.push_back(fred);
    menagerie.push_back(tigger);
    menagerie.push_back(pooh);
    for (size_t i = 0; i < menagerie.size(); ++i) {
        menagerie.eat();  // We will see all of them eating like Animals, not Lions and Tigers and Bears.
    }
    ```
* But we know this won't work. Everytime we do a push_back onto a vector, what we end up adding is a *copy*, not the original. And what are we copying into? An Animal. Remember the slicing problem? The result is that we have a collection of **Animals**, but none of whom are lions or tigers or bears (oh my!).
* What sort of collection can we have that allows us to add the various types of animals without "slicing" them up? Note that a base pointer is allowed to hold the address of a derived object. So instead of a collection of Animal, we could have a collection of pointers to Animal.

    ```c++
    vector<Animal*> menagerie;
    menagerie.push_back(&fred);
    menagerie.push_back(&tigger);
    menagerie.push_back(&pooh);
    for (size_t i = 0; i < menagerie.size(); ++i) {
        menagerie->eat();  // Note the -> operator.
    }
    ```
We still haven't solved the problem though. When we run the code, we find that even though the entries in the vector are all pointing to actual lions, etc., unfortunately they are still all using the Animal version of the eat() method. Why?

By default, C++ wants to generate the most efficient code possible. In this case, letting the compiler figure out which version of the method to call results in faster code than waiting till run time to ask what kind of Animal are we pointing at at the particular moment.

So to get C++ to do what we want, which will slow down our program (very slightly), the programmer has to tell C++ that it is ok to take the less effecient approach. How do we do that? Simple, we just have to tag the method, in our example eat(), with the keyword `virtual`. This is done in the base class:
```c++
class Animal {
public:
    Animal(const string& name) : name(name) {}
    // Mark the method in the base class as virtual
    virtual void eat() { cout << "Animal eating\n"; }
private:
    string name;
};
```
What about *also* markng that method in the derived classes? That is a matter of style. Some people say it is a good thing and others see doing so as just clutter. Feel free to do so or not, just realize that it does not effect the program.

Terminology:

* We have used the term polymorphism. The same idea is also referred to as: *Late Binding or Dynamic Binding*. These terms emphasize the idea that we are connecting / binding the *name* of the function to the actual code that we will run dynamically.
* Alternatvely, the default that C++ uses is known as *Early Binding or Static Binding*, referring to fact that it is done statically, at compile time, based only on the compile time types of the variables.
* In C++ specifically, polymorphism is often referred to as the *Virtual Mechanism*.

Constructors:

* Note that in C++ the virtual mechanism *does not work* inside constructors. Specifically, if the Base constructor calls a virtual method that is redefined in the Derived class, it is the version in the Base class that will be used.  Why do this? The reasoning is simple: during initialization of the Base object, the Derived object has not yet been initialized, so it is probably a bad idea to call any of its functions. Here is the program that demostrates this concept. [The complete program]()

Conclusion:

* For Polymorphism to work with **base class** pointer pointing to a **derived class** object, make sure to add keyword `virtual` in front of methods you intend to override.

## Protected
In addition to the access permissions `public` and `private`, that we are familiar with, C++ also provides a mode known as `protected`.

Technically, the point of marking a member as protected in the base class is to allow a derived class direct access to that member, while still keeping the field effectively private from all other code.

Consider a simple example with a field that is private in the base class. As we know, if we try to access it from code in the derived class, we will get an error:
```c++
class Base {
private:
    int value;
};

class Derived : public Base {
public:
    // Compilation error! value is private in Base
    void display() { cout << "Value: " << value << endl; }
};
```
Now if we just mark the field value as `protected` rather than `private`, the code compiles and runs correctly. (Ok, correctly except that we never intialized value so it would display as some random garbage int value.)
```c++
class Base {
protected:    // But we should do better and will below.
    int value;
};

class Derived : public Base {
public:
    // Compiles now because value is protected.
    void display() { cout << "Value: " << value << endl; }
};
```
C++'s creator, Bjarne Stroustrup, has said he feels it was a **mistake** to allow *fields* to be marked protected. Why? Because it violates the idea of encapsulation, making it harder to identify what code is responsible for properly maintaining the state of the object. In this course, we will follow his guidance and not use protected with fields.

If we aren't going to use protected for fields then what good is it? Suppose you want a field in the base class to only be able to be modified by its own class, whether that is the base or some derived class. Once the field is properly marked as private, then the derived class will have to use a method provided in Base. If that method is public, then anyone can modify the field. If it is private, then the derived class *can't* modify it. Solution? Mark the method as protected.
```c++
class Base {
protected:   // the right thing to do
    int getValue() const { return value; }
private:
    int value;
};

class Derived : public Base {
public:
    void display() { cout << "Value: " << getValue() << endl; }
};

int main() {
    Derived der;
    der.display();
    cout << der.getValue() << endl;  // Compilation error
}
```

Note that Derived's `display` method is allowed to call `Base`'s protected method `getValue`, but the print statement in `main` fails to compile when it tries to call the same function.

So the private field ensured proper data hiding, while the protected method allowed code within the heirarchy to get the value while keeping outsiders away.

Ok, now this might seem tricky. Let's work with the hierarchy we have defined. And add another class, DerivedTwo. For simplicity, lets define DerivedTwo the same way we did Derived, but we will add two more methods, the first to access the value field of Derived object and the second to do the same witha DerivedTwo object.
```c++
class DerivedTwo : public Base {
public:
    void display() { cout << "Value: " << getValue() << endl; }
    int getDerivedValue(const Derived& der) { return der.getValue(); } // doesn't compile
    int getDerivedTwoValue(const DerivedTwo& der2) { return der2.getValue(); }
};
```
So, what happens? One method fails to compile and the other is fine. Why? We have permission to call the protected `getValue` method on a `DerivedTwo` object, even if that object is not us, so the definition for `getDerivedTwoValue` compiles fine. But within `DerivedTwo`, we do not have permission to call that same protected method on a Derived object, so the defintion of `getDerivedValue` fails to compile. ([The complete program.]())

## Calling a Overridden Base Class Method with a `Derived` Object
Earlier, we saw how in the class `Tiger`, we could override the eat method from Animal, so that when we called eat on `tigger`, he used the Tiger version rather than the Animal version.

Great. But what if once in a while, `tigger` would like to eat the way his parent class taught him to. What if he wants to eat like any old Animal and not specifically like a Tiger? He still can!
```c++
int main() {
    Tiger tigger("Tigger");
    tigger.eat(); // tigger eating like a proper Tiger.
    tigger.Animal::eat();  // tigger eating like an Animal.
}
```
Here we are calling the Animal class's version of the eat method on tigger. The programmer who uses the derived class can choose which definition of the method in the hierarchy s/he wants to use!

It often happens when we are overriding a method that we would actually like take advantage of the original. Suppose we are implementing the Lion class and when we override the eat method, we would like to *first* identify our selves as a Lion and then continue to eat using the Animal version of the method:
```c++
class Lion : public Animal {
public:
    Lion(const string& name) : Animal(name) {}
    void eat() {
        cout << "Lion!!!!!  ";
        Animal::eat();  // Call our parent's eat method
    }
};
```
[Complete program.]()

## Function Overloading with Inheritance
People are often surprised as to how function overloading and inheritance interact. The rule is: the compiler will pick the most specific overload, based on the *compile-time* type of the arguments.

What does that mean? Suppose we have an inheritance hierarchy of three classes:
```c++
class A {};
class B : public A {};
class C : public B {};
```

And we have two functions:
```c++
void foo(const A& a) { cout << "foo(A)\n"; }
void foo(const B& a) { cout << "foo(B)\n"; }
```
Now assume we have the following code, what will happen?
```c++
void test(A& aref) { foo(aref); }

int main() {
   A a;
   B b;
   C c;

   foo(a);
   foo(b);
   foo(c);

   test(c);
}
```
No surprise that the first two calls to foo result in:
```c++
foo(A)
foo(B)
```
How about the third, foo(c)? There is nothing for it to directly match up with. Either of the foo functions would work. C++ picks the more specific option and so the output is:
```c++
foo(B)
```
Finally, we get to the last function call, test(c). The function `test` has a single parameter `aref` that is a reference to the class `A`. We are passing in the object `c`. That's fine, since I can always pass a derived object in where a base is expected (*principle of substitutability*), as we did earlier when we called `foo(c)`.

So `test` is passed in a `c` and it then attempts to call `foo` with that `c` object. Which `foo` should get called?

Now comes in the compile-time part of what we said above. The compiler is the one that is responsible for picking which overload to use. And the compiler only knows the *compile-time* type of the variable `aref`, not what it is actually referring to. Therefore the ouput is based on the fact that `aref`'s compile-time type is `A`, and the output is:
```c++
foo(A)
```

## Abstract Classes
* Purpose
    * Guarantee a consistent interface for all derived classes.
    * Enforce requirements for derived classes.
    * Used purely as interfaces.
* How
    * Forbid objects from being created for the class (that's how it enforces the requirements)
    * At least one method must be *pure* virtual.
    * Pure virtual methods are declared as virtual and also have `= 0` just before the semicolon.
    * A pure virtual method from a base class remains pure virtual in a derived class *unless* it is implemented in the derived class.

Example: 
```c++
class Base
{
public:
    const char* sayHi() const { return "Hi"; } // a normal non-virtual function    
 
    virtual const char* getName() const { return "Base"; } // a normal virtual function
 
    virtual int getValue() const = 0; // a pure virtual function
 
    int doSomething() = 0; // Compile error: can not set non-virtual functions to 0
};
```
### Multiple Inheritance
* Used for `iostream`
* Student, Employee, StudentEmployee.
    * If Student and Employee both inherit from Person how do we deal with ambiguities?

### Other stuff that is discussed later
* Copy control and Inheritance
    * Destructors  [Discussed with copy control]]
        * Automatically call their parent class’s destructor just before they finish.
        * If we `delete` an item pointed to by a Base class pointer then the destructor for the Derived class will be invoked *only* if the Base class destructor is `virtual`.
            * Destructors should be declared virtual if a class is ever expected to be used as a base class.
            * Constructors are never virtual.  Destructors are nearly always virtual.
    * Assignment operator.
        * The system-provided assignment operator calls the base class’s assignment operator before it does anything else.
        * If you write your own assignment operator then you need to call the base class’s assignment operator yourself.
* Output operator. How can we make this behave polymorphically?
    * Implement the output operator for the base class so that it calls a virtual method “display”. 
    * Since the object to be displayed is passed in to the operator by reference (of course), calling a virtual display method will invoke the virtual mechanism.

 