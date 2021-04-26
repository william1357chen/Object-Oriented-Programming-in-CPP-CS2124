# Structs in C++
A common way to make our own types is by using *structs*
```c++
struct Cat {
   string color;
   string name;
   double weight;
}; // Don't forget semi-colon at the end
```
`Cat` has three attributes: `color`, `name` and `weight`. Attributes are also known as fields or member variables.

We can then create a cat, provide values for its various attributes and finally access those values to print them with the following code:
```c++
Cat myCat;
myCat.name = "Felix";
myCat.color = "grey";
myCat.weight = 3.14;
cout << myCat.name << '\t' << myCat.color << '\t' << myCat.weight << endl;
```
## Assigning Structs to another
```c++
Cat b;
b = myCat;
```
same as 
```c++
b.color = myCat.color;
b.name = myCat.name;
b.weight = myCat.weight;
```

Note that currently `Cat` cannot perform operators like equality or printing. 
```c++
// COMPILATION  ERROR!!!
if (b == myCat) {/* We want to do something if they are equal*/}

cout << myCat << endl;   // COMPILATION ERROR!!!
```
To solve this, we use operator overloading.

## Filling a vector of structs
Above we defined a Cat struct. How would we fill a vector of cats from a file holding the cat information? Below is a function that is passed a stream to read from and a vector to fill with Cats. We assume that the file has one cat per line.
```c++
void fillCatVector (ifstream& ifs, vector<Cat>& vc) {
   Cat c;
   while (ifs >> c.name >> c.color >> c.weight) {
      vc.push_back(c);
   }
}
```