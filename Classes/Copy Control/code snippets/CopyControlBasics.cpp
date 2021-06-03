
/*
Important Note:
Shallow copy works only for primitive
non primitive uses delegation to their own associated copy constructor


Copy Control: The Big 3
    1. Destructor
    2. Copy Constructor
    3. Assignment Operator

Why do we need a Destructor?
If an instance is responsible for resource in the heap and is about to cease to exist which leads to memory leak

Why do we need Copy Constructor?
When a shallow copy of an instance is going to go through the desructor and pointer is lost
deep copy -> own copy constructor

Why do we need Assignment Operator
When we want to reassign an existing object will another object of the same type. We have to do the copy, and free up the object unused.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


class Thing{
    friend ostream& operator << (ostream& os, const Thing& rhs);
public:
    Thing(int x) {p = new int(x);}

    Thing(Thing& thing){p = new int(*thing.p);} // called whenever initilizing the same instance as a copy of something
    
    Thing operator = (const Thing& rhs){ // x = (y = z), y = z should return a Thing object
        // What if x = x? That's gonna crash
        if(rhs.p != p){ // if we are not doing self assignment
            // 1. freeup self's resource
            delete p; // calling destructor is not smart
            // 2. allocate new resource (u dont want to point to the same thing as rhs
            // 3. copy the resources from the rhs
            p = new int(*rhs.p); // deep copy
        }
        
        return *this; // 4. return self. if x = (y = z), y is self so return y.
    }
    
    void setValue(int val){*p = val;}
    int getValue() const {return *p;}

    void cleanUp(){
        delete p; // p will be pointed to a invalid address. It releases the memory, but it does not modify the value of p.
        p = nullptr;
        // If u do p = nullptr and then delete p later, nothing happens.
        // The source code for delete says if p = nullptr, return;
    }

    ~Thing(){ // This is a destructor. 
        // Whenever, an object is out of scope and when we delete an object, destructor is called
        // So we dont need cleanup()
        delete p;
        p = nullptr;
    }
private:
    int* p;
};
/*
Parameter "something" is pass-by-value but without Copy Constructor, the default copy constructor made by C++ itself
does a shallow copy. something did not create its own p, its p is connected to the p of aThing, 
and the destructor will be called to something which will delete the shared p.
*/
void doNothing(Thing something){} 

void simpleFunc(){
    // Demonstrating Purpose of Copy Constructor
    Thing aThing(17); // creates a pointer on the heap
    cout << aThing << endl;
    // delete aThing.p;

    // aThing.cleanUp(); 
    // however, we want cleanup() to run in every situation that heap gets memory
    doNothing(aThing);// here aThing's destructor is called but p is already deleted
    // WE NEED A DEEP COPY, a copy constructor
    
    Thing anotherThing(aThing); // the copy constructor is called
    Thing anotherThing2 = aThing; // same thing different syntax
    // return creates a copy

    // Demonstrating Purpose of Assignment Operators
    Thing somethingElse(28);
    aThing = somethingElse; // reassigning
    // if we don't have copy control, now aThing.p -> 28 and its original 17 is memory leaked, so we need assignment operator
    // operator = (aThing, somethingElse); doesn't work since operator=() is a method
    aThing.operator = (somethingElse);

}

ostream& operator << (ostream& os, const Thing& rhs){
    os << *rhs.p;
    return os;
}

int main() {
    simpleFunc();
}

