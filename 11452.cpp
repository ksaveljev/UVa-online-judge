#include <iostream>
#include <string>
using namespace std;

bool same(const string& s, int sz)
{
  for (int i = 0; i < sz; i++) {
    if (s[i] != s[sz+i]) {
      return false;
    }
  }

  for (int i = 2*sz; i < s.size(); i++) {
    if (s[i-2*sz] != s[i]) {
      return false;
    }
  }

  return true;
}

int main(void)
{
  int t;
  string input;

  cin >> t;

  while (t--) {
    cin >> input;

    int sz = input.size() / 2;

    do {
      if (same(input, sz)) {
        break;
      }
    } while (sz--);

    int cur = input.size() - 2 * sz;
    for (int i = 0; i < 8; i++) {
      cout << input[cur++];
      if (cur == sz) {
        cur = 0;
      }
    }

    cout << "..." << endl;
  }
  
  return 0;
}
