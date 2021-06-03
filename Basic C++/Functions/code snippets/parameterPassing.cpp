
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void pass_by_value(int n){
    n++;
    // the actual value n in main() did not change
}
void pass_by_ref(int& n){
    n++;
    // & is like the address, the ref to n in main(), so value changes
}
int pass_by_return(int n){
    return n+n;
    //return gives new copy of n+n
}

void pass_by_const_ref(const int& n){
    // n cannot be changed
}


void print_vec(vector<int> v){
    for (int n : v){
        cout << n << ' ';
    }
    cout << endl;
    
}

void print_vec_const(const vector<int>& v){ // doesn't return, doesn't change vector v, doesnt have side effects
    for (int n : v){ // int n is a copy
        cout << n << ' ';
    }
    cout << endl;
    
}

void square_vec(const vector<int>& v){
    for (int n : v){ // int n is a copy
        cout << (n * n) << ' ';
    }
}



int main(int argc, const char * argv[]) {
    // Test code here

    return 0;
}
