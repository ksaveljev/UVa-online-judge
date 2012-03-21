#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(void) {
    double a;
    double PI = 2 * acos(0);

    while (cin >> a) {

        if (a == 0) {
            cout << "0.000 0.000 0.000" << endl;
            continue;
        }

        double x = a / 2;
        
        double tmp = 0.5 * (x * sqrt(a * a - x * x) + a * a * atan(x / sqrt(a * a - x * x)));

        double checkered = (a * a / 2 - tmp) * 2;
        double dotted = a * a - PI * a * a / 4 - 2 * checkered;
        double striped = a * a - 4 * checkered - 4 * dotted;

        cout << fixed << setprecision(3) << striped << " " << dotted * 4 << " " << checkered * 4 << endl;
    }

    return 0;
}
