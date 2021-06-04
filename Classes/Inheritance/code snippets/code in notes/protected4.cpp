/*
  protected4.cpp
  CS1124
  John Sterling

  Demonstrates that within a derived class we can access a protected
  member on an instance of our own class, but not on an instance of a
  different derived class.
 */

#include <iostream>
using namespace std;

class Base {
protected:
    int getValue() const { return value; }
private:
    int value;
};

class Derived : public Base {
public:
    void display() { cout << "Value: " << getValue() << endl; }
};

class DerivedTwo : public Base {
public:
    void display() { cout << "Value: " << getValue() << endl; }

    // fails to compile
    int getDerivedValue(const Derived& der) { return der.getValue(); }

    // compiles fine.
    int getDerivedTwoValue(const DerivedTwo& der2) { return der2.getValue(); }
};

int main() {
    Derived der;
    DerivedTwo derTwo, derTwoB;
    cout << derTwo.getDerivedValue(der) << endl;
    cout << derTwo.getDerivedTwoValue(derTwoB) << endl;
}