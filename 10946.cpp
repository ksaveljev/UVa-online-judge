#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct hole {
  char id;
  int size;
};

int x, y;
char land[51][51];
vector<hole> holes;

bool theTruthIsOutThere(const hole &a, const hole &b) {
  if (a.size == b.size) {
    return a.id < b.id;
  }

  return a.size > b.size;
}

void add_hole(int i, int j) {
  char c = land[i][j];
  int result;

  pair<int,int> tmp;
  queue< pair<int,int> > q;

  tmp.first = i;
  tmp.second = j;

  land[i][j] = '.';
  result = 1;

  q.push(tmp);

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    if (tmp.first > 0 && land[tmp.first-1][tmp.second] == c) {
      land[tmp.first-1][tmp.second] = '.';
      result++;
      q.push(make_pair(tmp.first-1, tmp.second));
    }

    if (tmp.second > 0 && land[tmp.first][tmp.second-1] == c) {
      land[tmp.first][tmp.second-1] = '.';
      result++;
      q.push(make_pair(tmp.first, tmp.second-1));
    }

    if (tmp.first < x - 1 && land[tmp.first+1][tmp.second] == c) {
      land[tmp.first+1][tmp.second] = '.';
      result++;
      q.push(make_pair(tmp.first+1, tmp.second));
    }

    if (tmp.second < y - 1 && land[tmp.first][tmp.second+1] == c) {
      land[tmp.first][tmp.second+1] = '.';
      result++;
      q.push(make_pair(tmp.first, tmp.second+1));
    }
  }

  hole h;
  h.id = c;
  h.size = result;

  holes.push_back(h);
}

int main(void) {
  int problem = 0;

  while (cin >> x >> y) {
    if (x == 0 && y == 0)
      break;

    problem++;

    holes.clear();

    for (int i = 0; i < x; i++)
      for (int j = 0; j < y; j++)
        cin >> land[i][j];

    for (int i = 0; i < x; i++)
      for (int j = 0; j < y; j++)
        if (land[i][j] != '.')
          add_hole(i, j);

    sort(holes.begin(), holes.end(), theTruthIsOutThere);

    cout << "Problem " << problem << ":" << endl;
    for (int i = 0, sz = holes.size(); i < sz; i++) {
      cout << holes[i].id << " " << holes[i].size << endl;
    }
  }

  return 0;
}
