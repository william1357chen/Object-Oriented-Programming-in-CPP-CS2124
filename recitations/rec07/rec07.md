# Recitation 7: Separate Compilation
## Topics
* Separate Compilation
* Namespaces
## Overview
* This can be a big project, but we will break it into pieces, of hopefully easy steps. We will also identify / distinguish between activities that are required, and others you are to do but only if there is time during the lab.
* The overall goal is to implement a transaction processing program for a Registrar, making use of separate compilation and namespaces.
* But first we want to get something working in a single file, no separate compilation and no namespaces. Here we are not reading a file, instead just using local calls to the Registrar's methods to add students and courses, etc. We are not even implementing all of the possible functionality. For example, we will leave out dropping courses, students changing names, etc.
* Of course you want to test at every possible point! "Test early and often" is a common motto among successful developers.
* Only after all that works in a single file, then split it into multiple files, i.e. for each class a header and an implementation file, along with a cpp file for the "testing" code.
    * Don't modify your original working code, the solution that is in a single file!
    * When adding separate compilation, sometimes code that worked fine before now breaks. Good to have the working code to go back and look at.
* Next place the classes into the namespace BrooklynPoly.
* Only when all that is done, and only if there is time during lab, add the ability to process a file of commands for the registrar
* And finally for those who are truely lightning fast, implement the functions marked as optional.
## Some Details
We have provided some starter code that is attached. It will save you a few minutes initially setting up the three classes and test code. No, it does even begin to address the issues of cyclic association.

We are assuming that *names are unique* (if they weren't we would have to turn everyone into a number). Remember, just because we occasionaly make such assumptions, you should never assume names are unique unless your spec says so. I have notiece that there is more than one person with the name "John" in the real world.

Also, we are assuming that, miraculously, students' names are all single tokens (if they weren't, things would just be more annoying).

Where do you think the Course and Student objects should live? Suppose you just kept a vector of them, why might that prove to be a disaster? You are going to have pointers from a Course to the Students. If the Students are in a vector, i.e. a `vector<Student>`, what might happen to their addresses with you `push_back` another Student? If the vector was full, then the underlying array would get reallocated and all the pointers to them would become invalid.

Note that we are not asking you for copy control, despite the fact that the Registrar really owns all those objects on the heap.

Probably writing the code that looks for the course or student by name would make a useful method.

**This is the end of the required portion of the assignment.**

## Second Part
Only after you have made sure that all of the Registrar's required functions work, then *if you have time in lab*, you can write a program to read and process a transaction file.

## The file of transactions
Your program will read a file that contains "transactions". Each line will tell the Registrar to do something. A file might look like:
```
 PrintReport
AddCourse CS101.001
PrintReport
AddStudent FritzTheCat
PrintReport
AddCourse CS102.001
PrintReport
EnrollStudentInCourse FritzTheCat CS102.001
PrintReport
EnrollStudentInCourse Bullwinkle CS101.001
PrintReport
CancelCourse CS102.001
[OPTIONAL - Would read line-by-line and then use stringstreams] EnrollStudentInCourse FritzTheCat
[OPTIONAL - do later if time] ChangeStudentName FritzTheCat MightyMouse
[OPTIONAL - do later if time] PrintReport
[OPTIONAL - do later if time] DropStudentFromCourse MightyMouse CS101.001
[OPTIONAL - do later if time] PrintReport
[OPTIONAL - do later if time] RemoveStudent FritzTheCat
[OPTIONAL - do later if time] PrintReport
PrintReport
Purge 
```
Each transaction occurs on a separate line, ending with a newline character.

Some transactions have "parameters" like MighyMouse (a student's name) and CS101.001 (a course) in the "transaction":

DropStudentFromCourse MightyMouse CS101.001
___

The above file contents show all the possible transactions/commands that the file might contain.

It matches the same testing that was done in the tester code above - it's better to have a transaction file than having to constantly rewrite your tester program, eh?

Code for this part of the problem will read a line from the transaction file and call the appropriate methods in the appropriate objects to get this transaction done.

Note that it would be pretty useless to attempt this part until all the required functions are working!

## Error Checking in the Transaction File
Transactions may have errors. For example, a transaction may attempt to enroll a student in a course, who is not in the school.

In the file above, the line:
```
 EnrollStudentInCourse Bullwinkle CS101.001 
```
should result in an error.

Other errors in a command, such as the line below (which appeared in the file above) which fails to mention what course the student is enrolling would also produce an error:
```
 EnrollStudentInCourse FritzTheCat 
```
The program should print an appropriate error message and then continue, processing the next line.

## Third Part
If you have even more time (ok, not too likely), write the code for the [if time] items.

### Additional resources for assignment
* [output-for-required](./output-for-required.txt)
* [rec07.cpp](./rec07.cpp)