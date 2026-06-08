// REVERSE the string
// this code don't run in vs ccode
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    int n = s.length();
    string ans = "";
    reverse(s.begin(), s.end());

    for (int i = 0; i < n; i++) {
      string word = "";
      while (i < n && s[i] != ' ') {
        word += s[i];
        i++;
      }
      reverse(word.begin(), word.end());
      if (word.length() > 0) {
        ans += " " + word;
      }
    }
    return ans.substr(1);
  }
};

int main() {
  Solution sol;
  string s = "this girl is beautiful ";
  cout << "reverse the string: " << sol.reverseWords(s) << endl;

  return 0;
}