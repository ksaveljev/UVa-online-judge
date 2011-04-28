#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

bool isprime(int n) {
  if (n == 2)
    return true;
  else if (n % 2 == 0)
    return false;

  for (int i = 3, sq = sqrt(n); i <= sq; i += 2)
    if (n % i == 0)
      return false;

  return true;
}

int reverse(int n) {
  int tmp = 0;

  while (n) {
    tmp = tmp * 10 + n % 10;
    n /= 10;
  }

  return tmp;
}

int main(void) {
  int n;
  bool *primes;

  primes = new bool[1000000];
  memset(primes, false, sizeof(bool)*1000000);

  primes[2] = true;
  for (int i = 3; i < 1000000; i += 2)
    primes[i] = isprime(i);


  while (cin >> n) {
    if (primes[n] == false) {
      cout << n << " is not prime." << endl;
    } else if (reverse(n) != n && primes[reverse(n)]) {
      cout << n << " is emirp." << endl;
    } else {
      cout << n << " is prime." << endl;
    }
  }


  delete [] primes;

  return 0;
}
