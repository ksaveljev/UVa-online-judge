#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int t, n;

    cin >> t;

    rep (i, t) {
        cin >> n;

        cout << "Case #" << i+1 << ": ";

        if (n == 1) {
            cout << 1 << endl;
        } else {
            cout << 1 + (n - 1) * 2 << endl;
        }
    }

    return 0;
}
