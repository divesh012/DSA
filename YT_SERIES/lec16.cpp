#include <iostream>
using namespace std;
// Pointers
int main() {
  int a = 10;
  cout << &a << endl;  //---->This is address of a

  int *ptr = &a;
  cout << ptr
       << endl;  //---->This is address of a they can be store in a pointer
  cout << &ptr << endl;  //---->This is address of pointer

  return 0;
}

#include <iostream>
using namespace std;
// Pointer to pointer
int main() {
  int a = 10;
  int *ptr = &a;

  int **parPtr = &ptr;
  cout << *(&a) << endl;   // 10
  cout << *(ptr) << endl;  // 10
  cout << &ptr << endl;
  cout << **(parPtr) << endl;
  cout << (parPtr) << endl;

  return 0;
}

#include <iostream>
using namespace std;
// Null pointer
int main() {
  int **ptr = NULL;
  // int **ptr;            // this is also valid but output show in garbage
  // value
  cout << ptr << endl;  // 0
  return 0;
}
// question
#include <iostream>
using namespace std;

int main() {
  int a = 5;
  int *p = &a;
  int **q = &p;

  cout << *p << endl;   // a --->value of a
  cout << **q << endl;  // a --->value of a
  cout << p << endl;    // &a --->address of a
  cout << *q << endl;   // &a --->address of a

  return 0;
}

#include <iostream>
#include <vector>
using namespace std;
// call by reference
void changeA(int *ptr) {  // pass by reference by pointer
  *ptr = 20;
}

int main() {
  int a = 10;
  changeA(&a);

  cout << "Inside main function: " << a << endl;

  return 0;
}

#include <iostream>
#include <vector>
using namespace std;
// call by reference
void changeA(int &b) {  // pass by reference using alias------> means same name
                        // but diff work
  b = 20;
}

int main() {
  int a = 10;
  changeA(a);

  cout << "Inside main function: " << a << endl;

  return 0;
}

#include <iostream>
using namespace std;
// Array pointer

int main() {
  int arr[] = {1, 2, 3, 4, 5};

  int a = 50;

  int *ptr = &a;

  cout << ptr << endl;
  ptr++;
  cout << ptr << endl;

  cout << arr << endl;
  cout << *arr << endl;  // --->points to the 0th index number

  cout << ptr << endl;
  ptr = ptr + 2;  // 8 bytes memory added

  return 0;
}

#include <iostream>
using namespace std;
// Array pointer

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int *ptr2;             // 100
  int *ptr1 = ptr2 + 2;  // 108

  cout << ptr1 - ptr2 << endl;  // 2

  return 0;
}

// question
#include <iostream>
using namespace std;
int main() {
  int arr[] = {10, 20, 30, 40};
  int *ptr = arr;

  cout << *(ptr + 1) << endl;
  cout << *(ptr + 3) << endl;
  ptr++;
  cout << *ptr << endl;

  return 0;
}