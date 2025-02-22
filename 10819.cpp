#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define ll long long
#define pb push_back
#define loop(a) for (int i = 0; i < a; i++)
#define loopv(i, a) for (int i = 0; i < a; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define goog(tno) cout << "Case #" << tno << ": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(void) {
    int money, number_of_items;

    while (cin >> money >> number_of_items) {
        vector<pair<int, int>> items;
        int price, favour;
        for (int i = 0; i < number_of_items; i++) {
            cin >> price >> favour;
            items.push_back({price, favour});
        }

        vector<int> dp(money + 205, -1);
        dp[0] = 0;

        for (int i = number_of_items-1; i >= 0; i--) {
            auto& [price, favour] = items[i];
            for (int j = money + 200; j >= price; j--) {
                if (dp[j - price] >= 0) {
                    dp[j] = max(dp[j], dp[j-price] + favour);
                }
            }
        }

        int best = 0;
        for (int j = money + 200; j >= 0; j--) {
            if (dp[j] > best) {
                if (j < 2001 && j > money) {
                    continue;
                }
                best = dp[j];
            }
        }

        cout << best << "\n";
    }

    return 0;
}
