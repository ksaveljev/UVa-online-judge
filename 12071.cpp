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

int main(void) {
    int n;
    int T = 0;
    while (cin >> n) {
        if (!n) break;

        T++;
        goog(T);

        vector<int> v(n);
        for (auto& x: v) {
            cin >> x;
        }
        sort(v.begin(), v.end());

        int result = 0;
        for (int i = 0; i < n; i++) {
            int it = lower_bound(v.begin(), v.end(), v[i]) - v.begin();
            result += it;
        }

        cout << result << endl;
    }
    return 0;
}
