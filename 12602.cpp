#include <iostream>
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

int pow(int a, int b) {
    int result = 1;

    rep (i, b) {
        result *= a;
    }

    return result;
}

int main(void) {
    int n;
    char c;

    cin >> n;

    while (n--) {
        int left = 0;
        int right = 0;

        rep (i, 3) {
            cin >> c;

            left += (c - 'A') * pow(26, 2-i);
        }

        cin >> c;

        rep (i, 4) {
            cin >> c;

            right += (c - '0') * pow(10, 3-i);
        }

        int result = left - right;

        if (result >= -100 && result <= 100)
            cout << "nice" << endl;
        else
            cout << "not nice" << endl;
    }

    return 0;
}
