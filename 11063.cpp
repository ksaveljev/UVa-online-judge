#include <iostream>
#include <map>
using namespace std;

bool good_properties(int *nums, int n) {
  if (nums[0] < 1)
    return false;

  for (int i = 1; i < n; i++) {
    if (nums[i] <= nums[i-1])
      return false;
  }

  return true;
}

int main(void) {
  int nums[101];
  int n;
  map<int,bool> visited;
  int casenum = 0;

  while (cin >> n) {
    visited.clear();
    casenum++;
    bool ok = true;

    for (int i = 0; i < n; i++)
      cin >> nums[i];

    if (!good_properties(nums, n)) {
      ok = false;
    }

    if (ok) {
      for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
          if (visited.find(nums[i]+nums[j]) == visited.end()) {
            visited[nums[i] + nums[j]] = true;
          } else {
            ok = false;
            i = n;
            break;
          }
        }
      }
    }

    if (ok) {
      cout << "Case #" << casenum << ": It is a B2-Sequence." << endl;
    } else {
      cout << "Case #" << casenum << ": It is not a B2-Sequence." << endl;
    }
    cout << endl;
  }

  return 0;
}
