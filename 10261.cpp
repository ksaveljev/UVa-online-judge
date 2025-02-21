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
		int n;
		cin >> n;

		n *= 100;

		vector<vector<int>> paths(n+1, vector<int>());
		vector<int> dp(n+1, -1);
		dp[0] = 0;

		vector<int> cars, pref;
		pref.push_back(0);

		int car;
		while (cin >> car) {
			if (car == 0) {
				break;
			}

			pref.push_back(pref.back() + car);
			cars.push_back(car);
		}

		// Let's perform standard knapsack dp on one of the lanes and simultaneously
		// check if the rest of the cars (up to the current) fit on the other lane
		int idx = 0;
		for (int i = 1; i <= cars.size(); i++) {
			for (int j = n; j >= cars[i-1]; j--) {
				if (dp[j - cars[i-1]] >= 0 && pref[i] - j >= 0 && pref[i] - j <= n) {
					dp[j] = i;
					idx = j;
					paths[j] = paths[j - cars[i-1]];
					paths[j].push_back(i);
				}
			}
		}

		cout << dp[idx] << endl;
		int p = 0;
		for (int i = 1; i <= dp[idx]; i++) {
			if (p >= paths[idx].size()) {
				cout << "starboard\n";
			} else if (i < paths[idx][p]) {
				cout << "starboard\n";
			} else {
				cout << "port\n";
				p++;
			}
		}

		if (t) {
			cout << "\n";
		}
	}

    return 0;
}
