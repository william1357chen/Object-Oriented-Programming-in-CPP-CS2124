# Code Samples

## Basics of C++
* File I/O
    * [Reading in a file](./Basic%20C%2B%2B/File%20IO/code%20snippets/readFile.cpp)
    * [How <em>NOT</em> to read a file](./Basic%20C%2B%2B/File%20IO/code%20snippets/badFileHandling.cpp). The code shows the a common error in writing a loop to read a file. Can you modify the program so that it works properly? Don't change the input file.
* Functions
    * [Parameters Passing](./Basic%20C%2B%2B/Functions/code%20snippets/parameterPassing.cpp)
    * [Default Parameters](./Basic%20C%2B%2B/Functions/code%20snippets/defaultParameters.cpp)
* Structs
    * [Struct Basics](Basic%20C%2B%2B/Structs/code%20snippets/structs1.cpp)
    * [Demonstrating the need for const methods](Basic%20C%2B%2B/Structs/code%20snippets/structs2.cpp
* Vectors
    * [Reading a file into a vector](./Basic%20C%2B%2B/Vectors/code%20snippets/vectorBasics.cpp)
    * [Reading a file into a vector of class objects.](Basic%20C%2B%2B/Vectors/code%20snippets/vectorOfClass.cpp) How do you fill a vector of objects?
    * [Vector of objects that contain vectors](./Basic%20C%2B%2B/Vectors/code%20snippets/vectorOfObjectsContainingVectors.cpp)

## Classes 
* [The simplest class](./Classes/Class%20Basics/code%20snippets/SimplestClass.cpp)
* [A simple Date Class](./Classes/Class%20Basics/code%20snippets/SimpleDate.cpp)
* [A simple Person Class](./Classes/Class%20Basics/code%20snippets/ClassBasics.cpp)

## Pointers
* [Addresses, pointer variables and pointer arithmetic](./Pointers/code%20snippets/PointerBasics.cpp)
* [Pointer to const, const Pointers, the differences](Pointers/code%20snippets/pointerWithConst.cpp)
* [Dynamic arrays on the Heap](./Pointers/code%20snippets/NewDelete.cpp)
* ["Expanding" a dynamic array](./Pointers/code%20snippets/DynamicArray.cpp)
* [Reading a file into a vector of pointers to objects on the heap](Pointers/code%20snippets/vectorOfObjectsOnHeap.cpp)

## Composition and Association
* [A Person struct with a birthday and a spouse (composition and association)](./Classes/Composition%20and%20Association/code%20snippets/testAssociationComposition.cpp)
* [Same composition and association but using a Person class](./Classes/Composition%20and%20Association/code%20snippets/AssociationStruct.cpp)
* ["Association" - spouse pointers](./Classes/Composition%20and%20Association/code%20snippets/AssociationClass.cpp)

## Copy Control and the Big 3
* [Copy Control Basics](./Classes/Copy%20Control/code%20snippets/CopyControlBasics.cpp)
* The big 3 using a vector class: [Vector.h](./Classes/Copy%20Control/code%20snippets/Vector.h), [Vector.cpp](./Classes/Copy%20Control/code%20snippets/Vector.cpp) and [testVector.cpp](Classes/Copy%20Control/code%20snippets/testVector.cpp)

## Separate Compilation / Namespaces
* A simple date class using separate compilation: [Date.h](./Separate%20Compilation/code%20snippets/Date.h), [Date.cpp](Separate%20Compilation/code%20snippets/Date.cpp) and [testDate.cpp](Separate%20Compilation/code%20snippets/testDate.h)
* Same date class, but with the added feature a its own namespace: [Date.h](Separate%20Compilation/code%20snippets/dateWithNamespace.h), [Date.cpp](Separate%20Compilation/code%20snippets/dateWithNamespace.cpp) and [testDate.cpp](Separate%20Compilation/code%20snippets/testDateWithNamespace.cpp)

## Operator Overlaoding 
* [Overloading the Output Operator](Classes/Operator%20Overloading/code%20snippets/outputOperator.cpp)
* Square Brackets Operator for Vector: [SquareBrackets.cpp](Classes/Operator%20Overloading/code%20snippets/SquareBrackets.cpp)
* Overloading Operators: [Date.h](Classes/Operator%20Overloading/code%20snippets/dateWithOverload.h), [Date.cpp](Classes/Operator%20Overloading/code%20snippets/dateWithOverload.cpp) and [testDate.cpp](Classes/Operator%20Overloading/code%20snippets/testDateWithOverload.cpp).
* Overloading arithmetic operators: [Complex.h](Classes/Operator%20Overloading/code%20snippets/complexWithOverload.h), [Complex.cpp](Classes/Operator%20Overloading/code%20snippets/complexWithOverload.cpp) and [testComplex.cpp](Classes/Operator%20Overloading/code%20snippets/testComplexWithOverload.cpp)

## Inheritance
* Sample Code in Notes
    * [Animal-02.cpp](Classes/Inheritance/code%20snippets/code%20in%20notes/Animals-02.cpp)
    * [Animal-03.cpp](Classes/Inheritance/code%20snippets/code%20in%20notes/Animals-03.cpp)
    * [Animal-04.cpp](Classes/Inheritance/code%20snippets/code%20in%20notes/Animals-04.cpp)
    * [NoPolymorphismFromBaseConstructor.cpp](Classes/Inheritance/code%20snippets/code%20in%20notes/NoPolymorphismFromBaseConstructor.cpp)
    * [protected4.cpp](Classes/Inheritance/code%20snippets/code%20in%20notes/protected4.cpp)
    * [Animal-05.cpp](Classes/Inheritance/code%20snippets/code%20in%20notes/Animals-05.cpp)

* [Basic Inheritance](Classes/Inheritance/code%20snippets/Inheritance.cpp)
* [Polymorphism](Classes/Inheritance/code%20snippets/Polymorphism.cpp)
* [Abstract Classes](Classes/Inheritance/code%20snippets/abstractClasses.cpp)
* [Multiple Inheritance](Classes/Inheritance/code%20snippets/multipleInheritance.cpp)
* [Inheritance mixed with Copy Control](./Classes/Inheritance/code%20snippets/inheritanceInCopyControl.cpp)

## Linked Lists
* [A simple linked list toolkit](Linked%20Lists/code%20snippets/LinkedList.cpp) with functions for displaying, adding and removing items, and finding the length of the list.
* Mostly the same toolkit, however some it uses a Node constructor with default arguments to simplify some of the functions. A few other short cuts are also used. Separate compilation.: [Node.h](Linked%20Lists/code%20snippets/Node.h), [Node.cpp](Linked%20Lists/code%20snippets/Node.cpp) and [testLinkedList.cpp](Linked%20Lists/code%20snippets/testNode.cpp).

## Recursion 
* [Some recursive functions](Recursion/code%20snippets/Recursion.cpp)
* [Binary Search](Recursion/code%20snippets/binserach.cpp)
* [Some linked list toolkit functions using recursion](Recursion/code%20snippets/recursiveLinkedList.cpp)

## STL - Standard Template Library
* [STL examples](STL/code%snippets/STL.cpp)

## Templates
* A template function: [maximum.h](Template/code%20snippets/maximum.h)
* Templated vector class: [Vector.h](Template/code%20snippets/Vector.h) and a test program [testVector.cpp](Template/code%20snippets/testVector.cpp).

## Exceptions and Assertions 
* [Exception examples](Exception/code%20snippets/Exception.cpp)