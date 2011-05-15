#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int bin2dec(const string &s) {
  int counter = 0;
  int result = 0;

  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == '1') {
      result += (int)pow(2, counter);
    }

    counter++;
  }

  return result;
}

int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

int main(void) {
  int n, a, b;
  string input;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> input;
    a = bin2dec(input);
    cin >> input;
    b = bin2dec(input);

    cout << "Pair #" << i+1 << ": ";
    if (gcd(a, b) > 1) {
      cout << "All you need is love!" << endl;
    } else {
      cout << "Love is not all you need!" << endl;
    }
  }

  return 0;
}
