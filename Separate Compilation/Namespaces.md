# Namespaces
What is the point of a namespace? Why do we even have the namespace `std`? In all or our programs, having that namespace has just meant that we had to add the familiar additional line: `using namespace std`;.

The reason is so that programmers don't have to "worry" about what names other programmers have chosen to use. For example, when the developers who designed and implemented the `string class` needed a name for that class, it would be most annoying if they had to fret over whether anyone else might have wanted to use that same name, i.e. string.

If two programmers, Fred and Mary, chose the name Foo, for example, what would a third programmer, George, do if he needed to use both classes in his program? So long as Fred and Mary put their classes in different namespaces (maybe using their own names thereby providing themselves with a touch of imortality), George can just use the qualified names `Fred::Foo` and `Mary::Foo`.

How can we create a namespace and put our classes and other symbols inside it? Let's start with the `Thing` class that we developed earlier for separate compilation. How do we put it in a namespace, uncreatively, named CS2124?

It is actually quite simple. In **both** the header and implementation files, we wrap all of the definitions, both classes and functions in a block:
```c++
namespace CS2124 {
    // All of the class and function definitions
}
```
Start with the header file. Previously it looked like:
```c++
// Thing.h
#include <iostream>

class Thing {
    friend std::ostream& operator<<(std::ostream& os, const Thing& theThing);
public:
    Thing(int val);
    void setVal(int val);
    int getVal() const;
private:
    int val;
};
```

Now we will will wrap it in the namespace definition. After adding the namespace, the file will look like:
```c++
// Thing.h
#include <iostream>

// Change
namespace CS2124 {

    class Thing {
        friend std::ostream& operator<<(std::ostream& os, const Thing& theThing);
    public:
        Thing(int val);
        void setVal(int val);
        int getVal() const;
    private:
        int val;
    };

}
```
Now we do the *same thing* with the implementation file:
```c++
// Thing.cpp
#include "Thing.h"
#include <iostream>

// Change
namespace CS2124 {

    std::ostream& operator<<(std::ostream& os, const Thing& theThing) {
        os << "Thing: val = " << theThing.val;
        return os;
    }

    void Thing::setVal(int val) { this->val = val; }

    int Thing::getVal() const { return val; }

    Thing::Thing(int val) : val(val) {}

}
```
What's left? Well if we try to build the program testThing.cpp, complete with the test code, we will have compilation errors. Why? Below is the unmodified test code:

```c++
// testThing.cpp
#include <iostream>
#include "Thing.h"
using namespace std;

// We have a small problem, again.
int main() {
    Thing thingOne(17);
    cout << thingOne << endl;
    thingOne.setVal(42);
    cout << thingOne << endl;
    cout << "thingOne's val: " << thingOne.getVal() << endl;
}
```
What's the problem? testThing.cpp does not know anything about the Thing class. The result is that when we attempt to define thingOne, we will get a compilation error, as well as when we try to print it, or call its methods.

Solution? Either *qualify* whereever the symbols are used, or add a statement `using namespace CS2124;`. We can have as many using statements as we like. Of course if the different namespaces have any symbols in common, then the program should have to qualify those symbols.

Here is an example of the test program where we qualify Thing with `CS2124::`:
```c++
// testThing.cpp
#include <iostream>
#include "Thing.h"
using namespace std;

int main() {
    // Change
    CS2124::Thing thingOne(17);
    cout << thingOne << endl;
    thingOne.setVal(42);
    cout << thingOne << endl;
    cout << "thingOne's val: " << thingOne.getVal() << endl;
}
```

And below is an example using `using namespace`:
```c++
// testThing.cpp
#include <iostream>
#include "Thing.h"
using namespace std;
// Change
using namespace CS2124;

int main() {
    Thing thingOne(17);
    cout << thingOne << endl;
    thingOne.setVal(42);
    cout << thingOne << endl;
    cout << "thingOne's val: " << thingOne.getVal() << endl;
}
```
