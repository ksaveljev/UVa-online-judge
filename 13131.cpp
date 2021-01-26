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
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        int sum = 0;
        vector<int> v;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                if (i % k > 0) sum += i;
                v.push_back(i);
            }
        }
        for (int x : v) {
            int d = n / x;
            if (d != x && d % k > 0) {
                sum += d;
            }
        }
        cout << sum << endl;
    }

    return 0;
}
