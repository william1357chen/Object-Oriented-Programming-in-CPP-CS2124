# Basic Syntax of C++

## Topics
* Main function
* Variables
* Primitive types
* Conditions
* Logical Operators
* Loops

## The main function
In C++, every program must have a function called main, which is the program called when we compile and run a C++ program. The main program has to return type `int`. 

Here is a simple working C++ program:
```C++
int main() {return 0;}
```

## Hello World

```c++
#include <iostream>
using namespace std;

int main(){
    cout << "Hello World" << endl;
}
```
Note:
* `#include` tells compiler to read in the library `iostream` to use the function `cout`. 
* `using namespace` will same you having to type the **qualifier** `std` to `cout`. Otherwise, that line will turn to 
```c++
std::cout << "Hello World" << endl;
```

## Variables
 C++ requires that all variables be defined before they are used and furthermore that every variable must have a type that sticks with the variable until it ceases to exist.

Suppose we want to modify the previous program to ask the "user" for a name to say hello to:
```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
   string name = "world";
   cout << "Hello " << name << "!\n";
}
```

However, we should ask the user for their *name*:
```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
   string name;
   cout << "What is your name? ";
   cin >> name;
   cout << "Hello " << name << "!\n";
}
```

Note:
* `string name` did not define the content of name but did initilize the variable `name` for us to use in `cin >> name;`

### Default Types - Also known as *primitive* types
* int: the most common type to represent integers. In most compilers this will be a 32-bit value 
* double: used for "floating point" values, like 3.1415926535.
* bool: can hold the values `true` and `false`.
* char: holds a "character".

## Conditions
Here are the syntax for if / else if / else statements:
```c++
// a simple if statement
if (answer == 42) {
   cout << "Now what was the question?";
}

// an if-else statement
if (answer == 42) {
   cout << "Now what was the question?\n";
} else {
   cout << "The answer wasn't 42\n";
}

// an if-else-if-else statement
if (answer == 42) {
   cout << "Now what was the question?\n";
} else if (answer == 17) {
   cout << "That's pretty random\n";
} else {
   cout << "Wasn't anything we tested for.\n";
}
```
Note: conditions must be in parentheses in C++, which applies to *for loops*, *while loops*, *if else statements*, etc. 

### Logical Operators
* `and` is `&&`
* `or` is `||`
* `not` is `!`

## Loops 

### For loop
```c++
for (int i = 0; i < 5; ++i) {
      cout << "Hello world!\n";
   }
```
There are three parts in the for loop: 1) initialization, 2) test and 3) increment. 
1. Initilization defines a counter `i` of type `int`. The variable will *only* exist in this for loop.
2. Tess is evaluated each time we iterate the loop, which is the condition as to when we should stop.
3. Increment part is whatever code we want to use after a pass through the loop and before we do the test to decide if we should begin another loop.

### While loop
While loop is to continue looping over a block of code so long as some condition it true. 
```c++
while (i < 5) {
    cout << "Hello world!\n";
    ++i;
```


