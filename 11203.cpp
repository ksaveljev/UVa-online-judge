#include <iostream>
#include <string>
using namespace std;

bool validate(const string &s) {
  int m = -100, e = -100;
  bool m_q = false;
  bool e_q = false;

  for (int i = 0, sz = s.size(); i < sz; i++) {
    if (s[i] != '?' && s[i] != 'M' && s[i] != 'E')
      return false;

    if (i == 0 && s[i] != '?')
      return false;

    if (i == e+1) {
      if (s[i] == '?')
        e_q = true;
    } else if (i == m+1) {
      if (s[i] == '?')
        m_q = true;
    }

    if (s[i] == 'M') {
      if (m >= 0)
        return false;
      
      m = i;
    } else if (s[i] == 'E') {
      if (e >= 0)
        return false;

      e = i;
    }
  }

  if (!m || !e || !m_q || !e_q)
    return false;

  int x = m;
  int y = e - m - 1;
  int z = s.size() - (e+1);

  if (y != z - x)
    return false;

  return true;
}

int main(void) {
  int n;
  string input;

  cin >> n;
  cin.ignore(100, '\n');

  while (n--) {
    getline(cin, input);

    if (!validate(input)) {
      cout << "no-theorem" << endl;
    } else {
      cout << "theorem" << endl;
    }
  }

  return 0;
}
