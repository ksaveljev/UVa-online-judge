#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define sz(i) i.size()
#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)

int main(void) {
    string abbreviation;
    int num[55], num2[55], tmp, len;

    while (getline (cin, abbreviation)) {
        bool found = false;
        int result, sz;

        REP (st, 1, 10000) {
            sz = 0;

            rep (i, abbreviation.size()) {
                tmp = st + (abbreviation[i] - 'A');
                len = log10(tmp) + 1;
                sz += len;
                len = 1;
                while (tmp > 0) {
                    num[sz-len] = tmp % 10;
                    tmp /= 10;
                    len++;
                }
            }

            while (true) {
                if (sz < 3) break;
                if (sz == 3) {
                    if (num[0] == 1 && num[1] == 0 && num[2] == 0) {
                        found = true;
                        result = st;
                    }
		    break;
                }

                // reduce num
                for (int i = 0; i < sz - 1; i++) {
                    num2[i] = (num[i] + num[i+1]) % 10;
                }

                sz--;

                rep (i, sz) num[i] = num2[i];
            }

            if (found) break;
        }

        if (!found) {
            cout << ":(" << endl;
        } else {
            cout << result << endl;
        }
    }

    return 0;
}
