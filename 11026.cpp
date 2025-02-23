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

// dp[k][i] - groupings of K elements using first i numbers
ll dp[1005][1005];
ll nums[1005];

int main(void) {
	ll n, m;

	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;

		for (int i = 1; i <= n; i++) {
			cin >> nums[i];
		}

		for (int i = 0; i < 1005; i++) {
			dp[0][i] = 1;
		}

		for (int i = 1; i <= n; i++) {
			for (int k = 1; k <= n; k++) {
				dp[k][i] = (dp[k][i-1] + (dp[k-1][i-1] * nums[i]) % m) % m;
			}
		}

		ll fitness = 0;
		for (int k = 1; k <= n; k++) {
			fitness = max(fitness, dp[k][n]);
		}

		cout << fitness << "\n";
	}

    return 0;
}
