#include <iostream>
using namespace std;

int INF = 1000000000;

int main(void) {
  int t, n, r;
  int a, b;

  int dist[101][101];

  cin >> t;

  for (int c = 0; c < t; c++) {
    cin >> n >> r;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        dist[i][j] = INF;

    for (int i = 0; i < r; i++) {
      cin >> a >> b;
      dist[a][b] = 1;
      dist[b][a] = 1;
    }

    for (int i = 0; i < n; i++)
      dist[i][i] = 0;

    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          dist[i][j] = min(dist[i][j], dist[k][j] + dist[i][k]);
        }
      }
    }

    cin >> a >> b;

    int result = 0;

    for (int i = 0; i < n; i++) {
      if (dist[a][i] + dist[i][b] > result) {
        result = dist[a][i] + dist[i][b];
      }
    }

    cout << "Case " << c+1 << ": " << result << endl;
  }

  return 0;
}
