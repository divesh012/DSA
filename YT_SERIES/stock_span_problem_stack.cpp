#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> stockSpan(vector<int>& price) {
  vector<int> ans(price.size());
  stack<int> s;

  for (int i = 0; i < price.size(); i++) {
    while (!s.empty() &&
           price[s.top()] <=
               price[i]) {  // pop element smaller than current price
      s.pop();
    }
    if (s.size() == 0) {
      ans[i] = i + 1;
    } else {
      ans[i] = i - s.top();  // prevHigh
    }
    s.push(i);
  }
  return ans;
}
int main() {
  vector<int> price = {100, 80, 60, 70, 60, 75, 85};
  vector<int> result = stockSpan(price);
  for (int val : result) {
    cout << val << " ";
  }
  return 0;
}

// Next Greater Element
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreater(vector<int>& arr) {
  vector<int> ans(arr.size()); // -->This is used for size of answer vector is same as input vector size
  stack<int> s;

  for (int i = arr.size() - 1; i >= 0; i--) {
    while (s.size() > 0 &&
           s.top() <= arr[i]) {  // pop element smaller than current price
      s.pop();
    }
    if (s.empty()) {
      ans[i] = -1;
    } else {
      ans[i] = s.top();  // prevHigh
    }
    s.push(arr[i]);
  }
  return ans;
}
int main() {
  vector<int> arr = {6, 8, 0, 1, 3};
  vector<int> result = nextGreater(arr);
  for (int val : result) {
    cout << val << " ";
  }
  return 0;
}

// Next Greater Element with two Numbers
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> m;
    stack<int> s;

    for (int i = nums2.size() - 1; i >= 0; i--) {
      while (s.size() > 0 && s.top() <= nums2[i]) {
        s.pop();
      }
      if (s.empty()) {
        m[nums2[i]] = -1;
      } else {
        m[nums2[i]] = s.top();
      }
      s.push(nums2[i]);
    }
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++) {
      ans.push_back(m[nums1[i]]);
    }
    return ans;
  }
};
int main() {
  Solution sol;
  vector<int> nums1 = {4, 1, 2};
  vector<int> nums2 = {1, 3, 4, 2};
  vector<int> result = sol.nextGreaterElement(nums1, nums2);
  for (int val : result) {
    cout << val << " ";
  }
  return 0;
}

// Previous Smaller Element
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> prevSmaller(vector<int>& arr) {
    vector<int> ans(arr.size());
    stack<int> s;

    for (int i = 0; i < arr.size(); i++) {
      while (s.size() > 0 && s.top() >= arr[i]) {
        s.pop();
      }
      if (s.empty()) {
        ans[i] = -1;
      } else {
        ans[i] = s.top();
      }
      s.push(arr[i]);
    }
    return ans;
  }
};
int main() {
  Solution sol;
  vector<int> arr = {3, 1, 0, 8, 6};
  vector<int> result = sol.prevSmaller(arr);
  for (int val : result) {
    cout << val << " ";
  }
  return 0;
}