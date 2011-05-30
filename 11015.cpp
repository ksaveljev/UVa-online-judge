#include <iostream>
#include <string>
#include <map>
using namespace std;

int INF = 1000000000;

struct result {
  int n;
  int dist;
  result() : dist(INF) {}
};

int main(void) {
  int n, m;
  int dist[25][25];
  string input;
  int a, b, c;
  int counter = 0;

  while (cin >> n >> m) {
    if (n == 0 && m == 0)
      break;

      counter++;

    map<int,string> p;
    cin.ignore(100, '\n');

    for (int i = 0; i < 25; i++)
      for (int j = 0; j < 25; j++)
        dist[i][j] = INF;

    for (int i = 0; i < n; i++) {
      getline(cin, input);
      p[i+1] = input;
    }

    for (int i = 0; i < m; i++) {
      cin >> a >> b >> c;
      dist[a][b] = c;
      dist[b][a] = c;
    }

    for (int i = 0; i < 25; i++)
      dist[i][i] = 0;

    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          dist[i][j] = min(dist[i][j], dist[k][j] + dist[i][k]);
        }
      }
    }

    result best;

    for (int i = 1; i <= n; i++) {
      int sum = 0;
      for (int j = 1; j <= n; j++) {
        sum += dist[i][j];
      }

      if (sum < best.dist) {
        best.n = i;
        best.dist = sum;
      }
    }

    cout << "Case #" << counter << " : " << p[best.n] << endl;
  }

  return 0;
}
