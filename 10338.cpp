#include <iostream>
#include <string>
#include <vector>
using namespace std;

unsigned long long factorial(int n) {
  unsigned long long result = 1;

  for (int i = 2; i <= n; i++)
    result *= i;

  return result;
}

int main(void) {
  int n;
  string input;
  vector< pair<char,int> > v;

  cin >> n;
  cin.ignore(100, '\n');

  for (int cases = 1; cases <= n; cases++) {
    v.clear();

    getline(cin, input);

    for (int i = 0, sz = input.size(); i < sz; i++) {
      bool found = false;
      for (int j = 0, sz2 = v.size(); j < sz2; j++) {
        if (v[j].first == input[i]) {
          found = true;
          v[j].second++;
          break;
        }
      }

      if (!found) {
        v.push_back(make_pair(input[i], 1));
      }
    }

    unsigned long long tmp = factorial(input.size());
    unsigned long long rep = 1;

    for (int i = 0, sz = v.size(); i < sz; i++) {
      if (v[i].second > 1) {
        rep *= factorial(v[i].second);
      }
    }

    cout << "Data set " << cases << ": " << tmp / rep << endl;
  }

  return 0;
}
