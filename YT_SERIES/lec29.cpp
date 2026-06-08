//------------LEET CODE PROBLEM-------------
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  bool isAlphaNum(char ch) {
    if ((ch >= '0' && ch <= '9') ||
        (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {
      return true;
    }
    return false;
  }

  bool isPalindrome(string s) {
    int st = 0, end = s.length() - 1;

    while (st < end) {
      if (!isAlphaNum(s[st])) {
        st++;
        continue;
      }
      if (!isAlphaNum(s[end])) {
        end--;
        continue;
      }
      if (tolower(s[st]) != tolower(s[end])) {
        return false;
      }
      st++;
      end--;
    }
    return true;
  }
};

int main() {
  Solution sol;
  string str = "man playin a girl fellings";
  if (sol.isPalindrome(str)) {
    cout << "It is a Palindrom....!" << endl;
  } else {
    cout << "It is not A palindrom...!" << endl;
  }
  return 0;
}

//-----------SHORT CUT METHOD-------------
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

bool isAlpha(char ch) {
  if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {
    return true;
  }
  return false;
}

bool validPalindrom(string str) {
  string rev = str;
  reverse(str.begin(), str.end());
  return str == rev;
}

int main() {
  string str = "car a race";
  if (validPalindrom(str)) {
    cout << "It is valid palindrom..!" << endl;
  } else {
    cout << "It is not Valid palindrom..!" << endl;
  }

  return 0;
}

// Remove All Occurence of a given char from string
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  string removeOccurrences(string s, string part) {
    while (s.length() > 0 && s.find(part) < s.length()) {
      s.erase(s.find(part), part.length());
    }

    return s;
  }
};

int main() {
  Solution sol;
  string str = "ababababccabc";
  string part = "ab";
  string result = sol.removeOccurrences(str, part);
  cout << "Result of String after remove occurence :" << result << endl;

  return 0
}