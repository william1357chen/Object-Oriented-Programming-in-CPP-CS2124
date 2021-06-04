/*
  NoPolymorphismFromBaseConstructor.cpp
  CS1124
  John Sterling

  Demonstrates that in C++, function calls from a constructor do not
  use polymorphism
 */

#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        foo();
    }
    virtual void foo() const { cout << "Base::foo()\n"; }
};

class Derived : public Base {
public:
    Derived() : n(42) { }
    virtual void foo() const { cout << "Derived::foo() " << n << "\n"; }
private:  
    int n;
};

int main() {
    Derived der;
    der.foo();
}