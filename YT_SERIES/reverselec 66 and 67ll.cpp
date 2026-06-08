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
class List {
  ListNode* head;
  ListNode* tail;

 public:
  List() {
    head = NULL;
    tail = NULL;
  }
  // Push Element
  void push_front(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (head == NULL) {
      head = tail = newNode;
      return;
    } else {
      newNode->next = head;
      head = newNode;
    }
  }
  void print_list(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
      cout << temp->val << " -> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp = head;
    int cnt = 0;
    // check if k nodes exist
    while (cnt < k) {
      if (temp == NULL) {
        return head;
      }
      temp = temp->next;
      cnt++;
    }
    // recursively call for resst of ll
    ListNode* prevNode = reverseKGroup(temp, k);

    // reverse current Group
    temp = head;
    cnt = 0;
    while (cnt < k) {
      ListNode* next = temp->next;
      temp->next = prevNode;

      prevNode = temp;
      temp = next;

      cnt++;
    }
    return prevNode;
  }
};

int main() {
  Solution sol;
  List ln;
  ListNode* head = NULL;

  ln.push_front(head, 1);
  ln.push_front(head, 2);
  ln.push_front(head, 3);
  ln.push_front(head, 4);
  cout << "Oliginal List: " << endl;
  ln.print_list(head);
  // head = sol.reverseKGroup(head, 2);
  cout << "after Reverse K group: " << endl;
  ln.print_list(head);
  return 0;
}

// Lecture 67
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
class List {
  ListNode* head;
  ListNode* tail;

 public:
  List() {
    head = NULL;
    tail = NULL;
  }
  void push_front(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (head == NULL) {
      head = tail = newNode;
      return;
    } else {
      newNode->next = head;
      head = newNode;
    }
  }
  void print_list(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
      cout << temp->val << " -> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL) {
      return head;
    }
    ListNode* first = head;
    ListNode* sec = head->next;
    ListNode* prev = NULL;

    while (first != NULL && sec != NULL) {
      ListNode* third = sec->next;

      sec->next = first;
      first->next = third;

      if (prev != NULL) {
        prev->next = sec;
      } else {
        head = sec;
      }
      // update
      prev = first;
      first = third;

      if (third != NULL) {
        sec = third->next;
      } else {
        sec = NULL;
      }
    }
    return head;
  }
};

int main() {
  List ln;
  Solution sol;
  ListNode* head = NULL;

  ln.push_front(head, 3);
  ln.push_front(head, 2);
  ln.push_front(head, 1);
  ln.push_front(head, 0);

  ln.print_list(head);
  head = sol.swapPairs(head);

  cout << "After reversed" << endl;
  ln.print_list(head);

  return 0;
}