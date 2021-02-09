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
#define goog(tno) cout << "Case " << tno << ": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

const int INF = 1e9+7;
int dp[501][501];

int main(void) {
    int t;
    cin >> t;


    int n, k;
    for (int T = 0; T < t; T++) {
        cin >> n >> k;
        //memset(dp, 0, sizeof dp);

        for (int R = 2; R <= n; R++) {
            for (int L = R - 1; L >= 1; L--) {

                if (L == R) {
                    dp[L][R] = 0;
                    continue;
                }

                dp[L][R] = INF;

                for (int i = L; i <= R; i++) {
                    dp[L][R] = min(dp[L][R], (R - L + 1) * (k + i) + dp[L][i-1] + dp[i+1][R]);
                }

            }
        }

        goog(T+1) << dp[1][n] << endl;
    }

    return 0;
}
