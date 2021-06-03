/*
This program demonstrates the use of heaps
Important information about virtual addresss memory space for a program

Lowest place of memory: where your code is
Above it, we have data, which are the global variables
Above the globals there's the heaps where we can allocate and store new objects
At the very top. u have the call stack: main (inside the main there's local variables)

*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


class Person {
    friend ostream& operator<<(ostream& os, const Person& thePerson){
        os << "Person: " << thePerson.name << ", bday: " << thePerson.bday;
        if (thePerson.spouse == nullptr){
            os << " single";
        }
        else {
            os << " married to: " << thePerson.spouse -> name; 
        }
        return os;
    }
    friend void modify_ptr(Person& rhs){
        Person* p = &rhs;
        p -> name = "Mathilda";
        const Person* p2 = &rhs;
        Person* const p3 = &rhs;
    }
public:
    Person(const string& theName, const Date& aDate) : name(theName), bday(aDate), spouse(nullptr) {}
    bool marries(Person& betrothed){
        if (spouse == nullptr && betrothed.spouse == nullptr){
            spouse = &betrothed;
            betrothed.spouse = this;
            return true;
        }
        return false;
    }
private:
    string name;
    Date bday;
    Person* spouse; 
};

class Date{
    friend ostream& operator << (ostream& os, const Date& rhs);
public:
    Date(int m, int d, int y) : month(m), day(d), year(y) {}
private:
    int month, day, year;
};


ostream& operator << (ostream& os, const Date& rhs){
    os << rhs.month << '/' << rhs.day << '/' << rhs.year;
    return os;
}

int main() {
    // Vector of Person objects
    vector<Person*> people;
    ifstream file("people.txt"); // assumming we have a people.txt file
    string name;
    int m, d, y;
    while (file >> name){
        file >> m >> d >> y;
        Person myPerson(name, Date(m,d,y));
        people.push_back(&myPerson); // This is bad
        // &myPerson will always be the same. WHY?
        // because the address of myPerson did not change
        // we need a new person object every thing
    }
    
    people.clear(); // set the size to zero. If you have a vector of pointers, nothing happens to the objects it is pointing at.
    
    while (file >> name){ // Correct way
        file >> m >> d >> y;
        Person* p = new Person(name, Date(m,d,y)); // new Person returns the memory address
        people.push_back(p); // All the perosn objects are stored in the heaps area
    }
    /*
    The difference between heap and global objects is that globals are accessible to the entire program but heap is only
    accessible if the address is given. It is hidden without the address.
    */

    new Person("fred", Date(1,2,3)); // This is called memory leak. 
    // You create an object in the heap but is inaccessible because the addresss is not stored. This cause the program to run slower over time.

    // In order to get rid of old memory stored in the heap in people vector:
    for (Person* p : people){
        delete p; // release the memory in the heap
    }
}
