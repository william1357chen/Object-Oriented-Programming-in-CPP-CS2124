
#include <iostream>
using namespace std;

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

int main(){
    // Test code here
    return 0;
}