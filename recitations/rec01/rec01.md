# Recitation 01 - C++ Basics
## Topics
* strings, vectors, I/O
## Task
Some recitations, aka *labs*, will follow a "tutorial" style. Others, such as this one, will present you with a program to write. Regardless of the style of the assignment:

* Feel free to ask questions! Check the course notes! Even talk to your classmates! The purpose of the labs is for you to get hands on experience and produce good working code.
* If you are done before the end of the lab, ask a lab instructor to check over your code. It is very possible that even if your code works, the instructor may point out areas where your code could be improved, either to make it more readable, or because your code might have failed for input cases.
* When you are done, either because you have shown it to a lab instructor and had it "checked off" or if you needed to finish it up at home, submit it on NYU Classes.

And now on to the description of today's task.

* We want to read a file, display it to the screen and report how many "words" there are.
* There are several ways to do this. Here's one way:
    * Read the file line-by-line, printing each line to the screen.
    * Read the file again, word-by-word, keeping a count of the words read and displaying the count when you are done.
    
If you have time and know how (we didn't get to cover this in the fall, but again, *if* you know how...), break the problem into functions. What are good ways to do that? What parameters should you pass to the function? More time? Try counting each distinct "word".

* Good programming style:
    * Naming
    * Length of lines
    * Comments are not required for labs except be sure there is a comment at the top of the file identifying the author (you, hopefully), the name of the program file, and a *very* brief description of the program.
        * Note that all of your submissions both labs and homeworks for the semester should have such a comment at the beginning of each code file.
## Submit
* Whether or not you have been "checked off" during the recitation, submit a single source file, `rec01.cpp`, on NYU Classes. If you do not, your grade may be penalized. Do not submit any other files, such as those generated for your development environment (IDE).

## What you need to know
Since you are just starting out with C++ and with this course, I thought it might be handy to have links back to the course lecture notes on the necessary material. It is possible for this recitation that some item(s) may not have been covered in your lecture section. Hopefully, given your prior programming experience, none of these issues will seem complicated, but please feel free, as always, to ask for help from your lab instructors or your fellow students.

* [Defining variables](../../Basic%20C%2B%2B/Basic%20Syntax.md#variables), using [conditions and looping](../../Basic%20C%2B%2B/Basic%20Syntax.md#conditions)
* [How to open a file, check that it opened correctly, read and close it](Basic%20C%2B%2B/File%20IO/File%20IO.md)
    * Note we probably did not cover all the details of how to read files. In particular note that 
        * to read a single "token", use the input operator and read into a string variable
        * to read a line, use the function getline.
        * To read a file token by token or line by line, do either of the above, as part of a while loop, e.g.:
            * `while (ifs >> token) { /* code to do things with the token */ }`
            * `while ( getline(ifs, line) )  { /* code to do things with the line */ }`
    * There's a lot more explanation at the above link.
* [How to use strings](../../Basic%20C%2B%2B/Strings.md)
* Ideally [writing functions](../../Basic%20C%2B%2B/Functions/Functions.md). If you have covered this, then certainly break the problem up into appropriate functions. However, if you haven't gotten to that in lecture, as certainly happens in the fall semester, don't do it.

### Additional resources for assignment
* [Recitation 1 notes on input filesV2.pdf](./Recitation)
* jabberwocky 