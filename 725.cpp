#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  int a, b;
  int n;
  bool first = true;
  int nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector< pair<int,int> > v[100];

  do {
    a = nums[0] * 10000 + nums[1] * 1000 + nums[2] * 100 + nums[3] * 10 + nums[4];
    b = nums[5] * 10000 + nums[6] * 1000 + nums[7] * 100 + nums[8] * 10 + nums[9];

    if (a % b == 0) {
      v[a/b].push_back(make_pair(a,b));
    }
  } while (next_permutation(nums, nums+10));

  while (cin >> n) {
    if (n == 0)
      break;

    if (!first)
      cout << endl;
    
    if (v[n].size() == 0) {
      cout << "There are no solutions for " << n << "." << endl;
    } else {
      for (int i = 0, sz = v[n].size(); i < sz; i++) {
        cout << v[n][i].first << " / " << (v[n][i].second < 10000 ? "0" : "") << v[n][i].second << " = " << n << endl;
      }
    }

    first = false;
  }

  return 0;
}
