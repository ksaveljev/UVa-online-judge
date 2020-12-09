#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

typedef long long ll;

ll matrix[101][101];
ll suf[101][101];

int main(void) {
    int t, n, m;
    ll k;

    cin >> t;

    for (int test_case = 1; test_case <= t; test_case++) {
        rep (i, 101) rep (j, 101) matrix[i][j] = 0;

        cin >> n >> m >> k;

        rep (i, n) {
            rep (j, m) {
                cin >> matrix[i][j];
                suf[i][j] = matrix[i][j] + (i>0?suf[i-1][j]:0) + (j>0?suf[i][j-1]:0) - (i>0&&j>0?suf[i-1][j-1]:0);
            }
        }

        pair<ll,ll> result = make_pair(0, 0);

        rep(ii, n) {
            rep (jj, m) {
                REP(i, ii, n) {
                    REP (j, jj, m) {
                        ll cost = suf[i][j] - (ii>0?suf[ii-1][j]:0) - (jj>0?suf[i][jj-1]:0) + (ii>0&&jj>0?suf[ii-1][jj-1]:0);
                        if (cost <= k) {
                            ll area = (i-ii+1)*(j-jj+1);
                            if (area == result.second) {
                                if (cost < result.first) {
                                    result.first = cost;
                                }
                            } else if (area > result.second) {
                                result = make_pair(cost, area);
                            }
                        }
                    }
                }
            }
        }

        cout << "Case #" << test_case << ": " << result.second << " " << result.first << endl;
    }

    return 0;
}
