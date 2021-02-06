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

int n, m;
int nums[101];
int dp[101][5001];

int main(void) {
    while (cin >> n >> m) {
        if (n > m) swap(n, m);

        memset(dp, 0, sizeof dp);

        int sum = 0;
        for (int i = 1; i <= n + m; i++) {
            cin >> nums[i];
            sum += nums[i];
            nums[i] += 50;
        }

        dp[0][0] = 1;
        for (int i = 1; i <= n + m; i++) {
            for (int j = min(i, n); j >= 1; j--) {
                for (int k = 0; k <= 5000; k++) {
                    if (dp[j-1][k]) {
                        dp[j][k + nums[i]] = 1;
                    }
                }
            }
        }

        int mmax = - 5000;
        int mmin = 5000;
        loop(5001) {
            if (dp[n][i]) {
                int x = i - 50 * n;
                mmax = max(mmax, x * (sum - x));
                mmin = min(mmin, x * (sum - x));
            }
        }

        cout << mmax << " " << mmin << endl;
    }
    return 0;
}
