#include <iostream>
#include <vector>
using namespace std;

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

Node* rightMostInleftSubtree(Node* root) {
  Node* ans;
  while (root != NULL) {
    ans = root;
    root = root->right;
  }
  return ans;
}

Node* leftMostInrightSubtree(Node* root) {
  Node* ans;
  while (root != NULL) {
    ans = root;
    root = root->left;
  }
  return ans;
}
vector<int> getPreSuc(Node* root, int key) {
  Node* curr = root;
  Node* pred = NULL;
  Node* succ = NULL;

  while (curr != NULL) {
    if (key < curr->data) {
      succ = curr;
      curr = curr->left;
    } else if (key > curr->data) {
      pred = curr;
      curr = curr->right;
    } else {
      if (curr->left != NULL) {
        // Inorder Pred
        pred = rightMostInleftSubtree(curr->left);
      }
      if (curr->right != NULL) {
        // Inorder Succ
        succ = leftMostInrightSubtree(curr->right);
      }
      break;
    }
  }
  return {pred->data, succ->data};
}

int main() {
  Node* root = new Node(6);
  root->left = new Node(4);
  root->right = new Node(8);
  root->left->left = new Node(1);
  root->left->right = new Node(5);
  root->right->left = new Node(7);
  root->right->right = new Node(9);

  int key = 3;
  vector<int> ans = getPreSuc(root, key);
  cout << "Predecessor: " << ans[0] << endl;
  cout << "Succesor: " << ans[1] << endl;

  return 0;
}