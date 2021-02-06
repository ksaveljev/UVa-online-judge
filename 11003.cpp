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

const int maxN = 1000, maxW = 3000, maxL = 3000;
int n;
int W[maxN], L[maxN];
int dp[maxW + maxL + 1];

int main(void) {
    while (cin >> n) {
        if (!n) break;

        memset(dp, 0, sizeof dp);

        loop (n) {
            cin >> W[i] >> L[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int load = L[i]; load >= 0; load--) {
                if (dp[load]) {
                    dp[load + W[i]] = max(dp[load + W[i]], dp[load] + 1);
                }
            }

            if (dp[W[i]] == 0) {
                dp[W[i]] = 1;
            }
        }

        cout << *max_element(dp, dp + maxW + maxL + 1) << endl;
    }
    return 0;
}
