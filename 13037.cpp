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

int unique(set<int>& a, set<int>& b, set<int>& c) {
    int result = 0;
    for (int x: a) {
        if (b.find(x) == b.end() && c.find(x) == c.end()) {
            result++;
        }
    }
    return result;
}

int missing(set<int>& a, set<int>& b, set<int>& c) {
    int result = 0;
    for (int x: b) {
        if (c.find(x) != c.end() && a.find(x) == a.end()) {
            result++;
        }
    }
    return result;
}

int main(void) {
    int t, tmp;
    int L, R, S;

    cin >> t;

    for (int T = 1; T <= t; T++) {
        cout << "Case #" << T << ":" << endl;
        cin >> L >> R >> S;

        set<int> LL, RR, SS;

        for (int i = 0; i < L; i++) {
            cin >> tmp;
            LL.insert(tmp);
        }

        for (int i = 0; i < R; i++) {
            cin >> tmp;
            RR.insert(tmp);
        }

        for (int i = 0; i < S; i++) {
            cin >> tmp;
            SS.insert(tmp);
        }

        cout << unique(LL, RR, SS) << " " << missing(LL, RR, SS) << endl;
        cout << unique(RR, LL, SS) << " " << missing(RR, LL, SS) << endl;
        cout << unique(SS, RR, LL) << " " << missing(SS, RR, LL) << endl;
    }

    return 0;
}
