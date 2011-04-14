#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

int gcd2(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

int gcd(int a, int b) {
  int shift;
  int diff;

  if (a == 0 || b == 0)
    return a | b;

  for (shift = 0; ((a | b) & 1) == 0; shift++) {
    a >>= 1;
    b >>= 1;
  }

  while ((a & 1) == 0)
    a >>= 1;

  do {
    while ((b & 1) == 0)
      b >>= 1;

    if (a < b) {
      b -= a;
    } else {
      diff = a - b;
      a = b;
      b = diff;
    }
    b >>= 1;
  } while (b != 0);

  return a << shift;
}

int main(void) {
  int n, m;
  int tmp;
  int best;
  int nums[110];
  string input;

  cin >> n;
  getline(cin, input); // \n

  while (n--) {
    m = 0;
    best = 0;

    stringstream ss;
    getline(cin, input);
    ss << input;


    while (ss >> nums[m]) {
      m++;
    }

    for (int i = 0; i < m - 1; i++) {
      for (int j = i + 1; j < m; j++) {
        tmp = gcd(nums[i], nums[j]);
        if (tmp > best)
          best = tmp;
      }
    }

    cout << best << endl;
  }

  return 0;
}
