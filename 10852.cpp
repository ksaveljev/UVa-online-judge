#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool is_prime(int n) {
  for (int i = 3, sq = sqrt(n); i <= sq; i += 2) {
    if (n % i == 0)
      return false;
  }

  return true;
}

struct result {
  int p;
  int diff;
};

int main(void) {
  int t, n;
  vector<int> primes;
  result best;

  primes.push_back(2);
  for (int i = 3; i < 15000; i += 2)
    if (is_prime(i))
      primes.push_back(i);

  cin >> t;

  while (t--) {
    cin >> n;

    best.diff = 0;

    for (int i = 0, sz = primes.size(); primes[i] <= n; i++) {
      for (int p = 0; p * primes[i] <= n; p++) {
        if ((p+1) * primes[i] <= n)
          continue;

        if (n - primes[i] * p > best.diff) {
          best.p = primes[i];
          best.diff = n - primes[i] * p;
        }
      }
    }

    cout << best.p << endl;
  }

  return 0;
}
