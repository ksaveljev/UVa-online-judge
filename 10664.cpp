#include <iostream>
using namespace std;

int main(void)
{
  int t;
  int dp[21][101];
  int items[20];
  
  cin >> t;
  cin.ignore(100, '\n');

  while (t--) {
    int counter = 0;
    int sum = 0;

    for (int i = 0; i < 21; i++) {
      dp[i][0] = 0;
    }

    for (int i = 0; i < 101; i++) {
      dp[0][i] = 0;
    }

    do {
      cin >> items[counter];
      sum += items[counter];
      counter++;
    } while (cin.peek() != '\n' && cin.peek() != -1);

    cin.ignore(100, '\n');

    if (sum % 2 != 0) {
      cout << "NO" << endl;
      continue;
    }

    sum = sum / 2;

    for (int i = 1; i <= counter; i++) {
      for (int j = 1; j <= sum; j++) {
        if (j >= items[i-1]) {
          dp[i][j] = max(dp[i-1][j], dp[i-1][j-items[i-1]] + items[i-1]);
        } else {
          dp[i][j] = dp[i-1][j];
        }
      }
    }

    if (dp[counter][sum] == sum) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  
  return 0;
}
