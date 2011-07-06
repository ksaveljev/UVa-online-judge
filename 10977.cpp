#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

bool forest[201][201];

struct jiggly {
  int r, c, L;
};

struct point {
  int r, c, counter;
};

int bfs(int r, int c)
{
  point tmp;
  queue<point> q;

  if (forest[1][1] == true) {
    return -1;
  }

  tmp.r = 1;
  tmp.c = 1;
  tmp.counter = 0;
  q.push(tmp);

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    if (tmp.r == r && tmp.c == c) {
      return tmp.counter;
    }

    if (tmp.r - 1 > 0 && forest[tmp.r-1][tmp.c] == false) {
      forest[tmp.r-1][tmp.c] = true;
      point next(tmp);
      next.counter++;
      next.r--;
      q.push(next);
    }

    if (tmp.c - 1 > 0 && forest[tmp.r][tmp.c-1] == false) {
      forest[tmp.r][tmp.c-1] = true;
      point next(tmp);
      next.counter++;
      next.c--;
      q.push(next);
    }

    if (tmp.r + 1 <= r && forest[tmp.r+1][tmp.c] == false) {
      forest[tmp.r+1][tmp.c] = true;
      point next(tmp);
      next.counter++;
      next.r++;
      q.push(next);
    }

    if (tmp.c + 1 <= c && forest[tmp.r][tmp.c+1] == false) {
      forest[tmp.r][tmp.c+1] = true;
      point next(tmp);
      next.counter++;
      next.c++;
      q.push(next);
    }
  }

  return -1;
}

int main(void)
{
  int r, c, n, m, a, b;
  jiggly tmp;

  while (cin >> r >> c) {
    if (!r && !c) {
      break;
    }

    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        forest[i][j] = false;
      }
    }

    cin >> m;

    while (m--) {
      cin >> a >> b;
      forest[a][b] = true;
    }

    cin >> n;

    while (n--) {
      cin >> tmp.r >> tmp.c >> tmp.L;

      int nr = max(1, tmp.r - tmp.L);
      int nc = max(1, tmp.c - tmp.L);

      for (int i = nr; i <= min(r, tmp.r+tmp.L); i++) {
        for (int j = 0; j <= min(c, tmp.c+tmp.L); j++) {
          if (sqrt((i-tmp.r)*(i-tmp.r) + (j-tmp.c)*(j-tmp.c)) <= tmp.L) {
            forest[i][j] = true;
          }
        }
      }
    }

    int result = bfs(r, c);

    if (result == -1) {
      cout << "Impossible." << endl;
    } else {
      cout << result << endl;
    }
  }
  
  return 0;
}
