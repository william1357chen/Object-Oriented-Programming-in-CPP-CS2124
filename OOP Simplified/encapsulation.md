# Encapsulation
## Definition: Encapsulation refers to the **bundling of data with methods** that can operate on that data within a class. Essentially, it is the idea of **hiding data** within a class, preventing anything outside that class from *directly* interacting with it.
___
To interact with the attributes (member variables) of an object, we have to do that through the object's methods. In practice, we usually do this by implementing **getting** and **setting** methods for object attributes. 

## Getter Method - Retrieve information

In the chess example, to determine if I could capture another chess piece, I would need the other chess piece's color. So we define a getter method `getColor()` to retrieve the color of the other piece of chess. This way, we can check the color of any chess piece anything in the program without risking to alter the internal attributes of said pieces. 

## Setter Method - Change information

The setter methods provides the rules of changing attribute information. It will make sure the change to the attributes is within the bounds of what is allowed, so people won't have worry about breaking an object's behavior should could happen if they can alter that information of attributes *directly*.

For instance, in the `move()` method of a knight, we should provide *validation* checks to look for conditions like, a piece of the same color is in that position, or our king piece is *checked* and that move doesn't save us out of *check*, etc.

## Read Only Attributes

Some attributes should not be change by other parts of the program, so we want to keep it **read only** from the outside. To do this, we will define a **getter** method and not a **setter** method so that the variable could only be *referenced*, but not *changed*.

## How to achieve encapsulation
Always use `private` access modifiers for attributes. 

## Conclusion
It's generally best not to allow the external program to *directly* edit an object's attributes. This is very important whne working on large and complex programs, since we want an `object` to work well without requiring them to rely on other parts of the program to not have errors. **Information hiding** helps you keep control of your program. 