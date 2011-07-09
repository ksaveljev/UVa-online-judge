#include <iostream>
using namespace std;

int cuts[52];
int memo[52][52];

int cut(int start, int end, int n)
{
  if (start + 1 == end) {
    return 0;
  }

  if (memo[start][end] != -1) {
    return memo[start][end];
  }

  for (int i = start + 1; i < end; i++) {
    memo[start][i] = cut(start, i, n);
    memo[i][end] = cut(i, end, n);
    if (memo[start][end] == -1) {
      memo[start][end] = memo[start][i] + memo[i][end] + cuts[end] - cuts[start];
    } else {
      memo[start][end] = min(memo[start][end], memo[start][i] + memo[i][end] + cuts[end] - cuts[start]);
    }
  }

  return memo[start][end];
}

int main(void)
{
  int len, n;

  while (cin >> len) {
    if (!len) {
      break;
    }

    cin >> n;

    cuts[0] = 0;
    cuts[n+1] = len;

    for (int i = 0; i < 52; i++) {
      for (int j = 0; j < 52; j++) {
        memo[i][j] = -1;
      }
    }

    for (int i = 1; i <= n; i++) {
      cin >> cuts[i];
    }

    cout << "The minimum cutting is " << cut(0, n+1, n) << "." << endl;
  }
  
  return 0;
}
