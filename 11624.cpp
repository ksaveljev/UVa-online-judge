#include <iostream>
#include <queue>
using namespace std;

struct position {
  char id;
  int r, c;
  int count;
};

bool joe_visited[1000][1000];
bool fire_visited[1000][1000];

int bfs(char field[][1000], int r, int c, pair<int,int> &joe, const vector< pair<int,int> > &fire)
{
  position tmp;
  queue<position> q;
  int joe_count = 1;

  tmp.id = 'J';
  tmp.r = joe.first;
  tmp.c = joe.second;
  tmp.count = 0;
  joe_visited[tmp.r][tmp.c] = true;
  q.push(tmp);

  for (int i = 0, sz = fire.size(); i < sz; i++) {
    tmp.id = 'F';
    tmp.r = fire[i].first;
    tmp.c = fire[i].second;
    tmp.count = 0;
    fire_visited[tmp.r][tmp.c] = true;
    q.push(tmp);
  }

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    if (tmp.id == 'J') {
      if (field[tmp.r][tmp.c] != 'J') {
        continue;
      }

      if (tmp.r == 0 || tmp.r == r - 1 || tmp.c == 0 || tmp.c == c - 1) {
        return tmp.count + 1;
      }

      if (tmp.r > 0 && !joe_visited[tmp.r-1][tmp.c] && field[tmp.r-1][tmp.c] == '.') {
        joe_visited[tmp.r-1][tmp.c] = true;
        position next(tmp);
        next.count++;
        next.r--;
        q.push(next);
        joe_count++;
        field[tmp.r-1][tmp.c] = 'J';
      }

      if (tmp.c > 0 && !joe_visited[tmp.r][tmp.c-1] && field[tmp.r][tmp.c-1] == '.') {
        joe_visited[tmp.r][tmp.c-1] = true;
        position next(tmp);
        next.count++;
        next.c--;
        q.push(next);
        joe_count++;
        field[tmp.r][tmp.c-1] = 'J';
      }

      if (tmp.r + 1 < r && !joe_visited[tmp.r+1][tmp.c] && field[tmp.r+1][tmp.c] == '.') {
        joe_visited[tmp.r+1][tmp.c] = true;
        position next(tmp);
        next.count++;
        next.r++;
        q.push(next);
        joe_count++;
        field[tmp.r+1][tmp.c] = 'J';
      }

      if (tmp.c + 1 < c && !joe_visited[tmp.r][tmp.c+1] && field[tmp.r][tmp.c+1] == '.') {
        joe_visited[tmp.r][tmp.c+1] = true;
        position next(tmp);
        next.count++;
        next.c++;
        q.push(next);
        joe_count++;
        field[tmp.r][tmp.c+1] = 'J';
      }
    } else { // tmp.id == 'F'
      if (tmp.r > 0 && !fire_visited[tmp.r-1][tmp.c] && field[tmp.r-1][tmp.c] != '#') {
        fire_visited[tmp.r-1][tmp.c] = true;
        position next(tmp);
        next.r--;
        q.push(next);
        if (field[tmp.r-1][tmp.c] == 'J') {
          joe_count--;
        }
        field[tmp.r-1][tmp.c] = 'F';
      }

      if (tmp.c > 0 && !fire_visited[tmp.r][tmp.c-1] && field[tmp.r][tmp.c-1] != '#') {
        fire_visited[tmp.r][tmp.c-1] = true;
        position next(tmp);
        next.c--;
        q.push(next);
        if (field[tmp.r][tmp.c-1] == 'J') {
          joe_count--;
        }
        field[tmp.r][tmp.c-1] = 'F';
      }

      if (tmp.r + 1 < r && !fire_visited[tmp.r+1][tmp.c] && field[tmp.r+1][tmp.c] != '#') {
        fire_visited[tmp.r+1][tmp.c] = true;
        position next(tmp);
        next.r++;
        q.push(next);
        if (field[tmp.r+1][tmp.c] == 'J') {
          joe_count--;
        }
        field[tmp.r+1][tmp.c] = 'F';
      }

      if (tmp.c + 1 < c && !fire_visited[tmp.r][tmp.c+1] && field[tmp.r][tmp.c+1] != '#') {
        fire_visited[tmp.r][tmp.c+1] = true;
        position next(tmp);
        next.c++;
        q.push(next);
        if (field[tmp.r][tmp.c+1] == 'J') {
          joe_count--;
        }
        field[tmp.r][tmp.c+1] = 'F';
      }
    }

    if (joe_count == 0) {
      return -1;
    }
  }

  return -1;
}

int main(void)
{
  int t, r, c;
  char field[1000][1000];
  pair<int,int> joe;
  vector< pair<int,int> > fire;

  cin >> t;

  while (t--) {
    cin >> r >> c;

    fire.clear();

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        joe_visited[i][j] = false;
        fire_visited[i][j] = false;
        cin >> field[i][j];

        if (field[i][j] == 'J') {
          joe.first = i;
          joe.second = j;
        } else if (field[i][j] == 'F') {
          fire.push_back(make_pair(i,j));
        }
      }
    }

    int result = bfs(field, r, c, joe, fire);

    if (result == -1) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << result << endl;
    }
  }

  return 0;
}
