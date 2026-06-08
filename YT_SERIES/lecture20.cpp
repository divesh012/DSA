// let code 540
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int singleNonDuplicate(vector<int>& A) {
    int n = A.size();

    if (n == 1) return A[0];
    int st = 0, end = n - 1;
    while (st <= end) {
      int mid = st + (end - st) / 2;

      if (mid == 0 && A[0] != A[1]) return A[mid];
      if (mid == n - 1 && A[n - 1] != A[n - 2]) return A[mid];
      if (A[mid - 1] != A[mid] && A[mid] != A[mid + 1]) return A[mid];
      if (mid % 2 == 0) {            // even
        if (A[mid - 1] == A[mid]) {  // left
          end = mid - 1;
        } else {  // right
          st = mid + 1;
        }
      } else {                       // odd
        if (A[mid - 1] == A[mid]) {  // right
          st = mid + 1;
        } else {  // left
          end = mid - 1;
        }
      }
    }
    return -1;
  }
};

int main() {
  vector<int> A = {0, 0, 3, 3, 5, 5, 8, 9, 9};
  Solution sol;
  int value = sol.singleNonDuplicate(A);

  cout << "Non_Duplicate Value: " << value << endl;

  return 0;
}