#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

int diff;

bool encoding_fits(const string &a, const string &b) {
  char c;
  string tmp(b);
  diff = 0;

  c = b[0];

  while (c != a[0]) {
    diff++;
    c++;
    if (c > 'z')
      c = 'a';
  }

  for (int i = 0, sz = b.size(); i < sz; i++) {
    if ((int)b[i] + diff > 122)
      tmp[i] = 'a' + b[i] + diff - 'z' - 1;
    else
      tmp[i] = b[i] + diff;
  }

  return tmp == a;
}

int main(void) {
  int n;
  string input;
  string word;
  vector<char> result;

  cin >> n;
  cin.ignore(100, '\n');

  while (n--) {
    getline(cin, input);
    cin >> word;
    cin.ignore(100, '\n');

    result.clear();

    stringstream ss;
    ss << input;

    while (ss >> input) {
      if (input.size() == word.size()) {
        if (encoding_fits(input, word)) {
          result.push_back('a' + diff);
        }
      }
    }

    sort(result.begin(), result.end());

    for (int i = 0, sz = result.size(); i < sz; i++) {
      cout << result[i];
    }
    cout << endl;
  }

  return 0;
}
