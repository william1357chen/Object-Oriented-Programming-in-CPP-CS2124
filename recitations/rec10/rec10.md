# Recitation - More Inheritance
## Focus
* Inheritance
* Polymorphism
## Details
See attached. Note that there are two parts. In the first part you will develop a class hierarchy for musical instruments, together with a Musical Instrument Lending Library that stores them, lends them and tests them out. You are provided with a musician

In the second, you develop an Orchestra class and extend your instrument classes with new method(s).

The purpose of this exercise is to practice you skills at implementing and using inheritance. And part of that is the design of your hierarchies.

What methods should be abstract? Is there any "common" behavior that can be captured in a base class, and then extended in a derived class. An example might be the "make a sound" behavior. All instruments have to do that, but how they do it varies by type. Note that all instruments start off the same way when they make a sound. There's some "common code" you could call from the methods actually make the sound. Where should that common code go?

### Additional resources for assignment
* [rec10 19S.zip](./rec10%2019S.zip)