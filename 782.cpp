#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

char grid[50][100];
bool visited[50][100];
vector<int> line_sizes;

void flood_fill(int x, int y) {
  pair<int,int> tmp;
  queue< pair<int,int> > q;

  tmp.first = x;
  tmp.second = y;

  visited[x][y] = true;
  grid[x][y] = ' ';

  q.push(tmp);

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    if (tmp.first > 0 && !visited[tmp.first-1][tmp.second]) {
      if (grid[tmp.first-1][tmp.second] != ' ') {
        grid[tmp.first][tmp.second] = '#';

        if (tmp.second + 1 > line_sizes[tmp.first])
          line_sizes[tmp.first] = tmp.second + 1;
      } else {
        visited[tmp.first-1][tmp.second] = true;
        q.push(make_pair(tmp.first-1, tmp.second));
      }
    }

    if (tmp.second > 0 && !visited[tmp.first][tmp.second-1]) {
      if (grid[tmp.first][tmp.second-1] != ' ') {
        grid[tmp.first][tmp.second] = '#';

        if (tmp.second + 1 > line_sizes[tmp.first])
          line_sizes[tmp.first] = tmp.second + 1;
      } else {
        visited[tmp.first][tmp.second-1] = true;
        q.push(make_pair(tmp.first, tmp.second-1));
      }
    }

    if (tmp.first < 49 && !visited[tmp.first+1][tmp.second]) {
      if (grid[tmp.first+1][tmp.second] != ' ') {
        grid[tmp.first][tmp.second] = '#';

        if (tmp.second + 1 > line_sizes[tmp.first])
          line_sizes[tmp.first] = tmp.second + 1;
      } else {
        visited[tmp.first+1][tmp.second] = true;
        q.push(make_pair(tmp.first+1, tmp.second));
      }
    }

    if (tmp.second < 99 && !visited[tmp.first][tmp.second+1]) {
      if (grid[tmp.first][tmp.second+1] != ' ') {
        grid[tmp.first][tmp.second] = '#';

        if (tmp.second + 1 > line_sizes[tmp.first])
          line_sizes[tmp.first] = tmp.second + 1;
      } else {
        visited[tmp.first][tmp.second+1] = true;
        q.push(make_pair(tmp.first, tmp.second+1));
      }
    }
  }
}

int main(void) {
  int n;
  int lines;
  pair<int,int> star;
  string input;

  cin >> n;
  cin.ignore(100, '\n');

  while (n--) {
    lines = 0;
    line_sizes.clear();

    for (int i = 0; i < 50; i++) {
      for (int j = 0; j < 100; j++) {
        grid[i][j] = ' ';
        visited[i][j] = false;
      }
    }

    while (getline(cin, input)) {
      if (input.size() > 0 && input[0] == '_') {
        flood_fill(star.first, star.second);

        for (int i = 0, sz = line_sizes.size(); i < sz; i++) {
          for (int j = 0; j < line_sizes[i]; j++) {
            cout << grid[i][j];
          }
          cout << endl;
        }
        cout << input << endl;

        break;
      }

      for (int i = 0, sz = input.size(); i < sz; i++) {
        grid[lines][i] = input[i];

        if (input[i] == '*') {
          star.first = lines;
          star.second = i;
        }
      }

      lines++;

      int line_size = 0;
      for (int i = input.size() - 1; i >= 0; i--) {
        if (input[i] != ' ' && input[i] != '*') {
          line_size = i + 1;
          break;
        }
      }
      line_sizes.push_back(line_size);
    }
  }

  return 0;
}
