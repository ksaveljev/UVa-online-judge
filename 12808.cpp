#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <cstdio>
using namespace std;

int main(void) {
    int t;

    cin >> t;
    double G = 9.81 * 1000;

    while (t--) {
        double L, D, H, V;
        cin >> L >> D >> H >> V;

        double t = sqrt(H * 2.0 / G);
        double dist = V * t;

        if (dist < D - 500 || dist > D + L + 500) {
            cout << "FLOOR" << endl;
        } else if (dist >= D - 500 && dist <= D + 500) {
            cout << "EDGE" << endl;
        } else if (dist >= D + L - 500 && dist <= D + L + 500) {
            cout << "EDGE" << endl;
        } else {
            cout << "POOL" << endl;
        }
    }

    return 0;
}
