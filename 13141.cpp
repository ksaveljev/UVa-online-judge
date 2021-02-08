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

ll fib[86];

int main(void) {
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < 86; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    int n;
    while (cin >> n) {
        if (!n) break;
        cout << fib[n-1] << endl;
    }

    return 0;
}
