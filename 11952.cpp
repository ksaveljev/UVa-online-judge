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

int max_num(const string& s) {
    int result = 0;
    for (auto& c: s) {
        if (c - '0' > result) {
            result = c - '0';
        }
    }
    return result;
}

int from_base(const string& s, int base) {
    int result = 0;

    for (auto& c : s) {
        result = result * base + (c - '0');
    }

    return result;
}

bool all_ones(const string& s) {
    for (auto& c : s) {
        if (c != '1')
            return false;
    }
    return true;
}

int main(void) {
    int t;
    cin >> t;

    string a, b, c;
    char ch;
    while (t--) {
        cin >> a >> ch >> b >> ch >> c;

        int m = max(max(max_num(a), max_num(b)), max_num(c));
        m++;
        m = max(2, m);

        if (all_ones(a) && all_ones(b) && all_ones(c) && (a.size() + b.size() == c.size())) {
            cout << 1 << endl;
            continue;
        }

        bool found = false;
        for (int i = m; i <= 20; i++) {
            if (from_base(a, i) + from_base(b, i) == from_base(c, i)) {
                found = true;
                cout << i << endl;
                break;
            }
        }
        if (!found) cout << 0 << endl;
    }

    return 0;
}
