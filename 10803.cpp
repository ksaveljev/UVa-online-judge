#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

double distance_between(int a, int b, const vector< pair<int,int> > &towns) {
  return sqrt((towns[a].first - towns[b].first)*(towns[a].first - towns[b].first) + (towns[a].second - towns[b].second)*(towns[a].second - towns[b].second));
}

int main(void) {
  int cases, n, x, y;
  vector< pair<int,int> > towns;
  double dist[101][101];

  double INF = 1e20;

  cin >> cases;

  for (int casenum = 0; casenum < cases; casenum++) {
    cin >> n;

    towns.clear();

    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      towns.push_back(make_pair(x, y));
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) {
          dist[i][j] = 0;
          continue;
        }

        double tmp = distance_between(i, j, towns);
        if (tmp > 10.0) {
          dist[i][j] = INF;
        } else {
          dist[i][j] = tmp;
        }
      }
    }

    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }

    bool ok = true;
    double result = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dist[i][j] == INF) {
          ok = false;
          i = n;
          break;
        }
        if (dist[i][j] > result)
          result = dist[i][j];
      }
    }

    cout << "Case #" << casenum+1 << ":" << endl;
    if (ok) {
      cout << setprecision(4) << setiosflags(ios::fixed|ios::showpoint) << result << endl;
    } else {
      cout << "Send Kurdy" << endl;
    }
    cout << endl;
  }

  return 0;
}
