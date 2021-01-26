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
    fast_io;
    int T = 0;
    int m, n;
    while (cin >> m >> n) {
        if (!(m|n)) break;

        T++;
        cout << "Triangular Museum " << T << endl;

        rep (level, 0, n) {
            rep (height, 0, m) {
                int spaces = m * (n - level) - 1 - height;
                loop (spaces) cout << ' ';

                rep (p, 0, level + 1) {
                    if (p > 0) {
                        spaces = (m - 1 - height) * 2;
                        loop (spaces) cout << ' ';
                    }
                    cout << '/';
                    spaces = height * 2;
                    if (height == m-1) {
                        loop (spaces) cout << '_';
                    } else {
                        loop (spaces) cout << ' ';
                    }
                    cout << '\\';
                }
                cout << endl;
            }
        }

        cout << endl;
    }
    return 0;
}
