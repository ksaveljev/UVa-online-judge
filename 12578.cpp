#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int t;
    double L, W, R;
    double pi = acos(-1);
    double r1, r2;

    cin >> t;

    while (t--) {
        cin >> L;
        W = L * 6 / 10;
        R = L / 5;

        r1 = pi * R * R;
        r2 = W * L - r1;

        cout << fixed << setprecision(2) << r1 << " " << r2 << endl;
    }

    return 0;
}
