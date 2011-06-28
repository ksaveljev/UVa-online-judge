#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct constraint {
  int friend1;
  int friend2;
  int c;
};

bool satisfying(int nums[8], int n, const vector<constraint> &constraints)
{
  int pos[8];
  int diff;

  for (int i = 0; i < n; i++) {
    pos[nums[i]] = i;
  }

  for (int i = 0, sz = constraints.size(); i < sz; i++) {
    diff = abs(pos[constraints[i].friend1] - pos[constraints[i].friend2]);

    if (constraints[i].c < 0) {
      if (diff < abs(constraints[i].c)) {
        return false;
      }
    } else {
      if (diff > abs(constraints[i].c)) {
        return false;
      }
    }
  }

  return true;
}

int main(void)
{
  int n, m;
  int result;
  int nums[8];
  constraint tmp;
  vector<constraint> constraints;

  while (cin >> n >> m) {
    if (!n && !m) {
      break;
    }

    result = 0;
    constraints.clear();

    for (int i = 0; i < 8; i++) {
      nums[i] = i;
    }

    while (m--) {
      cin >> tmp.friend1 >> tmp.friend2 >> tmp.c;
      constraints.push_back(tmp);
    }

    do {
      if (satisfying(nums, n, constraints)) {
        result++;
      }
    } while (next_permutation(nums, nums + n));

    cout << result << endl;
  }

  return 0;
}
