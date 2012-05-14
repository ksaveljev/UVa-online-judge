#include <iostream>
#include <cstring>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

#define MAXN 1000005

bool calendar[MAXN];

int main(void) {
    int n, m, a, b, rep, s, e;

    while (cin >> n >> m) {
        if (n == 0 && m == 0)
            break;

        bool ok = true;
        memset(calendar, false, MAXN);

        while (n--) {
            cin >> a >> b;

            REP (i, a, b) {
                if (calendar[i] == true)
                    ok = false;

                calendar[i] = true;
            }
        }

        while (m--) {
            cin >> a >> b >> rep;

            for (int i = 0; b + i * rep < MAXN; i++) {
                s = a + i * rep;
                e = b + i * rep;

                REP (j, s, e) {
                    if (calendar[j] == true)
                        ok = false;

                    calendar[j] = true;
                }
            }
        }

        if (ok)
            cout << "NO CONFLICT" << endl;
        else
            cout << "CONFLICT" << endl;
    }

    return 0;
}
