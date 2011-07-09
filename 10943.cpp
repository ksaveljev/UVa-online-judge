#include <iostream>
using namespace std;

int memo[101][101];

int solve(int n, int k) {
  unsigned long long result = 0;

  if (k == 1) {
    return 1;
  }

  if (memo[n][k] != -1) {
    return memo[n][k];
  }

  for (int i = 0; i <= n; i++) {
    memo[n - i][k - 1] = solve(n - i, k - 1);
    result += memo[n-i][k - 1];
  }

  return result % 1000000;
}

int main(void)
{
  int n, k;

  while (cin >> n >> k) {
    if (!n && !k) {
      break;
    }

    for (int i = 0; i < 101; i++) {
      for (int j = 0; j < 101; j++) {
        memo[i][j] = -1;
      }
    }

    cout << solve(n, k) << endl;
  }
  
  return 0;
}
