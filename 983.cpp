#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int matrix[1001][1001];
int result[1001][1001];
int suf[1001][1001];

int main(void) {
    int n, m;
    bool first = true;

    while (cin >> n >> m) {
        if (!first) cout << endl;
        first = false;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        rep (i, n) {
            rep (j, n) {
                suf[i][j] = matrix[i][j] + (i>0?suf[i-1][j]:0) + (j>0?suf[i][j-1]:0) - (i>0&&j>0?suf[i-1][j-1]:0);
            }
        }

        long long sum = 0;

        rep (ii, n - m + 1) {
            rep (jj, n - m + 1) {
                result[ii][jj] = suf[ii+m-1][jj+m-1] - (jj>0?suf[ii+m-1][jj-1]:0) - (ii>0?suf[ii-1][jj+m-1]:0) + (ii>0&&jj>0?suf[ii-1][jj-1]:0);
                sum += result[ii][jj];
            }
        }

        for (int ii = n - m; ii >= 0; ii--) {
            for (int jj = 0; jj < n - m + 1; jj++) {
                cout << result[ii][jj] << endl;
            }
        }
        cout << sum << endl;
    }

    return 0;
}
