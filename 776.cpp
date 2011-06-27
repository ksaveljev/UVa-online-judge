#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int row = 0, col = 0;
int cols[1000];
char input[1000][1000];
int forest[1000][1000];

int num_length(int n)
{
  return int(log10(n)) + 1;
}

void fill_forest()
{
  pair<int,int> tmp;
  queue< pair<int,int> > q;
  int counter = 1;
  bool visited[1000][1000] = {false};

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (visited[i][j]) {
        continue;
      }

      tmp.first = i;
      tmp.second = j;
      q.push(tmp);

      visited[i][j] = true;
      forest[i][j] = counter;
      if (num_length(counter) > cols[j]) {
        cols[j] = num_length(counter);
      }

      while (!q.empty()) {
        tmp = q.front();
        q.pop();

        if (tmp.first > 0 && !visited[tmp.first-1][tmp.second] && input[tmp.first-1][tmp.second] == input[tmp.first][tmp.second]) {
          visited[tmp.first-1][tmp.second] = true;
          forest[tmp.first-1][tmp.second] = counter;
          q.push(make_pair(tmp.first-1, tmp.second));
          if (num_length(counter) > cols[tmp.second]) {
            cols[tmp.second] = num_length(counter);
          }
        }

        if (tmp.first + 1 < row && !visited[tmp.first+1][tmp.second] && input[tmp.first+1][tmp.second] == input[tmp.first][tmp.second]) {
          visited[tmp.first+1][tmp.second] = true;
          forest[tmp.first+1][tmp.second] = counter;
          q.push(make_pair(tmp.first+1, tmp.second));
          if (num_length(counter) > cols[tmp.second]) {
            cols[tmp.second] = num_length(counter);
          }
        }

        if (tmp.second > 0 && !visited[tmp.first][tmp.second-1] && input[tmp.first][tmp.second-1] == input[tmp.first][tmp.second]) {
          visited[tmp.first][tmp.second-1] = true;
          forest[tmp.first][tmp.second-1] = counter;
          q.push(make_pair(tmp.first, tmp.second-1));
          if (num_length(counter) > cols[tmp.second-1]) {
            cols[tmp.second-1] = num_length(counter);
          }
        }

        if (tmp.second + 1 < col && !visited[tmp.first][tmp.second+1] && input[tmp.first][tmp.second+1] == input[tmp.first][tmp.second]) {
          visited[tmp.first][tmp.second+1] = true;
          forest[tmp.first][tmp.second+1] = counter;
          q.push(make_pair(tmp.first, tmp.second+1));
          if (num_length(counter) > cols[tmp.second+1]) {
            cols[tmp.second+1] = num_length(counter);
          }
        }

        if (tmp.first > 0 && tmp.second > 0 && !visited[tmp.first-1][tmp.second-1] && input[tmp.first-1][tmp.second-1] == input[tmp.first][tmp.second]) {
          visited[tmp.first-1][tmp.second-1] = true;
          forest[tmp.first-1][tmp.second-1] = counter;
          q.push(make_pair(tmp.first-1, tmp.second-1));
          if (num_length(counter) > cols[tmp.second-1]) {
            cols[tmp.second-1] = num_length(counter);
          }
        }

        if (tmp.first + 1 < row && tmp.second + 1 < col && !visited[tmp.first+1][tmp.second+1] && input[tmp.first+1][tmp.second+1] == input[tmp.first][tmp.second]) {
          visited[tmp.first+1][tmp.second+1] = true;
          forest[tmp.first+1][tmp.second+1] = counter;
          q.push(make_pair(tmp.first+1, tmp.second+1));
          if (num_length(counter) > cols[tmp.second+1]) {
            cols[tmp.second+1] = num_length(counter);
          }
        }

        if (tmp.first > 0 && tmp.second + 1 < col && !visited[tmp.first-1][tmp.second+1] && input[tmp.first-1][tmp.second+1] == input[tmp.first][tmp.second]) {
          visited[tmp.first-1][tmp.second+1] = true;
          forest[tmp.first-1][tmp.second+1] = counter;
          q.push(make_pair(tmp.first-1, tmp.second+1));
          if (num_length(counter) > cols[tmp.second+1]) {
            cols[tmp.second+1] = num_length(counter);
          }
        }

        if (tmp.first + 1 < row && tmp.second > 0 && !visited[tmp.first+1][tmp.second-1] && input[tmp.first+1][tmp.second-1] == input[tmp.first][tmp.second]) {
          visited[tmp.first+1][tmp.second-1] = true;
          forest[tmp.first+1][tmp.second-1] = counter;
          q.push(make_pair(tmp.first+1, tmp.second-1));
          if (num_length(counter) > cols[tmp.second-1]) {
            cols[tmp.second-1] = num_length(counter);
          }
        }
      }

      counter++;
    }
  }
}

void output_forest()
{
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      for (int k = 0; k < cols[j] - num_length(forest[i][j]) + (j==0 ? 0 : 1); k++) {
        cout << " ";
      }
      cout << forest[i][j];
    }
    cout << endl;
  }

  cout << "%" << endl;
}
int main(void)
{
  char tmp;
  int r, c;

  while (true) {
    r = c = 0;
    fill(cols, cols+1000, 0);

    while (cin.peek() != '%' && cin.peek() != -1) {
      cin >> tmp;

      input[r][c++] = tmp;

      if (cin.peek() == '\n') {
        cin.ignore(100, '\n');
        r++;
        row = r;
        col = c;
        c = 0;
      }
    }

    if (cin.peek() == '%') {
      cin >> tmp;
    }

    fill_forest();
    output_forest();

    if (cin.peek() == -1) {
      break;
    }
  }

  return 0;
}
