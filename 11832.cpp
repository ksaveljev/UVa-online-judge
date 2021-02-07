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

const int LIM = 80001, MID = 40000;
int N, F;
int nums[41];
int dp[41][LIM];
ll pos[41][LIM];
ll neg[41][LIM];

int main(void) {
    while (cin >> N >> F) {
        if (!(N|F)) break;

        memset(dp, 0, sizeof dp);
        memset(pos, 0, sizeof pos);
        memset(neg, 0, sizeof neg);

        for (int i = 1; i <= N; i++) {
            cin >> nums[i];
        }

        dp[0][MID] = 1;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < LIM; j++) {
                if (dp[i-1][j]) {
                    dp[i][j-nums[i]]++;
                    neg[i][j-nums[i]] |= neg[i-1][j] | (1LL << i);
                    pos[i][j-nums[i]] |= pos[i-1][j];
                    dp[i][j+nums[i]]++;
                    pos[i][j+nums[i]] |= pos[i-1][j] | (1LL << i);
                    neg[i][j+nums[i]] |= neg[i-1][j];
                }
            }
        }

        if (!dp[N][F + MID]) {
            cout << "*" << endl;
            continue;
        }

        for (int i = 1; i <= N; i++) {
            if (pos[N][F + MID] & (1LL << i)) {
                if (neg[N][F + MID] & (1LL << i)) {
                    cout << "?";
                } else {
                    cout << "+";
                }
            } else {
                cout << "-";
            }
        }
        cout << endl;
    }

    return 0;
}
