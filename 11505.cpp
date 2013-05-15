#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>
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

#define pi 2*acos(0.0)

int main(void) {
    int number_of_cases, n;
    string command;
    double a;

    cin >> number_of_cases;

    while (number_of_cases--) {
        cin >> n;

        double x = 0, y = 0, angle = 0;

        while (n--) {
            cin >> command >> a;

            if (command == "fd") {
                x = x + a * cos(angle * pi / 180.0);
                y = y + a * sin(angle * pi / 180.0);
            } else if (command == "lt") {
                angle += a;
                angle = fmod(angle, 360);
            } else if (command == "bk") {
                x = x - a * cos(angle * pi / 180.0);
                y = y - a * sin(angle * pi / 180.0);
            } else if (command == "rt") {
                angle -= a;
                angle = fmod(angle, 360);
            }
        }

        double result = sqrt(x * x + y * y);
        printf("%0.lf\n", result);
    }

    return 0;
}
