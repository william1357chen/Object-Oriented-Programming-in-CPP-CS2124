# Converting the Vector class to a Vector Template class.

1. Add the template header:
```c++
template <class T>
```
just before the class definition. The word "template" is a keyword and so is "class". Instead of "class", the language allows you to use "typename", so you may come across either one when reading code. "T" is a totally arbitrary choice for the name of the type that we are using. It is very common for people to use "T", but you could use "SLUG" or "slug" just as well.
2. Change the type of the member data from `int*` to `T*`. This is the data type that the Vector depends on and the main point of converting to a template class.
3. Look for other uses of int to replace them with `T`.
    * Change the return types in the two versions of operator[] from `int&` to `T&`
4. Copy and paste *all* the function definitions from Vector.cpp to the end of Vector.h.


Every function needs to be examined for changes. Here I have described the kinds of changes that have to be made and which functions they apply to.

1. Add the template header.
```c++
template <class T>
```
in front of every function definition. (Sorry for being boring and using "T". Not everyone likes SLUGs.)

2. Replace "`Vector::`" with "`Vector<T>::`" throughout the file.
3. You do not have to change parameter types passed to member functions, because the use of `Vector<T>::` already tells the compiler that we will be using a parameterized type for Vector throughout the *rest* of the function.
4. However, non-member functions need to have their parameter types qualified:
    * In the input/output operators change the parameter from `Vector` to `Vector<T>`.
5. Also the *return type* for the assignment operator must be qualified as it is not 6. within the scope of the qulified function name.
    1. Look for other uses of "int" that need to change to "T".
    1. Check any use of `int*`
        * the `resize` function.
    1. Check any use of `new int` for functions where an array of ints is being created
        * constructors
        * resize function
        * assignment operator
    1. Change the return type for the const `operator[]` from `int` to `T`.
    1. Change the return type for the non-const `operator[]` and `int&` to `T&`.
    1. Be careful *not* to change any use of int that is used for other purposes such as an index for an array or the size of the Vector. (It would have been better if we'd used size_t for all these, but we haven't been. Oh, well.)

### In TestVector.cpp

Change "`Vector`" to "`Vector<int>`" when defining the vectors `v` and `w`.

### Finally

1. ReBuild the project. You will get several errors for the compilation of Vector.cpp. That's ok, we'll get rid of them right now:
    * In the VC++'s Solution Explorer select the file Vector.cpp and hit the delete key because we do not want it in the project anymore. Don't worry the file wasn't deleted, in case you still want it for some reason. It's just been removed from the project.

That completes all the changes necessary. We can now create Vectors of any type we wish without any further changes.