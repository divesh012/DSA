#include <iostream>
#include <vector>
using namespace std;
//leet code problem no 852
class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& A) {
    int st = 1, end = A.size() - 2;

    while (st <= end) {
      int mid = st + (end - st) / 2;
      if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1]) {
        return mid;
      } else if (A[mid - 1] < A[mid]) {  // right
        st = mid + 1;
      } else {  // left
        end = mid - 1;
      }
    }
    return -1;
  }
};

int main() {
  vector<int> arr = {0, 3, 8, 9, 5, 2};
  Solution sol;
  int index = sol.peakIndexInMountainArray(arr);

  cout << "peakIndexInMountainArray: " << index << endl;
  cout << "peak element value: " << arr[index] << endl;

  return 0;
}