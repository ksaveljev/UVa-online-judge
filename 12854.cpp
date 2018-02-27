#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int a[5], b;

    while (cin >> a[0]) {
        bool ok = true;

        rep (i, 4) {
            cin >> a[i + 1];
        }
        rep (i, 5) {
            cin >> b;
            if (a[i] + b != 1) ok = false;
        }

        cout << (ok ? "Y" : "N") << endl;
    }

    return 0;
}
