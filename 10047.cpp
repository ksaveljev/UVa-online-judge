#include <iostream>
#include <queue>
using namespace std;

int r, c;
char field[25][25];

enum direction { NORTH, SOUTH, EAST, WEST };
enum color { GREEN, BLACK, RED, BLUE, WHITE };

struct position {
  int row;
  int col;
  color c;
  direction d;
  int steps;
};

direction turn_left(direction d) {
  switch (d) {
    case NORTH:
      return WEST;
    case SOUTH:
      return EAST;
    case EAST:
      return NORTH;
    case WEST:
      return SOUTH;
  }
}

direction turn_right(direction d) {
  switch (d) {
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

bool ok_to_move(const position &current)
{
  switch (current.d) {
    case NORTH:
      if (current.row > 0 && field[current.row-1][current.col] == '.') {
        return true;
      }
      break;
    case SOUTH:
      if (current.row + 1 < r && field[current.row+1][current.col] == '.') {
        return true;
      }
      break;
    case EAST:
      if (current.col + 1 < c && field[current.row][current.col+1] == '.') {
        return true;
      }
      break;
    case WEST:
      if (current.col > 0 && field[current.row][current.col-1] == '.') {
        return true;
      }
      break;
  }

  return false;
}

color next_color(color c)
{
  switch (c) {
    case GREEN:
      return BLACK;
    case BLACK:
      return RED;
    case RED:
      return BLUE;
    case BLUE:
      return WHITE;
    case WHITE:
      return GREEN;
  }
}

position make_move(const position &current)
{
  position result = current;

  switch (current.d) {
    case NORTH:
      result.row--;
      break;
    case SOUTH:
      result.row++;
      break;
    case EAST:
      result.col++;
      break;
    case WEST:
      result.col--;
      break;
  }

  result.c = next_color(result.c);

  return result;
}

int bfs(position &start, position &end) {
  position tmp;
  queue<position> q;
  bool visited[4][5][25][25] = {false};

  //cout << "WE START AT: " << start.row << " " << start.col << endl;

  q.push(start);
  visited[start.d][start.c][start.row][start.col] = true;

  while (!q.empty()) {
    tmp = q.front();
    q.pop();

    //cout << "CURRENT POSITION: " << tmp.row << " " << tmp.col << " c: " << tmp.c << " d: " << tmp.d << endl;

    if (tmp.row == end.row && tmp.col == end.col && tmp.c == GREEN) {
      return tmp.steps;
    }

    // turn left
    if (!visited[turn_left(tmp.d)][tmp.c][tmp.row][tmp.col]) {
      visited[turn_left(tmp.d)][tmp.c][tmp.row][tmp.col] = true;
      position next = tmp;
      next.steps++;
      next.d = turn_left(tmp.d);
      q.push(next);
    }

    // turn right
    if (!visited[turn_right(tmp.d)][tmp.c][tmp.row][tmp.col]) {
      visited[turn_right(tmp.d)][tmp.c][tmp.row][tmp.col] = true;
      position next = tmp;
      next.steps++;
      next.d = turn_right(tmp.d);
      q.push(next);
    }

    // move forward
    if (ok_to_move(tmp)) {
      position next = make_move(tmp);
      if (!visited[next.d][next.c][next.row][next.col]) {
        visited[next.d][next.c][next.row][next.col] = true;
        next.steps++;
        q.push(next);
      }
    }
  }

  return -1;
}

int main(void)
{
  int casenum = 0;
  position start, end;

  while (cin >> r >> c) {
    if (!r && !c) {
      break;
    }

    if (casenum > 0) {
      cout << endl;
    }

    casenum++;

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cin >> field[i][j];

        if (field[i][j] == 'S') {
          start.row = i;
          start.col = j;
          start.d = NORTH;
          start.c = GREEN;
          start.steps = 0;
          field[i][j] = '.';
        } else if (field[i][j] == 'T') {
          end.row = i;
          end.col = j;
          field[i][j] = '.';
        }
      }
    }

    int result = bfs(start, end);

    cout << "Case #" << casenum << endl;
    if (result == -1) {
      cout << "destination not reachable" << endl;
    } else {
      cout << "minimum time = " << result << " sec" << endl;
    }
  }
  
  return 0;
}
