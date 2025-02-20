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

int main(void) {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>> L(n+1, vector<int>(m+1, 0));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> L[i][j];
				if (L[i][j] < 5) {
					L[i][j] = -1000000;
				}
			}
		}

		if (n > m) {
			cout << "Peter, you shouldn't have played billiard that much.\n";
			continue;
		}

		vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
		for (int j = 1; j <= m; j++) {
			dp[1][j] = L[1][j];
		}
		for (int i = 2; i <= n; i++) {
			dp[i][i] = dp[i-1][i-1] + L[i][1];
			for (int j = i + 1; j <= m; j++) {
				for (int k = 1; k < j; k++) {
					dp[i][j] = max(dp[i][j], dp[i-1][j-k] + L[i][k]);
				}
			}
		}

		if (dp[n][m] >= n * 5) {
			cout << "Maximal possible average mark - " << setprecision(2) << fixed << ((double)dp[n][m] + 1e-8)/n << ".\n";
		} else {
			cout << "Peter, you shouldn't have played billiard that much.\n";
		}
	}

    return 0;
}
