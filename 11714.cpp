#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
  unsigned long n;

  while (cin >> n) {
    n--;
    cout << n + (int)log2(n) << endl;
  }

  return 0;
}
