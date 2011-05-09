#include <iostream>
using namespace std;

struct result {
  int value;
  int start;
  int end;
  result() : value(-2000000000), start(0), end(0) {}
};

int main(void) {
  int cases;
  int roads[20001];
  int busstops;

  cin >> cases;

  for (int c = 1; c <= cases; c++) {
    cin >> busstops;

    for (int i = 0; i < busstops - 1; i++)
      cin >> roads[i];

    result best;
    //maxSum = -2000000000;
    //maxStartIndex = 0;
    //maxEndIndex = 0;

    result current;
    current.value = 0;
    //currentMaxSum = 0;
    //currentStartIndex = 0;

    for (current.end= 0; current.end < busstops - 1; current.end++) {
      current.value += roads[current.end];
      if (current.value > best.value) {
        best.value = current.value;
        best.start = current.start;
        best.end = current.end;
      } else if (current.value == best.value) {
        if (current.end - current.start > best.end - best.start) {
          best.value = current.value;
          best.start = current.start;
          best.end = current.end;
        }
      }

      if (current.value < 0) {
        current.value = 0;
        current.start = current.end + 1;
      }
    }

    if (best.value <= 0) {
      cout << "Route " << c << " has no nice parts" << endl;
    } else {
      cout << "The nicest part of route " << c << " is between stops " << best.start + 1 << " and " << best.end + 2 << endl;
    }
  }

  return 0;
}
