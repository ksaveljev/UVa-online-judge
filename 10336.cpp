#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int h, w;
char **world;
vector< pair<char,int> > result;

bool theTruthIsOutThere(const pair<char,int> &a, const pair<char,int> &b) {
  if (a.second == b.second)
    return a.first < b.first;

  return a.second > b.second;
}

void process_state(int a, int b) {
  char c;
  pair<int,int> tmp;
  queue< pair<int,int> > q;

  tmp.first = a;
  tmp.second = b;

  c = world[a][b];
  world[a][b] = '.';

  q.push(tmp);

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    if (tmp.first > 0 && world[tmp.first-1][tmp.second] == c) {
      world[tmp.first-1][tmp.second] = '.';
      q.push(make_pair(tmp.first-1, tmp.second));
    }

    if (tmp.second > 0 && world[tmp.first][tmp.second-1] == c) {
      world[tmp.first][tmp.second-1] = '.';
      q.push(make_pair(tmp.first, tmp.second-1));
    }

    if (tmp.first < h - 1 && world[tmp.first+1][tmp.second] == c) {
      world[tmp.first+1][tmp.second] = '.';
      q.push(make_pair(tmp.first+1, tmp.second));
    }

    if (tmp.second < w - 1 && world[tmp.first][tmp.second+1] == c) {
      world[tmp.first][tmp.second+1] = '.';
      q.push(make_pair(tmp.first, tmp.second+1));
    }
  }

  bool found = false;
  for (int i = 0, sz = result.size(); i < sz; i++) {
    if (result[i].first == c) {
      found = true;
      result[i].second += 1;
    }
  }

  if (!found) {
    result.push_back(make_pair(c, 1));
  }
}

int main(void) {
  int cases;

  cin >> cases;

  for (int i = 0; i < cases; i++) {
    result.clear();

    cin >> h >> w;

    world = new char*[h];
    for (int j = 0; j < h; j++)
      world[j] = new char[w];

    for (int a = 0; a < h; a++) {
      for (int b = 0; b < w; b++) {
        cin >> world[a][b];
      }
    }

    for (int a = 0; a < h; a++) {
      for (int b = 0; b < w; b++) {
        if (world[a][b] != '.')
          process_state(a, b);
      }
    }

    sort(result.begin(), result.end(), theTruthIsOutThere);

    cout << "World #" << i+1 << endl;
    for (int i = 0, sz = result.size(); i < sz; i++) {
      cout << result[i].first << ": " << result[i].second << endl;
    }

    for (int j = 0; j < h; j++)
      delete [] world[j];

    delete [] world;
  }

  return 0;
}
