// 28 string
//-----------INPUT OUTPUT used GETLINE in charecter-------------
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  // char str [100] = {'a','b''c'}
  char str[12];  //-->This is valid  used always \0
  // cout<<str<<endl;
  cout << "Enter char array: ";
  cin.getline(str, 100);

  // cout<<"output: "<<str<<endl;  -->simple output used

  for (char ch : str) {
    cout << ch << " ";
  }
  cout << endl;

  // cout<<strlen(str)<<endl;

  return 0;
}
//-----------length-------------
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  char str[] = "Appna college";
  int len = 0;

  for (int i = 0; i < str[i] != '\0'; i++) {
    len++;
  }
  cout << "length of string: " << len << endl;
  return 0;
}

#include <cstring>
#include <iostream>
using namespace std;

int main() {
  string str = "Divesh Kuthe.";  // It is dynamic  in nature ==> Run time pr
                                 // resize hote hai
  // string str;
  // getline(cin,str);
  // cout<<"output: "<<str<<endl;
  // cout<<str1.length()<<endl;
  // string str2 = "Kuthe";
  // string str3 = str1+str2; // Concatination

  // cout<<(str1 < str2)<<endl;  //1 = True ,0 = False

  // cout<<str3<<endl;

  // for(int i = 0;i<str.length();i++){
  //   cout<<str[i];
  //}

  // for Each loop
  for (char ch : str) {
    cout << ch << " ";
  }
  cout << endl;

  return 0;
}
//----------REVERSE A STRING-------------
// 1) Charecter reverse
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  // char ch[] = {'d','i','v','e','s','h','\0'};
  char ch[100];
  cout << "Enter Any Charecter to reverse: ";
  cin.getline(ch, 100);
  int st = 0;
  int end = strlen(ch) - 1;

  while (st < end) {
    swap(ch[st++], ch[end--]);
  }
  cout << "Output is: " << ch << endl;

  return 0;
}
// string reverse
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  string str = "Divesh Kuthe.";
  reverse(str.begin(), str.end());
  cout << str << endl;
  return 0;
}