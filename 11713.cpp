#include <iostream>
#include <string>
using namespace std;

bool isvowel(char c) {
  return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u';
}

bool same(const string &str1, const string &str2) {
  if (str1.size() != str2.size())
    return false;

  for (int i = 0, sz = str1.size(); i < sz; i++) {
    if (str1[i] != str2[i]) {
      if (!isvowel(str1[i]) || !isvowel(str2[i]))
        return false;
    }
  }

  return true;
}

int main(void) {
  int n;
  string str1, str2;

  cin >> n;
  cin.ignore(100, '\n');

  while (n--) {
    getline(cin, str1);
    getline(cin, str2);

    if (same(str1, str2))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}
