#include <iostream>
using namespace std;

string isPrime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return "non prime";
    }
  }
  return "prime";
}
int main() {
  int n = 42;
  cout << "Number is: " << isPrime(n) << endl;
  return 0;
}
// count of the prime number
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int countPrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    int count = 0;
    for (int i = 2; i < n; i++) {
      if (isPrime[i]) {
        count++;
        for (int j = i * 2; j < n; j = j + i) {
          isPrime[j] = false;
        }
      }
    }
    return count;
  }
};
int main() {
  Solution sol;
  int n = 50;
  cout << "No.of count: " << sol.countPrimes(n) << endl;
  return 0;
}
// Digit in a number

#include <iostream>
using namespace std;

void printDigit(int n) {
  // int count = 0;
  int sum = 0;
  while (n != 0) {
    int digit = n % 10;
    // count++;
    sum = sum + digit;
    cout << digit << endl;

    n = n / 10;
  }
  // cout<<"Count is: "<<count<<endl;
  cout << "Sum of digit is: " << sum << endl;
}
int main() {
  int n = 4212;
  printDigit(n);

  return 0;
}
// Armstrong number
#include <iostream>
using namespace std;
bool isArmstrong(int n) {
  int copyN = n;
  int sumofCubes = 0;

  while (n != 0) {
    int dig = n % 10;
    sumofCubes += (dig * dig * dig);

    n = n / 10;
  }
  return sumofCubes == copyN;
}
int main() {
  int n = 4212;
  if (isArmstrong(n)) {
    cout << "this is an Armstrong no!!\n";
  } else {
    cout << "This is NOT an Armstrong no!!";
  }

  return 0;
}
// GCD of two numbers

#include <iostream>
using namespace std;
int gcd(int a, int b) {
  while (a > 0 && b > 0) {
    if (a > b) {
      a = a % b;
    } else {
      b = b % a;
    }
  }
  if (a == 0) return b;
  return a;
}
int main() {
  cout << gcd(20, 28);

  return 0;
}
// Lcm
#include <iostream>
using namespace std;
int gcdRec(int a, int b) {
  if (b == 0) return a;
  return gcdRec(b, a % b);
}
int lcm(int a, int b) {
  int gcd = gcdRec(a, b);
  return (a * b) / gcd;
}
int main() {
  cout << "lcm Of this Number is: " << lcm(20, 28) << endl;
  return 0;
}