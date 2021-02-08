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

const int maxN = 2e5+1, INF = 1e9+7;
int dp[2][maxN];
int nums[maxN];

int main(void) {
    int N, C;

    while (cin >> N >> C) {
        memset(dp, 0, sizeof dp);

        for (int i = 1; i <= N; i++) {
            cin >> nums[i];
        }

        dp[0][0] = 0;
        dp[1][0] = -INF;

        for (int i = 1; i <= N; i++) {
            dp[0][i] = max(dp[0][i-1], dp[1][i-1] + nums[i]);
            dp[1][i] = max(dp[1][i-1], dp[0][i-1] - nums[i] - C);
        }

        cout << dp[0][N] << endl;
    }

    return 0;
}
