#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int find_nearest_cube_root(int n) {
    REP (i, 1, 101) {
        if (i * i * i == n)
            return i;

        if (i * i * i > n)
            return i - 1;
    }

    return -1;
}

int main(void) {
    double n;
    int sq;

    while (cin >> n) {
        if (n == 0)
            break;

        sq = find_nearest_cube_root(int(n));

        double dx = (n - sq * sq * sq) / (3 * sq * sq);
        cout << setprecision(4) << fixed << sq + dx << endl;
    }

    return 0;
}
