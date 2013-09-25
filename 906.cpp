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

#define EPS 1e-16L

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap (a, b);
    }

    return a;
}

long long a, b, c, d;
double n;

void find_c() {
    c = (a * d + b * d * n) / b - 2;
    while (c * b <= a * d) c++;
}

int main(void) {

    while (cin >> a >> b) {
        cin >> n;

        long long g = gcd(a, b);
        a /= g;
        b /= g;

        d = 1;

        while (true) {
            find_c();
            if (c * 1.0 / d - a * 1.0 / b < n + EPS) {
                cout << c << " " << d << endl;
                break;
            }

            d++;
        }
    }

    return 0;
}
