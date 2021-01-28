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
#define goog(tno) cout << "Case " << tno << ":"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

vector<int> w(10);
vector<int> tmp(10);

int main(void) {
    int t;
    cin >> t;

    for (int T = 1; T <= t; T++) {
        int sum = 0;
        loop(10) {
            cin >> w[i];
        }

        sort(w.begin(), w.end());

        bool found = false;
        for (int a = 0; !found && (a <= w[0]/2); a++) {
            int b = w[0] - a;
            int c = w[1] - a;
            for (int d = c; ; d++) {
                int e = w[9] - d;
                if (e < d) break;
                tmp[0] = a + b;
                tmp[1] = a + c;
                tmp[2] = a + d;
                tmp[3] = a + e;
                tmp[4] = b + c;
                tmp[5] = b + d;
                tmp[6] = b + e;
                tmp[7] = c + d;
                tmp[8] = c + e;
                tmp[9] = d + e;
                sort(tmp.begin(), tmp.end());

                bool ok = true;
                loop(10) {
                    if (w[i] != tmp[i]) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    goog(T);
                    cout << " " << a << " " << b << " " << c << " " << d << " " << e << endl;
                    found = true;
                    break;
                }
            }
        }
    }
    return 0;
}
