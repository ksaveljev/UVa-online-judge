#include <iostream>
#include <vector>
using namespace std;

int INF = 1000000000;
int dist[150][150];
int p[150][150];
vector<int> path;

void calculate_path(int a, int b) {
  if (a != b)
    calculate_path(a, p[a][b]);
  path.push_back(b);
}

int main(void) {
  int n, s, a, b;
  int casenum = 0;

  while (cin >> n) {
    if (n == 0)
      break;

    casenum++;

    for (int i = 0; i < 150; i++) {
      for (int j = 0; j < 150; j++) {
        dist[i][j] = INF;
        p[i][j] = i;
      }
    }

    for (int i = 0; i < n; i++) {
      cin >> s;

      while (s--) {
        cin >> a >> b;
        dist[i+1][a] = b;
      }
    }

    for (int i = 0; i < 150; i++)
      dist[i][i] = 0;

    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (dist[i][k] + dist[k][j] < dist[i][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
            p[i][j] = p[k][j];
          }
        }
      }
    }

    cin >> a >> b;

    path.clear();
    calculate_path(a, b);

    cout << "Case " << casenum << ": Path =";
    for (int i = 0, sz = path.size(); i < sz; i++)
      cout << " " << path[i];
    cout << "; " << dist[a][b] << " second delay" << endl;
  }

  return 0;
}
