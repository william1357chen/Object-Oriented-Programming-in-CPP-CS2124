# Include Guard
Include Guards (also sometimes called macroguards) are used to prevent functions, classes and other symbols from being declared more than once. Remember that if C++ comes across a symbol being declared a second time then it will flag that second declaration as an error. Classes are usually declared in header files and sometimes a header file gets included more than once. The second time you include the header file, the class that is declared inside it will be declared again.

Suppose you have a class, Person, that you have declared in a file called Person.h. You would like to be able to include Person.h in your code without having to think if it has already been included. That's where the include guard comes in. An include guard consists of three lines:

```c++
#ifndef ...
#define ...
#endif
```
I have used "..." to refer to some identifier name that we will fill in later.

The command "#ifndef" means "if ... is not defined". If it is already defined then every line of code up till the line "#endif" will be completely ignored by the compiler.

The command "#define ..." defines the identifier that we use instead of "...". What does it define it as? In this case we are only saying that the identifier *exists*, or in other words that it has been defined. The value doesn't matter and since we never intend to refer to its value, we don't bother to specify one. I figure if I did specify a value then someone might become confused and wonder why we picked that value instead of some other value.

The third line, which would come at the end of your file, is used to end the "if" that was used in the "#ifndef" line.

The next question is, what should be put in place of "..." in lines 1 & 2? Any symbol name at all could be used. But it should be a symbol that `isn't being used anywhere else`. What could we use? Well, a name based on the file name would seem a good choice. For example, we might choose `PERSON_H`. We used the underscore character ("_") instead of the period (".") since identifiers can't have a period in them. We used capital letters just because that's the accepted tradition when declaring any constant symbol.

Therefore the header file Person.h, might look something like this:
```c++
#ifndef PERSON_H
#define PERSON_H
class Person {
// The rest of the definition of the Person class would go here.
};
#endif 
```
A common programming error is to use the same symbol in more than one file. Be careful and don't do it. What kind of error would be caused? Suppose we already included in a *different* file that also started with the lines:
```c++
#ifndef PERSON_H 
#define PERSON_H
```
and then we try to include our Person.h header file. This time the class Person will not get defined. Any code in the ".cpp" file which refers to the Person class will get an error indicating that the Person class is undefined.
