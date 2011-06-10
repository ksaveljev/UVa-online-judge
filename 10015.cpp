#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool is_prime (int n) {
  for (int i = 3, sq = sqrt(n); i <= sq; i += 2) {
    if (n % i == 0)
      return false;
  }
  return true;
}

vector<int> primes;

int survivor (int n) {
  int i, s;

  for (s = 0, i = 1; i <= n; i++) {
    s = (s + primes[n-i]) % i;
  }

  return s+1;
}

int main(void) {
  int n;

  primes.push_back(2);
  for (int i = 3; i < 100000; i += 2) {
    if (is_prime(i))
      primes.push_back(i);
  }

  while (cin >> n) {
    if (!n)
      break;

    cout << survivor(n) << endl;
  }

  return 0;
}
