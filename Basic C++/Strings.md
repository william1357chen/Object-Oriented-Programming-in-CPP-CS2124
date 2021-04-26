# Strings
Strings are like vectors and `string` in Python, and can be used like a vector of characters. The methods and operators used for vectors all works for strings.

```c++
string s = "abc";  // Note the double quotes around a string.
s.push_back('z');  // Note the single quotes around a character.
```
We can also access the characters in a string using the square-bracket operator. And if the string hasn't been marked as *constant*, we can change the value of a character inside it, the same way we would change any of the values inside a vector.
## String Concatenation
Two string objects can be concatenated together using the + operator, to form a new string. Similarly, we can use += to add one string onto another string (i.e. to append one string to another).
```c++
string a = "The";
string b = "Cat";
cout << a + " " + b << endl;
```
or 
```c++
string a = "The";
string b = "Cat";
a += " ";
a += b;
cout << a << endl;
```

Note: these `+` and `+=` operators only support *string* objects, not string literals
Ex:
```c++
cout << "The" + " " + "Cat" << endl;  // Does NOT compile!
```
`"The"` is a string literal, not a string object.