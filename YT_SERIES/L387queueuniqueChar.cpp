#include <iostream>
#include <queue>  //FIFO
#include <unordered_map>
using namespace std;

class Solutions {
 public:
  int firstUniqueChar(string s) {
    unordered_map<char, int> m;
    queue<int> Q;

    for (int i = 0; i < s.size(); i++) {
      if (m.find(s[i]) == m.end()) {
        Q.push(i);
      }
      m[s[i]]++;

      while (Q.size() > 0 && m[s[Q.front()]] > 1) {
        Q.pop();
      }
    }
    return Q.empty() ? -1 : Q.front();
  }
};

int main() {
  Solutions obj;
  string s = "aabb";
  int result = obj.firstUniqueChar(s);
  cout << result << endl;

  return 0;
}