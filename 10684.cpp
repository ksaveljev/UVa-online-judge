#include <iostream>
using namespace std;

struct result {
  int value;
  int start;
  int end;
  result() : value(-2000000000), start(0), end(0) {}
};

int main(void) {
  int n;
  int nums[10001];

  while (cin >> n) {
    if (n == 0)
      break;

    for (int i = 0; i < n; i++)
      cin >> nums[i];

    result best;
    result current;

    current.value = 0;

    for (current.end = 0; current.end < n; current.end++) {
      current.value += nums[current.end];
      if (current.value > best.value) {
        best.value = current.value;
        best.start = current.start;
        best.end = current.end;
      }

      if (current.value < 0) {
        current.value = 0;
        current.start = current.end + 1;
      }
    }

    if (best.value <= 0) {
      cout << "Losing streak." << endl;
    } else {
      cout << "The maximum winning streak is " << best.value << "." << endl;
    }
  }

  return 0;
}
