#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
  int r, c;
  int **maze;
  char tmp;
  enum direction { NORTH, SOUTH, EAST, WEST };

  while (cin >> r >> c) {
    if (!r && !c)
      break;

    maze = new int*[r];
    for (int i = 0; i < r; i++)
      maze[i] = new int[c];

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cin >> tmp;
        if (tmp == '0')
          maze[i][j] = 0;
        else
          maze[i][j] = -1; // wall
      }
    }

    pair<int,int> cur = make_pair(r-1, 0);
    pair<int,int> end = make_pair(r-1, 0);
    direction d = EAST;
    bool first_move = true;
    while (true) {
      if (d == NORTH) {
        if (cur.second + 1 < c && maze[cur.first][cur.second+1] != -1) {
          maze[cur.first][cur.second]++;
          cur.second++;
          d = EAST;
          first_move = false;
        } else if (cur.first > 0 && maze[cur.first-1][cur.second] != -1) {
          maze[cur.first][cur.second]++;
          cur.first--;
          first_move = false;
        } else {
          d = WEST;
        }
      } else if (d == SOUTH) {
        if (cur.second > 0 && maze[cur.first][cur.second-1] != -1) {
          maze[cur.first][cur.second]++;
          cur.second--;
          d = WEST;
          first_move = false;
        } else if (cur.first + 1 < r && maze[cur.first+1][cur.second] != -1) {
          maze[cur.first][cur.second]++;
          cur.first++;
          first_move = false;
        } else {
          d = EAST;
        }
      } else if (d == EAST) {
        if (cur.first + 1 < r && maze[cur.first+1][cur.second] != -1) {
          maze[cur.first][cur.second]++;
          cur.first++;
          d = SOUTH;
          first_move = false;
        } else if (cur.second + 1 < c && maze[cur.first][cur.second+1] != -1) {
          maze[cur.first][cur.second]++;
          cur.second++;
          first_move = false;
        } else {
          d = NORTH;
        }
      } else { // WEST
        if (cur.first > 0 && maze[cur.first-1][cur.second] != -1) {
          maze[cur.first][cur.second]++;
          cur.first--;
          d = NORTH;
          first_move = false;
        } else if (cur.second > 0 && maze[cur.first][cur.second-1] != -1) {
          maze[cur.first][cur.second]++;
          cur.second--;
          first_move = false;
        } else {
          d = SOUTH;
        }
      }

      if (!first_move && cur.first == end.first && cur.second == end.second)
        break;
    }

    int result[5] = {0,0,0,0,0};

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (maze[i][j] >= 0 && maze[i][j] <= 4) {
          result[maze[i][j]]++;
        }
      }
    }

    printf("%3d%3d%3d%3d%3d\n", result[0], result[1], result[2], result[3], result[4]);

    for (int i = 0; i < r; i++)
      delete [] maze[i];

    delete [] maze;
  }

  return 0;
}
