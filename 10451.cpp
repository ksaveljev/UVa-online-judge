#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(void) {
    int n, case_num = 0;
    double A, PI = 2 * acos(0);

    while (cin >> n >> A) {
        if (n < 3)
            break;

        case_num++;

        double r = sqrt(A / (n * tan(PI/n)));
        double c = 2 * A / (r * n);
        double R = c / (2 * sin(PI/n));

        cout << "Case " << case_num << ": " << fixed << setprecision(5) << R * R * acos(-1) - A << " " << A - r * r * acos(-1) << endl;
    }

    return 0;
}
