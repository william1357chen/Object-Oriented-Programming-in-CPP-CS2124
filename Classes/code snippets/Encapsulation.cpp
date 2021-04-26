//Object Oriented Programming
//Classes
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 Struct are usually identified as only data without behavior
 Only big difference between Classes and Structs is that methods are all public in struct
*/


class Person {
public:
    Person(const string& theName, const int& theAge) // contructor with arguments, can't just initilize empty Person object
    : name(theName), age(theAge) // initilization list (initilize non-primitive fields) . More effcient
    {
        //name = theName; this is also okie. But the initilization list will call default constructor for non-primitive fields. This is extra work.
    }
    
    // Person() {} default constructer syntax. In the initlization list it calls the default constructor for non-primitive fields
    // Same as Person() : name() {}
    
    
    void display() const { // if not const, displayPerson() function will get an error
        // const makes all the attributes in the function unchangable
        cout << name << endl;
    }
    // void setName(const string& theName){name = theName;} // extra work
    
    
private: // ALL MEMBER FIELDS MUST BE PRIVATE. This is encapsulation in play 
    string name;
    int age;
};

void displayPerson(const Person& aPerson) { 
    // The compiler can't tell if aPerson.display() would modify the object or not. if Person.display() doesn't have const keyword
    aPerson.display();
}

int main() {
    Person john("John", 20); // use constructer
    // Person george; this is an error now, no arguments added. Constructer defined, so default constructer disappears
    // john.setName("John"); This is very extra
    // john.name = "John"; This doesn't work anymore cuz .name is private
    john.display();
}
















