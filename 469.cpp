#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <map>
using namespace std;

int n, m;
int num;
char field[100][100];
bool visited[100][100];

int bfs(int a, int b) {
  int counter = 0;
  pair<int,int> tmp;
  queue< pair<int,int> > q;

  tmp.first = a;
  tmp.second = b;

  if (field[a][b] != 'W')
    return 0;

  counter++;
  visited[a][b] = true;

  q.push(tmp);

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    if (tmp.first > 0 && !visited[tmp.first-1][tmp.second] && field[tmp.first-1][tmp.second] == 'W') {
      visited[tmp.first-1][tmp.second] = true;
      q.push(make_pair(tmp.first-1, tmp.second));
      counter++;
    }

    if (tmp.second > 0 && !visited[tmp.first][tmp.second-1] && field[tmp.first][tmp.second-1] == 'W') {
      visited[tmp.first][tmp.second-1] = true;
      q.push(make_pair(tmp.first, tmp.second-1));
      counter++;
    }

    if (tmp.first < n - 1 && !visited[tmp.first+1][tmp.second] && field[tmp.first+1][tmp.second] == 'W') {
      visited[tmp.first+1][tmp.second] = true;
      q.push(make_pair(tmp.first+1, tmp.second));
      counter++;
    }

    if (tmp.second < m - 1 && !visited[tmp.first][tmp.second+1] && field[tmp.first][tmp.second+1] == 'W') {
      visited[tmp.first][tmp.second+1] = true;
      q.push(make_pair(tmp.first, tmp.second+1));
      counter++;
    }

    if (tmp.first > 0 && tmp.second > 0 && !visited[tmp.first-1][tmp.second-1] && field[tmp.first-1][tmp.second-1] == 'W') {
      visited[tmp.first-1][tmp.second-1] = true;
      q.push(make_pair(tmp.first-1, tmp.second-1));
      counter++;
    }

    if (tmp.first < n - 1 && tmp.second > 0 && !visited[tmp.first+1][tmp.second-1] && field[tmp.first+1][tmp.second-1] == 'W') {
      visited[tmp.first+1][tmp.second-1] = true;
      q.push(make_pair(tmp.first+1, tmp.second-1));
      counter++;
    }

    if (tmp.first > 0 && tmp.second < m - 1 && !visited[tmp.first-1][tmp.second+1] && field[tmp.first-1][tmp.second+1] == 'W') {
      visited[tmp.first-1][tmp.second+1] = true;
      q.push(make_pair(tmp.first-1, tmp.second+1));
      counter++;
    }

    if (tmp.first < n - 1 && tmp.second < m - 1 && !visited[tmp.first+1][tmp.second+1] && field[tmp.first+1][tmp.second+1] == 'W') {
      visited[tmp.first+1][tmp.second+1] = true;
      q.push(make_pair(tmp.first+1, tmp.second+1));
      counter++;
    }
  }

  return counter;
}

int main(void) {
  int cases;
  string input;
  int a, b;
  stringstream ss;
  map<int,int> result;

  cin >> cases;
  cin.ignore(100, '\n');
  cin.ignore(100, '\n');

  while (cases--) {
    n = 0;
    m = 0;
    num = 1;
    result.clear();

    for (int i = 0; i < 100; i++)
      for (int j = 0; j < 100; j++) {
        visited[i][j] = false;
        field[i][j] = 'L';
      }

    while (getline(cin, input)) {
      if (input == "")
        break;

      if (input[0] == 'L' || input[0] == 'W') {
        for (int i = 0, sz = input.size(); i < sz; i++) {
          field[n][i] = input[i];
        }

        n++;
        m = input.size();
      } else {
        for (int i = 0; i < 100; i++)
          for (int j = 0; j < 100; j++)
            visited[i][j] = false;

        ss << input;
        ss >> a >> b;
        ss.str("");
        ss.clear();

        cout << bfs(a-1, b-1) << endl;
      }
    }

    if (cases)
      cout << endl;
  }

  return 0;
}
