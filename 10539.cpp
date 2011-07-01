#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

unsigned long long LIMIT = 1000000000000L;
vector<long long> almost;

void generate_almost_primes(int n)
{
  unsigned long long tmp = (unsigned long long)n * (unsigned long long)n;

  while (tmp < LIMIT) {
    almost.push_back(tmp);
    tmp *= n;
  }
}

bool is_prime(int n) {
  for (int i = 3, sq = sqrt(n); i <= sq; i++) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

int main(void)
{
  int t;
  long long low, high;

  generate_almost_primes(2);
  for (int i = 3; i < 1000000; i+=2) {
    if (is_prime(i)) {
      generate_almost_primes(i);
    }
  }
  
  cin >> t;

  int sz = almost.size();

  while (t--) {
    cin >> low >> high;

    int result = 0;

    for (int i = 0; i < sz; i++) {
      if (almost[i] >= low && almost[i] <= high) {
        result++;
      }
    }

    cout << result << endl;
  }
  
  return 0;
}
