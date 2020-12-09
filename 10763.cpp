#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int n;

    while (cin >> n) {
        if (n == 0) {
            break;
        }

        vector<int> va(n), vb(n);

        rep (i, n) {
            cin >> va[i] >> vb[i];
        }

        sort(va.begin(), va.end());
        sort(vb.begin(), vb.end());

        if (va == vb) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
