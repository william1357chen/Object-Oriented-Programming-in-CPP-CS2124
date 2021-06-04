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
  Bear yogi("Yogi");
  yogi.eat();
  Tiger tigger("Tigger");
  tigger.eat();
}