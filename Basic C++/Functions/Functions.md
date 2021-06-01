# Functions in C++

A typical example of a function is one that computes the factorial.
```c++
int factorial(int n) {
   int result = 1;
   for (int i = 2; i <= n; ++i) {
      result *= i;
   }
   return result;
}
```
Note:
* parameter of *type* int
* return value of *type* int
* *local variable* called result which only exists inside the scope of the function

Here is a complete program that queries the user for a number and displays the factorial of that number:
```c++
#include <iostream>
using namespace std;

// compute n!
int factorial(int n) {
   int result = 1;
   for (int i = 2; i <= n; ++i) {
      result *= i;
   }
   return result;
}

int main() {
   cout << "N? ";
   int value;
   cin >> value;
   int answer = factorial(value);
   cout << value << "! is " << answer << endl;
}
```
## Prototypes
In the program above, we had to write the definition for `factorial()` before `main()` since the compiler compiles top down. 

Sometimes it is inconvenient, or impossible, to provide the defintion of a function before the function is called. The compiler will still be happy if you just promise that you will define the function. To do that, we provide a *prototype* for the function. 

The prototype shows the function's 
* return type
* name 
* parameter types.

A prototype for our factorial function would be:
```c++
int factorial(int n);
```
Note: the semi-colon at the end of the line is necessary.

We could rewrite the program we showed that asks for a number and displays the number's factorial as:
```c++
#include <iostream>
using namespace std;

// compute n!
int factorial(int n);

int main() {
   cout << "N? ";
   int value;
   cin >> value;
   int answer = factorial(value);
   cout << value << "! is " << answer << endl;
}

int factorial(int n) {
   int result = 1;
   for (int i = 2; i <= n; ++i) {
      result *= i;
   }
   return result;
}
```
## Void Return Type

Not all functions return a value. If the function has nothing that it needs to return, the return type is `void`. 

A function that prints out factorials:
```c++
// display n!
void displayFactorial(int n) {
   cout << factorial(n) << endl;
}
```
## Parameter Passing

### pass-by-value
Suppose we want a function that will return a value one more than what gets passed as the argument:
```c++
int addOne(int n) {
   int n = n + 1;
   return n;
}

int main() {
   int num = 5;
   int answer = addOne(num);
   cout << "num: " << num << "; answer: " << answer << endl;
}

// output: num: 5; answer: 6
```
Note:
* The number we passed into addOne is *copied* into the parameter
* `num` in `main` is not changed
* This is called **pass-by-value**.

### pass-by-reference
What if we do want the value to get changed? We **pass by reference**.

```c++
int addOneByReference(int& n) {
   n = n + 1;
   return n;
}
```
Note:
*  Now the value that gets passed in does not get *copied*.
* Any changes made to the parameter also effect the argument that was passed.
* If we call `main()`, the output will be
```c++
num: 6; answer: 6
```

We cannot pass a literal by reference:
```c++
addOneByReference(17);  // Won't compile!!  17 cannot be passed to a reference parameter.
```
Pass-by-reference requires the argument to be a thing that has an actual address somewhere in memory, something whose value we can modify. Similarly, it won't work if we are trying to pass the result of some computation:
```c++
int x = 3, y = 4;
addOneByReference(x+y);  // Won't compile!!  x+y cannot be passed to a reference parameter.
```
 The result of x+y is "temporary", it doesn't exist past the expression it is in, and so C++ won't allow you to make a reference to it.

 ### pass-by-constant-reference
 
 Why is this bad?
 ```c++
 void displayString(string aString) {  // BAD code!!!
   cout << aString << endl;
}
```
Whatever we are passing in gets *copied* into the variable aString. That takes time and space. If we pass in a large string, or call the function very often, we might be surprised how much this can impact the performance of our program.

Should we then pass-by-reference?
```c++
void displayString(string& aString) {  // an improvement in performance, but still not good.
   cout << aString << endl;
}
```
The main problem is that if we had a bug in this function that happened to change what is in aString, then the change would also effect whatever was passed in. If we don't need to change aString, we should 
**pass-by-constant-reference**

```c++
void displayString(const string& aString) {  // The right way to do it!
   cout << aString << endl;
}
```

### Overloading Functions
C++ allows you to write two different functions that have the same name. This is known as **function overloading**. The requirement is that the functions have different parameter lists. They can differ either in the number of parameters or in their types.

So, if we wanted to write a couple of [fairly useless] functions, one to display an int and another to display a string, we could either give them different names, as in:
```c++
void displayInt(int n) { cout << n << endl; }
void displayString(const string& s) { cout << s << endl; }
```

or we could just pick one function name for both:
```c++
void display(int n) { cout << n << endl; }
void display(const string& s) { cout << s << endl; }
```
Many languages support this feature nowadays. But some widely used languages, such as C, do not.

Note that in the programming literature there are those who argue against overloading functions, claiming that it can make the code more difficult to read. You should make sure that the overloaded functions mean the same thing to avoid confusion.