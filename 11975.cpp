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
    int T, N, L, V[4], drawn[75], num, ticket[5][5];

    cin >> T;

    REPI (case_number, 1, T) {
        if (case_number > 1) cout << endl;
        cout << "Case " << case_number << ":" << endl;

        cin >> N >> L;

        rep (i, N) cin >> drawn[i];
        rep (i, 4) cin >> V[i];

        while (L--) {
            int result = 0;

            rep (i, 5) rep (j, 5) ticket[i][j] = -1;

            rep (i, 5) {
                rep (j, 5) {
                    cin >> num;

                    rep (k, N) {
                        if (drawn[k] == num) {
                            ticket[i][j] = k;
                            break;
                        }
                    }
                }
            }

            if (ticket[0][0] != -1 && ticket[0][4] != -1 && ticket[4][0] != -1 && ticket[4][4] != -1 &&
                ticket[0][0] < 35 && ticket[0][4] < 35 && ticket[4][0] < 35 && ticket[4][4] < 35) {
                result += V[0];
            }

            bool ok = true;
            rep (i, 5) {
                if (ticket[2][i] == -1 || ticket[2][i] >= 40) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                result += V[1];
            }

            ok = true;
            rep (i, 5) {
                rep (j, 5) {
                    if (i == j || i + j == 4) {
                        if (ticket[i][j] == -1 || ticket[i][j] >= 45) {
                            ok = false;
                            i = j = 5;
                        }
                    }
                }
            }

            if (ok) {
                result += V[2];
            }

            ok = true;
            rep (i, 5) {
                rep (j, 5) {
                    if (ticket[i][j] == -1) {
                        ok = false;
                        i = j = 5;
                    }
                }
            }

            if (ok) {
                result += V[3];
            }

            cout << result << endl;
        }
    }

    return 0;
}
