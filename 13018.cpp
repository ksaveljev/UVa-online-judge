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

int counter[41];
int main(void) {
    int n, m;

    bool first = true;
    while (cin >> n >> m) {
        if (!first) cout << endl;
        first = false;

        memset(counter, 0, sizeof counter);

        int best = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                counter[i+j]++;
                best = max(best, counter[i+j]);
            }
        }

        for (int i = 1; i <= 40; i++) {
            if (counter[i] == best) {
                cout << i << endl;
            }
        }
    }

    return 0;
}
