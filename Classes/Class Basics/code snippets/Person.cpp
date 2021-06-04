#include <string>
#include <iostream>
using namespace std;

class Date {
public:
  Date(int month, int day, int year) : month(month), day(day), year(year) {}
  void display() const { cout << month << '/' << day << '/' << year; }
private:
  int month, day, year;
};

class Person {
public:
  Person(const string& aName, int m, int d, int y)
    : myName(aName), bday(m, d, y) { }
  void display() const {
    cout << "Displaying a Person named " << myName << " whose birthday is ";
    bday.display();
    cout << endl;
  }
private:
  string myName;
  Date bday;
};

int main() {
  Person will("Will", 3, 14, 1592); // Don't know how old Will is.  March 14, 1592 is just a guess.
  will.display();
}