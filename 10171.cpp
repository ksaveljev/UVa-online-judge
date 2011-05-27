#include <iostream>
using namespace std;

int INF = 1000000000;

struct result {
  int n;
  int dist;
  result() : dist(INF) {}
};

int main(void) {
  int n;
  char a, b, c, d;
  int e;

  while (cin >> n) {
    if (n == 0)
      break;

    int distY[26][26];
    int distM[26][26];

    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        distY[i][j] = INF;
        distM[i][j] = INF;
      }
    }

    for (int i = 0; i < n; i++) {
      cin >> a >> b >> c >> d >> e;

      if (a == 'Y') {
        if (b == 'U') {
          distY[c-'A'][d-'A'] = e;
        } else if (b == 'B') {
          distY[c-'A'][d-'A'] = e;
          distY[d-'A'][c-'A'] = e;
        }
      } else if (a == 'M') {
        if (b == 'U') {
          distM[c-'A'][d-'A'] = e;
        } else if (b == 'B') {
          distM[c-'A'][d-'A'] = e;
          distM[d-'A'][c-'A'] = e;
        }
      }
    }

    for (int i = 0; i < 26; i++) {
      distY[i][i] = 0;
      distM[i][i] = 0;
    }

    for (int k = 0; k < 26; k++) {
      for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
          distY[i][j] = min(distY[i][j], distY[i][k] + distY[k][j]);
        }
      }
    }

    for (int k = 0; k < 26; k++) {
      for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
          distM[i][j] = min(distM[i][j], distM[i][k] + distM[k][j]);
        }
      }
    }

    cin >> a >> b; // position of Y and M

    int y = a - 'A';
    int m = b - 'A';
    result best;

    for (int i = 0; i < 26; i++) {
      if (distY[y][i] == INF || distM[m][i] == INF)
        continue;

      if (distY[y][i] + distM[m][i] < best.dist) {
        best.n = i;
        best.dist = distY[y][i] + distM[m][i];
      }
    }

    if (best.dist == INF) {
      cout << "You will never meet." << endl;
    } else {
      cout << best.dist; 
      for (int i = 0; i < 26; i++) {
        if (distY[y][i] + distM[m][i] == best.dist) {
          cout << " " << char(i+'A');
        }
      }
      cout << endl;
    }
  }

  return 0;
}
