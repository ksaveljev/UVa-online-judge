#include <iostream>
#include <cmath>
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
    int T, R, C;
    char field[52][52];

    cin >> T;

    REPI (case_number, 1, T) {
        cin >> R >> C;

        rep (i, R) rep (j, C) cin >> field[i][j];

        int result = -1;

        rep (i, C) {
            bool ok = true;
            int counter = 0;

            rep (j, R) {
                if (field[j][i] == '0') continue;

                int left = -1;
                int right = -1;

                if (i > 0) {
                    for (int k = i - 1; k >= 0; k--) {
                        if (field[j][k] == '0') {
                            left = i - k;
                            break;
                        }
                    }
                }

                if (i + 1 < C) {
                    for (int k = i + 1; k < C; k++) {
                        if (field[j][k] == '0') {
                            right = k - i;
                            break;
                        }
                    }
                }

                if (left == -1 && right == -1) {
                    ok = false;
                    break;
                } else if (left == -1) {
                    counter += right;
                } else if (right == -1) {
                    counter += left;
                } else {
                    counter += min(left, right);
                }
            }

            if (ok) {
                if (result == -1 || counter < result) result = counter;
            }
        }


        cout << "Case " << case_number << ": " << result << endl;
    }

    return 0;
}
