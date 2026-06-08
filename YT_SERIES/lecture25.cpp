// 0's 1's and 2's Algorithm ---->Dutch National Flag algorithm
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
      if (nums[mid] == 0) {
        swap(nums[low], nums[mid]);
        mid++;
        low++;
      } else if (nums[mid] == 1) {
        mid++;
      } else {  // 2
        swap(nums[high], nums[mid]);
        high--;
      }
    }
  }
};
int main() {
  vector<int> A = {2, 0, 2, 1, 1, 0};
  Solution sol;
  sol.sortColors(A);

  cout << "Sorted using 0's 1's and 2's Algorithm: ";
  for (int x : A) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}