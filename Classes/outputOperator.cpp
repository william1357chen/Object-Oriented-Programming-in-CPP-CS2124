
#include <iostream>
#include <string>
using namespace std;

class Person {
    // not a method so we use friend to let it access private fields. 
    friend ostream& operator<<(ostream& os, const Person& thePerson);
public:
    Person(const string& theName, const int& theAge) : name(theName), age(theAge){}

    void display() const {cout << name << endl;}
    
    const string& getName() const {return name;} //return type string& means the thing returned is a reference that can be modified which we dont want, so we add const.
    
private:
    string name;
    int age;
};
void displayPerson(const Person& aPerson) {
    aPerson.display();
}
/*
Why return type ostream&?
Ex: (cout << "fred") << 17 operates cout << "fred" first
cout << "fred" has to return cout to do cout << 17
*/
ostream& operator<<(ostream& os, const Person& thePerson){ // ostream always has to referred
    // os << "Person: " << thePersn.name << endl; Person is private ):. Need getName function
    //os << "Person: " << thePerson.getName(); Or
    os << "Person: " << thePerson.name; // define this function as friend in Person class.
    return os;
}

int main() {
    Person john("John", 20);
    john.display();
    cout << john; // Overload cout.operator<<(john)
}





