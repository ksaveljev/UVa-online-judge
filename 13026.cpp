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
#define goog(tno) cout << "Case " << tno << ":" << endl
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

bool similar(const string& a, const string& b) {
    if (a.size() != b.size())
        return false;

    int diff = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            diff++;
        }
    }

    return diff < 2;
}

int main(void) {
    int t;
    cin >> t;

    rep (T, 0, t) {
        int n;
        cin >> n;

        vector<string> dad(n);
        for (auto& x : dad) {
            cin >> x;
        }
        string mom;
        cin >> mom;

        vector<string> result;
        for (const auto& x : dad) {
            if (similar(mom, x)) {
                result.push_back(x);
            }
        }
        goog(T+1);
        for (auto x : result) {
            cout << x << endl;
        }
    }
    return 0;
}
