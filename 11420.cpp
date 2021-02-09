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

int n, s;
ll dp[2][66][66];

int main(void) {
    dp[0][0][0] = 1;

    for (int i = 1; i < 66; i++) {
        for (int j = 0; j <= i; j++) {
            dp[0][i][j] = dp[0][i-1][j] + (j<i?dp[1][i-1][j+1]:0);
            dp[1][i][j] = (j>0?dp[0][i-1][j-1]:0) + (j>0?dp[1][i-1][j-1]:0);
        }
    }

    while (cin >> n >> s) {
        if (n < 0 && s < 0) break;

        cout << dp[0][n][s] + dp[1][n][s] << endl;
    }
    return 0;
}
