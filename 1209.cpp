#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int valueOf(string& s) {
  int result = 0;

  for (int i = 1, sz = s.size(); i < sz; i++) {
    int dist = abs(s[i] - s[i-1]);

    if (result == 0) {
      result = dist;
    } else if (dist < result) {
      result = dist;
    }
  }

  return result;
}

int main(void)
{
  string input;
  pair<int, string> result;

  while (getline(cin, input)) {
    int count = 0;

    string a(input);
    result.first = valueOf(a);
    result.second = a;

    while (prev_permutation(a.begin(), a.end())) {
      count++;

      int tmpValue = valueOf(a);
      if (tmpValue >= result.first) {
        result.first = tmpValue;
        result.second = a;
      }

      if (count == 10) {
        break;
      }
    }

    count = 0;

    while (next_permutation(input.begin(), input.end())) {
      count++;

      int tmpValue = valueOf(input);
      if (tmpValue > result.first) {
        result.first = tmpValue;
        result.second = input;
      }

      if (count == 10) {
        break;
      }
    }

    cout << result.second << result.first << endl;
  }
  
  return 0;
}
