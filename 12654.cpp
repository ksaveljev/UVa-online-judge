#include <climits>
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
	int N, C, T1, T2;

	while (cin >> N >> C >> T1 >> T2) {
		vector<int> F;

		int f;
		for (int i = 0; i < N; i++) {
			cin >> f;
			F.push_back(f);
			F.push_back(C + f);
		}

		sort(F.begin(), F.end());

		int result = INT_MAX;

		for (int i = 0; i < N; i++) {
			vector<int> dp(N+1, INT_MAX);

			dp[N] = 0;
			for (int j = N-1; j >= 0; j--) {
				int x = j + 1, y = j + 1;
				while (x < N && F[i+x] - F[i+j] <= T1) {
					x++;
				}
				while (y < N && F[i+y] - F[i+j] <= T2) {
					y++;
				}
				dp[j] = min(dp[j], T1 + dp[x]);
				dp[j] = min(dp[j], T2 + dp[y]);
			}

			result = min(result, dp[0]);
		}

		cout << result << "\n";
	}

    return 0;
}
