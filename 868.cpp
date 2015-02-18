#include <iostream>
using namespace std;

#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define sz(i) i.size()
#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)

int n, m;
int maze[128][128];
int drow[4] = { 1, -1,  0, 0};
int dcol[4] = { 0,  0, 1, -1};
int start_col, end_col;

void solve(int row, int col, int search_for, int search_max) {
    if (row == n - 1) {
        if (end_col == -1 || col < end_col) {
            end_col = col;
        }

        return;
    }

    rep (i, 4) {
        if (row + drow[i] >= 0 && col + dcol[i] >= 0 && row + drow[i] < n && col + dcol[i] < m) {
            if (maze[row+drow[i]][col+dcol[i]] == search_for) {
                if (search_for == search_max) {
                    solve(row + drow[i], col + dcol[i], 1, search_max + 1);
                } else {
                    solve(row + drow[i], col + dcol[i], search_for + 1, search_max);
                }
            }
        }
    }
}

int main(void) {
    int number_of_cases;

    cin >> number_of_cases;

    while (number_of_cases--) {
        cin >> n >> m;

        rep (row, n) {
            rep (col, m) {
                cin >> maze[row][col];
            }
        }

        rep (col, m) {
            start_col = col;
            end_col = -1;

            if (maze[0][col] == 1) {
                solve(0, col, 1, 2);
            }

            if (end_col != -1) {
                break;
            }
        }

        cout << 1 << " " << start_col + 1 << endl;
        cout << n << " " << end_col + 1 << endl;

        if (number_of_cases > 0) cout << endl;
    }

    return 0;
}
