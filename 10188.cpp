#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string numeric(const vector<string> &v) {
  stringstream ss;

  for (int i = 0, sz = v.size(); i < sz; i++) {
    for (int j = 0, sz2 = v[i].size(); j < sz2; j++) {
      if (v[i][j] >= '0' && v[i][j] <= '9')
        ss << v[i][j];
    }
  }

  return ss.str();
}

int main(void) {
  int a, b;
  int counter = 0;
  string input;
  vector<string> correct, answer;

  while (cin >> a) {
    if (!a)
      break;

    counter++;

    correct.clear();
    answer.clear();

    cin.ignore(100, '\n');

    for (int i = 0; i < a; i++) {
      getline(cin, input);
      correct.push_back(input);
    }

    cin >> b;
    cin.ignore(100, '\n');
    for (int i = 0; i < b; i++) {
      getline(cin, input);
      answer.push_back(input);
    }

    cout << "Run #" << counter << ": ";

    if (a == b) {
      bool ok = true;
      for (int i = 0; i < a; i++) {
        if (correct[i] != answer[i]) {
          ok = false;
          break;
        }
      }

      if (ok) {
        cout << "Accepted" << endl;
        continue;
      }
    }

    if (numeric(correct) == numeric(answer)) {
      cout << "Presentation Error" << endl;
      continue;
    }

    cout << "Wrong Answer" << endl;
  }

  return 0;
}
