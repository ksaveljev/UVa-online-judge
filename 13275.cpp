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
#define goog(tno) cout << "Case " << tno << ": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

bool is_leap(int y) {
    if (y % 400 == 0) return true;
    else if (y % 100 == 0) return false;
    else if (y % 4 == 0) return true;
    else return false;
}

int main(void) {
    int t;
    cin >> t;

    rep (T, 0, t) {
        goog(T+1);
        int d, m, y, qy;

        cin >> d >> m >> y >> qy;

        if (d == 29 && m == 2) {
            int result = 0;
            for (int i = y+1; i <= qy; i++) {
                if (is_leap(i)) result++;
            }
            cout << result << endl;
        } else {
            cout << qy - y << endl;
        }
    }

    return 0;
}
