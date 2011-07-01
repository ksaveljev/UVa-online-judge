#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
  int n, sz, len[20];
  stack<int> result;

  while (cin >> n) {
    cin >> sz;

    for (int i = 0; i < sz; i++) {
      cin >> len[i];
    }

    int **dp;
    dp = new int*[sz+1];
    for (int i = 0; i < sz+1; i++) {
      dp[i] = new int[n+1];
    }

    for (int i = 0; i < sz+1; i++) {
      dp[i][0] = 0;
    }

    for (int i = 0; i < n+1; i++) {
      dp[0][i] = 0;
    }

    for (int i = 1; i < sz+1; i++) {
      for (int j = 1; j < n+1; j++) {
        if (j - len[i-1] < 0) {
          dp[i][j] = dp[i-1][j];
        } else {
          dp[i][j] = max(dp[i-1][j], dp[i-1][j-len[i-1]] + len[i-1]);
        }
      }
    }

    int sum = dp[sz][n];

    int cur = sz;
    while (cur > 0) {
      if (dp[cur][n] == dp[cur-1][n]) {
        cur--;
        continue;
      }

      result.push(len[cur-1]);
      n -= len[cur-1];
      cur--;
    }

    while (!result.empty()) {
      cout << result.top() << " ";
      result.pop();
    }

    cout << "sum:" << sum << endl;

    for (int i = 0; i < sz+1; i++) {
      delete [] dp[i];
    }

    delete [] dp;
  }
  
  return 0;
}
