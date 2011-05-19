#include <iostream>
#include <string>
using namespace std;

string transform(const string &s) {
  string result = "";

  if (s.size() == 0)
    return result;


  char c = s[0];
  int counter = 0;

  for (int i = 1, sz = s.size(); i < sz; i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      counter = counter * 10 + int(s[i] - '0');
    } else {
      for (int j = 0; j < counter; j++) {
        result += c;
      }
      counter = 0;
      c = s[i];
    }
  }

  for (int j = 0; j < counter; j++)
    result += c;

  return result;
}

int main(void) {
  int t;
  string input;

  cin >> t;
  cin.ignore(100, '\n');

  for (int casenum = 0; casenum < t; casenum++) {
    getline(cin, input);

    cout << "Case " << casenum+1 << ": " << transform(input) << endl;
  }

  return 0;
}
