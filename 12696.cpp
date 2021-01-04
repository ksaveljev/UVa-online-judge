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

int get_value() {
    char tmp;
    int a, b;
    cin >> a >> tmp >> b;
    return a * 100 + b;
}

int main(void) {
    int t;
    int total = 0;
    int len, wid, dep, w;

    cin >> t;

    while (t--) {
        len = get_value();
        wid = get_value();
        dep = get_value();
        w = get_value();

        if (((len <= 5600 && wid <= 4500 && dep <= 2500) || (len + wid + dep) <= 12500) && w <= 700) {
            cout << 1 << endl;
            total++;
        } else {
            cout << 0 << endl;
        }
    }

    cout << total << endl;

    return 0;
}
