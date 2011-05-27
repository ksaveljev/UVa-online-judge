#include <iostream>
#include <vector>
using namespace std;

int INF = 1000000000;

struct result {
  int max_distance;
  int n;
  result() : max_distance(INF) {}
};

int main(void) {
  int t, n, d;
  int a, b, c;
  int dist[101][101];

  cin >> t;

  for (int casenum = 0; casenum < t; casenum++) {
    cin >> n >> d;

    result best;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j)
          dist[i][j] = 0;
        else
          dist[i][j] = INF;
      }
    }

    while (d--) {
      cin >> a >> b >> c;
      dist[a][b] = min(dist[a][b], c);
      dist[b][a] = min(dist[b][a], c);
    }

    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }

    int tmp;
    bool ok = false;
    vector<int> possible_result;
    for (int i = 1; i <= n; i++) {
      if (dist[i][1] == dist[i][2] && dist[i][2] == dist[i][3] && dist[i][3] == dist[i][4] && dist[i][4] == dist[i][5]) {
        ok = true;
        possible_result.push_back(i);
      }
    }
    
    if (ok) {
      for (int i = 0, sz = possible_result.size(); i < sz; i++) {
        int tmp = 0;
        for (int j = 1; j <= n; j++) {
          if (dist[possible_result[i]][j] > tmp)
            tmp = dist[possible_result[i]][j];
        }
        if (tmp < best.max_distance) {
          best.n = possible_result[i];
          best.max_distance = tmp;
        }
      }
    }

    cout << "Map " << casenum+1 << ": ";
    if (ok && best.max_distance != INF) {
      cout << best.max_distance << endl;
    } else {
      cout << "-1" << endl;
    }
  }

  return 0;
}
