#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool checkDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (int num : nums) {
      if (seen.count(num)) return true;

      seen.insert(num);
    }
    return false;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 2, 3, 4};  // False
  // vector<int> nums = {1,2,3,1}; //True
  if (sol.checkDuplicate(nums))
    cout << "True -> Contain Duplicate" << endl;
  else
    cout << "False ->Not contain Duplicate" << endl;

  return 0;
}