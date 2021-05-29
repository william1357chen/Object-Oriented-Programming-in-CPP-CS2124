#include <iostream>
using namespace std;

struct TNode {
  TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
  int data;
  TNode *left, *right;
};

int max(TNode* root) {
  // Provide this code
}

int main() {

  TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
  cout << max(&f) << endl;

}

  
  
