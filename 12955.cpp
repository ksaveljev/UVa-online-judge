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

const int maxN = 1e5, INF = 1e9+7;
int n;
ll dp[maxN+1];
ll fact[10];

int main(void) {
    fact[1] = 1;
    fact[2] = 2;
    for (int i = 3; i < 10; i++) {
        fact[i] = i * fact[i-1];
    }

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= maxN; i++) {
        dp[i] = INF;
        for (int j = 1; j < 10; j++) {
            if (fact[j] > i) break;

            dp[i] = min(dp[i], 1 + dp[i - fact[j]]);
        }
    }

    while (cin >> n) {
        cout << dp[n] << endl;
    }
    return 0;
}
