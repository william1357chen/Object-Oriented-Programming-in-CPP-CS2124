# Recitation 14 - Recursion
Note: This lab must be checked out in class!!!

## Topics
* recursion
## Recitation Instructions
* Solve the tasks below using recursion. That means the function we ask you to write must call itself.
* **Do not** use globals!
* **Do not** use any loops, i.e. for or while. And don't call any functions that would be using loops.
* **Do not** pass any arguments other than those stated in the problem.
* Once you have tested your code and are confident that it is working correctly, *then run each of your functions through the debugger* for your system and examine *the call stack* as you go. 
    * Usually we use the debugger to [duh] debug our programs. Here you are using it to understand the way your code works. The key to understanding recursion is to understand recursion... No, no. I meant to say the key is understanding how the call stack represents each step of the recursion.

Ok, here are the things to do today. Hopefully by the time you are done, you will be an ace at recursion.

1. Write a recursive function to determine if a non-negative integer has an even number of ones in its binary representation. Return true if it does and false otherwise.
    * Note that you are not being asked to compute the number of bits that are one, only if that would be even.
    * Think about what the recursive call will do for you. It will tell you if the subproblem has an even number of bits. Now you just need to take that information and combine it with whether this next bit you are looking at is one or not.
1. Write a recursive function to create and return a new list that is the sum of the values in the two lists passed in. Do not assume that the two lists are the same length. (By a *list*, I mean a `Node*`, not an instance of a list class.)

1. Write a recursive function to return the maximum of the values in a binary tree.
    * Here is a definition for a binary tree's node in case you have forgotten:
    ```C++
    struct TNode {
        TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
            : data(data), left(left), right(right) {}
        int data;
        TNode *left, *right;
    };
    ```
* We will assume there is no meaningful value for the maximum of an empty tree. You should throw an appropriate exception for C++'s exception hierarchy (http://www.cplusplus.com/reference/exception/exception/).
    * Note that the standard exceptions are in a header file called stdexcept. Also, they tend not to have a default constructor, but rather to require a string argument that will be returned by the method `what()`.
    * Be sure to test your code using try / catch and demonstrating that your function works correctly whether the tree passed is empty or not.
    * Note, this is not a binary search tree.
1. Write a recursive function called palindrome. It will be passed an array Note that when an array is passed to a function, only the address of the first element is passed. So, what your function is really being passed is the starting point of the array and how many characters there are. Of course, to use it you can just pass in the name of the array, as the name is equivalent to its address.
    * Your recursive calls only need to be passed the address of the portion of the array you want to process and the number of characters.
    * An example of calling your function might be:
    ```c++
    char s[] = "racecar";
    if (palindrome(s, 7)) { cout << "Yes!\n"; }
    ```
    * It of course would also return true for "noon".
1. Implement a recursive function to solve the towers of hanoi problem. However, your function should not print anything. Instead it should just return the number of moves needed.
Remember: 1) you are writing a recursive function. We are not interested in seeing a function that just outputs the result of computing a formula. 2) As always, no globals.

    * If you are unsure what the results should be, the test code that I used to check my solution generated the following output:
    ```
    #5) Testing towers
    towers(1, 'a', 'b', 'c'): 1
    towers(2, 'a', 'b', 'c'): 3
    towers(3, 'a', 'b', 'c'): 7
    towers(4, 'a', 'b', 'c'): 15
    towers(5, 'a', 'b', 'c'): 31
    towers(6, 'a', 'b', 'c'): 63
    towers(7, 'a', 'b', 'c'): 127
    towers(8, 'a', 'b', 'c'): 255
    towers(9, 'a', 'b', 'c'): 511
    towers(10, 'a', 'b', 'c'): 1023
    ```
1. Given the following function definition, figure out what it will return for values 0 to 10, and verify that you were correct. (If you were not correct, then use your debugger or print statements to determine where you went wrong.
    ```C++
    void mystery(int n) { 
    if (n > 1) { 
        cout << 'a'; 
        mystery(n/2); 
        cout << 'b'; 
        mystery(n/2); 
    } 
    cout << 'c'; 
    }
    ```

### Additional resources for assignment
* [tree.cpp](./tree.cpp)