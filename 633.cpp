#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <cstdio>
using namespace std;

int n;
int ki, kj;
int di, dj;
int board[40][40];
map<pair<int,int>, int> visited;

struct kmove {
    int type; // 1 - normal, 2 - bishop, 3 - teleport
    int row;
    int col;
    int moves;
};

int dir1[8][2] = { {-2,-1}, {-2,1}, {2,-1}, {2,1}, {-1,-2}, {-1,2}, {1,-2}, {1,2} };
int dir2[4][2] = { {-2, -2}, {-2, 2}, {2, -2}, {2, 2} };

bool operator<(const kmove& a, const kmove& b) {
    return a.moves < b.moves;
}

bool valid(int row, int col, int counter) {
    return row >= 0 && col >= 0 && row < 2 * n && col < 2 * n && board[row][col] == 0 && (visited.find({row, col}) == visited.end() || visited[{row, col}] >= counter);
}

int bfs() {
    queue<kmove> q;
    kmove tmp;

    tmp.type = 0; // next move can be of any type
    tmp.row = ki;
    tmp.col = kj;
    tmp.moves = 0;
    q.push(tmp);

    while (!q.empty()) {
        tmp = q.front();
        q.pop();

        if (tmp.row == di && tmp.col == dj) {
            return tmp.moves;
        }

        if (tmp.type != 1) {
            for (int i = 0; i < 8; i++) {
                int r = tmp.row + dir1[i][0];
                int c = tmp.col + dir1[i][1];
                if (valid(r, c, tmp.moves + 1)) {
                    kmove next;
                    next.type = 1;
                    next.row = r;
                    next.col = c;
                    next.moves = tmp.moves + 1;
                    q.push(next);
                    visited[{r, c}] = next.moves;
                }
            }
        }

        if (tmp.type != 2) {
            for (int i = 0; i < 4; i++) {
                int r = tmp.row + dir2[i][0];
                int c = tmp.col + dir2[i][1];
                if (valid(r, c, tmp.moves + 1)) {
                    kmove next;
                    next.type = 2;
                    next.row = r;
                    next.col = c;
                    next.moves = tmp.moves + 1;
                    q.push(next);
                    visited[{r, c}] = next.moves;
                }
            }
        }

        if (tmp.type != 3) {
            kmove next;
            next.type = 3;
            next.moves = tmp.moves + 1;

            int r = tmp.row;
            int c = 2 * n - tmp.col - 1;

            if (valid(r, c, tmp.moves + 1)) {
                next.row = r;
                next.col = c;

                q.push(next);
                visited[{r, c}] = next.moves;
            }

            r = 2 * n - tmp.row - 1;
            c = tmp.col;

            if (valid(r, c, tmp.moves + 1)) {
                next.row = r;
                next.col = c;

                q.push(next);
                visited[{r, c}] = next.moves;
            }
        }
    }

    return -1;
}

int main(void) {
    while (cin >> n) {
        if (n == 0) break;
        cin >> ki >> kj;
        --ki, --kj;
        cin >> di >> dj;
        --di, --dj;

        for (int i = 0; i < 2 * n; i++)
            for (int j = 0; j < 2 * n; j++)
                board[i][j] = 0;

        int a, b;
        while (cin >> a >> b) {
            if (a == 0 && b == 0) break;
            --a, --b;
            board[a][b] = 1;
        }

        visited.clear();
        int result = bfs();

        if (result == -1) {
            cout << "Solution doesn't exist" << endl;
        } else {
            cout << "Result : " << result << endl;
        }
    }

    return 0;
}
