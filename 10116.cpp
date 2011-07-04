#include <iostream>
using namespace std;

struct position {
  int r, c;
};

int main(void)
{
  int row, col, enter;
  char field[10][10];

  while (cin >> row >> col >> enter) {
    if (!row && !col && !enter) {
      break;
    }

    int visited[10][10];

    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        visited[i][j] = -1;
      }
    }

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        cin >> field[i][j];
      }
    }

    position current;
    current.r = 0;
    current.c = enter - 1;
    visited[current.r][current.c] = 0;

    int result = 0;
    bool loop = false;

    while (true) {
      result++;

      if (field[current.r][current.c] == 'N') {
        if (current.r > 0) {
          current.r--;
        } else {
          break;
        }
      } else if (field[current.r][current.c] == 'S') {
        if (current.r + 1 < row) {
          current.r++;
        } else {
          break;
        }
      } else if (field[current.r][current.c] == 'E') {
        if (current.c + 1 < col) {
          current.c++;
        } else {
          break;
        }
      } else if (field[current.r][current.c] = 'W') {
        if (current.c > 0) {
          current.c--;
        } else {
          break;
        }
      }

      if (visited[current.r][current.c] >= 0) {
        loop = true;
        break;
      } else {
        visited[current.r][current.c] = result;
      }
    }

    if (loop) {
      cout << visited[current.r][current.c] << " step(s) before a loop of " << result - visited[current.r][current.c] << " step(s)" << endl;
    } else {
      cout << result << " step(s) to exit" << endl;
    }
  }
  return 0;
}
