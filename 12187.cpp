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

int field[101][101];
int tmp[101][101];

int main(void) {
    int n, r, c, k;

    while (cin >> n >> r >> c >> k) {
        if (n == 0 && r == 0 && c == 0 && k == 0) break;

        rep (i, r) {
            rep (j, c) {
                cin >> field[i][j];
            }
        }

        rep (i, 101) rep (j, 101) tmp[i][j] = field[i][j];

        while (k--) {
            rep (i, n) {
                int hates = (i + 1) % n;

                rep (row, r) {
                    rep (col, c) {
                        if (field[row][col] != i) continue;

                        if (row - 1 >= 0) {
                            if (field[row-1][col] == hates)
                                tmp[row-1][col] = i;
                        }

                        if (row + 1 < r) {
                            if (field[row+1][col] == hates) {
                                tmp[row+1][col] = i;
                            }
                        }

                        if (col - 1 >= 0) {
                            if (field[row][col-1] == hates)
                                tmp[row][col-1] = i;
                        }

                        if (col + 1 < c) {
                            if (field[row][col+1] == hates)
                                tmp[row][col+1] = i;
                        }
                    }
                }
            }

            rep (i, 101) rep (j, 101) field[i][j] = tmp[i][j];
        }

        rep (i, r) {
            rep (j, c) {
                if (j > 0) cout << " ";
                cout << field[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
