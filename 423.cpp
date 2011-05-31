#include <iostream>
#include <string>
using namespace std;

int str2int(const string &s) {
  int result = 0;

  for (int i = 0, sz = s.size(); i < sz; i++) {
    result = result * 10 + int(s[i] - '0');
  }

  return result;
}

int main(void) {
  int dist[150][150];
  int INF = 1000000000;
  int n;
  string input;

  cin >> n;
  int a;

  for (int i = 0; i < 150; i++)
    for (int j = 0; j < 150; j++)
      dist[i][j] = INF;

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      cin >> input;
      if (input == "x")
        continue;

      a = str2int(input);
      dist[i][j] = a;
      dist[j][i] = a;
    }
  }

  for (int i = 0; i < 150; i++)
    dist[i][i] = 0;

  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

  int result = 0;
  for (int i = 1; i <= n; i++) {
    result = max(result, dist[1][i]);
  }

  cout << result << endl;

  return 0;
}
