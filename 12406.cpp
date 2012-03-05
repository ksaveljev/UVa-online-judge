#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> precalc[18];

void precalculate(int n, long long a, int depth) {
    if (depth == n) {
        precalc[n].push_back(a);
        return;
    }

    precalculate(n, a * 10 + 1, depth + 1);
    precalculate(n, a * 10 + 2, depth + 1);
}

int mypow(int a) {
    int result = 1;

    while (a--) {
        result <<= 1;
    }

    return result;
}

int main(void) {
    int t, p, q;
    vector<int> result;

    for (int i = 1; i < 18; i++) {
        precalculate(i, 0, 0);
        sort(precalc[i].begin(), precalc[i].end());
    }

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> p >> q;

        result.clear();
        int div = mypow(q);

        long long min = -1, max = -1;
        for (int j = 0, sz = precalc[p].size(); j < sz; j++) {
            if (precalc[p][j] % div == 0) {
                if (min == -1)
                    min = precalc[p][j];
                else
                    max = precalc[p][j];
            }
        }

        cout << "Case " << i+1 << ": ";
        if (min == -1)
            cout << "impossible" << endl;
        else if (max == -1)
            cout << min << endl;
        else
            cout << min << " " << max << endl;
    }

    return 0;
}
