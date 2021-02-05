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

const int maxN = 5100, INF = 1e9+7;
int counter[maxN];

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        memset(counter, 0, sizeof counter);
        counter[0] = 1;

        int n;
        cin >> n;

        int p;
        cin >> p;

        int v;
        int best = INF;
        while (p--) {
            cin >> v;

            for (int i = maxN; i >= 0; i--) {
                if (counter[i] && i + v < maxN) {
                    counter[i + v] = 1;

                    if (i + v >= n && (i + v - n < best - n)) {
                        best = i + v;
                    }
                }
            }
        }
        if (best == INF) {
            cout << "NO SOLUTION" << endl;
        } else {
            cout << best << endl;
        }
    }

    return 0;
}
