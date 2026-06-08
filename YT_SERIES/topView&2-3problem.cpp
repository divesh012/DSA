#include <iostream>
#include <map>
#include <queue>
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
static int idx = -1;
Node* buildTree(vector<int> preorder) {
  idx++;
  if (preorder[idx] == -1) {
    return NULL;
  }
  Node* root = new Node(preorder[idx]);
  root->left = buildTree(preorder);
  root->right = buildTree(preorder);
  return root;
}
// TOP VIEW of Binary Tree
void topView(Node* root) {
  queue<pair<Node*, int>> q;  // pair (node,horizontal DIstance - HD)
  map<int, int> m;
  q.push({root, 0});

  while (q.size() > 0) {
    Node* curr = q.front().first;
    int currHD = q.front().second;
    q.pop();
    if (m.find(currHD) == m.end()) {
      m[currHD] = curr->data;
    }
    if (curr->left != NULL) {
      q.push({curr->left, currHD - 1});
    }
    if (curr->right != NULL) {
      q.push({curr->right, currHD + 1});
    }
  }
  for (auto it : m) {
    cout << it.second << " ";
  }
  cout << endl;
}

int main() {
  vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
  Node* root = buildTree(preorder);
  topView(root);

  return 0;
}

//---------------------------Kth Level of Binary
// Tree---------------------------//

void kthLevel(Node* root, int k) {
  if (root == NULL) {
    return;
  }
  if (k == 1) {
    cout << root->data << " ";
    return;
  }
  kthLevel(root->left, k - 1);
  kthLevel(root->right, k - 1);
}
int main() {
  vector<int> preorder = {1, 2, 7, -1, -1, -1, 3, 4, -1, -1, 5, -1, -1};
  Node* root = buildTree(preorder);
  kthLevel(root, 3);

  return 0;
}

// used preorder and inorder create tree

class Solution {
 public:
  int search(vector<int>& inorder, int left, int right, int val) {
    for (int i = left; i <= right; i++) {
      if (inorder[i] == val) {
        return i;
      }
    }
    return -1;
  }

  TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx,
                   int left, int right) {
    if (left > right) {
      return NULL;
    }
    TreeNode* root = new TreeNode(preorder[preIdx]);

    int inIdx = search(inorder, left, right, preorder[preIdx]);
    preIdx++;

    root->left = helper(preorder, inorder, preIdx, left, inIdx - 1);

    root->right = helper(preorder, inorder, preIdx, inIdx + 1, right);

    return root;
  }
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preIdx = 0;
    return helper(preorder, inorder, preIdx, 0, inorder.size() - 1);
  }
};