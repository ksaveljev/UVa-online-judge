#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int search(unsigned long long s, unsigned long long d) {
    unsigned long long gmin = s, gmax = 100000000, gmid, sum;

    while (gmax >= gmin) {
        gmid = (gmin + gmax) / 2;

        sum = (gmid - s + 1) * (s + gmid) / 2;

        if (sum < d) {
            gmin = gmid + 1;
        } else if (sum > d) {
            gmax = gmid - 1;
        } else {
            break;
        }
    }

    return gmin;
}

int main(void) {
    unsigned long long s, d;

    while (cin >> s >> d) {
        cout << search(s, d) << endl;
    }

    return 0;
}
