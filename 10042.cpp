#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool is_prime(int n) {
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

int digitsum(int n) {
  int result = 0;

  while (n) {
    result += n % 10;
    n /= 10;
  }

  return result;
}

int main(void) {
  int t, n, tmp;
  int sum1, sum2;
  vector<int> primes;

  primes.push_back(2);
  for (int i = 3; i < 35000; i += 2) {
    if (is_prime(i))
      primes.push_back(i);
  }

  cin >> t;

  while (t--) {
    cin >> n;

    while (++n) {
      if (is_prime(n))
        continue;

      sum1 = digitsum(n);

      tmp = n;
      sum2 = 0;
      for (int i = 0, sz = primes.size(); i < sz; i++) {
        if (tmp == 1 || is_prime(tmp)) {
          if (tmp != 1)
            sum2 += digitsum(tmp);
          break;
        }

        if (tmp % primes[i] == 0) {
          while (tmp % primes[i] == 0) {
            sum2 += digitsum(primes[i]);
            tmp /= primes[i];
          }
        }
      }

      if (sum1 == sum2) {
        cout << n << endl;
        break;
      }
    }
  }

  return 0;
}
