#include <iostream>
using namespace std;

class ListNode {
 public:
  int val;
  ListNode* next;

  ListNode(int data) {
    val = data;
    next = NULL;
  }
};

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
    if (h1 == NULL || h2 == NULL) {
      return h1 == NULL ? h2 : h1;
    }
    // case1

    if (h1->val <= h2->val) {
      h1->next = mergeTwoLists(h1->next, h2);
      return h1;
    } else {
      h2->next = mergeTwoLists(h1, h2->next);
      return h2;
    }
  }
};
void push_front(ListNode*& head, int val) {
  ListNode* newNode = new ListNode(val);
  newNode->next = head;
  head = newNode;
}
void printList(ListNode* head) {
  while (head != NULL) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "NULL" << endl;
}

int main() {
  ListNode* head1 = NULL;
  push_front(head1, 9);
  push_front(head1, 7);
  push_front(head1, 5);
  // LinkedList 2
  ListNode* head2 = NULL;
  push_front(head2, 1);
  push_front(head2, 3);
  push_front(head2, 5);

  cout << "List1: ";
  printList(head1);

  cout << "List2: ";
  printList(head2);

  Solution obj;
  ListNode* merge = obj.mergeTwoLists(head1, head2);
  cout << "Merge Of two List: ";
  printList(merge);

  return 0;
}