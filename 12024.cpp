#include <iostream>
using namespace std;

int main(void)
{
  int t, n;
  long dp[13];
  long fact[13];

  dp[0] = 1;
  dp[1] = 0;

  for (int i = 2; i < 13; i++) {
    dp[i] = (i - 1) * (dp[i-1] + dp[i-2]);
  }

  fact[0] = 1;
  fact[1] = 1;

  for (int i = 2; i < 13; i++) {
    fact[i] = i * fact[i-1];
  }

  cin >> t;

  while (t--) {
    cin >> n;
    cout << dp[n] << "/" << fact[n] << endl;
  }
  
  return 0;
}
