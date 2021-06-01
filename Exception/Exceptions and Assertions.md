# Exceptions
The problem
What should a function do if something goes wrong? Wrong? What could go wrong? Well, the function might be passed an argument that it was not expecting. Suppose you had a function to modify the volume on some sound device. If the volume is given in decibels, then a value of 200, for example, would be enough to cause a good deal of pain if a human were anywhere nearby. What should the function do in such a circumstance? What are some possible options?

Proceed with the bad value
Print an error message and
ask for another value
or exit
adjust the value to be within range
let the caller know
by returning an error value
Let's assume that the first option (going ahead with the bad value) would be a very very bad idea. What about printing an error message and either asking the user for another value or just exiting. Well, it depends on what we are doing. Exiting might be very bad if this is a program that is controlling an automated automobile or perhaps a nuclear powerplant. On the other hand, there are lots of programs that run on computers without a "user" or a device to print a message to. And while in some cases we could remap the value to one that is acceptable, we cannot always do so. In fact that sort of "failing silently" can be a very bad practice in general.

What if the simple truth is that it is not possible for our function to handle this situation. What option is left? Let the caller know! The classic approach to doing this is to provide a return value that indicates that an error occurred. There are two problems here. In some cases, all possible return values are already valid and none are available to indicate that something is wrong. Yes, we can work around that, perhaps using a reference paramter for this purpose, but we are still relying on the function that called us to check our return value. What if the programmer who wrote the function who is calling you, doesn't check? Maybe he was lazy? (Programmers are never that lazy! Right?)

Humor aside, sometimes a function encounters an "exceptional" circumstance and needs to report it to some function up the calling chain, even if the immediate calling function ignores the problem.

Exception Handling
Most modern languages provide a way for our function to report the error in a whaymechanism, know as exceptions, that allows any of the functions all up the call stack to have the option to address the problem. Note that if none of the callers does, then the program crashes!

The terminology we use is that our poor function will throw an exception. A function up the call stack might try our code and then if an exception was thrown, catch the exception.

Note that this terminology is used by a number of languages besides C++, e.g. Java and C#, but certainly not all. Some languages, e.g. Python, instead of throwing the exception, "raise" it. The basic concepts are similar across languages, but some details will of course vary.

Here's a possible "real" world example:

int main() {
    try {
        vector v;
        //
        // Followed by lots of code that fills and modifes the vector
        //

        v.clear();  Now the vector is empty again
        // cout << v[0] << endl; // Undefined behavior
        cout << v.at(0) << endl; // Throws an out_of_range exception
    }
    catch (out_of_range e) {
        cout << "Caught an out_of_range exception\n";
    }
    // if we properly handle the exception, we will continue here
    cout << "Done\n";  
}
There can actually be multiple catch "clauses", each for handling a different possible exception that might have been thrown. Their order matters! Think the catch clauses as acting in the same way as a series of if/else if blocks. Your compiler will hopefully be nice and generate a warning if you put them in the wrong order.

"Catch-all": sometimes we don't know every kind of exception that might be thrown. In order to allow us to be able to catch whatever is thrown, C++ provides a special catch clause:

catch(...) { /* whatever you want to do */ }
Note that we don't know what type of exception was thrown, so there's not terribly much we can do, but we may still be able to shut the application down in a controlled way, instead of just crashing.

What can be thrown?
C++ is extremely flexible as to what can be thrown. You can throw an number, e.g. 17 or 3.15159, or a string, or anything.

More commonly, you will throw an instance of a class, either one that was previously defined or one of your own.

The classes that are provided all inherit from a base class exception, which is defined in a header file of the same name. Examples of derived classes include the out_of_bounds class that we saw previously along with range_error, invalid_argument, bad_cast, bad_alloc and others.

If you like, you can define your own class to use for an exception, in which case it will be up to you whether or not to have it inherit from exception.

Comparison to Python
try is the same
C++ throw is Python raise
C++ catch is Python except
C++ catch(...) is Python except:
C++ does not have "finally"