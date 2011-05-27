#include <iostream>
#include <iomanip>
using namespace std;

int INF = 1000000000;

int main(void) {
  int a, b, n;
  int casenum = 0;
  int dist[101][101];

  while (cin >> a >> b) {
    if (a == 0 && b == 0)
      break;

    casenum++;

    for (int i = 0; i < 101; i++)
      for (int j = 0; j < 101; j++)
        dist[i][j] = INF;

    dist[a][b] = 1;

    while (cin >> a >> b) {
      if (a == 0 && b == 0)
        break;

      dist[a][b] = 1;
    }

    for (int i = 0; i < 101; i++)
      dist[i][i] = 0;

    n = 101;

    for (int k = 1; k < n; k++) {
      for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
          dist[i][j] = min(dist[i][j], dist[k][j] + dist[i][k]);
        }
      }
    }

    int counter = 0;
    int sum = 0;

    for (int i = 1; i < 101; i++) {
      for (int j = 1; j < 101; j++) {
        if (dist[i][j] == INF || i == j)
          continue;

        counter++;
        sum += dist[i][j];
      }
    }

    double result = sum * 1.0 / counter;
    cout << "Case " << casenum << ": average length between pages = " << setprecision(3) << fixed << showpoint << result << " clicks" << endl;
  }

  return 0;
}
