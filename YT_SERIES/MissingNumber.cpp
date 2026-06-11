#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int missingValue(vector<int>& nums) {
    int n = nums.size();
    int actualValue = 0;
    int predictValue = n * (n + 1) / 2;
    for (int num : nums) {
      actualValue += num;
    }
    return predictValue - actualValue;
  }
};
int main() {
  Solution sol;
  vector<int> nums = {1, 0, 2, 4};  // missing 3

  int result = sol.missingValue(nums);

  cout << "Missing Element is: " << result << endl;

  return 0;
}