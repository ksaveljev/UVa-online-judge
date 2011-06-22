#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool is_runaround(int n) {
  int nums[10];
  bool visited[10] = {false};

  int sz = log10(n) + 1;

  for (int i = sz - 1; i >= 0; i--) {
    nums[i] = n % 10;
    if (nums[i] == 0)
      return false;
    n /= 10;
  }

  for (int i = 0; i < sz; i++)
    for (int j = i + 1; j < sz; j++)
      if (nums[i] == nums[j])
        return false;

  int tmp = nums[0];
  int pos = 0;
  int last = 0;
  while (true) {
    while (tmp--) {
      pos++;
      if (pos >= sz)
        pos = 0;
    }

    if (visited[pos]) {
      if (last != 0)
        break;
      break;
    }

    visited[pos] = true;
    tmp = nums[pos];
    last = pos;
  }

  for (int i = 0; i < sz; i++)
    if (!visited[i])
      return false;

  return true;
}

int main(void) {
  int n, casenum = 0;
  vector<int> runaround;

  for (int i = 11; i < 10000000; i++) {
    if (is_runaround(i))
      runaround.push_back(i);
  }

  while (cin >> n) {
    if (!n)
      break;
    
    casenum++;

    for (int i = 0, sz = runaround.size(); i < sz; i++) {
      if (runaround[i] >= n) {
        cout << "Case " << casenum << ": " << runaround[i] << endl;
        break;
      }
    }
  }

  return 0;
}
