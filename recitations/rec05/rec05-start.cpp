/*
  rec05.cpp
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;


// Test code
void doNothing(Section sec) { cout << sec << endl; }

int main() {

    cout << "Test 1: Defining a section\n";
    // Section secA2("A2", "Tuesday", 16);
    // cout << secA2 << endl;

    cout << "\nTest 2: Adding students to a section\n";
    // secA2.addStudent("John");
    // secA2.addStudent("George");
    // secA2.addStudent("Paul");
    // secA2.addStudent("Ringo");
    // cout << secA2 << endl;

    cout << "\nTest 3: Defining a lab worker.\n";
    // LabWorker moe( "Moe" );
    // cout << moe << endl;

    cout << "\nTest 4: Adding a section to a lab worker.\n";
    // moe.addSection( secA2 );
    // cout << moe << endl;

    cout << "\nTest 5: Adding a second section and lab worker.\n";
    // LabWorker jane( "Jane" );
    // Section secB3( "B3", "Thursday", 11 );
    // secB3.addStudent("Thorin");
    // secB3.addStudent("Dwalin");
    // secB3.addStudent("Balin");
    // secB3.addStudent("Kili");
    // secB3.addStudent("Fili");
    // secB3.addStudent("Dori");
    // secB3.addStudent("Nori");
    // secB3.addStudent("Ori");
    // secB3.addStudent("Oin");
    // secB3.addStudent("Gloin");
    // secB3.addStudent("Bifur");
    // secB3.addStudent("Bofur");
    // secB3.addStudent("Bombur");
    // jane.addSection( secB3 );
    // cout << jane << endl;

    cout << "\nTest 6: Adding some grades for week one\n";
    // moe.addGrade("John", 17, 1);  
    // moe.addGrade("Paul", 19, 1);  
    // moe.addGrade("George", 16, 1);  
    // moe.addGrade("Ringo", 7, 1);  
    // cout << moe << endl;

    cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
    // moe.addGrade("John", 15, 3);  
    // moe.addGrade("Paul", 20, 3);  
    // moe.addGrade("Ringo", 0, 3);  
    // moe.addGrade("George", 16, 3);  
    // cout << moe << endl;

    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all "
         << "those students (or rather their records?)\n";

    cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, "
         << "then make sure the following call works:\n";
    // doNothing(secA2);
    // cout << "Back from doNothing\n\n";

} // main
