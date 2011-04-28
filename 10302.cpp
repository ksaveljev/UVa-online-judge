#include <iostream>
using namespace std;

int main(void) {
  int n;
  unsigned long long *sum;

  sum = new unsigned long long[50001];

  sum[1] = 1;

  for (unsigned long long i = 2; i < 50001; i++) {
    sum[i] = sum[i-1] + i * i * i;
  }

  while (cin >> n) {
    cout << sum[n] << endl;
  }

  delete [] sum;

  return 0;
}
