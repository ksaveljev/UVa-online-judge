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
    string a, b;

    cin >> t;

    while (t--) {
        cin >> a >> b;

        string c = a;
        string d = b;

        cout << a << " " << b << endl;
        while (true) {
            loop(a.size()) {
                c[i] = a[i] == b[i] ? '0' : '1';
                d[i] = a[i] == '1' && b[i] == '1' ? '1' : '0';
            }

            a = c;
            cout << a;

            if (d[0] == '1') {
                cout << " overflow" << endl;
                break;
            } else {
                loop(d.size()) {
                    if (i == d.size() - 1) {
                        d[i] = '0';
                    } else {
                        d[i] = d[i+1];
                    }
                }
            }

            b = d;
            cout << " " << b << endl;

            bool done = true;
            loop(b.size()) {
                if (b[i] != '0') {
                    done = false;
                    break;
                }
            }

            if (done) break;
        }

        if (t) cout << endl;
    }

    return 0;
}
