#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];

string readLCS(const string &a, const string &b, int i, int j) {
  if (i == 0 || j == 0)
    return "";
  else if (a[i-1] == b[j-1])
    return readLCS(a, b, i - 1, j -1) + a[i-1];
  else
    if (dp[i][j-1] > dp[i-1][j])
      return readLCS(a, b, i, j-1);
    else
      return readLCS(a, b, i-1, j);
}

int main(void) {
  string a, b;

  while (getline(cin, a)) {
    getline(cin, b);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0, sz = a.size(); i <= sz; i++)
      dp[i][0] = 0;

    for (int i = 0, sz = b.size(); i <= sz; i++)
      dp[0][i] = 0;

    for (int i = 1, sz = a.size(); i <= sz; i++) {
      for (int j = 1, sz2 = b.size(); j <= sz2; j++) {
        if (a[i-1] == b[j-1])
          dp[i][j] = dp[i-1][j-1] + 1;
        else
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }

    cout << readLCS(a, b, a.size(), b.size()) << endl;
  }

  return 0;
}
