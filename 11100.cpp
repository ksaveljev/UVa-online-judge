#include <iostream>
#include <algorithm>
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
    int n;
    int bags[10002];
    bool taken[10002];
    int result;
    bool first = true;

    while (cin >> n) {
        if (n == 0) break;

        if (first) first = false; else cout << endl;

        rep (i, n) {
            cin >> bags[i];
            taken[i] = false;
        }

        sort (bags, bags + n);

        result = 0;
        int prev = bags[0];
        int counter = 1;

        REP (i, 1, n) {
            if (bags[i] == prev) {
                counter++;
            } else {
                if (counter > result) result = counter;
                counter = 1;
                prev = bags[i];
            }
        }

        if (counter > result) result = counter;

        cout << result << endl;
        rep (i, result) {
            for (int j = i; j < n; j += result) {
                if (j > i) cout << " ";
                cout << bags[j];
            }
            cout << endl;
        }
    }

    return 0;
}
