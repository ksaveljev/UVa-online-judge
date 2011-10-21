#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(unsigned long long n) {
  if (n == 2)
    return true;
  
  if (n % 2 == 0)
    return false;

  for (int i = 3, sq = sqrt(n); i <= sq; i += 2)
    if (n % i == 0)
      return false;

  return true;
}

// a ^ k mod n
unsigned int calc(unsigned long long a, long long k, long long n) {
  if (k == 1)
    return a;

  if (k % 2 == 0)
    return calc((a * a) % n, k / 2, n);
  else
    return (a * calc((a * a) % n, k / 2, n)) % n;
}

int main(void) {
  unsigned long long p, a;

  while (cin >> p >> a) {
    if (p == 0 && a == 0) {
      break;
    }

    if ((calc(a, p, p) == a) && !is_prime(p)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }

  return 0;
}
