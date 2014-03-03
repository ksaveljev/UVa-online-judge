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

int main(void) {
    char board[100][100];
    int row, col;

    while (cin >> row) {
        if (row == 0) break;

        cin >> col;

        int result = 0;

        rep (i, row) rep (j, col) cin >> board[i][j];

        rep (i, row) {
            rep (j, col) {
                if (board[i][j] != '1') continue;

                REP (r, i, row) {
                    REP (c, j, col) {
                        bool ok = true;
                        REPI (a, i, r) {
                            REPI (b, j, c) {
                                if (board[a][b] != '1') {
                                    ok = false;
                                    a = r+1;
                                    b = c+1;
                                }
                            }
                        }
                        if (ok) result++;
                    }
                }
            }
        }

        cout << result << endl;
    }

    return 0;
}
