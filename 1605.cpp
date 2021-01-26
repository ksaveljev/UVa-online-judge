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

char get_char(int i) {
    if (i < 26) {
        return 'A' + i;
    } else {
        return 'a' + (i - 26);
    }
}

int main(void) {
    int n;

    while (cin >> n) {
        cout << 2 << " " << n << " " << n << endl;
        rep (i, 0, n) {
            char c = get_char(i);
            rep (j, 0, n) {
                cout << c;
            }
            cout << endl;
        }

        cout << endl;

        rep (i, 0, n) {
            rep (j, 0, n) {
                char c = get_char(j);
                cout << c;
            }
            cout << endl;
        }
    }

    return 0;
}
