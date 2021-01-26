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

bool fits(int a, int b) {
    int diff = 0;
    while (a > 0) {
        if (a % 10 != b % 10) diff++;
        a /= 10;
        b /= 10;
    }
    return diff == 1;
}

int main(void) {
    int t;
    cin >> t;

    int x = 32;
    vector<int> sq;
    while (x * x < 10000) {
        sq.push_back(x*x);
        x++;
    }

    rep (T, 0, t) {
        goog(T+1);

        int n;
        cin >> n;

        int result = 0;
        for (int x : sq) {
            if (fits(x, n))
                result++;
        }
        cout << result << endl;
    }


    return 0;
}
