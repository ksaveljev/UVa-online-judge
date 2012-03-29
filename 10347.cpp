#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    double a, b, c, s, tmp, result;

    while (cin >> a >> b >> c) {
        s = (a + b + c) / 2;
        tmp = s * (s - a) * (s - b) * (s - c);

        if (a < 0 || b < 0 || c < 0)
            result = -1;
        else if (tmp <= 0)
            result = -1;
        else
            result = 4.0 / 3 * sqrt(tmp);

        cout << fixed << setprecision(3) << result << endl;
    }

    return 0;
}
