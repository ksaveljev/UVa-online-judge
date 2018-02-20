#include <iostream>
#include <queue>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int m, n;
int r, c;
char board[100][100];
bool visited[100][100];
int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
int kdir[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};

typedef struct state_ {
    pair<int,int> pos;
    int moves;
} state;

void mark_unavailable_fields(int row, int col) {
    rep (i, 8) {
        r = row + kdir[i][0];
        c = col + kdir[i][1];

        if (r >= 0 && r < m && c >= 0 && c < n && board[r][c] == '.') {
            board[r][c] = '#';
        }
    }
}

int main(void) {
    int t;
    char field;
    pair<int,int> start;

    cin >> t;

    while (t--) {
        rep (i, 100) {
            rep (j, 100) {
                visited[i][j] = false;
            }
        }

        cin >> m >> n;

        rep (i, m) {
            rep (j, n) {
                cin >> field;
                board[i][j] = field;

                if (field == 'A') {
                    start = make_pair(i, j);
                }
            }
        }

        rep (i, m) {
            rep (j, n) {
                if (board[i][j] == 'Z') {
                    mark_unavailable_fields(i, j);
                }
            }
        }

        /*
        rep (i, m) {
            rep (j, n) {
                cout << board[i][j];
            }
            cout << endl;
        }
        */

        bool found = false;
        int result = -1;
        queue<state> q;
        state tmp;

        tmp.pos = start;
        tmp.moves = 0;

        q.push(tmp);

        while (!q.empty()) {
            tmp = q.front();
            q.pop();

            if (board[tmp.pos.first][tmp.pos.second] == 'B') {
                found = true;
                result = tmp.moves;
                break;
            }

            rep (i, 8) {
                r = tmp.pos.first + dir[i][0];
                c = tmp.pos.second + dir[i][1];
                if (r >= 0 && r < m && c >= 0 && c < n && !visited[r][c] && (board[r][c] == '.' || board[r][c] == 'B')) {
                    state move;
                    move.pos = make_pair(r, c);
                    move.moves = tmp.moves + 1;
                    visited[r][c] = true;
                    q.push(move);
                }
            }
        }

        if (found) {
            cout << "Minimal possible length of a trip is " << result << endl;
        } else {
            cout << "King Peter, you can't go now!" << endl;
        }
    }

    return 0;
}
