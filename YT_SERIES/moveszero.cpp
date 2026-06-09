#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void movesZero(vector<int>& nums) {
    int left = 0;

    for (int right = 0; right < nums.size(); right++) {
      if (nums[right] != 0) {
        swap(nums[left], nums[right]);
        left++;
      }
    }
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 2, 0, 3, 0, 4};
  sol.movesZero(nums);

  for (int X : nums) {
    cout << X << " ";
  }

  return 0;
}