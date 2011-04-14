#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
  int t;
  unsigned long long result;
  int price, counter;
  int lands[50];

  cin >> t;

  while (t--) {
    counter = 0;
    result = 0;

    while (cin >> price) {
      if (price == 0)
        break;
      lands[counter] = price;
      counter++;
    }

    sort(lands, lands + counter, greater<int>());

    for (int i = 0; i < counter; i++) {
      result += 2 * pow(lands[i], i+1);
      if (result > 5000000)
        break;
    }

    if (result > 5000000)
      cout << "Too expensive" << endl;
    else
      cout << result << endl;
  }

  return 0;
}
