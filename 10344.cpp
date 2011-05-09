#include <iostream>
#include <vector>
using namespace std;

int nums[5];
vector<int> v(9);
bool taken[5];

bool solve(int depth) {
  if (depth == 5) {
    long tmp = v[0];
    int a, action;

    for (int i = 1; i < 9; i += 2) {
      a = v[i];
      action = v[i+1];

      if (action == 1) {
        tmp += a;
      } else if (action== 2) {
        tmp -= a;
      } else if (action == 3) {
        tmp *= a;
      }
    }

    return (tmp == 23 ? true : false);
  }

  bool result;

  if (depth == 0) {
    for (int i = 0; i < 5; i++) {
      v[0] = nums[i];
      taken[i] = true;
      result = solve(1);
      if (result)
        return true;
      taken[i] = false;
    }
  } else {
    for (int i = 0; i < 5; i++) {
      if (taken[i])
        continue;

      taken[i] = true;
      v[depth * 2 - 1] = nums[i];

      v[depth*2] = 1; // +
      result = solve(depth+1);
      if (result)
        return true;

      v[depth*2] = 2; // -
      result = solve(depth+1);
      if (result)
        return true;

      v[depth*2] = 3; // *
      result = solve(depth+1);
      if (result)
        return true;

      taken[i] = false;
    }
  }
}

int main(void) {
  while (cin >> nums[0] >> nums[1] >> nums[2] >> nums[3] >> nums[4]) {
    if (nums[0] == 0 && nums[1] == 0 && nums[2] == 0 && nums[3] == 0 && nums[4] == 0)
      break;

    for (int i = 0; i < 5; i++)
      taken[i] = false;

    if (solve(0)) {
      cout << "Possible" << endl;
    } else {
      cout << "Impossible" << endl;
    }
  }

  return 0;
}
