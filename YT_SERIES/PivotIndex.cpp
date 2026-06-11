#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    int totalSum = 0;
    for (int num : nums) {
      totalSum += num;
    }
    int leftSum = 0;
    for (int i = 0; i < nums.size(); i++) {
      int rightSum = totalSum - leftSum - nums[i];

      if (leftSum == rightSum) {
        return i;
      }
      leftSum += nums[i];
    }
    return -1;
  }
};
int main() {
  Solution sol;
  vector<int> nums = {1, 7, 3, 6, 5, 6};

  int result = sol.pivotIndex(nums);
  cout << "Pivot IDX is: " << result << endl;

  return 0;
}