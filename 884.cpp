#include <iostream>
#include <cmath>
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

int main(void) {
  int n;
  int *f = new int[1000001];
  int *dp = new int[1000001];

  f[1] = 0;
  f[2] = 1;
  f[3] = 1;

  for (int i = 4; i < 1000001; i++) {
    if (i % 2 == 0) {
      f[i] = 1 + f[i/2];
      continue;
    }

    if (is_prime(i)) {
      f[i] = 1;
    } else {
      for (int j = 3, sq = sqrt(i); j <= sq; j += 2) {
        if (i % j == 0) {
          f[i] = f[j] + f[i/j];
          break;
        }
      }
    }
  }

  dp[1] = 0;
  for (int i = 2; i < 1000001; i++) {
    dp[i] = dp[i-1] + f[i];
  }

  while (cin >> n) {
    cout << dp[n] << endl;
  }

  delete [] dp;
  delete [] f;

  return 0;
}
