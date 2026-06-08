#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node(int val) {
    data = val;
    next = NULL;
  }
};
class circularList {
  Node* head;
  Node* tail;

 public:
  circularList() { head = tail = NULL; }
  void insertat_head(int val) {
    Node* newNode = new Node(val);
    if (tail == NULL) {
      head = tail = newNode;
      tail->next = newNode;
    } else {
      newNode->next = head;
      head = newNode;
      tail->next = head;
    }
  }
  void insertat_tail(int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
      head = tail = newNode;
      tail->next = head;
    } else {
      newNode->next = head;
      tail->next = newNode;
      tail = newNode;
    }
  }
  void deleteat_head() {
    if (head == NULL) {
      cout << "NULL!!" << endl;
      return;                   // LinkedList is empty
    } else if (head == tail) {  // LinkedList is one Node
      delete head;
      head = tail = NULL;
    } else {
      Node* temp = head;
      head = head->next;
      tail->next = head;

      temp->next = NULL;
      delete temp;
    }
  }

  void deleteat_tail() {
    if (head == NULL) {
      cout << "NULL!!" << endl;
      return;
    } else if (head == tail) {
      delete head;
      head = tail = NULL;
    } else {
      Node* temp = tail;
      Node* prev = head;
      while (prev->next != tail) {
        prev = prev->next;
      }
      tail = prev;
      tail->next = head;
      temp->next = NULL;
      delete temp;
    }
  }
  void print() {
    if (head == NULL) return;
    cout << head->data << "->";
    Node* temp = head->next;

    while (temp != head) {
      cout << temp->data << "->";
      temp = temp->next;
    }
    cout << temp->data << endl;
  }
};
int main() {
  circularList cl;
  // cl.insertat_head(1);
  // cl.insertat_head(2);
  // cl.insertat_head(3);

  cl.insertat_tail(1);
  cl.insertat_tail(2);
  cl.insertat_tail(3);
  cl.print();

  // cl.deleteat_head();
  // cl.print();
  // cl.deleteat_head();
  // cl.print();
  // cl.deleteat_head();
  // cl.print();
  // cl.deleteat_head();
  // cl.print();

  cl.deleteat_tail();
  cl.print();
  cl.deleteat_tail();
  cl.print();
  cl.deleteat_tail();
  cl.print();
  cl.deleteat_tail();
  cl.print();

  return 0;
}