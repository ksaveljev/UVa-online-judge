#include <iostream>
using namespace std;

int main(void) {
  int n1, n2;
  int counter = 0;
  int towers[2][101];
  int dp[101][101];

  while (cin >> n1 >> n2) {
    if (n1 == 0 && n2 == 0)
      break;

    counter++;

    for (int i = 0; i <= n1; i++)
      dp[i][0] = 0;

    for (int j = 0; j <= n2; j++)
      dp[0][j] = 0;

    for (int i = 0; i < n1; i++)
      cin >> towers[0][i];

    for (int i = 0; i < n2; i++)
      cin >> towers[1][i];

    for (int i = 1; i <= n1; i++) {
      for (int j = 1; j <= n2; j++) {
        if (towers[0][i-1] == towers[1][j-1])
          dp[i][j] = dp[i-1][j-1] + 1;
        else
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }

    cout << "Twin Towers #" << counter << endl;
    cout << "Number of Tiles : " << dp[n1][n2] << endl;
    cout << endl;
  }

  return 0;
}
