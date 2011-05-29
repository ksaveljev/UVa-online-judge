#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
  int t;
  int results[7];

  cin >> t;

  for (int casenum = 0; casenum < t; casenum++) {
    for (int i = 0; i < 7; i++)
      cin >> results[i];

    sort(results + 4, results + 7);

    double sum = results[0] + results[1] + results[2] + results[3] + (results[5] + results[6]) / 2.0;

    cout << "Case " << casenum+1 << ": ";
    if (sum >= 90) {
      cout << "A" << endl;
    } else if (sum >= 80) {
      cout << "B" << endl;
    } else if (sum >= 70) {
      cout << "C" << endl;
    } else if (sum >= 60) {
      cout << "D" << endl;
    } else {
      cout << "F" << endl;
    }
  }

  return 0;
}
