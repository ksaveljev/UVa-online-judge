#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

enum DIR {
    NORTH = 0,
    SOUTH = 1,
    EAST = 2,
    WEST = 3
};

typedef struct _maze_square {
    bool directions[4];
    _maze_square() {
        rep (i, 4)
            directions[i] = false;
    }
} maze_square;

int rotate(DIR d, int rotation) {
    int result;
    int north[4] = {0,3,1,2};
    int south[4] = {1,2,0,3};
    int east[4] = {2,0,3,1};
    int west[4] = {3,1,2,0};

    switch (d) {
        case NORTH:
            result = north[rotation];
            break;
        case SOUTH:
            result = south[rotation];
            break;
        case EAST:
            result = east[rotation];
            break;
        case WEST:
            result = west[rotation];
            break;
    }

    return result;
}

typedef struct _pos {
    int r, c;
    int rotation;
    int steps;
} position;

int unique_position(position current_position) {
    return current_position.r * 10000 + current_position.c * 10 + current_position.rotation;
}

int find_way_out(maze_square **maze, int R, int C) {
    map<int,bool> visited;
    queue<position> q;
    position tmp;

    tmp.r = 0;
    tmp.c = 0;
    tmp.rotation = 0;
    tmp.steps = 0;

    q.push(tmp);

    visited[unique_position(tmp)] = true;

    while (!q.empty()) {
        tmp = q.front();
        q.pop();

        if (tmp.r == R - 1 && tmp.c == C - 1)
            return tmp.steps;

        position next_position(tmp);

        next_position.rotation = (tmp.rotation + 1) % 4;
        next_position.steps = tmp.steps + 1;

        // try NORTH
        next_position.r = tmp.r - 1;
        next_position.c = tmp.c;
        if (next_position.r >= 0 && !visited[unique_position(next_position)] && maze[tmp.r][tmp.c].directions[rotate(NORTH, tmp.rotation)]) {
            visited[unique_position(next_position)] = true;
            q.push(next_position);
        }

        // try SOUTH
        next_position.r = tmp.r + 1;
        next_position.c = tmp.c;
        if (next_position.r < R && !visited[unique_position(next_position)] && maze[tmp.r][tmp.c].directions[rotate(SOUTH, tmp.rotation)]) {
            visited[unique_position(next_position)] = true;
            q.push(next_position);
        }
        
        // try EAST
        next_position.r = tmp.r;
        next_position.c = tmp.c + 1;
        if (next_position.c < C && !visited[unique_position(next_position)] && maze[tmp.r][tmp.c].directions[rotate(EAST, tmp.rotation)]) {
            visited[unique_position(next_position)] = true;
            q.push(next_position);
        }

        // try WEST
        next_position.r = tmp.r;
        next_position.c = tmp.c - 1;
        if (next_position.c >= 0 && !visited[unique_position(next_position)] && maze[tmp.r][tmp.c].directions[rotate(WEST, tmp.rotation)]) {
            visited[unique_position(next_position)] = true;
            q.push(next_position);
        }
    }

    return -1;
}

int main(void) {
    int R, C;
    string input;

    while (cin >> R >> C) {
        maze_square **maze;

        maze = new maze_square*[R];
        rep (i, R) {
            maze[i] = new maze_square[C];
        }

        cin.ignore(100, '\n');

        rep (i, R) {
            rep (j, C) {
                if (i == R - 1 && j == C - 1)
                    continue;

                getline(cin, input);

                rep (k, input.size()) {
                    switch (input[k]) {
                        case 'N':
                            maze[i][j].directions[rotate(NORTH, 0)] = true;
                            break;
                        case 'E':
                            maze[i][j].directions[rotate(EAST, 0)] = true;
                            break;
                        case 'W':
                            maze[i][j].directions[rotate(WEST, 0)] = true;
                            break;
                        case 'S':
                            maze[i][j].directions[rotate(SOUTH, 0)] = true;
                            break;
                    }
                }
            }
        }

        int result = find_way_out(maze, R, C);

        if (result == -1) {
            cout << "no path to exit" << endl;
        } else {
            cout << result << endl;
        }

        rep (i, R) {
            delete [] maze[i];
        }

        delete [] maze;
    }

    return 0;
}
