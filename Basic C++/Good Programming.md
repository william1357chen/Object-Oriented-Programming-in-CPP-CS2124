# Good Programming
It's a little scary to start a section on "good programming", especially in an introductory guide to C++. There's a lot to say under this heading, but I want to keep it short and to the point. First off, you should probably check my [C++ Coding Guidelines](https://cse.engineering.nyu.edu/jsterling/cs2124/Notes/CodeGuideline.html) for simple things like naming conventions and the like.

There are a few other things that you should pay careful attention to as you start your C++ programming career.

## Globals
Global variables are variables that are defined outside of any function or type definition. Every variable that we have defined was either local to a function or was a member of a struct. My "advice" on using globals at this stage?

Don't.

Overuse of globals is generally viewed as a sign of sloppy code. What's the problem with them? Any piece of code, anywhere in the program can access and even modify their contents. It makes debugging much, much harder. And one of the advantages of using a language like C++ is to make debugging easier.

For this course, you will **never use global variables**. This is to get you thinking the right way. Later on, you will make up your own mind as to when a global is an improvement to your program. Hopefully by then you will recognize the danger of globals and use them sparingly.

Global constants, on the other hand, are ok, in fact we encourage you to use them! Here is an example:
```c++
const int THE_ANSWER = 42;
```

## Scope
Define your variables using the smallest scope possible. This is in a sense an extension of what I said about globals. You want to define a variable so that ideally it can only be used where it makes sense. We saw an example of this earlier when I talked about the for loop and how you can limit the scope of the loop's index to just the for loop itself. That's a good thing.

In general, define a variable as close to the place where it is first used as possible. In some languages, like earlier versions of C, you have to define all local variables at the beginning of a function. That's not true in C++. In fact, it is considered poor programming style in C++ to define them all at the beginning of the function. (Old time C programmers will tend to disagree with me on this.)

So, if a variable is only going to be used inside a block of code (i.e. within a pair of curly-braces) such as in an if statement or a loop, then put the definition for that variable *inside* that block.