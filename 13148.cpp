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
    set<int> result = {1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441, 1000000, 1771561, 2985984, 4826809, 7529536, 11390625, 16777216, 24137569, 34012224, 47045881, 64000000, 85766121};
    int n;

    while (cin >> n) {
        if (n == 0) break;

        if (result.find(n) == result.end()) {
            cout << "Ordinary" << endl;
        } else {
            cout << "Special" << endl;
        }
    }

    return 0;
}
