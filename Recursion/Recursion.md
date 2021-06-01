# Recursion
*To understand recursion, first you must understand recursion.*

A function that calls itself is a **recursive function**. This programming technique is called **recursion**. Some uses of recursion may lead to very inefficient code, while others are perfectly reasonable and make the implementation of an algorithm easier to understand.

## Design
1. Think about how you can solve the problem by using the *same* function on a smaller version of the problem.
1. Do some *small* piece of the task at each call to the function.
Know when to stop.
1. Be sure to get the right ordering between items 1 & 2.

Always try your solution out on a small test case. Employing such sanity checks should be an ingrained habit.

Recursive solutions are often a little surprising the first time you see them. **Practice** helps.

## Simple Examples
* Basic Printing
    * Print 1 to n [in reverse]
    * Print n of one character followed by n of another.
    * Print n to 1 followed by 1 to n.
    * Print digits of an int [in reverse]
* Arrays
    * Print an array [in reverse]. Note: requires passing in the array’s size.
    * Sum/max/min of an array.
    * Reverse an array
    * Check for palindrome
    * c-string. No size needed. Example of using a sentinel.
        * print [in reverse].
        * length.
* Factorial
* Count the number of 1’s in the binary representation of a non-negative int.
* Exponention: pow(x, n). Both brute force and “smart”. The smart solution saves a lot * of multiplies for large values of n.
* `gcd( x, y ) = ( y == 0 ? x : gcd( y, x%y ) )`.
* Linked list* 
    * Display [in reverse]
    * Find a specified value
    * Find last element
    * Clear
    * Copy
    * Size [or length] of the list.
    * Sum/max/min

## Harder Examples
* Fibonnaci
* Binary Search
* Towers of Hanoi (also try an iterative solution)