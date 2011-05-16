#include <iostream>
#include <string>
using namespace std;

int main(void) {
  int counter = 0;
  string a, b;
  int dp[101][101];

  while (getline(cin, a)) {
    if (a == "#")
      break;

    counter++;

    getline(cin, b);

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

    cout << "Case #" << counter << ": you can visit at most " << dp[a.size()][b.size()] << " cities." << endl;
  }

  return 0;
}
