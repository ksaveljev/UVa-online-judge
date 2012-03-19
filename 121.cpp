#include <iostream>
#include <cmath>
using namespace std;

int count_skew(double a, double b) {
    int cols, rows;

    bool same = (a - int(a) >= 0.5);
    cols = int(a);
    rows =  2.0 * (b - 1) / sqrt(3) + 1;

    return cols * rows - (same ? 0 : rows / 2);
}

int main(void) {
    double a, b;

    while (cin >> a >> b) {
        if (a < 1 || b < 1) {
            cout << "0 grid" << endl;
            continue;
        }

        int grid = int(a) * int(b);
        int skew = count_skew(a, b);
        skew = max(skew, count_skew(b,a));

        if (skew > grid) {
            cout << skew << " skew" << endl;
        } else {
            cout << grid << " grid" << endl;
        }
    }

    return 0;
}
