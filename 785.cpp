#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

char mark;
char field[40][90];
bool visited[40][90];
vector<int> lines;

char find_marking_char() {
  for (int i = 0, sz = lines.size(); i < sz; i++)
    for (int y = 0; y < lines[i]; y++)
      if (field[i][y] != ' ')
        return field[i][y];
}

void clear_visited() {
  for (int i = 0; i < 40; i++)
    for (int j = 0; j < 90; j++)
      visited[i][j] = false;
}

void print_result(const string &input) {
  for (int i = 0, sz = lines.size(); i < sz; i++) {
    for (int y = 0; y < lines[i]; y++) {
      cout << field[i][y];
    }
    cout << endl;
  }
  cout << input << endl;
}

void fill(int x, int y) {
  char c;
  pair<int,int> tmp;
  queue< pair<int,int> > q;

  tmp.first = x;
  tmp.second = y;
  q.push(tmp);

  c = field[x][y];
  visited[x][y] = true;

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    if (!visited[tmp.first-1][tmp.second] && field[tmp.first-1][tmp.second] != mark) {
      visited[tmp.first-1][tmp.second] = true;
      field[tmp.first-1][tmp.second] = c;
      q.push(make_pair(tmp.first-1, tmp.second));
    }

    if (!visited[tmp.first][tmp.second-1] && field[tmp.first][tmp.second-1] != mark) {
      visited[tmp.first][tmp.second-1] = true;
      field[tmp.first][tmp.second-1] = c;
      q.push(make_pair(tmp.first, tmp.second-1));
    }

    if (!visited[tmp.first+1][tmp.second] && field[tmp.first+1][tmp.second] != mark) {
      visited[tmp.first+1][tmp.second] = true;
      field[tmp.first+1][tmp.second] = c;
      q.push(make_pair(tmp.first+1, tmp.second));
    }

    if (!visited[tmp.first][tmp.second+1] && field[tmp.first][tmp.second+1] != mark) {
      visited[tmp.first][tmp.second+1] = true;
      field[tmp.first][tmp.second+1] = c;
      q.push(make_pair(tmp.first, tmp.second+1));
    }
  }
}

int main(void) {
  string input;

  clear_visited();

  while (getline(cin,input)) {
    if (input[0] == '_') {
      mark = find_marking_char();

      for (int i = 0, sz = lines.size(); i < sz; i++) {
        for (int j = 0; j < lines[i]; j++) {
          if (!visited[i][j] && field[i][j] != mark && field[i][j] != ' ')
            fill(i,j);
        }
      }

      print_result(input);

      lines.clear();
      clear_visited();
    } else {
      for (int x = lines.size(), y = 0, sz = input.size(); y < sz; y++) {
        field[x][y] = input[y];
      }
      lines.push_back(input.size());
    }
  }

  return 0;
}
