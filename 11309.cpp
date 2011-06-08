#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
using namespace std;

bool is_palindrome(int h, int m) {
  stringstream ss;

  if (h == 0) {
    if (m > 0)
      ss << m;
  } else {
    ss << h;
    if (m < 10)
      ss << 0;
    ss << m;
  }

  string a = ss.str();
  string b(a.rbegin(), a.rend());

  return a == b;
}

int main(void) {
  int n;
  int h, m;
  char c;

  cin >> n;

  while (n--) {
    cin >> h >> c >> m;

    for (int i = h; i < 24; i++) {
      for (int j = m + 1; j < 60; j++) {
        if (is_palindrome(i, j)) {
          printf("%02d:%02d\n", i, j);
          j = 60;
          i = 30;
        }
      }

      if (i == 23)
        i = -1; // next H will be 0

      m = -1;
    }
  }

  return 0;
}
