# Recitation 2 - Structs, Vectors and Functions
## Topics
* Structs, Vectors and Functions
## Task
We have been given a file of chemical formulae, specifically hydrocarbons. Hydrocarbons consist of only hydrogen and carbon atoms.

Each line of the file contains the name of the chemical followed by its molecular formula which will be in the form:
C#H#

where the two #'s represent the number of carbon (C) and hydrogen (H) atoms, respectively..
(No name in the file contains blanks.)

Because hyrdocarbons with the same molecular formula can appear in many structural forms and each of the forms has a different name, the same molecular formula might appear more than once in the file, each time with different a name. (e.g.: Butane and 2-methylpropane both have the molecular formula C4H10.)

Our goal is to maintain one entry for each unique molecular formula along with all the names for that formula. After they have all been read in, we will sort the vector by carbon and hydrogen, and finally display all the entries in the sorted vector.

Each molecular formula will be kept in a struct with three fields:

* the name(s) for formula. Note that is a collection of names
* the number of carbon atoms
* the number of hydrogen atoms

We will be storing all these structs in a vector.

**An example**

Suppose this is the file:
```
n-Butane C4H10
Propyne C3H3
1,3-Butadiyne C4H2
Hexane C6H14
Butane C4H10
iso-Butane C4H10
Pentane C5H12
```
Your program should store these five entries and then display:
```
C3H3 Propyne
C4H2 1,3-Butadiyne
C4H10 n-Butane Butane iso-Butane
C5H12 Pentane
C6H14 Hexane
```

The collection has been sorted by number of carbons and then the number of hydrogens. I assume you know from data structures how to write some simple sort algorithm, e.g. bubble sort, selection sort or insertion sort. (Yes, in general these run in quadratic time, but we don't want you spending a lot of time implementing a more effecient sort.) Write a function that will be passed your collection and modify it so that it is sorted.

## Discussion
As you have all studied data structures by now, you might have some good ideas of other ways to design a solution to this program. A map, for example, would save having to search the vector to see if an entry for the formula already exists. And if the map was a sorted map, perhaps implemented with a self-balancing binary tree, the issue of displaying the elements in some sorted order could have been simpler and more efficient.

Why aren't we doing this? Simply because we are avoiding throwing more of C++'s syntax and libraries at you. Our goal now is to be sure that you become adept at the basics of the language. We will introduce later things like the STL (Standard Template Library) map class, which serves the same purpose ast Python's dictionary, along with the representation of iterators.

So while the design for this lab may seem a bit "clumsy", please understand that it is an exercise in the language features we have covered so far.

## Notes
As always, write good clean code. What does that mean?

* Good use of functions to make code more readable.
* Good naming of everything.
* No long lines. What's long? Anything over 80 characters.

And now that you know about function prototypes (if not covered in your lecture section look it up in the notes or ask in lab), there should first be one for each of your functions other than main, then the definition of main, and then the definitions of those functions.

In the interests of encouraging good design (and saving you from having to rewrite your program if we find it poorly written) let me outline what main will do:

* Define variables for the stream and vector. No, don't open the stream here.
* Call a function to open the stream. It will ask the user for a filename. If the filename fails, repeatedly ask for a new one until you succeed. If opening the stream object fails, you will need to call the clear() method on the stream before attempting to open it again. By the time this function is done, the stream should be open. It does not need to return anything.
* Call a function to fill the vector from the stream. Pass in the vector and the stream. Do not return anything.
* Call a function to sort the vector, in place.
* Call a function to display the vector.

In addition to the functions directly called by main, it a couple of other functions would make the overall code easier to read

* A function to insert the information for a name, carbon count and hydrogen count into the vector.
* A function to find the location of a formula object that matches the number of hydrogene and carbons for a new entry. It will have to return a suitable value if there is no such formala entry in the vector yet. This function would obviously be called by the one in the previous bullet.
We want to track all of the names of the formulae. It would not be very useful if we were to build up a long string of all the names. Instead what makes sense? We want a *collection* of the all of the names for each formula, not a single string.

# Submit
* Reminder, as always for lab, whether or not you have been "checked off" during the recitation, submit your code to NYU Classes.
* For this lab, your submission will be a single source file, `rec02.cpp`, on NYU Classes. If you do not, your grade may be penalized.
* Do not submit any other files, such as those generated for your development environment (IDE).