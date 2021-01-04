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

int n, m;

int main(void) {
    int tmp;

    while (cin >> n >> m) {
        int result = 0;
        for (int i = 0; i < n; i++) {
            bool ok = true;
            for (int j = 0; j < m; j++) {
                cin >> tmp;
                if (tmp == 0) ok = false;
            }
            if (ok) result++;
        }
        cout << result << endl;
    }

    return 0;
}
