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

int dp[27][27][352]; // dp[ending letter][length][sum]

int main(void) {
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    for (int letter = 1; letter < 27; letter++) {
        for (int length = 0; length <= letter; length++) {
            for (int sum = 0; sum < 352; sum++) {
                dp[letter][length][sum] = dp[letter-1][length][sum];
                if (length > 0 && sum >= letter) {
                    dp[letter][length][sum] += dp[letter-1][length-1][sum-letter];
                }
            }
        }
    }
    
    int count = 0;
    int L, S;
    while (cin >> L >> S) {
        if (L + S == 0) break;
        count++;
        cout << "Case " << count << ": ";
        if (L > 26 || S > 351) {
            cout << "0\n";
        } else {
            cout << dp[26][L][S] << "\n";
        }
    }
    return 0;
}
