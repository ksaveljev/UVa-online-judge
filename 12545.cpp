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
    int n;
    string a, b;

    cin >> n;

    for (int T = 1; T <= n; T++) {
        cout << "Case " << T << ": ";

        cin >> a;
        cin >> b;

        int q = 0, d0 = 0, d1 = 0, a1 = 0, b1 = 0;
        for (int i = 0;  i < a.size(); i++) {
            if (a[i] == '1') a1++;
            if (b[i] == '1') b1++;

            if (a[i] == '?') {
                q++;
            } else if (a[i] == '0' && b[i] == '1') {
                d0++;
            } else if (a[i] == '1' && b[i] == '0') {
                d1++;
            }
        }

        if (a1 > b1) {
            cout << -1 << endl;
        } else {
            int result = 0;
            result += min(d0, d1);
            int rem = max(d0, d1) - min(d0, d1);
            result += q;
            result += rem;
            cout << result << endl;
        }
    }

    return 0;
}
