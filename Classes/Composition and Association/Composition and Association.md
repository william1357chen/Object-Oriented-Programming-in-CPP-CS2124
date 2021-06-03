# Composition and its Issues
Suppose we have two classes, `Foo` and `Bar` and we would like every `Foo` to have a `Bar`. We can represent that with the following class definitions:
```c++
class Bar {};	// Not interested in what Bar consists of right now.

class Foo {
public:
private:
  Bar myBar;	// Every Foo has a Bar.
  int someOtherData;
};
```
This is referred to as *composition*. It is also called *containment*. What is implied by this arrangement?

* When we create a `Foo`, we automatically create a `Bar` at the same time. When our `Foo` object is destroyed, the `Bar` is destroyed with it.
* What if I want to use a different `Bar` from the one we started with? Sure I might be able to change the values stored inside the `Bar`, but I couldn't put a *different* `Bar` there.
* Every `Foo` has a `Bar`. It can't get rid of it.
* The `Bar` belongs to the `Foo` and can't be shared equally with other `Foos`.
* The `Bar` is stored inside the `Foo`. `Foo` has to be big enough to hold `Bar` and anything else it wants to hold.

So, when might we want a different design?

* What if we don't want every `Foo` to start out with a `Bar`, but instead to get one later.
* Or what if we want to be able to throw away the `Bar` after a while?
* Or replace it with a different one?
* What if I want to share a single `Bar` among several `Foos`?
* What if `Bar` is actually the same class as `Foo`?

Any of these would require that we use a different arrangement. For example, if `Bar` is actually the same class a `Foo`, then we are proposing the following class:

```c++
class Foo {
public:
private:
  Foo myFoo;	// Every Foo has a Foo.
  int someOtherData;
}; 
```

But this says that inside a `Foo` is another `Foo`. Not only that but it has `someOtherData`, which is an `int`. How can I fit a `Foo` inside another `Foo`. Every `Foo` is the same size, but if one was inside another wouldn't the second one have to be bigger than the one that's inside of it??? Definitely a problem.

How could we come up with such a problem? Consider a `Person` class, in which we want to store the possibilty that a `Person` has a spouse (i.e., a husband or a wife). The class might look like:

```c++
class Person {
private:
   string name;
   Person spouse;
};
```

It should be clear that a `Person` can't have space to have another `Person` inside of him/her. Also, most people are not born with a spouse. And sadly, sometimes we may have to allow for losing a spouse or even acquiring another. (We are not trying to handle multiple simultaneous spouses.)

How can we handle these issues in C++? 

## Solution: Association by using Pointers

We can make our **member variable into a pointer**. In the case of the `Person` with a spouse, the class could be written as:

```c++
class Person {
private:
   string name;
   Person* spouse;
};
```

The only difference is that now spouse is a pointer to a `Person`, instead of a `Person`. Since a pointer variable just holds an address, there is not difficulty in storing a pointer to a `Person` inside of a `Person`. 

Now we are **associating** one `Person` with another, and not **containing** one `Person` in another.

How does this approach help us with the other problems mentioned earlier? What value could we store in spouse if a `Person` is not currently married? In other words, what value can we use to say that the variable spouse is not actually pointing to another Person? `nullptr`. The value `nullptr` for a pointer variable always means the variable is not pointi*ng at anything. That makes pointers ideal when you might need a variable that *sometimes* refers to an object and other times doesn't refer to anything at all.

## Conclusion

### *Composition* refers to containing an `object` of one class in an `object` of another class. Composition has several issues. We can solve the issues of composition by not storing the entire `object` of one class in an `object` of another class but rather just use a pointer. This is called *Association*.