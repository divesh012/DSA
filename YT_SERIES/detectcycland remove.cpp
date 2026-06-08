#include <iostream>
#include <string>
using namespace std;
// Simple Cycle occur in LL
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
  bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast) return true;
    }
    return false;
  }
};

void push_front(ListNode*& head, int val) {
  ListNode* newNode = new ListNode(val);
  newNode->next = head;
  head = newNode;
}
void print_list(ListNode* head) {
  while (head != NULL) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "NULL" << endl;
}

int main() {
  ListNode* head = NULL;
  push_front(head, 4);
  push_front(head, 5);
  push_front(head, 6);

  // Create cycle
  ListNode* temp = head;
  ListNode* thirdNode = head->next->next;

  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = thirdNode;  // cycle created

  Solution obj;

  bool cycleNode = obj.hasCycle(head);
  if (cycleNode) {
    cout << "cycle Occur" << endl;
  } else {
    cout << "No cycle Found \n";
  }
  return 0;
}
//  occur cycle and remove cycle in LL

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
  ListNode* hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    bool isCycle = false;  // used for remove cycle

    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast) {
        isCycle = true;
        break;
      }
    }
    if (!isCycle) {
      return NULL;
    }
    slow = head;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
};
void pushFront(ListNode*& head, int val) {
  ListNode* newNode = new ListNode(val);
  newNode->next = head;
  head = newNode;
}

int main() {
  ListNode* head = NULL;
  pushFront(head, 5);
  pushFront(head, 4);
  pushFront(head, 3);
  pushFront(head, 2);
  pushFront(head, 1);

  // Create Cycle
  ListNode* temp = head;
  ListNode* thirdNode = head->next->next;

  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = thirdNode;  // cycle created

  Solution obj;

  ListNode* cycleNode = obj.hasCycle(head);

  if (cycleNode) {
    cout << "cycle Occur with value: " << cycleNode->val << "!!" << endl;
  } else {
    cout << "No cycle Found\n";
  }

  return 0;
}