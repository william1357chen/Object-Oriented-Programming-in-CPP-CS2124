#include <iostream>
#include <string>
using namespace std;
/* 
Demostrating some interesting behaviors of pass-by-const-reference using structs

Note these behaviors also apply to Classes

display() is called a method of Person object
*/

struct Person
{
    void display() const
    { // if not const, displayPerson() function will get an error
        cout << name << endl;
    }
    string name;
};

void displayPerson(const Person &aPerson)
{   // That's because there's a const in this function,
    // The compiler can't tell if aPerson.display() would modify the object or not.
    aPerson.display();
}

int main()
{
    Person john;
    john.name = "John";
    john.display();
    displayPerson(john);
}