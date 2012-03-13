/*
 * Area of an Ellipse:
 * http://www.math.hmc.edu/funfacts/ffiles/10006.3.shtml
 *
 */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(void) {
    int n;
    double D, L, pi = atan(1) * 4;

    cin >> n;

    while (n--) {
        cin >> D >> L;

        double area = pi * (L / 2) * sqrt((L/2)*(L/2) - (D/2)*(D/2));
        cout << fixed << setprecision(3) << area << endl;
    }

    return 0;
}
