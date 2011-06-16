#include <iostream>
#include <string>
#include <queue>
using namespace std;

void fill(char pic[260][260], int x, int y, char c, int m, int n) {
  pair<int,int> tmp;
  queue< pair<int,int> > q;
  bool visited[260][260];

  if (c == pic[x][y])
    return;

  for (int i = 0; i < 260; i++)
    for (int j = 0; j < 260; j++)
      visited[i][j] = false;

  tmp.first = x;
  tmp.second = y;
  q.push(tmp);

  char old_c = pic[x][y];
  pic[x][y] = c;
  visited[x][y] = true;

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    if (tmp.first > 1 && pic[tmp.first-1][tmp.second] == old_c && !visited[tmp.first-1][tmp.second]) {
      pic[tmp.first-1][tmp.second] = c;
      visited[tmp.first-1][tmp.second] = true;
      q.push(make_pair(tmp.first-1, tmp.second));
    }

    if (tmp.second > 1 && pic[tmp.first][tmp.second-1] == old_c && !visited[tmp.first][tmp.second-1]) {
      pic[tmp.first][tmp.second-1] = c;
      visited[tmp.first][tmp.second-1] = true;
      q.push(make_pair(tmp.first, tmp.second-1));
    }

    if (tmp.first + 1 <= m && pic[tmp.first+1][tmp.second] == old_c && !visited[tmp.first+1][tmp.second]) {
      pic[tmp.first+1][tmp.second] = c;
      visited[tmp.first+1][tmp.second] = true;
      q.push(make_pair(tmp.first+1, tmp.second));
    }

    if (tmp.second + 1 <= n && pic[tmp.first][tmp.second+1] == old_c && !visited[tmp.first][tmp.second+1]) {
      pic[tmp.first][tmp.second+1] = c;
      visited[tmp.first][tmp.second+1] = true;
      q.push(make_pair(tmp.first, tmp.second+1));
    }
  }
}

int main(void) {
  int m, n;
  int x, y;
  int y1, y2;
  int x1, x2;
  char c;
  string input;
  char pic[260][260];

  while (cin >> c) {
    switch (c) {
      case 'I':
        cin >> m >> n;
        for (int i = 1; i <= m; i++)
          for (int j = 1; j <= n; j++)
            pic[i][j] = 'O';
        break;
      case 'C':
        for (int i = 1; i <= m; i++)
          for (int j = 1; j <= n; j++)
            pic[i][j] = 'O';
        break;
      case 'L':
        cin >> x >> y >> c;
        pic[x][y] = c;
        break;
      case 'V':
        cin >> x >> y1 >> y2 >> c;
        if (y1 > y2)
          swap(y1, y2);
        for (int i = y1; i <= y2; i++)
          pic[x][i] = c;
        break;
      case 'H':
        cin >> x1 >> x2 >> y >> c;
        if (x1 > x2)
          swap(x1, x2);
        for (int i = x1; i <= x2; i++)
          pic[i][y] = c;
        break;
      case 'K':
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        for (int i = x1; i <= x2; i++)
          for (int j = y1; j <= y2; j++)
            pic[i][j] = c;
        break;
      case 'F':
        cin >> x >> y >> c;
        fill(pic, x, y, c, m, n);
        break;
      case 'S':
        cin >> input;
        cout << input << endl;
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= m; j++) {
            cout << pic[j][i];
          }
          cout << endl;
        }
        break;
      case 'X':
        return 0;
        break;
      default:
        cin.ignore(10000, '\n');
        break;
    }
  }

  return 0;
}
