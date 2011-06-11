#include <iostream>
#include <algorithm>
using namespace std;

bool primes[1000001];

void sieve() {
  fill(primes, primes + 1000001, true);

  for (int i = 2; i < 1002; i++) {
    for (int j = i * i; j < 1000001; j += i)
      primes[j] = false;
  }

  primes[0] = primes[1] = false;
}

int main(void) {
  int n;

  sieve();

  while (cin >> n) {
    int last;

    if (n == 0)
      break;

    if (n % 2 == 0)
      last = n - 1;
    else
      last = n - 2;

    cout << n << ":" << endl;

    if (primes[n-2]) {
      cout << 2 << "+" << n-2 << endl;
      continue;
    }

    bool found = false;
    while (n - last <= last) {
      if (primes[last] && primes[n - last]) {
        cout << n - last << "+" << last << endl;
        found = true;
        break;
      }
      last -= 2;
    }

    if (!found)
      cout << "NO WAY!" << endl;
  }

  return 0;
}
