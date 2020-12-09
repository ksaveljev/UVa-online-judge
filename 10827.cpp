#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int matrix[150][150];
int suf[150][150];

int main(void) {
    int cases, n, tmp;

    cin >> cases;

    while (cases--) {
        cin >> n;

        rep (i, 150) rep (j, 150) matrix[i][j] = -1e6;

        rep (i, n) {
            rep (j, n) {
                cin >> tmp;
                matrix[i][j] = tmp;
                matrix[i+n][j] = tmp;
                matrix[i][j+n] = tmp;
                matrix[i+n][j+n] = tmp;
            }
        }

        rep (i, 2 * n) {
            rep (j, 2 * n) {
                suf[i][j] = matrix[i][j] + (i>0?suf[i-1][j]:0) + (j>0?suf[i][j-1]:0) - (i>0&&j>0?suf[i-1][j-1]:0);
            }
        }

        /*
        rep (i, 2*n) {
            rep (j, 2*n) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        */

        int result = -1e6;

        rep (ii, n) {
            rep (jj, n) {
                for (int i = ii; i < ii + n; i++) {
                    for (int j = jj; j < jj + n; j++) {
                        tmp = suf[i][j] - (ii>0?suf[ii-1][j]:0) - (jj>0?suf[i][jj-1]:0) + (ii>0&&jj>0?suf[ii-1][jj-1]:0);
                        if (tmp > result) {
                            result = tmp;
                        }
                    }
                }
            }
        }

        cout << result << endl;
    }

    return 0;
}
