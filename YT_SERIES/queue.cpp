#include <iostream>
#include <queue>
#include <vector>
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

class Queue {
  Node* head;
  Node* tail;

 public:
  Queue() { head = tail = NULL; }
  void push(int data) {  // insert data in tail of ll
    Node* newNode = new Node(data);
    if (empty()) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }
  void pop() {
    if (empty()) {
      cout << "Linked List Is empty!!\n";
      return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
  }
  int front() {
    if (empty()) {
      cout << "LL is empty!!\n";
      return -1;
    }
    return head->data;
  }
  bool empty() { return head == NULL; }
};

int main() {
  Queue q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;

  return 0;
}

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// -----------!!! USING STL !!!----------------//
int main() {
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;

  return 0;
}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// Deque : Double Ended Queue
int main() {
  deque<int> dq;
  dq.push_back(1);
  dq.push_back(2);
  dq.push_back(3);

  dq.push_front(4);                                // 4,1,2,3
  cout << dq.front() << " " << dq.back() << endl;  // output : 4,3

  dq.pop_back();  // 4,2
  cout << "After pop\n";
  cout << dq.front() << " " << dq.back() << endl;  // output : 4,3

  return 0;
}

// Circular Queue

#include <iostream>
using namespace std;

class cirQueue {
  int* arr;
  int currSize, cap;
  int f, r;

 public:
  cirQueue(int size) {
    cap = size;
    arr = new int[cap];
    currSize = 0;
    f = 0;
    r = 1;
  }
  void push(int data) {
    if (currSize == cap) {
      cout << "CQ is Full\n";
      return;
    }
    r = (r + 1) % cap;
    arr[r] = data;
    currSize++;
  }
  void pop() {
    if (empty()) {
      cout << "CQ is full \n";
      return;
    }
    f = (f + 1) & cap;
    currSize--;
  }

  int front() {
    if (empty()) {
      cout << "CQ is Full\n";
      return -1;
    }
    return arr[f];
  }
  bool empty() { return currSize == 0; }
  void print() {
    for (int i = 0; i < cap; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  cirQueue cq(3);
  cq.push(1);
  cq.push(2);
  cq.push(3);
  // cq.print(); //--> this can used print array element
  cq.pop();
  cq.push(4);
  // cout<<"After elemnt Pop !!\n";
  // cq.print();
  // This are print queue
  while (!cq.empty()) {
    cout << cq.front() << " ";
    cq.pop();
  }
  cout << endl;
  return 0;
}