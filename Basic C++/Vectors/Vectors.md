# Vectors 
Vectors are similar to lists in Python. It is a flexible *container* that can hold any number of things, can grow as needed and provides quick access to any item given a number, its "index."

## How to define vectors
We need the `<vector>` library to use vectors:
```c++
#include <vector>
```

## Properties of vector
* initilized like an empty list in Python, with 0 elements inside
* Supports indexing
* Doesn't support slicing
* Doesn't have a fixed size like arrays

To define a variable as a vector, we have to say what kind of vector it is. Is it a vector of ints? A vector of Elephants?

To define a vector of ints:
```c++
vector<int> vectorOfInts;
```
Note: the *type* of variable is `vector<int>`

To define a variable to be a vector of Elephants:
```c++
vector<Elephant> vectorOfElephants;
```
Note: the *angle brackets* are what we call **templates**

## Access an element of vector
We use *square brackets* to specify an element we want, and this is called indexing.
```c++
cout << vectorOfInts[0]; // 1th element
```
### Adding elements to a vector at the end
Like list's `append()` method, vectors has the method `push_back()` to add elements to the end of a vector.
```c++
vectorOfInts.push_back(5);
vectorOfInts.push_back(8);
```
### Size of a vector
We use `size()` method:
```c++
cout << vectorOfInts.size();
```

### Looping through a vector
```c++
for (size_t i = 0; i < vectorOfInts.size(); ++i) {
    cout << vectorOfInts[i] << endl;
}
```
Note: we use type `size_t` instead of `int` for counter `i`. Maybe int won't be "big enough" to hold the size of a vector. To allow your code to be "portable", the type `size_t` was defined. It will always match up with whatever the size method returns. The type `size_t` is `unsigned` so it will never be negative.

## Ranged For
There is an easier way to loop over a vector known as the *ranged for*.

```c++
for (int x : vectorOfInts) {
    cout << x << endl;
}
```
## Pass by Reference
Technical detail: While *ranged for* accomplishes the same thing as the traditional for loop I showed first, there is an important difference that goes beyond appearances. 

The ranged for is actually equivalent to the following variation on our loop:
```c++
for (size_t i = 0; i < vectorOfInts.size(); ++i) {
    int x = vectorOfInts[i];
    cout << x << endl;
}
```
The difference is that x is a copy of the element in the vector. Why does that matter? It doesn't in our example of printing the elements in a vector of ints. But what if we wanted to modify the contents of the vector? Below is a loop that looks like it modifies all of the elements in the vector to be 17. In fact, it doesn't change the contents of the vector at all.
```c++
for (int x : vectorOfInts) {
    x = 17;  // Does not modify the vector
}
```

To change the contents, then we need to use a feature we introduced in the discussion of parameter passing, the "reference"
```c++
for (int& x : vectorOfInts) {
    x = 17;  //  Does modify the vector
}
```
we specified x's type to be a *reference* to an int, by using the "and-sign". Now there won't be any copying. Instead x will be an alias for each element of the vector as it steps through the loop.

## If we don't want an empty vector
Suppose we want to have the vector start out with, e.g. 28 elements, all with the value 17, we could have defined our vector as:
```c++
vector<int> vectorOfInts1(28, 17); // initialised to hold 28 seventeens.
vector<int> vectorOfInts2(28); // initialized to 28 zeros.
vector<int> vectorOfInts3; // initialized to a size of zero.
```

## Vector as a function parameter
When writing a function that will take a vector of ints as an argument, the type is `vector<int>`. But we will almost certainly want to pass the vector by *reference*. Otherwise when we try to change the values stored in it, the changes will only happen to a *copy*. If we are not going to change the contents of the vector then pass it by *constant reference*. Why? So that we don't waste time and space making a copy of the vector.
```c++
void displayVector(const vector<int>& aVector) {
   for (size_t i = 0; i < aVector.size(); ++i) {
      cout << aVector[i] << endl;
   }
}
```

## Common Vector Methods
* push_back
   * Takes a single argument, the thing to be copied onto the end of the vector.
    * The vector's size increases by one, each time we do a push_back.
* pop_back
    * Takes no arguments and returns nothing.
    * Removes the last item from the vector, decreasing the size by one.
* size
    * Takes no arguments.
    * Returns a size_t representing how many items are in the vector.
    * Note that the index for the last item in the vector aVec would be aVec.size()-1.
* clear
    * Takes no arguments.
    * Sets the size of the vector to zero.
* back
    * Takes no arguments.
    * Returns a *reference* to the last element in the vector.
