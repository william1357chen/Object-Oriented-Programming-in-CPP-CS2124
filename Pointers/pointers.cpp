#include <iostream>
using namespace std;

// Memory and pointer

int main(){

    // POINTER HOLDS ADDRESS
    int x = 17;
    cout << &x << endl; // prints the memory address of x 0x7ffeefbff4ec hexa decimal (starts with 0x)

    // If u want to store the address:
    int* p = &x; // int* means an int pointer
    // int *p = &x same thing
    // int * p = &x
    cout << p << endl;
    
    // how to use p to get value of x?
    cout << *p << endl; // *p = x and p = &x

    // Different pointers 
    const int* p1 = &x; // This is a pointer pointing to a constant int, meaning p1 cannot modify the integer x
    int* const p2 = &x; // This is a constant pointer pointing to an int, meaning p2 can modufy the integer x, but p2 cannot point to something else
    const int* const p3 = &x; // This a constant pointer pointing to a constant int, meaning p3 can modify neither x nor point to something else
}