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
#include <sstream>
using namespace std;

#define ll long long
#define pb push_back
#define loop(a) for(int i = 0; i < a; i++)
#define loopv(i,a) for (int i = 0; i < a; i++)
#define rep(i,a,b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define goog(tno) cout << "Case " << tno << ":"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

bool read_price(int& v) {
    bool done = false;
    int a, b;
    char tmp;

    while (cin >> a >> tmp >> b) {
        v = a * 100 + b;
        done = true;
        break;
    }

    return done;
}

int dp[101];

int main(void) {
    int unit_price;
    int m;
    string input;
    int T = 0;

    while (read_price(unit_price)) {
        T++;
        cin >> m;
        vector<pair<int,int>> prices(m+1);
        for (int i = 1; i <= m; i++) {
            cin >> prices[i].first;
            read_price(prices[i].second);
        }
        cin.ignore(100, '\n');
        getline(cin, input);
        stringstream ss(input);

        memset(dp, 0x3f3f3f3f, sizeof dp);
        dp[0] = 0;
        for (int i = 1; i < 101; i++) {
            dp[i] = i * unit_price;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j < 101; j++) {
                if (prices[i].first >= j) {
                    dp[j] = min(dp[j], prices[i].second);
                } else {
                    dp[j] = min(dp[j], prices[i].second + dp[j - prices[i].first]);
                }
            }
        }


        goog(T) << endl;
        int x;
        while (ss >> x) {
            cout << "Buy " << x << " for $" << dp[x]/100 << ".";
            if (dp[x]%100 < 10) {
                cout << "0" << dp[x]%100 << endl;
            } else {
                cout << dp[x] % 100 << endl;
            }
        }
    }

    return 0;
}
