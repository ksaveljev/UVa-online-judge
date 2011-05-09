#include <iostream>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

bool is_prime(long long n) {
  if (n < 2)
    return false;

  if (n == 2)
    return true;

  if (n % 2 == 0)
    return false;

  for (int i = 3, sq = sqrt(n); i <= sq; i += 2) {
    if (n % i == 0)
      return false;
  }

  return true;
}

int main(void) {
  vector<int> primes;
  long long n;

  primes.push_back(2);
  for (int i = 3; i < 1000000; i += 2)
    if (is_prime(i))
      primes.push_back(i);

  while (cin >> n) {
    if (n < 0)
      break;

    for (int i = 0, sz = primes.size(); i < sz; i++) {
      if (n == 1)
        break;

      if (is_prime(n)) {
        cout << "    " << n << endl;
        break;
      }

      while (n % primes[i] == 0) {
        cout << "    " << primes[i] << endl;
        n /= primes[i];
      }
    }

    cout << endl;
  }

  return 0;
}
