# Class Basics
We will talk about the basics of creating and using a class. Classes are the core of Object-Oriented Programming and why you will hear people say C++ is a Object Oriented Language and C isn't one. 
## Writing a Minimal Class

This is the simplest class we can write:
```c++
class Simplest {};  // Remember that semi-colon, otherwise there will be confusing error messages.
```
This class definition defines a type called `Simplest`. We can declare variables of type Simplest, but there's not much we can do with it. 
```c++
Simplest x;
```
Note: `x` is a `Simplest` *object*, The object was initialized using the *default constructor* provided by the compiler since we haven't written one for class `Simplest`. (We discuss constructors below.)

## Difference Between Class and Structs
There is really only one difference between Classes and Structs, which is the default **access modifier** of member variables and methods. In a `struct` they are **public**, and in a `class` they are **private**. (We will also discuss accessibility below)

## Providing a Public Interface (Member Methods) to make a Class Interactive
For a class to have functional purpose and perform actions, we need to give it a *public interface*.
```c++
class Simple {
public: // The access modifiers of member variables and methods.
   void display() {cout << "Displaying a Simple object\n";}  // Note: will be done better, later on.
};
```
With the class Simple, we can now do more than just create an instance of the type Simple. We can also call its display function. 
```c++
Simple simpleton;
simpleton.display();
```
Functions like `display()` are referred to as *member methods*. Notice above how we called the method. First we defined a variable `simpleton`, that held and instance of the class `Simple`. Then, using `simpleton` we called the method `display()`.

## Member Variables
A class like `Simple` is still not interesting. Variables of the type `Simple` are all exactly the same and do the exact same thing. They don't have anything inside themselves to make each one different. (They do occupy different locations in memory, but that's a topic for a different discussion.)

We can provide a class with *member variables* to hold information about the different objects of that class's type.
```c++
class Person {
public:
   void display() {cout << "Displaying a Person named " << myName << endl;}  // Note will be done better, later on.
   string myName;
};
```
Now we can create an object, give it a name and display the object, getting to see what it's name is.
```c++
Person p1;
p1.myName = "William";
p1.display();
```
Here we created a `Person``, gave it the name "William" and then displayed it. Inside the definition of the display method , we can use `myName` to refer to the name of the `Person` that we are currently displaying. Every time we call a method, there is a specific object that the method is being called for. We will call that the **current object**.

## Private Members
The definition of the `Person` class above would allow us to easily, even accidentally, change a Person's name. In fact any piece of code that can access the `Person` can change its name. This could result in some difficult programming bugs to track down.

It's also possible that we don't want programmers to depend on the exact way in which we store the member variables. In the case of a Person's name, perhaps we're not likely to change our minds on how to implement it, but in other cases that we will see later, we may well want to provide ourselves that freedom.

In general, we would prefer not to have our member variables so easily accessible and so easily modifiable. Classes allow us to mark some members (both member variables and methods) as **private**, so that only other members of the class can get at them. 

Note: This idea is called [*Encapsulation*](../OOP%20Simplified.md), which is one of the four core object oriented principles. 

```c++
class Person {
public:
   void display() {cout << "Displaying a Person named " << myName << endl;}  // Note will be done better, later on.
private:
   string myName;
};
```
The method display can still access the name, but any code that is not part of the class can not, which causes us a problem. How can we set a Person's name? The code that we used earlier will get an error when we try to compile.
```c++
Person p1;
p1.myName = "William";  // Compilation ERROR!  Can't access private member variable myName.
p1.display();
```
## Constructors
A special kind of method is provided in order to allow us to *initialize* an object. It is called a **constructor**. A class can have several constructors, depending on what kind of information we want to use during initialization. The name of the constructor is exactly the same as the name of the class.

We want to provide the Person's name to the constructor, so that each time a Person is created, it recieves a name.
```c++
class Person {
public:
   Person(const string& aName) {myName = aName;}  // We will do this better in a moment.
   void display() {cout << "Displaying a Person named " << myName << endl;}  // Note will be done better, later on.
private:
   string myName;
};
```
Notice a very unusual thing about the `Person` constructor in the class definition. It doesn't have a return type. None at all. That is true of all constructors.

Now we can create our Person named William:
```c++
Person p2("William");
p2.display();
```
We provide the Person's name at the same time that the `Person` is created. This is how we can get around the problem we had in the last section when we tried to set the private member variable `myName` from outside the class.

## Initilization List
In the constructor for Person, the comment said that we would do it better "in a moment". Well, that moment has come.

What could possibly be wrong with that code? It sets the only *member variable* there is, so that's good. Well, actually that's the problem. It sets it. It doesn't initialize it. Consider these two lines:
```c++
string cat;
cat = "Felix";
```
and compare them to this line:
```c++
string cat = "Felix";
```
Which is better? Why? The second approach takes only one line, which some might say is better, but that's not the point. What would happen in the first example if we printed out the cat before setting it to Felix? We would print an empty string. So? 

The problem with the first approach is that we took the time to create that empty string and then **undid** that work and assigned "Felix" to it. In the second approach, we never create the empty string. Instead when the string is created we immediately *initialize* it to "Felix". Some people like to write that line as:
```c++
string cat("Felix");
```
to make the fact that we are initializing more clear.

What's all that got to do with our constructor? Well we are doing the same thing. The member variable myName is first getting initialized to the empty string, and only afterwards being changed to get the value of the parameter, `aName`. We can do better. And we will require that you do. The trick is to use the *initialization list*:
```c++
class Person {
public:
   Person(const string& aName) : myName(aName) {}  // This is the correct way you write this constructor.
   void display() {cout << "Displaying a Person named " << myName << endl;}  // Note: will be done better, later on.
private:
   string myName;
};
```
The body of the constructor doesn't do anything anymore. Instead a new bit of syntax is introduced. In between the parameter list and the body of the constructor is the initialization list. It begins with the colon character `:` and is followed by a list of initializations. 

Here we only have one member variable, so there is actually only one thing initialized here. The member variable`myName` is being initialized to the parameter value `aName`.

Note: If there are more than one member variable, we use a comma `,` to seperate them.

This example shows the initialization list being used for a minor improvement in speed. Later we will see examples in which the intialization list plays more important roles. In fact we could change our example just a little and immediately find the initialization list **has** to be used.

```c++
class Person {
public:
   Person(const string& aName) {myName = aName;}  // This will NOT COMPILE
   void display() {cout << "Displaying a Person named " << myName << endl;}  // Note will be done better, later on.
private:
   const string myName; // Note that myName is now const
};
```
I made only a small change to the original example and now it won't compile at all. What was the change? The member variable `myName` is now `const`. We cannot *assign* to it anymore. We can only *initialize* it. We have no choice but to use the intialization list.

## Default Constructor
The first time we created a Person, we did not provide a name. All we wrote was:

```c++
Person p1;
```
Interestingly, if we tried that now we would get a compilation error. Why? Creating an object that way depends on a special constructor, called the default constructor. The default constructor is simply a constructor that doesn't take any arguments. C++ provides you with a default constructor *automatically* for every class you define "if you don't define any other constructors". As soon as we defined a constructor that takes a single argument, the Person's name, C++ figured we knew what we were doing as far as constructors go and did not proved a default constructor.

If we want to be able to construct Perons who don't have names assigned, we can provide our own default constructor:
```c++
Person() {}
```
It would appear that this function doesn't do anything. We will learn that that is far from the truth.

For now, you should know that every constructor first initializes the class's member variables. Not all of them, though. Specifically, it does not initialize member variables whose type is *built-in* to C++, such as `char`, `int` and `double`. It also does not initialize any member variables that are pointers.

All other member variables, those whose type is a *class*, such as `string` and even `Person`, are initialized. How do they get initialized? Later we will see how we can specify how to intialize these member variables. If we don't specify then they get initialized by their **default constructors**!

See, default constructors are very important.

## Const Methods
If we want to pass our `Person` object into a function as a parameter, how should we declare the parameter to the function? Remember that there are three ways to do this:
1. Pass by Value
2. Pass by Reference
3. Pass by Constant Reference

Passing by-value makes a copy of the object passed. In general we want to avoid pass-by-value, as it is frequently a silly waste of time. Pass-by-reference allows us to avoid the copying, but it makes our code vulnerable to other bugs that can be difficult to track down, such as changing something about the `Person` that is passed in. Often the best choice is to pass-by-constant-reference. This saves the copying and protects the object from being accidentally modified.

So a simple function that is passed a Person and calls its display method would be:
```c++
void simpleFunction (const Person& fred) {
   fred.display();  // Compilation error.
}
```
There's a problem however. We said that fred is `const` so that nothing will be allowed to change anything inside fred (i.e., fred's member variables). But then we call the method `display` on fred. We know that `display` won't change any of fred's member variables. But C++ doesn't. C++ will not allow `simpleFunction` to compile without an error unless we provide a guarantee that simpleFunction is safe. How? We must state that in simpleFunction's definition that it is **const**.
```c++
class Person {
public:
   Person(const string& aName) : myName(aName) { }
   void display() const {cout << "Displaying a Person named " << myName << endl;} // Finally, we did it right!!!
private:
   string myName;
};
```
What did we change in the definition of `Person`? In the definition for `display`, we put `const` after the parameter list and before the body of the function. Now, we have guaranteed that display will not change anything in the current object's member variables. If we would try to change a member variable's value inside display, C++ would give an compilation error. Now display is **safe** to use on const objects.

Whenever you write a method that should not change the values of any member variables inside the current object, you should mark the method `const` as we did with display. Note that we often refer to such a method as a **const method**.

## Vector of Objects
Earlier we talked about how to fill a [vector of struct objects](../Basic%20C++/Structs/Structs.md) from a stream. In that case, we were not using *encapsulation* and had not made the `date` private. Suppose we want to fill a vector of class objects, how will the code change? What will have to change? In that case, we were not using encapsulation and had not made the date private. Suppose we want to fill a vector of class objects, how will the code change? What will have to change?

First, let's look at that code again. (Sorry that I used a different class there than we've been using in this set of notes.)
```c++
void fillCatVector (ifstream& ifs, vector<Cat>& vc) {
   Cat c;
   while (ifs >> c.name >> c.color >> c.weight) {
      vc.push_back(c);
   }
}
```
Now, what will be different if Cat is defined as a class? First, let's write such a class.
```c++
class Cat {
public:
   Cat(const string& theName, const string& theColor, double theWeight) 
      : name(theName), weight(theWeight), color(theColor) { }
   void display() const {
      cout << "Displaying a Cat named" << name << " with color " << color << " and weight " << weight << endl;
   }
private:
   string name;
   string color;
   double weight;
};
```
The only real difference in how we would fill a vector is how we set the fields in each object. Since we are using *encapsulation*, the fields need to be initialized in the constructor. That means we need to first read the values into temporary variables and use those to initialize the object. (Note, the is not a method of the class but a function!)
```c++
void fillCatVector (ifstream& ifs, vector<Cat>& vc) {
   string name;    // Used to read in the name
   string color;   // Used to read in the color
   double weight;  // Used to read in the weight
   while (ifs >> name >> color >> weight) {
      Cat aCat(name, color, weight);  // Cat object defined inside loop.
      vc.push_back(aCat);
   }
}
```
What changed? First, we defined temporary variables in order to read in the name, color and weight. Then we defined a Cat object inside the loop, so that we could initialize it using the Cat's constructor.

How would we write a function to display a vector of Cats?
```c++
void displayCatVector (const vector<Cat>& vc) {  // Remember the const
   for (size_t index = 0; index < vc.size(); ++index) {
      vc[index].display();
   }
}
```

## Objects within Objects
Many of our examples show objects inside of other objects. You probably haven't noticed them. The `Person` class, for example, has a string object inside it holding its name. You might not have thought about if because for one thing, we weren't the one that defined that class. So, let's create another class, a Date class, to use with our Persons.

Our Date objects will be created by passing in integers representing the month, day and year. So, we might want to create a Date as:
```c++
Date theFourth(7, 4, 1776); // July 4th, 1776
```
A simple implementation of the class might be:
```c++
class Date {
public:
    Date(int month, int day, int year) : month(month), day(day), year(year) {}
    void display() const { cout << month << '/' << day << '/' << year; }
private:
    int month, day, year;
};
```
Now we need to modify the `Person` class to include a date of birth field. We will also want its constructor to initialize the Date and and its display method to display it.

For the constructor, there are two natural designs. We could pass in an actual `Date` object. We will take a second approach, just passing in the month, day and year fields, leaving the construction of a `Date` object up to the Person constructor. Using this approach, we might define a `Person` with:
```c++
Person will("William", 3, 14, 1592);
```
That leave us with just having to make the necessary modification to the Person class. Here's the constructor:
```c++
Person(const string& aName, int m, int d, int y)
   : myName(aName), bday(m, d, y) { }
```
Note how the field bday was initialized. See that it took three arguments. Well of course it did. The point is simply that to initialize the Date object in the `Person` class, we have to use the Date constructor and it takes three parameters. We had not previously seen anything in the initialization list taking anything other than three arguments. Whatever number the corresponding constructor needs, that's what we pass in.

One thing to observe there. The Date class had to be defined first, otherwise the `Person` class would not have compiled. After all, otherwise how would the compiler know when looking at the `Person` class that a Date class actually exists, let alone that it has the appropriate constructor and display method.

Complete Program Here: [Person and Date Class](./code%20snippets/classes_person_date.cpp)
