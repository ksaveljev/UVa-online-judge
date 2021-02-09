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

const int maxN = 1e4;
int dp[maxN+1];
int n;

int main(void) {

    memset(dp, 0x3f3f3f3f, sizeof dp);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int n = 3; n <= maxN; n++) {
        for (int i = 1; i <= sqrt(n); i++) {
            dp[n] = min(dp[n], 1 + dp[n - i * i]);
        }
    }

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}
