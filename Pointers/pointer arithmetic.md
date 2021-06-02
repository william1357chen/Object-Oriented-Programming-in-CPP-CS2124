# Pointer Arithmetic
The C++ language allows you to perform integer addition or subtraction operations on pointers. This is called ***pointer arithmetic***. If `ptr` points to an integer `value`, `ptr + 1` is the address of the next integer in memory after `ptr`. `ptr - 1` is the address of the previous integer before `ptr`. 
## Why does pointer arithmetic work
Pointer arithmetic works because the C++ is a static type language, meaning every variable has a defined and non-changing type. Therefore, C++ knows exactly how many bytes in memory to skip for `ptr + 1` to not point at the integer `value` anymore. Integers are usually 4 bytes in memory, so the address of `ptr + 1` will be 4 bytes ahead of the address of `ptr`.

Example: 
```c++
#include <iostream>
using namespace std;
 
int main()
{
    int value = 7;
    int* ptr = &value;
 
    cout << ptr << '\n';
    cout << ptr+1 << '\n';
    cout << ptr+2 << '\n';
    cout << ptr+3 << '\n';
 
    return 0;
}
```
On the my machine, this output:
```
0xf2d1bffce4
0xf2d1bffce8
0xf2d1bffcec
0xf2d1bffcf0
```
As you can see, each of these addresses differs by 4 (e4 + 4 = e8 in hexadecimal). This is because an integer is 4 bytes on the machine.

## Pointer Arthemetic in Arrays 
Because of pointer arthemetic, we can easily index an array, since **Arrays are laid out sequentially in memory**. Additionally, **Arrays can only store a single type of elements**, so the memory size of each element in an array is the exact same.

By using the address-of operator (&), we can determine that arrays are laid out sequentially in memory. That is, elements 0, 1, 2, … are all adjacent to each other, in order.

```c++
#include <iostream>
using namespace std;
 
int main()
{
    int array[] = { 9, 7, 5, 3, 1 };
 
    cout << "Element 0 is at address: " << &array[0] << '\n';
    cout << "Element 1 is at address: " << &array[1] << '\n';
    cout << "Element 2 is at address: " << &array[2] << '\n';
    cout << "Element 3 is at address: " << &array[3] << '\n';
 
    return 0;
}
```
On my machine, the output is:
```c++
Element 0 is at address: 0x32ec7ff8b0
Element 1 is at address: 0x32ec7ff8b4
Element 2 is at address: 0x32ec7ff8b8
Element 3 is at address: 0x32ec7ff8bc
```
Note: each of these memory addresses is 4 bytes apart

## Array Subcripting and Pointer Arithmetics
We now know that arrays are laid out in memory sequentially. 

We should also know that a fixed array can work as a pointer, since the array variable is a pointer that points to the first element (element 0) of the array.

In a section above, we learned that adding 1 to a pointer returns the memory address of the next object of that type in memory.

Therefore, we might conclude that adding 1 to an array should point to the second element (element 1) of the array. We can verify experimentally that this is true:
```c++
#include <iostream>
using namespace std;

int main()
{
     int array[] = { 9, 7, 5, 3, 1 };
 
     cout << &array[1] << '\n'; // print memory address of array element 1
     cout << array+1 << '\n'; // print memory address of array pointer + 1 
 
     cout << array[1] << '\n'; // prints 7
     cout << *(array+1) << '\n'; // prints 7 (note the parenthesis required here)
 
    return 0;
}
```

Output:
```
0xa5061ffd74
0xa5061ffd74
7
7
```
Now, we found out that **pointer arithmetic** is why we are able to get the indices of an array. The syntax:
```c++
array[1]
```
is actually implemented using pointer arithmetic and they are the exact same thing
```
*(array + 1)
```
Note that the parenthesis are necessary to ensure the operator precedence is correct, since operator `*` has *higher* precedence than operator `+`.

## Two ways of Iterating an Array
With the above knowledge, we are able to loop through an array with indicing and pointer arithmetic.
```c++
#include <iostream>
using namespace std;

int main(){
    int array[] = {1,2,3,4,5};
    // Using Indicing
    cout << "Loop through the array with Indicing" << endl;
    for (size_t i = 0; i < 5; i++){
        cout << array[i] << " ";
    }

    // Using Pointer Arithmetic
    cout << endl << "Loop through the array with Pointer Arithmetic" << endl;
    for (int* ptr = array; ptr != (array + 5); ptr++){
        cout << *(ptr) << " ";
    }
}
```

Output: 
```
Loop through the array with Indicing
1 2 3 4 5 
Loop through the array with Pointer Arithmetic
1 2 3 4 5 
```
## Conclusion
It turns out that when the compiler sees the subscript operator `[]` for arrays, it actually translates that into a pointer addition and indirection! Generalizing, `array[n]` is the same as `*(array + n)`, where n is an integer. The subscript operator `[]` is there both to look nice and for ease of use (so you don’t have to remember the parenthesis).

___

Reference: [Link](https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-array-indexing/)