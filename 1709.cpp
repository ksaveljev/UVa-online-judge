#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

typedef long long ll;

double f(ll k, ll p, ll a, ll b, ll c, ll d) {
    return p * (sin(a * k + b) + cos(c * k + d) + 2);
}

int main(void) {
    ll p, a, b, c, d, n;

    while (cin >> p >> a >> b >> c >> d >> n) {
        double prev = f(1, p, a, b, c, d);
        double result = 0;
        for (ll i = 2; i <= n; i++) {
            double cur = f(i, p, a, b, c, d);
            result = max(result, prev - cur);
            prev = max(prev, cur);
        }
        cout << fixed << setprecision(10) << result << endl;
    }

    return 0;
}
