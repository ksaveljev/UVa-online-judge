#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(void) {
  int t;
  string input;
  char c;

  cin >> t;
  cin.ignore(100, '\n');

  for (int casenum = 0; casenum < t; casenum++) {
    cout << "Case #" << casenum+1 << ":" << endl;

    input = "";
    while (cin.peek() != '\n' && cin.peek() != -1) {
      cin >> c;

      if (c >= 'a' && c <= 'z')
        input += c;
    }
    cin.ignore(100, '\n');

    int sq = sqrt(input.size());

    if (sq * sq != input.size()) {
      cout << "No magic :(" << endl;
      continue;
    }

    if (input != string(input.rbegin(), input.rend())) {
      cout << "No magic :(" << endl;
      continue;
    }

    string tmp = "";

    for (int i = 0; i < sq; i++) {
      for (int j = 0; j < sq; j++) {
        tmp += input[i + j*sq];
      }
    }

    if (tmp != input) {
      cout << "No magic :(" << endl;
      continue;
    }

    cout << sq << endl;
  }

  return 0;
}
