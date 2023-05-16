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
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";

        int a[4], b[4];
        loop(4) cin >> a[i];
        loop(4) cin >> b[i];

        bool ok = false;

        loop(4) {
            if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3]) {
                ok = true;
                break;
            }

            loop(3) {
                int tmp = a[0];
                a[0] = a[1];
                a[1] = a[3];
                a[3] = a[2];
                a[2] = tmp;
            }
        }

        if (!ok) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << "POSSIBLE\n";
        }
    }

    return 0;
}
