#include <climits>
#include <iostream>
#include <vector>
using namespace std;

//TC = O(N) 

class Node {
 public:
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

class Info {
 public:
  int min, max, sz;
  bool isBST;

  Info(int mi, int ma, int size, bool bst) {
    min = mi;
    max = ma;
    sz = size;
    isBST = bst;
  }
};
Info helper(Node* root) {
  if (root == NULL) {
    return Info(INT_MAX, INT_MIN, 0, true);
  }
  Info left = helper(root->left);
  Info right = helper(root->right);

  if (left.isBST && right.isBST && root->data > left.max &&
      root->data < right.min) {
    int currMin = min(root->data, left.min);
    int currMax = max(root->data, right.max);
    int currSz = left.sz + right.sz + 1;

    return Info(currMin, currMax, currSz, true);
  }
  return Info(INT_MAX, INT_MIN, max(left.sz, right.sz), false);
}

int largestBSTinBT(Node* root) {
  Info info = helper(root);
  return info.sz;
}

int main() {
  Node* root = new Node(10);
  root->left = new Node(5);
  root->right = new Node(15);
  root->left->left = new Node(1);
  root->left->right = new Node(8);
  root->right->right = new Node(50);

  cout << largestBSTinBT(root) << endl;

  return 0;
}