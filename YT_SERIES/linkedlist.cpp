#include <iostream>

using namespace std;

class Node {
 public:
  Node* next;
  int data;

  Node(int val) {
    data = val;
    next = NULL;
  }
};

class list {
  Node* head;
  Node* tail;

 public:
  list() { head = tail = NULL; }
  // ADD IN  A FRONT OF LINKED LIST
  void push_front(int val) {
    Node* newNode = new Node(val);  // dynamic
    if (head == NULL) {
      head = tail = newNode;
      return;
    } else {
      newNode->next = head;
      head = newNode;
    }
  }
  // PUSH BACK FUNCTION ADD IN A LAST
  void push_back(int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }
  // POP FRONT IN LINKED LIST --> FUNCTION
  void pop_front() {
    if (head == NULL) {
      cout << "linked list is empty!";
      return;
    }
    Node* temp = head;
    head = head->next;
    temp->next = NULL;

    delete temp;
  }
  // POP BACK FUNCTION
  void pop_back() {
    if (head == NULL) {
      cout << "LL is Empty\n";
      return;
    }
    Node* temp = head;
    while (temp->next != tail) {
      temp = temp->next;
    }
    temp->next = NULL;
    delete tail;
    tail = temp;
  }
  // INSERT ELEMENT IN ANY POSITION
  void insert(int pos, int val) {
    if (pos < 0) {
      cout << "Return Invalid possition!" << endl;
      return;
    }
    if (pos == 0) {
      push_front(val);
      return;
    }
    if (head == NULL) {
      cout << "List is empty!\n";
      return;
    }
    Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
      if (temp->next == NULL) {
        cout << "position out of range\n";
        return;
      }
      temp = temp->next;
    }
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
  }
  // PRINT ALL ELEMENT IN A LINKEDLIST
  void printLL() {
    Node* temp = head;
    while (temp != NULL) {
      cout << temp->data << "--> ";
      temp = temp->next;
    }
    cout << "Null" << endl;
  }
  // THIS IS SEARCH FUNCTION USED IN NUMBER AND OUTPUT GIVE IS INDEX
  int search(int key) {
    Node* temp = head;
    int idx = 0;

    while (temp != NULL) {
      if (temp->data == key) {
        return idx;
      }
      temp = temp->next;
      idx++;
    }
    return -1;
  }
};
// MAIN FUNCTION
int main() {
  list li;
  li.push_front(1);
  li.push_front(2);
  li.push_front(3);
  li.insert(0, 10);  //(2,10) where the 2 is position and 10 in value or data
                     //   li.push_back(4);
                     //   li.printLL();

  //   li.pop_front();
  //   li.printLL();

  //   li.pop_back();
  li.printLL();

  cout << "Position of this Number: " << li.search(10) << endl;
  return 0;
}

// Reverse a linked list
#include <iostream>
using namespace std;
class ListNode {
 public:
  ListNode* next;
  int data;
  ListNode(int val) {
    data = val;
    next = NULL;
  }
};
class Solution {
 public:
  ListNode* head;
  ListNode* tail;
  Solution() {
    head = NULL;
    tail = NULL;
  }
  // Insert at starting
  void push(int val) {
    ListNode* newNode = new ListNode(val);
    if (head == NULL) {
      head = tail = newNode;
    } else {
      newNode->next = head;
      head = newNode;
    }
  }
  // reverse Linked List
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;

    while (curr != NULL) {
      next = curr->next;
      curr->next = prev;

      prev = curr;
      curr = next;
    }
    return prev;
  }

  void display() {
    ListNode* temp = head;
    while (temp != NULL) {
      cout << temp->data << "->";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};
int main() {
  Solution li;
  li.push(10);
  li.push(12);
  li.push(13);
  cout << "Original Linkedlist!\n";
  li.display();
  li.head = li.reverseList(li.head);
  cout << "Reverse List: \n";
  li.display();
  return 0;
}