#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  bool isFreqSame(int freq1[], int freq2[]) {
    for (int i = 0; i < 26; i++) {
      if (freq1[i] != freq2[i]) {
        return false;
      }
    }
    return true;
  }

  bool checkInclusion(string s1, string s2) {
    int freq[26] = {0};

    for (char c : s1) {
      if (c < 'a' || c > 'z') return false;
      freq[c - 'a']++;
    }

    int windSize = s1.length();

    for (int i = 0; i + windSize <= s2.length(); i++) {
      int windFreq[26] = {0};
      int winIdx = 0;

      while (winIdx < windSize) {
        char c = s2[i + winIdx];
        if (c < 'a' || c > 'z') break;
        windFreq[c - 'a']++;
        winIdx++;
      }

      if (winIdx == windSize && isFreqSame(freq, windFreq)) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  Solution sol;
  string s1 = "ab";
  string s2 = "arcdac";

  if (s1.empty() || s2.empty() || s1.length() > s2.length()) {
    cout << "Permutation is present: 0" << endl;
    return 0;
  }

  cout << "Permutation is present: " << sol.checkInclusion(s1, s2) << endl;

  return 0;
}
