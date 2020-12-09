#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int matrix[101][101];
int suf[101][101];

int main(void) {
    int cases;
    int n, b;
    int r1, c1, r2, c2;

    cin >> cases;

    while (cases--) {
        cin >> n >> b;

        rep (i, 101) rep (j, 101) matrix[i][j] = 0;

        while (b--) {
            cin >> r1 >> c1 >> r2 >> c2;

            for (int i = r1-1; i < r2; i++) {
                for (int j = c1-1; j < c2; j++) {
                    matrix[i][j] = 1;
                }
            }
        }

        rep (i, n) {
            rep (j, n) {
                suf[i][j] = matrix[i][j] + (i>0?suf[i-1][j]:0) + (j>0?suf[i][j-1]:0) - (i>0&&j>0?suf[i-1][j-1]:0);
            }
        }

        int result = 0;

        rep (ii, n) {
            rep (jj, n) {
                REP (i, ii, n) {
                    REP (j, jj, n) {
                        int tmp = suf[i][j] - (ii>0?suf[ii-1][j]:0) - (jj>0?suf[i][jj-1]:0) + (ii>0&&jj>0?suf[ii-1][jj-1]:0);
                        int area = (i - ii + 1) * (j - jj + 1);
                        if (tmp == 0 && area > result) {
                            result = area;
                        }
                    }
                }
            }
        }

        cout << result << endl;
    }

    return 0;
}
