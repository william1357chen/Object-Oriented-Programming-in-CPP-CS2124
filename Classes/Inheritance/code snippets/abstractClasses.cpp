/*
	File: TestAbstract.cpp
	John Sterling -- jsterling@poly.edu
	CS1124
	Polytechnic University

	Demonstrates use of Pure Virtual methods and Abstract Classes.
*/

#include <iostream>
#include <string>
using namespace std;

// We are developing a class hierarchy of shapes.  
// Every shape needs to be able to "draw" itself.
// We may have Circles, rectangles, triangles, etc.
// But first a couple of issues:
//
// 1) Each type of Shape will need to know how to draw
// itself.  So every Shape must have a draw method.
// We can make sure that every type of Shape has a draw
// method by putting the prototype for draw() in the 
// Shape class definition.

// 2) But how do we draw a "Shape", if it's not
// some particular kind of Shape, like a Circle.  We can't.
// In fact it doesn't even make any sense to create a Shape
// if we don't know what kind it is.
// 
// We can handle both issues by declaring the draw method 
// as "pure virtual".  The class Shape is then said to be
// an "abstract class".  Any class that has at least one pure
// virtual method is an abstract class.
// A method is made to be pure virtual by writing its
// declaration in the Shape class as:
//   virtual void draw() = 0;
// This declaration forces the class that inherit from Shape
// into providing an implementation for draw().
// It also prevents anyone from trying to create a Shape object
// that isn't something more specific.  That is, you cannot:
//    Shape s;  // error
// That would cause a compilation error.
// You *can* however create a pointer to a Shape:
//    Shape* shapePtr;

// All Shape classes will need a Point object to keep track of 
// their location.
class Point {
public:
	Point() : x(0), y(0) {}
	Point(int newX, int newY) : x(newX), y(newY) {}
	void display() const {cout << "x = " << x << "; y = " << y << endl;}
	// other methods omitted for now.
private:
	int x, y;
};

class Shape {
public:
	// draw method is "pure virtual".  Note the " = 0".
	virtual void draw() const = 0;
	// It is always good to declare the destructor in any
	// base class to be virtual.
	virtual ~Shape() {}
	// Abstract classes *can* have constructors.  With no arguments
	// this constructor initializes the location to x=10, y=20;
	Shape(int x = 10, int y = 20) : location(x, y) {}
protected:
	// Abstract classes can have members.
	Point location;
};

class Circle : public Shape {
public:
	// Circle constructor would automatically (implicitly) call
	// the Shape constructor in its initialization list, but it is 
	// a good idea to write it in yourself, if only to remind you.
	Circle() : Shape(), radius(5) {};
	void draw() const {
		cout << "I'm drawing a circle with radius = " << radius 
			<< " and location: ";
		location.display();
	}
private:
	int radius;
};

class Square : public Shape {
public:
	// The Square constructor will invoke the Shape constructor
	// even though we didn't say to.  This has the same effect as
	// in the default Circle constructor above.
	Square() : side(1) {};
	void draw() const {
		cout << "I'm drawing a square with side = " << side 
			<< " and location: ";
		location.display();
	}
private:
	int side;
};


int main() {

	Shape* sp = new	Circle;
	sp->draw();
	delete sp;
	sp = new Square;
	sp->draw();
	delete sp;
	// Either of the following two lines would cause compilation errors.
	//Shape sp;
	//sp = new Shape();

	return 0;
}