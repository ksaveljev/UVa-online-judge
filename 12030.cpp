#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <numeric>
using namespace std;

#define ll long long
#define pb push_back
#define loop(a) for(int i = 0; i < a; i++)
#define loopv(i,a) for (int i = 0; i < a; i++)
#define rep(i,a,b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define goog(tno) cout << "Case #" << tno << ": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define bits __builtin_popcount

int status[16][16];
ll dp[16][1<<16][2];
ll fact[16];

int main(void) {
    fast_io;
    fact[0] = 1;
    fact[1] = 1;
    rep (i, 2, 16) fact[i] = fact[i-1] * i;

    int t;
    cin >> t;
    rep (T, 0, t) {
        cout << "Case " << T+1 << ": ";

        int n;
        cin >> n;

        memset(dp, 0, sizeof dp);

        rep (i, 1, n+1) rep (j, 1, n+1) cin >> status[i][j];

        dp[0][0][0] = 1;
        rep (dress, 1, n+1) {
            rep (mask, 1, 1<<n) {
                if (dress > bits(mask)) continue;
                rep (shoe, 1, n+1) if (mask & (1<<(shoe-1))) {
                    if (status[dress][shoe] == 1) {
                        dp[dress][mask][0] += dp[dress-1][mask^(1<<(shoe-1))][0];
                    }

                    if (status[dress][shoe] == 2) {
                        dp[dress][mask][1] += fact[dress-1];
                    } else {
                        dp[dress][mask][1] += dp[dress-1][mask^(1<<(shoe-1))][1];
                    }
                }
            }
        }

        cout << dp[n][(1<<n)-1][0] + dp[n][(1<<n)-1][1] << endl;
    }
}
