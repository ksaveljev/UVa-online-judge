#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int L, f;

    while (cin >> L >> f) {
        if (L == 0 && f == 0)
            break;

        double v = sqrt(2 * f * L);
        double volume = (v * 3600) / (2 * L);

        cout << fixed << setprecision(8) << v << " " << volume << endl;
    }

    return 0;
}
