# Recitation 6: Dynamic Arrays and Copy Control
## Topics
* Copy Control (aka Big 3)
* operator[]
## Task
You will develop a class to represent a directory or employees.

We provide you with some code to start with in the attached file rec06-orig.cpp.

It provides the basic class definitions that we will need for modeling a directory of employees in a company. In particular, it provides the code you will need for the classes Entry and Position, along with a start for the Directory class.
___
Your job is to:

* Read and understand the given code.
* Fill in the missing code for the Directory add method.
* Overload Directory's output operator. Test your code now!
* Implement the Big 3 (i.e., destructor, copy constructor and assignment operator) for the Directory class. At the beginning of each of these functions, add a print statement to show when you have entered them. This will help you understand when / where they are each being used.
* Overload Directory's [] operator to allow looking up a person's phone number, by passing in their name.
* You should (as always) consider if there is any way to further expand the code in main() to test your new features.
## Dynamic Array?
Some might ask, "Why are we using a *dynamic array* of Entry pointers for our Directory?" Sure, you are [much] more likely to use a vector or other container type (e.g. map), but this provides you with a good exercise in implementing copy control, which is the point of this exercise.

Note that the Directory is *responsible* for both the Entries and the dynamic array itself.

You should *think* about how using a vector of pointers would change your code.