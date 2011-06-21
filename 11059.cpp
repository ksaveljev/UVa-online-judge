#include <iostream>
using namespace std;

int main(void) {
  int n;
  int nums[20];
  int casenum = 0;

  while (cin >> n) {
    casenum++;

    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    long long best = 0;
    for (int i = 0; i < n; i++) {
      long long current = 1;
      for (int j = i; j < n; j++) {
        current *= nums[j];
        if (current > best)
          best = current;
      }
    }

    cout << "Case #" << casenum << ": The maximum product is " << best << "." << endl;
    cout << endl;
  }

  return 0;
}
