#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int result[10001];

bool is_prime(int n) {
  for (int i = 3, sq = sqrt(n); i <= sq; i+=2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main(void)
{
  int n;

  for (int i = 0; i < 10001; i++) {
    result[i] = 0;
  }

  vector<int> primes;

  primes.push_back(2);
  for (int i = 3; i < 10001; i+=2) {
    if (is_prime(i)) {
      primes.push_back(i);
    }
  }

  for (int i = 0, sz = primes.size(); i < sz; i++) {
    for (int j = i; j < sz; j++) {
      int count = 0;
      for (int k = i; k < j; k++) {
        count += primes[k];
      }
      if (count < 10001) {
        result[count] += 1;
      }
    }
  }

  while (cin >> n) {
    if (!n) {
      break;
    }

    cout << result[n] << endl;
  }
  
  return 0;
}
