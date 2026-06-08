#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int data) {
    val = data;
    next = NULL;
    random = NULL;
  }
};
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (head == NULL) {
      return NULL;
    }
    unordered_map<Node*, Node*> m; //This map is used to store address of old node and new node

    Node* newHead = new Node(head->val);
    Node* oldTemp = head->next;
    Node* newTemp = newHead;

    m[head] = newHead;

    while (oldTemp != NULL) {
      Node* copyNode = new Node(oldTemp->val);
      newTemp->next = copyNode;
      m[oldTemp] = copyNode;

      newTemp = newTemp->next;
      oldTemp = oldTemp->next;
    }
    oldTemp = head;
    newTemp = newHead;
    while (oldTemp != NULL) {
      newTemp->random = m[oldTemp->random];
      oldTemp = oldTemp->next;
      newTemp = newTemp->next;
    }
    return newHead;
  }
};
int main() {
  Node* head = new Node(1);
  Node* second = new Node(2);
  Node* third = new Node(3);
  Node* fourth = new Node(4);
  Node* fifth = new Node(5);
  // NextPointers
  head->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;

  // random Pointers
  head->random = third;     // 1->3
  second->random = head;    // 2->1
  third->random = fourth;   // 3->4
  fourth->random = second;  // 4->2
  fifth->random = third;    // 5->3

  Solution obj;

  Node* newHead = obj.copyRandomList(head);
  // print Copied List
  Node* temp = newHead;
  while (temp != NULL) {
    cout << "Node Value: " << temp->val;
    if (temp->random != NULL) {
      cout << "Random: " << temp->random->val;
    } else {
      cout << "Random: NUll";
    }
    cout << endl;
    temp = temp->next;
  }

  return 0;
}