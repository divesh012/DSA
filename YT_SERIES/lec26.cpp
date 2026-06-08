#include <iostream>
#include <vector>
using namespace std;
// leet code problem no 88 ----> First Question
class Solution {
 public:
  void merge(vector<int>& A, int m, vector<int>& B, int n) {
    int idx = m + n - 1, i = m - 1, j = n - 1;

    while (i >= 0 && j >= 0) {
      if (A[i] >= B[j]) {
        A[idx--] = A[i--];
      } else {
        A[idx--] = B[j--];
      }
    }
    while (j >= 0) {
      A[idx--] = B[j--];
    }
  }
};

int main() {
  vector<int> A = {1, 2, 3, 0, 0, 0};
  vector<int> B = {2, 5, 6};

  Solution sol;

  sol.merge(A, 3, B, 3);  // m = 3 Three element Of A and Three element of B
  cout << "Solve after merge: ";
  for (int num : A) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}

// 2nd Question
#include <algorithm>  // for reverse and swap
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int>& A) {
    // find the pivot
    int pivot = -1, n = A.size();
    for (int i = n - 2; i >= 0; i--) {
      if (A[i] < A[i + 1]) {
        pivot = i;
        break;
      }
    }
    if (pivot == -1) {
      reverse(A.begin(),
              A.end());  // inplace change --> use vector ke andr changes kiye
                         // hai without using extra space
      return;
    }
    // 2nd to find the next larger
    for (int i = n - 1; i > pivot; i--) {
      if (A[i] > A[pivot]) {
        swap(A[i], A[pivot]);
        break;
      }
    }
    // 3rd reverse
    // reverse(A.begin()+pivot+1,A.end()); -->this can be uncommentr then next
    // three line is comment out

    int i = pivot + 1, j = n - 1;
    while (i <= j) {
      swap(A[i++], A[j--]);
    }
  }
};

int main() {
  vector<int> A = {1, 2, 3, 5, 4};

  Solution sol;

  sol.nextPermutation(A);
  cout << "Next Permutation: ";
  for (int num : A) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}