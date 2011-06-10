#include <iostream>
#include <string>
#include <queue>
using namespace std;

char grid[25][25];
int row, col;

int calc(int i, int j) {
  pair<int,int> tmp;
  queue< pair<int,int> > q;

  tmp.first = i;
  tmp.second = j;
  q.push(tmp);

  int result = 1;
  grid[i][j] = '0';

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    i = tmp.first;
    j = tmp.second;

    if (i > 0 && grid[i-1][j] == '1') {
      result++;
      grid[i-1][j] = '0';
      q.push(make_pair(i-1,j));
    }

    if (j > 0 && grid[i][j-1] == '1') {
      result++;
      grid[i][j-1] = '0';
      q.push(make_pair(i, j-1));
    }

    if (i > 0 && j > 0 && grid[i-1][j-1] == '1') {
      result++;
      grid[i-1][j-1] = '0';
      q.push(make_pair(i-1,j-1));
    }

    if (i + 1 < row && grid[i+1][j] == '1') {
      result++;
      grid[i+1][j] = '0';
      q.push(make_pair(i+1,j));
    }

    if (j + 1 < col && grid[i][j+1] == '1') {
      result++;
      grid[i][j+1] = '0';
      q.push(make_pair(i,j+1));
    }

    if (i + 1 < row && j + 1 < col && grid[i+1][j+1] == '1') {
      result++;
      grid[i+1][j+1] = '0';
      q.push(make_pair(i+1,j+1));
    }

    if (i > 0 && j + 1 < col && grid[i-1][j+1] == '1') {
      result++;
      grid[i-1][j+1] = '0';
      q.push(make_pair(i-1,j+1));
    }

    if (i + 1 < row && j > 0 && grid[i+1][j-1] == '1') {
      result++;
      grid[i+1][j-1] = '0';
      q.push(make_pair(i+1,j-1));
    }
  }

  return result;
}

int main(void) {
  int t;
  string input;

  cin >> t;
  cin.ignore(100, '\n');
  cin.ignore(100, '\n');

  while (t--) {
    row = 0;

    while (getline(cin, input)) {
      if (input == "")
        break;

      col = input.size();

      for (int i = 0, sz = input.size(); i < sz; i++) {
        grid[row][i] = input[i];
      }

      row++;
    }

    int tmp;
    int best = 0;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (grid[i][j] == '1') {
          tmp = calc(i, j);
          if (tmp > best)
            best = tmp;
        }
      }
    }

    cout << best << endl;
    if (t)
      cout << endl;
  }

  return 0;
}
