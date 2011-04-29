#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

bool theTruthIsOutThere(int a, int b) {
  if (a % m == b % m) {
    if (a % 2 == 0 && b % 2 == 0) {
      return a < b;
    } else if (a % 2 != 0 && b % 2 != 0) {
      return a > b;
    } else if (a % 2 == 0 && b % 2 != 0) {
      return false;
    } else if (a % 2 != 0 && b % 2 == 0) {
      return true;
    }
  }

  return a % m < b % m;
}

int main(void) {
  int nums[10001];

  while (cin >> n >> m) {
    for (int i = 0; i < n; i++)
      cin >> nums[i];

    sort(nums, nums + n, theTruthIsOutThere);

    cout << n << " " << m << endl;

    for (int i = 0; i < n; i++)
      cout << nums[i] << endl;
  }

  return 0;
}
