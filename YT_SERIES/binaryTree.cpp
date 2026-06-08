#include <iostream>
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
    left = NULL;
    right = NULL;
  }
};
static int idx = -1;
Node* buildTree(vector<int> preorder) {
  idx++;
  if (preorder[idx] == -1) {
    return NULL;
  }
  Node* root = new Node(preorder[idx]);
  root->left = buildTree(preorder);   // LEFT
  root->right = buildTree(preorder);  // RIGHT
  return root;
}

// preorder Traversal

void preOrder(Node* root) {
  if (root == NULL) {
    return;
  }
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

// INORDER TRAVERSAL
void inOrder(Node* root) {
  if (root == NULL) {
    return;
  }
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}
// POSTORDER TRAVERSAL
void postOrder(Node* root) {
  if (root == NULL) {
    return;
  }
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}
// LEVEL ORDER TRAVERSAL
void levelOrder(Node* root) {
  queue<Node*> q;

  q.push(root);
  q.push(NULL);

  while (q.size() > 0) {
    Node* curr = q.front();
    q.pop();

    if (curr == NULL) {
      if (!q.empty()) {
        cout << endl;
        q.push(NULL);
        continue;
      } else {
        break;
      }
    }

    cout << curr->data << " ";

    if (curr->left != NULL) {
      q.push(curr->left);
    }
    if (curr->right != NULL) {
      q.push(curr->right);
    }
  }
}

int main() {
  vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

  Node* root = buildTree(preorder);
  // preOrder(root);
  // inOrder(root);
  // postOrder(root);
  levelOrder(root);
  // cout << endl;
  return 0;
}

// Post Order Traversal ---> count , sum and Height of the tree

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
// Post Order TRAVERSAL -->To calculate the Height
int height(Node* root) {
  if (root == NULL) {
    return 0;
  }
  int leftHt = height(root->left);
  int rightHt = height(root->right);
  return max(leftHt, rightHt) + 1;
}
// Count of the tree -->Used Post Order logic
int count(Node* root) {
  if (root == NULL) {
    return 0;
  }
  int leftCount = count(root->left);
  int rightCount = count(root->right);
  return leftCount + rightCount + 1;
}
// Sum Of nodes -->Used POST ORDER
int sumNode(Node* root) {
  if (root == NULL) {
    return 0;
  }
  int leftSum = sumNode(root->left);
  int rightSum = sumNode(root->right);

  return leftSum + rightSum + root->data;
}
int main() {
  vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
  Node* root = buildTree(preorder);
  // int result = height(root);
  // int result = count(root);
  int result = sumNode(root);
  // cout<<"Height Of the Tree: "<<result;
  // cout<<"Count of Tree Nodes is: "<<result;
  cout << "Sum of Node is: " << result;

  return 0;
}