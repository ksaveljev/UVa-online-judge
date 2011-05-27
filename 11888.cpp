#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(const string &s, int start, int end) {
  int sz = end - start + 1;

  if (sz % 2 == 0) {
    int middle = start + sz/2;
    int i;
    for (i = 0; middle - 1 - i >= 0 && middle+i <= end && s[middle-1-i] == s[middle+i]; i++);
    if (middle - i - 1 < 0 || middle+i > end)
      return true;
  } else {
    int middle = start + sz/2;
    int i;
    for (i = 1; middle - i >= 0 && middle+i <= end && s[middle-i]==s[middle+i]; i++);
    if (middle - i < 0 || middle+i > end)
      return true;
  }

  return false;
}

bool is_alindrome(const string &s) {
  for (int i = 0, sz = s.size(); i < sz - 1; i++) {
    if (is_palindrome(s, 0, i) && is_palindrome(s, i + 1, sz - 1))
      return true;
  }

  return false;
}

int main(void) {
  int cases;
  string input;

  cin >> cases;
  cin.ignore(100, '\n');

  while (cases--) {
    getline(cin, input);

    if (input.size() == 0) {
      cout << "simple" << endl;
      continue;
    }

    if (is_alindrome(input)) {
      cout << "alindrome" << endl;
    } else if (is_palindrome(input, 0, input.size() - 1)) {
      cout << "palindrome" << endl;
    } else {
      cout << "simple" << endl;
    }
  }

  return 0;
}
