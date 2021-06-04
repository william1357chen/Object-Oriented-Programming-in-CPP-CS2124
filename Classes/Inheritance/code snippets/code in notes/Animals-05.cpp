/*
  Call a method from the base class on an instance of the derived
  class.
 */

#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    Animal(const string& name) : name(name) {}
    void eat() { cout << "Animal eating\n"; }
private:
    string name;
};

class Lion : public Animal {
public:
    Lion(const string& name) : Animal(name) {}
    void eat() {
        cout << "Lion!!!!!  ";
        Animal::eat();
    }
private:
};

class Tiger : public Animal {
public:
  Tiger(const string& name) : Animal(name) {}
  void eat() { cout << "Tiger eating\n"; }
private:
};

class Bear : public Animal {
public:
  Bear(const string& name) : Animal(name) {}
private:
};

int main() {
    Tiger tigger("Tigger");
    tigger.eat(); // tigger eating like a proper Tiger.
    tigger.Animal::eat();  // tigger eating like an Animal.
    Lion coward("Cowardly");
    coward.eat();
}