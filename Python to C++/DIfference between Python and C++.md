# Python to C++ (the Differences)

## C++ is a Compiled language
Python is a interpreted langauge, where you type a line into IDE and  the code execute immediately. C++ has to be **builded** in order to be executable, which includes two steps: complication and linking. The word **build** and **compile** are used interchangeably. 

## C++ is a static type language
Python is a dynamically typed language where a variable can change from an integer to a string. In C++, we have to define a type for the variable and assigning a value with the **wrong** type to a variable will result in a complication error.

Remember, we have to define the types for variables, parameters of functions, and return values for fucntions.

## Indentation vs. Blocks
In Python, we use indentation to define structures. In C++ we use a pair of curly braces to define structures. Of course, for human readability, it is important in C++ that we still use consistent indentation.

In Python:
```python
def func():
    print("CS 2124")
```
In C++:
```c++
void func(void):
    cout << "CS 2124" << endl;
```
## Statements End in Semicolon
In Python, each line is a statment by default, but C++ allows a statement to take multiple lines so we use the semicolon `;` to tell the compiler when a statement is finished.

## Console I/O
C++ does not have a `print()` function like Python. Instead, the simple input (from the keyboard) and output (to the screen) uses the input and output operator.

Print variable x to screen:
```c++
cout << x << endl;
// endl means to print a new line character, which is the same as 
cout << x << '\n';
```

Read from keyboard into variable x:
```c++
cin >> x;
```

Note:
* `cout` stands for *standard output*, which represents the screen.
* `<<` is the *output operator*, which directs variable `x` to `cout`
* `cin` stands for *standard input*, which represents our keyboard.
* `>>` is the *input operator*, which directs the input from keyboard to variable `x`. 

## String and Character Literals
In Python, we can use single and double quotes to represent a string or character. In C++, double quotes are used to represent string literals and single quotes are used to represent a character literal. 

## Syntax Differences
There are lots of syntax differences between Python and C++, which will be shown to you in the following semester. 



