#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int t, n, tmp, case_number = 0;

    cin >> t;

    while (t--) {
        cin >> n;

        bool ok = true;
        int count[101] = { 0 };

        rep (i, n * n) {
            cin >> tmp;
            count[tmp]++;

            if (count[tmp] > n)
                ok = false;
        }

        cout << "Case " << ++case_number << ": ";

        if (ok) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
