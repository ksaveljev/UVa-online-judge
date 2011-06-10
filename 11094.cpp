#include <iostream>
#include <queue>
using namespace std;

char grid[21][21];
int x, y;

void erase(int a, int b, char c) {
  grid[a][b] = -1;

  if (a > 0 && grid[a-1][b] == c)
    erase(a-1, b, c);

  if (b > 0 && grid[a][b-1] == c)
    erase(a, b-1, c);

  if (a + 1 < x && grid[a+1][b] == c)
    erase(a+1, b, c);

  if (b + 1 < y && grid[a][b+1] == c)
    erase(a, b+1, c);

  if (b == 0 && grid[a][y-1] == c)
    erase(a, y-1, c);

  if (b == y-1 && grid[a][0] == c)
    erase(a, 0, c);
}

int conquer(int a, int b, char c) {
  pair<int,int> tmp;
  queue< pair<int,int> > q;

  int result = 1;
  grid[a][b] = -1;

  tmp.first = a;
  tmp.second = b;
  q.push(tmp);

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    a = tmp.first;
    b = tmp.second;

    if (a > 0 && grid[a-1][b] == c) {
      result++;
      grid[a-1][b] = -1;
      q.push(make_pair(a-1,b));
    }

    if (b > 0 && grid[a][b-1] == c) {
      result++;
      grid[a][b-1] = -1;
      q.push(make_pair(a,b-1));
    }

    if (a+1 < x && grid[a+1][b] == c) {
      result++;
      grid[a+1][b] = -1;
      q.push(make_pair(a+1,b));
    }
    
    if (b+1 < y && grid[a][b+1] == c) {
      result++;
      grid[a][b+1] = -1;
      q.push(make_pair(a,b+1));
    }

    if (b == 0 && grid[a][y-1] == c) {
      result++;
      grid[a][y-1] = -1;
      q.push(make_pair(a,y-1));
    }

    if (b == y-1 && grid[a][0] == c) {
      result++;
      grid[a][0] = -1;
      q.push(make_pair(a,0));
    }
  }

  return result;
}

int main(void) {
  int a, b;

  while (cin >> x >> y) {
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) {
        cin >> grid[i][j];
      }
    }

    cin >> a >> b;

    char c = grid[a][b];

    erase(a,b,c);

    int tmp;
    int best = 0;
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) {
        if (grid[i][j] == c) {
          tmp = conquer(i,j,c);
          if (tmp > best)
            best = tmp;
        }
      }
    }

    cout << best << endl;
  }

  return 0;
}
