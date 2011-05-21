#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int w, h;
char pic[55][55];

void erase(int x, int y) {
  pic[x][y] = '*';

  if (x-1 > 0 && pic[x-1][y] == 'X')
    erase(x-1, y);

  if (y-1 > 0 && pic[x][y-1] == 'X')
    erase(x, y-1);

  if (x + 1 < h && pic[x+1][y] == 'X')
    erase(x+1, y);

  if (y + 1 < w && pic[x][y+1] == 'X')
    erase(x, y+1);
}

int scan(int x, int y) {
  int value = 0;
  pair<int,int> tmp;
  queue< pair<int,int> > q;

  tmp.first = x;
  tmp.second = y;
  q.push(tmp);

  if (pic[x][y] == 'X') {
    value++;
    erase(x, y);
  } else
    pic[x][y] = '.';

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    if (tmp.first > 0) {
      if (pic[tmp.first-1][tmp.second] == '*') {
        pic[tmp.first-1][tmp.second] = '.';
        q.push(make_pair(tmp.first-1, tmp.second));
      } else if (pic[tmp.first-1][tmp.second] == 'X') {
        value++;
        erase(tmp.first-1, tmp.second);
        q.push(make_pair(tmp.first-1, tmp.second));
      }
    }

    if (tmp.second > 0) {
      if (pic[tmp.first][tmp.second-1] == '*') {
        pic[tmp.first][tmp.second-1] = '.';
        q.push(make_pair(tmp.first, tmp.second-1));
      } else if (pic[tmp.first][tmp.second-1] == 'X') {
        value++;
        erase(tmp.first, tmp.second-1);
        q.push(make_pair(tmp.first, tmp.second-1));
      }
    }

    if (tmp.first + 1 < h) {
      if (pic[tmp.first+1][tmp.second] == '*') {
        pic[tmp.first+1][tmp.second] = '.';
        q.push(make_pair(tmp.first+1, tmp.second));
      } else if (pic[tmp.first+1][tmp.second] == 'X') {
        value++;
        erase(tmp.first+1, tmp.second);
        q.push(make_pair(tmp.first+1, tmp.second));
      }
    }

    if (tmp.second + 1 < w) {
      if (pic[tmp.first][tmp.second+1] == '*') {
        pic[tmp.first][tmp.second+1] = '.';
        q.push(make_pair(tmp.first, tmp.second+1));
      } else if (pic[tmp.first][tmp.second+1] == 'X') {
        value++;
        erase(tmp.first, tmp.second+1);
        q.push(make_pair(tmp.first, tmp.second+1));
      }
    }
  }

  return value;
}

int main(void) {
  int counter = 0;
  vector<int> result;

  while (cin >> w >> h) {
    if (w == 0 && h == 0)
      break;

    counter++;
    result.clear();

    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        cin >> pic[i][j];

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (pic[i][j] == '*' || pic[i][j] == 'X') {
          int v = scan(i,j);
          if (v > 0)
            result.push_back(v);
        }
      }
    }

    sort(result.begin(), result.end());

    cout << "Throw " << counter << endl;
    for (int i = 0, sz = result.size(); i < sz; i++) {
      if (i > 0)
        cout << " ";
      cout << result[i];
    }
    cout << endl << endl;
  }

  return 0;
}
