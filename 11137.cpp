#include <iostream>
using namespace std;

int main(void) {
  int n;
  int coins[22];
  long dp[22][10010];

  for (int i = 0; i < 22; i++)
    coins[i] = i * i * i;

  for (int i = 0; i < 10001; i++)
    dp[0][i] = 0;

  for (int i = 0; i < 22; i++)
    dp[i][0] = 1;

  for (int i = 1; i < 22; i++) {
    for (int j = 1; j <= 10000; j++) {
      if (j < coins[i]) {
        dp[i][j] = dp[i-1][j];
        continue;
      }

      dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];
    }

  }

  while (cin >> n) {
    cout << dp[21][n] << endl;
  }

  return 0;
}
