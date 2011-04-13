#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
  int n;
  int m;
  int total, target;
  int coins[110];
  int **dp;

  dp = new int*[110];
  for (int i = 0; i < 110; i++) {
    dp[i] = new int[25010];
  }

  cin >> n;

  while (n--) {
    total = 0;
    for (int i = 0; i < 110; i++)
      memset(dp[i], 0, 25010*sizeof(int));

    cin >> m;

    for (int i = 0; i < m; i++) {
      cin >> coins[i];
      total += coins[i];
    }


    target = total / 2;

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= target; j++) {
        if (coins[i-1] > j) {
          dp[i][j] = dp[i-1][j];
          continue;
        }

        dp[i][j] = max(dp[i-1][j], dp[i-1][j-coins[i-1]] + coins[i-1]);
      }
    }

    cout << total - dp[m][target] * 2 << endl;
  }


  for (int i = 0; i < 110; i++)
    delete [] dp[i];

  delete [] dp;


  return 0;
}
