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
    int t, n, tmp;

    cin >> t;

    for (int T = 1; T <= t; T++) {
        cout << "Case " << T << ": ";

        cin >> n;
        int best = 0;
        while (n--) {
            cin >> tmp;
            best = max(best, tmp);
        }
        cout << best << endl;
    }

    return 0;
}
