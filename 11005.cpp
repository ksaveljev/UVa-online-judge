#include <iostream>
#include <string>
#include <vector>
using namespace std;

int VALUES[36];
string NUMS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string convert(long long n, int base) {
  if (n == 0)
    return "0";

  string result = "";

  do {
    result.push_back(NUMS[n % base]);
    n /= base;
  } while (n);

  return string(result.rbegin(), result.rend());
}

int count_value(string& s) {
  int result = 0;
  size_t found;

  for (int i = 0, sz = s.size(); i < sz; i++) {
    found = NUMS.find(s[i]);
    result += VALUES[int(found)];
  }

  return result;
}

int main(void) {
  int cases, queries, n;
  vector<int> result;
  int best;

  cin >> cases;

  for (int case_num = 0; case_num < cases; case_num++) {
    if (case_num > 0) {
      cout << endl;
    }

    for (int i = 0; i < 36; i++) {
      cin >> VALUES[i];
    }

    cin >> queries;

    cout << "Case " << case_num + 1 << ":" << endl;

    while (queries--) {
      cin >> n;

      best = -1;

      for (int i = 2; i < 37; i++) {
        string converted = convert(n, i);
        int tmp = count_value(converted);

        if (best == -1 || tmp < best) {
          result.clear();
          result.push_back(i);
          best = tmp;
        } else if (tmp == best) {
          result.push_back(i);
        }
      }

      cout << "Cheapest base(s) for number " << n << ":";
      for (int i = 0, sz = result.size(); i < sz; i++) {
        cout << " " << result[i];
      }
      cout << endl;
    }
  }

  return 0;
}
