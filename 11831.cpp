#include <iostream>
#include <string>
using namespace std;

char field[100][100];
enum direction { NORTH, SOUTH, EAST, WEST };

struct robot {
  int row;
  int col;
  direction dir;
};

direction char2direction(char dir)
{
  switch (dir) {
    case 'N':
      return NORTH;
    case 'S':
      return SOUTH;
    case 'L':
      return EAST;
    case 'O':
      return WEST;
  }
}

direction turn_right(direction dir) {
  switch (dir) {
    case NORTH:
      return EAST;
    case SOUTH:
      return WEST;
    case EAST:
      return SOUTH;
    case WEST:
      return NORTH;
  }
}

direction turn_left(direction dir)
{
  switch (dir) {
    case NORTH:
      return WEST;
    case SOUTH:
      return EAST;
    case WEST:
      return SOUTH;
    case EAST:
      return NORTH;
  }
}

int move_forward(robot &r, int n, int m)
{
  int result = 0;

  switch (r.dir) {
    case NORTH:
      if (r.row > 0 && field[r.row-1][r.col] != '#') {
        r.row--;
      }
      break;
    case EAST:
      if (r.col + 1 < m && field[r.row][r.col+1] != '#') {
        r.col++;
      }
      break;
    case WEST:
      if (r.col > 0 && field[r.row][r.col-1] != '#') {
        r.col--;
      }
      break;
    case SOUTH:
      if (r.row + 1 < n && field[r.row+1][r.col] != '#') {
        r.row++;
      }
      break;
  }

  if (field[r.row][r.col] == '*') {
    field[r.row][r.col] = '.';
    result = 1;
  }

  return result;
}

int main(void)
{
  int n, m, s;
  char instruction;

  while (cin >> n >> m >> s) {
    if (!n && !m && !s) {
      break;
    }

    robot r;
    int result = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> field[i][j];
        if (field[i][j] == 'N' || field[i][j] == 'S' || field[i][j] == 'L' || field[i][j] == 'O') {
          r.row = i;
          r.col = j;
          r.dir = char2direction(field[i][j]);
          field[i][j] = '.';
        }
      }
    }

    while (s--) {
      cin >> instruction;

      switch (instruction) {
        case 'F':
          result += move_forward(r, n, m);
          break;
        case 'D':
          r.dir = turn_right(r.dir);
          break;
        case 'E':
          r.dir = turn_left(r.dir);
          break;
      }
    }

    cout << result << endl;
  }
  return 0;
}
