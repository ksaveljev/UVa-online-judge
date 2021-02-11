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

int gen(int x) {
    int result = x;

    while (x > 0) {
        result += (x % 10);
        x /= 10;
    }

    return result;
}

int main(void) {
    int t;
    cin >> t;

    map<int,int> generators;

    for (int i = 1; i <= 100000; i++) {
        int x = gen(i);
        if (generators.find(x) == generators.end()) {
            generators[x] = i;
        }
    }

    int n;
    while (t--) {
        cin >> n;
        if (generators.find(n) == generators.end()) {
            cout << 0 << endl;
        } else {
            cout << generators[n] << endl;
        }
    }

    return 0;
}
