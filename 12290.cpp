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


bool clap_number(int num) {
    if (num % 7 == 0)
        return true;

    while (num) {
        int r = num % 10;
        num /= 10;

        if (r == 7)
            return true;
    }

    return false;
}

int main(void) {
    int n, m, k;

    while (cin >> n >> m >> k) {
        if (n == 0 && m == 0 && k == 0)
            break;

        int person = 1;
        int current = 0;
        int step = 1;

        while (true) {
            current++;

            if (person == m && clap_number(current)) {
                k--;
                if (k == 0) {
                    cout << current << endl;
                    break;
                }
            }

            person += step;

            if (person > n) {
                person = n - 1;
                step = -1;
            } else if (person == 0) {
                person = 2;
                step = 1;
            }
        }
    }

    return 0;
}
