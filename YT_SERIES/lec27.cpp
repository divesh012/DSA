#include <iostream>
#include <vector>
using namespace std;
// capacity,size, push_back, pop_back, at, front, back
int main() {
  vector<int> vec = {1, 2, 5, 6, 8, 9, 11};
  vec.push_back(1);     // size =1
  vec.push_back(2);     // size 2 capacity =2
  vec.push_back(3);     // size = 3 capacity = 4
  vec.emplace_back(4);  // size = 4 capacity = 4
  vec.emplace_back(5);  // size = 4 capacity = 8
  vec.emplace_back(6);  // size = 4 capacity = 8
  for (int val : vec) {
    cout << "Value is: " << val << endl;
  }
  cout << endl;
  vec.pop_back();  // size = 4 capacity = 8
  cout << "last elemnt is Deleted 6" << endl;
  cout << "value at idx 2: " << vec[2] << endl;            //---->3
  cout << "value at idx 3: " << vec.at(3) << endl;         //------>4
  cout << "value front element: " << vec.front() << endl;  //------>1
  cout << "value last element: " << vec.back() << endl;    //------>5
  cout << "size:" << vec.size();
  vec.erase(vec.begin());
  cout << "\ncapacity:" << vec.capacity();

  return 0;
}

// Erase ,Insert and Clear
#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> vec = {1, 2, 5, 6, 8, 9, 11};
  // vec.erase(vec.begin()); //remove 1st element
  //  vec.erase(vec.begin()+2);//remove 3rd index element
  //  vec.erase(vec.begin()+1,vec.begin()+3);//remove element in the range //2
  //  and 5 is deleted
  vec.insert(vec.begin() + 2, 100);  //-->[1,2,100,5,6,8,9,11]

  vec.clear();

  for (int val : vec) {
    cout << "Value is: " << val << endl;
  }
  cout << endl;
  cout << " empty: " << vec.empty() << endl;  // --->1 = True
  cout << "capacity is : " << vec.capacity();

  return 0;
}

// Vector iterators
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
  vector<int> vec = {1, 2, 3, 4, 5};

  // vector<int>::iterator it; == auto
  for (auto it = vec.begin(); it != vec.end(); it++) {
    cout << *(it) << " ";
  }
  cout << endl;
  return 0;
}
// List container
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
  list<int> l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);
  l.push_front(5);
  l.push_front(6);

  for (int val : l) {
    cout << val << " ";
  }

  cout << endl;
  return 0;
}

// Deque container
#include <deque>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
  deque<int> d = {1, 2, 3, 4, 5};

  for (int val : d) {
    cout << val << " ";
  }
  cout << endl;
  cout << d[2] << endl;
  return 0;
}

// Pair container
#include <iostream>
using namespace std;

int main() {
  // pair<int , int> p ={1,5};
  // pair<int , string> p ={1,"Divesh"};
  pair<int, pair<int, string>> p = {
      1, {2, "Janhavi"}};  //>p used for one pair and >>p this used for two pair

  cout << p.first << endl;          // 1
  cout << p.second.first << endl;   // 2
  cout << p.second.second << endl;  // Janhavi
  return 0;
}
// Pair in a vector
#include <deque>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
  vector<pair<int, int>> vec = {{1, 2}, {2, 3}, {2, 4}, {4, 5}};
  // vec.push_back({{4,5}); // insert --->This can not work in pair of vector
  vec.emplace_back(6, 7);  // in-place object creats

  for (auto p : vec) {
    cout << p.first << " " << p.second << endl;
  }

  return 0;
}
// Stack container
#include <deque>
#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;

int main() {
  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  stack<int> s2;

  s2.swap(s);
  cout << "S Size: " << s.size() << endl;
  ;                                          // 0
  cout << "S2.size: " << s2.size() << endl;  // 4

  // cout<<"Top element: "<<s.top()<<endl; --->this used only one stack

  // while(!s.empty()){
  // cout<<s.top()<<" ";
  // s.pop();
  // s.top();-- > this not used at any time infinite loop run
  //}
  // cout<<endl;

  return 0;
}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);

  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;

  return 0;
}
// prioeity queue
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  priority_queue<int, vector<int>, greater<int>> q;

  q.push(5);
  q.push(3);
  q.push(10);
  q.push(4);

  while (!q.empty()) {
    cout << q.top() << " ";
    q.pop();
  }
  cout << endl;

  return 0;
}
//-----------MAP-------------#
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int main() {
  map<string, int> m;
  m["tv"] = 50;  //--->output is sorted order
  m["apple"] = 50;
  m["laptop"] = 100;
  m["laptop"] = 100;
  m["tablet"] = 50;
  m["watch"] = 120;
  // m.insert({"camera" , 25}) ;
  m.emplace("camera", 25);

  m.erase("tv");  // remove

  for (auto p : m) {
    cout << p.first << " " << p.second << endl;
  }

  if (m.find("tv") == m.end()) {
    cout << "found \n";
  } else {
    cout << "not_Found\n";
  }
  // cout<<"coutn= "<<m.count("laptop")<<endl;
  // cout<<"count : "<<m["laptop"]<<endl;
  return 0;
}
//-----------multimap-------------
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int main() {
  multimap<string, int> m;
  m.emplace("tv", 100);
  m.emplace("tv", 50);
  m.emplace("tv", 100);
  m.emplace("tv", 100);
  m.emplace("camera", 25);
  m.emplace("camera", 25);
  // m.erase("tv");   // remove
  m.erase(m.find("tv"));
  for (auto p : m) {
    cout << p.first << " " << p.second << endl;
  }
  return 0;
}
//-----------unordered_map-------------
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  unordered_map<string, int> m;
  // that way only return small value
  m.emplace("tv", 10);
  // m.emplace("tv" ,50);
  m.emplace("laptop", 50);
  // m.emplace("tv" ,200);
  // m.emplace("tv" ,20);
  // m.emplace("camera" , 25);
  m.emplace("mobile", 50);
  m.emplace("camera", 205);
  // m.erase("tv");   // remove
  // m.erase(m.find("tv"));
  for (auto p : m) {
    cout << p.first << " " << p.second << endl;
  }
  return 0;
}
//-----------set-------------
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  set<int> s;
  s.insert(1);
  s.insert(11);
  s.insert(111);
  s.insert(101);
  s.insert(1011);
  s.insert(100111);
  s.insert(1);
  s.insert(11);
  s.insert(111);
  cout << s.size() << endl;  // duplicate not allowed -->sorted order
  for (auto val : s) {
    cout << " " << val << " ";
  }
  cout << endl;
  return 0;
}
//-----------set-------------
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  set<int> s;
  s.insert(1);
  s.insert(2);
  s.insert(3);
  s.insert(4);
  s.insert(5);

  cout << "lower bound: " << *(s.lower_bound(4)) << endl;  // s.end()  --->0
  cout << "upper bound: " << *(s.upper_bound(4)) << endl;  // s.end()  --->0
  // cout<<s.size()<<endl; //duplicate not allowed -->sorted order
  for (auto val : s) {
    cout << " " << val << " ";
  }
  cout << endl;
  return 0;
}
//-----------multiset-------------
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  multiset<int> s;
  s.insert(1);
  s.insert(2);
  s.insert(3);
  s.insert(4);
  s.insert(5);
  s.insert(2);
  s.insert(3);
  s.insert(4);

  // cout<<s.size()<<endl; //duplicate not allowed -->sorted order
  for (auto val : s) {
    cout << " " << val << " ";
  }
  cout << endl;
  return 0;
}
//-------------Algorithms in STL----------------//
//----------custom comparator------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// This is a custom comparator
bool comparator(pair<int, int> p1, pair<int, int> p2) {
  if (p1.second < p2.second) return true;
  if (p1.second > p2.second) return false;

  if (p1.first < p2.first)
    return true;
  else
    return false;
}

int main() {
  // vector <int> vec = {3,5,4,2,1};
  vector<pair<int, int>> vec = {
      {3, 1},
      {2, 1},
      {1, 1},
      {6, 66}};  // pair sort on the basis of 1st element
  // but rquired to sort 2nd element to create custome comparator

  sort(vec.begin(), vec.end(),
       comparator);  // greater<int>() --->used descending order sort output
  for (auto p : vec) {
    cout << p.first << " " << p.second << endl;
  }
  cout << endl;
  return 0;
}
//-------Reverse---------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> vec = {1, 2, 3, 4, 5};
  // reverse(vec.begin(),vec.end());
  reverse(vec.begin() + 1, vec.begin() + 3);  // 2 and three only reverse

  for (auto val : vec) {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  // PERMUTATION
  // string s = "abc";
  // next_permutation(s.begin(),s.end());
  // prev_permutation(s.begin(),s.end());
  // cout<<s<<endl;

  // MIN MAX
  // cout<<max(4,5) <<" "<<min(6,10)<<endl;
  // SWAPE
  int a = 5;
  int b = 10;
  swap(a, b);
  cout << "a= " << a << "b= " << b << endl;

  return 0;
}
//--------------binary_functions, max_element , min_element-------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> vec = {1, 2, 3, 4, 5};
  cout << binary_search(vec.begin(), vec.end(), 4)
       << endl;  // output is 0 and one 1
                 // cout<<*(max_element(vec.begin(),vec.end())) <<endl;

  // cout<<*(min_element(vec.begin(),vec.end())) <<endl;

  // print all array element
  for (auto val : vec) {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}

//---------------Count Sort Algorithm-------------
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n1 = 15;
  long int n2 = 15;
  long long int n3 = 15;
  cout << __builtin_popcount(n1) << endl;
  cout << __builtin_popcountl(n2) << endl;   // l used for long
  cout << __builtin_popcountll(n3) << endl;  // l l used for long long long

  return 0;
}