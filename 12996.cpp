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
    int t;
    cin >> t;

    rep (T, 0, t) {
        int N, L;
        cin >> N >> L;
        vector<int> mango(N);
        vector<int> limit(N);
        int sum = 0;
        loop(N) {
            cin >> mango[i];
            sum += mango[i];
        }
        bool ok = true;
        loop(N) {
            cin >> limit[i];
            if (limit[i] < mango[i]) {
                ok = false;
            }
        }

        goog(T+1);
        if (!ok || sum > L) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}
