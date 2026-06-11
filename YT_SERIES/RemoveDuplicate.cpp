#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int removeDuplicate(vector<int>& nums) {
    if (nums.empty()) return 0;
    int i = 0;

    for (int j = 1; j < nums.size(); j++) {
      if (nums[j] != nums[i]) {
        i++;
        nums[i] = nums[j];
      }
    }
    return i + 1;
  }
};
int main() {
  Solution sol;
  // Sorted Array Remove Only not work Random array
  //  Work on random array then used
  //-----------!!!  This Condition !!!!!!---------
  // #include <algorithm>
  // sort(nums.begin(), nums.end());
  vector<int> nums = {1, 1, 2, 2, 5, 6, 8};

  int result = sol.removeDuplicate(nums);

  cout << "Number of unique Element: " << result << endl;

  cout << "Array After Removing Duplicate: ";

  for (int i = 0; i < result; i++) {
    cout << nums[i] << " ";
  }

  return 0;
}