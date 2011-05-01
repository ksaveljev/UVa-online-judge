#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool prefix(const string &a, const string &b) {
  int sz = min(a.size(), b.size());
  for (int i = 0; i < sz; i++) {
    if (a[i] != b[i])
      return false;
  }
  return true;
}

int main(void) {
  bool ok;
  int cases;
  int numbers;
  string input;
  vector<string> nums;

  cin >> cases;

  while (cases--) {
    nums.clear();

    cin >> numbers;
    cin.ignore(100, '\n');

    ok = true;
    for (int i = 0; i < numbers; i++) {
      getline(cin, input);

      if (!ok)
        continue;

      for (int j = 0, sz = nums.size(); j < sz; j++) {
        if (prefix(input, nums[j])) {
          ok = false;
          break;
        }
      }

      nums.push_back(input);
    }

    if (ok)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}
