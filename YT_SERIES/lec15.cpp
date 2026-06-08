// This is not used because space complexity is O(n)
// But we can optimize it to O(1) space complexity

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);
    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);

    // prefix

    for (int i = 1; i < n; i++) {
      prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    // suffix
    for (int i = n - 2; i >= 0; i--) {
      suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    // Ans

    for (int i = 0; i < n; i++) {
      ans[i] = suffix[i] * prefix[i];
    }

    return ans;
  }
};

// This is best optimize solution

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);

    // prefix ==>Ans
    for (int i = 1; i < n; i++) {
      ans[i] = ans[i - 1] * nums[i - 1];
    }

    // suffix ===>ans
    int suffix = 1;

    for (int i = n - 2; i >= 0; i--) {
      suffix *= nums[i + 1];
      ans[i] = ans[i] * suffix;
    }

    return ans;
  }
};

int main() {
  Solution s;
  vector<int> nums = {10, 2, 1, 5};

  vector<int> result = s.productExceptSelf(nums);
  cout << "OutPut: ";
  for (int x : result) {
    cout << " " << x;
  }
  cout << endl;
  return 0;
}