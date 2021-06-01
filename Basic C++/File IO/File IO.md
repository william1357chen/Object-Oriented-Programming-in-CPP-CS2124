# File I/O for Text Files
To deal with text files in C++, we need the `<ifstream>` library, which is the input stream class to operate on files. 

## Reading a File
1. The first step of reading a file is to create a **stream object** to get input from a file. A stream object has type `ifstream`.
```c++
#include <ifstream>
ifstream ifs("data.txt")
```
Note: Here we defined a variable `ifs` which is a stream object of the `data.txt` file. 

2. We should check if the file opened correctly. 
```c++
if (!ifs) {
   cerr << "Could not open the file.\n";
   exit(1);
}
```
3. To read from the file, it depends on what information is in the file and how we want to use it. 

Most common way to read from a file:
```c++
ifs >> x;
```
C++ would skip over any whitespace, interpret what it sees in the file based on the type of variable x, and read until whitespace. 
### Loop Through a File
Suppose we have a file of integers to read and print, we will need a loop:
```c++
int anInt;
while (ifs >> anInt) {
   cout << anInt << endl;
}
```
Note: the while loop has the condition of whether the read is successful, and if unsuccessful we know there is no more to read. 

### Reading a Line
If we want to read an entire line with whitespaces:
```c++
string line;
getline(cin, line);
```
Note: variable `line` will get every character expect the end-of-line character.

Looping through a file line by line:
```c++
while (getline(ifs, line)) {
   cout << line << endl;
}
```
### Close a File
Make sure to always close a file whenever you are done with it.
```c++
ifs.close();
```
### Other Useful Methods
If you have attempted to read something and couldn't, either because you came to the end of the file, or something of the type you wanted to read wasn't at that spot in the file, some flags get set inside the stream object. These flags will prevent you from reading anything else from the file. If you still reading the file, you will need to "clear" those flags.
```c++
ifs.clear();
```
If we finished reading till the end of a file and want to go back to the start and read the file again, jump to the beginning with:
```c++
ifs.seekg(0);
```
Note:  if you had already read all the way to the end of file, you will nead to call `clear` before you can `seekg`.

### Passing Streams
One group of parameter types that need to be treated specialy is the stream classes. Whether you are talking about the standard streams (i.e. `cin`, `cout` and `cerr`) or you are talking about a file stream, the all must be passed-by-reference.

Why? The point is we never want to make a copy of a stream. We don't want to have two different stream "objects" referring to a single real underlying stream. A stream has a number of attributes that describe the stream's current status. For example, is it still ok to read from? What is the next position in the stream that we will read from or write to? Every time you use a stream, those attributes can change. But if we have to different stream objects referring to the same underlying stream then they can end up disagreeing with each other. And that's not good.

To prevent such confusion, we always pass streams by reference. That way even when we have passed a stream to a function, the parameter name in the function is really referring to the same stream object as the calling function was using.

Oh, and you will find that you don't have any choice in this area. If you try to pass a stream by value, or try to make a copy of a stream in any other way, your program will not compile. The folks who wrote the stream classes made sure of that. Later on, when we discuss copy control, we will see how they did it.

What about making your stream a const parameter? Not likely to be a good idea. After all, think about what a stream object holds. Among other things, it has flags as to whether it is still readable or if we have hit the end of the file. And it has some sort of position marker that keeps track of where the next read will come from or where the next write will go to. All these things need to be free to be modified when we use the stream, so passing a stream by constant reference is not good.