#include <iostream>
using namespace std;

class Animal {
public:
  void eat() { cout << "Animal eating\n"; }
private:
};

class Lion : public Animal {
public:
private:
};

class Tiger : public Animal {
public:
  void eat() { cout << "Tiger eating\n"; }
private:
};

class Bear : public Animal {
public:
private:
};

int main() {
  Bear yogi;
  yogi.eat();
  Tiger tigger;
  tigger.eat();
}