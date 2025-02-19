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
	int N, x, T, K;

	while (cin >> N >> x >> T >> K, N + x + T + K) {
		N++; // N is just a number of friends, include yourself as well
		int tea_price = N * T;

		/*we have N * x money*/
		/*suppose we spend them all, what is the maximum price (P) of a single dish in this case*/
		/*to find maximum price of the dish we must assume we only bought one dish*/
		/*N * x = 1.1 * (P + N * T)*/
		/*N * x = 1.1 * P + 1.1 * N * T*/
		/*1.1 * P = N * x - 1.1 * N * T*/
		/*P = N * x / 1.1 - N * T*/
		int max_dish_price = (N * x) / (float)1.1 - N * T;

		int dish_price, tmp;
		vector<pair<int,int>> price_favour;
		for (int i = 0; i < K; i++) {
			cin >> dish_price;

			int dish_favour = 0;
			for (int j = 0; j < N; j++) {
				cin >> tmp;
				dish_favour += tmp;
			}
			price_favour.push_back({dish_price, dish_favour});
			price_favour.push_back({dish_price, dish_favour});
		}

		vector<vector<int>> dp(2*N+1, vector<int>(max_dish_price+1, 0));
		for (int pf = 0; pf < price_favour.size(); pf++) {
			auto& [price, favour] = price_favour[pf];
			for (int i = 2*N; i > 0; i--) {
				for (int j = max_dish_price; j >= price; j--) {
					dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i-1][j-price] + favour));
				}
			}
		}

		int result = 0;
		for (int i = 0; i <= 2 * N; i++) {
			result = max(result, dp[i][max_dish_price]);
		}

		cout << setprecision(2) << fixed << (double)result / N << "\n";
	}

    return 0;
}
