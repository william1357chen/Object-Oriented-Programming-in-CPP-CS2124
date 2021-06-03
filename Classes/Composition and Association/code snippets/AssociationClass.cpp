/*
    William's Notes

	Demonstrate how to create an "association"
	between two classes objects using pointers.
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
        else { // use pointer to get the other person's name
            // os << "married to: " << *thePerson.spouse.name; this doesn't work. Dot operator has more precedence than *
            // os << "married to: " << (*thePerson.spouse).name; works but ugly
            os << " married to: " << thePerson.spouse -> name; // same as (*thePerson.spouse).name
        }
        return os;
    }
    // it is possible to modify data using pointer
    friend void modify_ptr(Person& rhs){
        Person* p = &rhs;
        p -> name = "Mathilda";
        // if don't want p to modify the content of the thing it is pointing too
        const Person* p2 = &rhs;
        // p2 -> name = "Cant change"; doesn't work
        // if don't want p to get changed and point to another object
        Person* const p3 = &rhs;
    }

public:
    //Person(const string& theName, int m, int d, int y) : name(theName), bday(m, d, y) {}
    //same as:
    Person(const string& theName, const Date& aDate) : name(theName), bday(aDate), spouse(nullptr) {}
    
    bool marries(Person& betrothed){
        if (spouse == nullptr && betrothed.spouse == nullptr){
            spouse = &betrothed; // point the pointer spouse to the address of Person object betrothed
            betrothed.spouse = this; // this is a person pointer. It holds the address of this object.
            // private can be accessed by the same class, so betrothed.spouse is not private since betrothed is also a Person
            return true;
        }
        return false;
    }
  
private:
    string name;
    Date bday;
    // Person spouse; Cannot have another person field in Person class. Occupy too much memory (same memory as the class's object memory)
    // string spouse; only know the name
    Person* spouse; // only 8 bits of memory for pointer
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
    Person john("John", Date(7,1,1999));
    Person mary("Mary", Date(7,1,1200));
    
    vector<Person*> people;
    people.push_back(&john);
    people.push_back(&mary);
    for (Person* p : people){
        cout << *p << endl;
    }
    people.clear();
}
