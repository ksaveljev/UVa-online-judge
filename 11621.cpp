#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int main(void) {
  unsigned long long m;
  set<unsigned long long> s;

  for (int i = 0; i < 32; i++) {
    for (int j = 0; j < 32; j++) {
      s.insert(pow(2, i) * pow(3, j));
    }
  }

  while (cin >> m) {
    if (!m)
      break;

    for (typeof(s.begin()) it = s.begin(); it != s.end(); it++) {
      if (*it >= m) {
        cout << *it << endl;
        break;
      }
    }
  }

  return 0;
}
