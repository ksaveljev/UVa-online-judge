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

int main(void) {
    int h, w, height;

    while (cin >> h >> w) {
        if (h == 0 && w == 0)
            break;

        int result = 0;
        int prev = h;

        while (w--) {
            cin >> height;

            if (height < prev)
                result += (prev - height);

            prev = height;
        }

        cout << result << endl;
    }

    return 0;
}
