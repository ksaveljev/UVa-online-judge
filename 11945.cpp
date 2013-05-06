#include <iostream>
#include <cstdio>
#include <clocale>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)

int main(void) {
    int n;
    double sum, tmp;

    setlocale(LC_ALL, "en_US.UTF-8");

    cin >> n;

    REPI(case_number, 1, n) {
        sum = 0;

        rep (i, 12) {
            cin >> tmp;
            sum += tmp;
        }

        printf("%d $%'.2lf\n", case_number, sum / 12);
    }

    return 0;
}
