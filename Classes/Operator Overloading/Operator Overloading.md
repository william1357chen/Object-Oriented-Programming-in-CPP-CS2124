# Overloading Operators
* What does it mean?
* What you can and can't do
* Operator expressions and function calls
* Types of operators
* Implementing operators in terms of other operators
* Member or non-member?
* Friends?
* Conversion operators

Overloading operators is a cool thing that most programming languages can't do. C++ can. And not only is it cool, but it can make your programs much easier to read. Of course, first you have to learn how. Well, first you have to learn what it means.

## What does "Overloading Operators" mean?
What's `1 + 1`? Wouldn't it be cool to make it be something other than `2`? (That was the answer that you got, right?)

Well, we actually can't do that. 1 + 1 will continue to be 2.

But, you can do things like:
```c++
cout << x;
```
even if x is an elephant or other type that you have created. You just have to write the code for C++ to call in order to make that work.

What are the most common operators that you are likely to want to overload? Probably the output operator (some people like to call that one the "insertion operator" because it "inserts" information into a stream). Also the equality and inequality operators, `==` and `!=`. And there are a number of times when it is handy to be able to say what "order" you would want to put your elephants in, so you might want to implement the less-than operator, `<`.

And there are lots of other operators that we can overload.

## What can't you do?
We said you can't change the meaning of `1 + 1`. Why not, if we're allowed to change the meaning of the operator `+`? Well, there are a few rules, provisios, quid pro quos (see the movie Alladin if you don't get the reference).

* **Built-in types**: You cannot change the meaning of an operator when it is used with built-in types. So the meaning of adding two numbers can't be changed. However, we could decide how to add a number and an elephant. So long as one of the objects is an instance of a defined type (i.e., it's not an int or a char or...), then you can overload the operator.

* **Precedence**: What's the value of `2 + 3 * 4`? Why isn't it `20`? Because the operator `*` has a higher precedence than `+`. And it always will. You can't change the relative precedence of the operators.

* **Associativity**: `2 + 3 + 4` is evaluated as `(2 + 3) + 4`. Not that it matters much. It does make a difference that `2 - 3 - 4` is evaluated as `(2 - 3) - 4` and not `2 - (3 - 4)`. That's the order in which the operators `+` and `-` are evaluated, left-to-right. This is called associativity. How about `x = y = z`? That turns out to be `x = (y = z)`, right-to-left. Most operators are applied left-to-right. But whatever it is, this in something that you cannot change.

* **Nothing new**: What does `x ** y` mean? In the language Fortran, it meant exponentiation. But in C++ it doesn't mean anything. And you can't make it mean something for your class if it doesn't already mean something for a built-in type. You can overload the operators that already exist, at least most of them, but you can't create new ones.

* **Arity**: You know what `4 / 2` means, but have you every seen just `/ 2`? No? That's because the operator `/` has to have two things to work with. It's a "**binary operator**". Some operators are only used with one thing. They are called "**unary operators**". An example is the operator `++`. Some operators can be unary or binary, such as `+`. There is even one **ternary** operator, `?:`.

* **Short circuiting and order of evaluation**: For most operators, we can't guarantee in what order the operands will be evaluated. For example: `if (foo() == bar()) {}`, might call the function `foo` first and then `bar` or it might call `bar` first and then `foo`. The operators `&&` and `||`, however, provide a guarantee that the lefthand side will be evaluated first. For `&&` if the result of evaluating the lefthand side is false then the righthand side will not be evaluated at all!
    * What would happen if we overload `&&`? This special behavior, called short circuiting, would be lost when using your version of the function. For this reason, it is generally recommended that you do not overload the `&&` and `||` operators.

## What can we do?
But that's enough of what we can't do. Let's see what we can!

In general we can use any operator that already exists. We *could* implement `x == y` and have it result in "adding" them together producing a new one. (No, I haven't bothered to say what x and y are.) Isn't this great? No, not really. People expect `x == y` to return `true` or `false`, depending on whether x and y are "equal". It's up to us to decide what it means to be equal.

Why should you do what people expect? You don't have to! You can write code that makes absolutely no sense to anyone but yourself (if it even makes sense to you). You can have `==` return things other than `true` and `false`. But most of us write code to be understood by others, not just by the computer. This suggests making the behavior match up reasonably well with normal expectations. I certainly would not expect, for example, for the expression `x + y` to change the value in either x or y. (I tend to see a lot of code in homework and exam exercises that violates these expectations.)

## Operator Expressions as Function Calls
Before we can start writing code, we need to understand how the code will get used. Let's assume we have a couple of elephants:

```c++
Elephant x, y;
```

and we want to add them together:
```c++
x + y
```
How does that work? C++ sees the expression `x + y` and tries to find a function that will do the addition. Said another way, C++ tries to *convert* the expression `x + y` into a function call. In general, the function can be either a non-member function or a member function.

As a *non-member* function, x + y will be converted to:
```c++
operator+(x, y)
```
As a member function, x + y will be converted to:
```c++
x.operator+(y)
```

### The Function Name for an Overloaded Operator
Notice that either way, member or non-member, the function that is being used is named `operator+`. Our functions will always be named "operator" and then the one or two characters for the operator.

*The key point is that C++ tries to convert operator expressions to function calls. If we implement the appropriate function then we can add or compare or print out... whatever we like.*

## Types of Operators
There are various sorts of operators. *Input*, *output*, *comparison*, *arithmetic*, and *assignment* operators, just to mention the more obvious. You should remember that there is also the *dereferencing* operator and the *address-of* operator. Furthermore, `new` and `delete` are also operators. We will consider here issues that apply to these different categories.    

Here are the list of operators we will discuss:
* Output Operator
* Comparison Operator
* Arithmetic Operators
* Pre and post Increment and Decrement Operators
* Assignment Operators
* Conditional Operator
* Indexing Operator
* Conversion Operators

## Output Operator
This is one of the more complicated operators to overload, but but quite possibly the most common. If you prefer to implement a simpler one first, take a look at the comparison operators.

If we have dumbo, the elephant, we might want to print it out with:
```c++
cout << dumbo
```
We discussed before that an expression using an operator might be converted into 
either of two function calls. for the output operator, they would be:

```c++
operator<<(cout, dumbo)
```

and

```c++
cout.operator<<(dumbo)
```

Which one would we choose here? Consider the option of using a member function. There we would be invoking the member function `operator<<` on the target object `cout`, passing `dumbo` as the only argument. If `operator<<` is invoked as a member function of the `cout` object, then it has to be implemented in the cout's class, ostream. Where is that file? Do we even have permission to access/modify it? On some computer systems we would not have that permission. Even if we do have permission and no where to look, it's a file with lots of complicated code that almost every program depends on. Do you want to take the chance of making a mistake and corrupting this key file?? The correct choice is:
```c++
operator<<(cout, dumbo) // Yes.
```
Ok, so the normal implementation of the output operator is as a non-member. What should the prototype be?

* Function Name: operator<<. The function's name is formed by the word: `operator` together with `<<`
* Parameters: There are two arguments, so this function must have two parameters.
    * The first parameter is the stream. We know from past experience that streams are *always* passed by reference, so the first parameter type must be `ostream&`. It is not a const parameter, because the stream will be modified when we write to it. (Streams are also modified when we read from them.)
    * The second is the thing we are trying to display. Since it won't change by being displayed it will be a const reference parameter: `const Elephant&`
* Return Type: We wish to be able to write expressions like:
    ```c++
    cout << dumbo << endl;
    ```

    in which the output operator is "chained". This is the same as:
    ```C++
    (cout << dumbo) << endl;
    ```

    The expression must have the value of the output stream (`cout`, in this example) for this chaining to work. However, as noted before streams do not get "copied". To prevent a copy, and pass back the exact stream that was passed in, we must return the stream by reference: `ostream&`

The resulting protoype is:
```c++
ostream& operator<<(ostream&, const Elephant&);
```
Now we can decide how to implement it. Remember that it must return the stream that was passe in. Also remember that it is *not* a member function of Elephant. Other than that, we are free to print out whatever we think is appropriate for an elephant. We could just print the elephant's name, or the name and weight or... Here we give an example:
```c++
// Pass the stream in and return the stream by reference
ostream& operator<< (ostream& os, const Elephant& e) {
    // We needed to use an accessor since this function does not
    // have permission to access the private members of the elephant.
    os << e.getName();
    return os; // Remember to return the stream.
} 
```

## Comparison Operators
Comparison operators include:
```c++
== != < > <= >=
```
They normally return true or false, depending on the result of the test that their name suggests. We'll show the equality operator. The others are similar. 

Assume two elephants are "equal" if they have the same name *and* they have the same weight:
```c++
bool operator== (const Elephant& lhs, const Elephant& rhs) {
    return lhs.getName() == rhs.getName() && lhs.getWeight() == rhs.getWeight();
} 
```

## Arithmetic Operators
Arithmetic operators include:
```
+ - * / %
```
The operators `+` and `-` can be binary or unary. `/` and `%` can only be binary.

What about `*`? As an arithmetic operator, it is only binary. But as the dereferencing operator it is unary. We will not overload the dereferencing operator, but there are times when it is useful to do so.

## Pre and post Increment and Decrement Operators
The operators `++` and `--` are also arithmetic operators, but they are different enough in what they do and how we implement them, that I am giving them their own section.

Each of these two operators exist as pre- and post- versions. Suppose we start with:
```c++
int x = 0;
```
What is the difference between the following two expressions?

```c++
++x;
x++;
```

They both have the "side effect" of adding one to `x`. But they have different *values*. The value of `++x` is the value of `x` *after* we increment it. The value of `x++` is the value of `x` *before* we increment it. (We will shortly be a little more precise about what we mean by "the value of x".)

### Pre-increment as a member
The pre-increment operator increments and then returns the modified value. It is expected that the returned value is the *same* object as the one that got incremeneted, not just a copy. Whenever we need to return the *same* object, not a copy, then we need to return by reference. We'll assume that incrementing our elephant means adding one to his weight. Should the increment operator return the number that was modified, his weight? No. It is expected that if it is an Elephant that we were incrementing, then that is what we should return.
```c++
Elephant& Elephant::operator++() {
   ++weight;
   return *this;
}
```
This little function shown above has several points worth noting.

* Return type. As noted above, we should return the original Elephant, the one that's being incremented. This require returning it by reference.
* Function name. We chose to implement this as a member function. That is an arbitrary choice. (We will do the pre-decrement as a non-member for comparison.) But it does result in the function needing the class name as a modifier, if we are writing the implementation outside the class definition.
* Arguments. This is a unary operator. As a member function it does not have any argument.
* Body
    * We can directly modify the elephant's member variable weight since this is a member function.
    * The thing we need to return is ourselves. Who are we? The object pointed to by `this`.

### Pre-decrement as Non-member
[see sample code for examples]

### Post-increment as member
[see sample code for examples]

### Post-decrement as non-member
[see sample code for examples]

## Assignment Operators
The assignment operator, `=`, is very special. We will spend a good deal of time overloading it later on. Key points to remember about the implementation are:

* It must be implemented as a member
* It should be able to be chained so it should return the left-hand object. By reference.
* Check for a self-assignment. "`x = x;`" may look silly, but it can cause complications for the assignment statement which will need special code to handle..

There are other operators, sometimes called the Combination Operators, that behave similarly:
```
+= -= *= /= %=
```
They do not have all the same requirements, but it is *recommended* that be implemented similarly. In particular, they are usually implemented as member functions. Also, they return the left-hand-side of the expression by reference. Note that they directly modify the value in the left-hand-side.

## Conditional Operator
The `?:` operator is the only ternary operator in the C++ language. It was decided that it wasn't worth the effort for compiler writers to be bothered with effort of allowing people to overload this one and only ternary operator. So you can't. Simple.

## Indexing Operator
Also known as the "square bracket operator". This is very useful when implementing such things as the vector class, where we want to an object that can behave similarly to an array. We will explore this more when we write our own vector class, when we explore the "Big 3" (Copy Control). Note it must also be implemented as a member.

## Implementing Operators in terms of Other Operators
If we have implemented the equality test for Elephants, we could easily write the inequality operator:
```c++
bool operator!=(const Elephant& lhs, const Elephant& rhs) { 
    return !(lhs == rhs);
}
```
In fact all the comparison operators can be implemented based on just the `==` and the `<` operators.

A number of operators can be easily implemented if certain other operators were implemented beforehand. If we already have the `+=` operator, then the `+` operator can be trivially implemented as a non-member function. This is the usual pattern to how the binary arithmetic operators are implemented.
```c++
Elephant operator+ (const Elephant& lhs, const Elephant& rhs) {
   Elephant temp = lhs;
   return temp += rhs; 
}
```
## Member or Non-member?
How to decide whether to implement an operator as a member or a non-member function? The first question is, do we have a choice? The assignment and square bracket operators are *required* by C++ to be member functions. These are the only operators that C++ has rules forcing us to use member vs. non-member functions.

* The input and output operators would be extremely difficult to implement as member functions because they would have to be members of the istream and ostream classes. We don't have easy access to the files. Furthermore those classes are *very* complicated and we would definitely not want to modify them (even if we had permission). We certainly wouldn't want other people modifying these important classes!
* The "combination operators" are commonly implemented as members.
* Other binary operators are usually implemented as non-members.
* Unary operators are most often implemented as member functions.

## Friend?
If you are implementing a function as a non-member, you might like to make your operator a friend of the class. This reduces the need to use accessors and mutators, often making the code easier to read. On the other hand, every function that accesses (or mutates) member variables directly may have to be modified if the representation of the data changes. A function that is a non-member and not a friend will not need to be modified.

* The input and output operators are often written as friends.
* The binary arithmetic operators (`+ - * / %`) don't need to be friends as they are normally implemented using the corresponding compound operator (`+= -= *= /= %=`).
* Two relational operators, typcially < and ==, would likely be implemented as friends, while the remaining four operators (!=, <=, > and >=) are easily implemented using the first two, so there is no reason to make them friends.

## Conversion Operators
We now have almost enough technology to understand the magic of how
```c++
if (!ifs) {}
```
works.

So, what's the trick? You might think, "Oh, they just overload the `!` operator." That would be reasonable, but it's actually a little different. Why not just do that? Well, there's another "conversion" having to do with streams that also needs to be dealt with:
```c++
// Loop through a file of ints
int x;
while (ifs >> x) {}
```
What is the *type* of the expression `ifs >> x`? If you look back at how we overloaded the output operator, you'll see that the return type was `ostream&` and that the value was simply the output file stream. It's the same thing for the input operator. The return value is the stream you are reading from.

So if value of the expression `ifs >> x` is actually just the stream `ifs`, then how does that stream object get "*converted*" into a `bool`?

C++ lets you write special operators that *convert* into other types. They look kind of wierd. The prototype for the operator that converts from an *ifstream* to a *bool* is:
```c++
operator bool() const;
```
First of all when I say convert, I don't mean that anything happened to the original stream in the process. The operator is just *returning* a bool, depending on whether the stream is still ok to read from. The stream itself has not *become* a bool.

The name is "operator bool". There is no return type specified. If we did have to write one down it would just be bool, of course, and that would be nothing but an annoyance to have to type in. (Just one more typo to have to fix.) And of course this operator is const since generating a true / false from a stream should not change the stream object.
