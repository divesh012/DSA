#include <iostream>
using namespace std;
// BUBBLE   SORTING

void bubbleSort(int arr[], int n) {  // 0 (n*n = n^2)

  for (int i = 0; i < n; i++) {
    bool isSwap = false;

    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        isSwap = true;
      }
    }
    if (!isSwap) {  // array already sorted
      return;
    }
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int n = 5;
  int arr[] = {1, 5, 2, 4, 3};
  cout << "This is Given array: " << arr << endl;
  bubbleSort(arr, n);
  printArray(arr, n);
  return 0;
}
// selection sort
#include <iostream>
using namespace std;
// Selection   SORTING

void selectioSort(int arr[], int n) {  //
  for (int i = 0; i < n - 1; i++) {
    int smallestIdx = i;  // unsorted part of starting
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[smallestIdx]) {  // " < " replace by " > " then print is desending order 
        smallestIdx = j;
      }
    }
    swap(arr[i], arr[smallestIdx]);
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int n = 5;
  int arr[] = {1, 5, 2, 4, 3};

  selectioSort(arr, n);
  printArray(arr, n);
  return 0;
}

// INSERTION SORTING

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {  //
  for (int i = 1; i < n; i++) {
    int curr = arr[i];
    int prev = i - 1;
    while (prev >= 0 && arr[prev] > curr) {
      arr[prev + 1] = arr[prev];
      prev--;
    }
    arr[prev + 1] = curr;  // placing the curr element in its correct position
  }
}
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
int main() {
  int n = 5;
  int arr[] = {1, 5, 2, 4, 3};

  insertionSort(arr, n);
  printArray(arr, n);
  return 0;
}