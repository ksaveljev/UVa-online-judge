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
#include <cstring>
using namespace std;

const int maxN = 1e5;
int sum[maxN][10];

int main(void) {
    int n;

    while (cin >> n) {
        int a;
        memset(sum, 0, sizeof sum);
        for (int i = 0; i < n; i++) {
            cin >> a;
            if (i > 0) {
                for (int j = 0; j < 10; j++) {
                    sum[i][j] = sum[i-1][j];
                }
            }
            sum[i][a]++;
        }

        int q, R, L, tmp;
        cin >> q;

        while (q--) {
            cin >> L >> R;
            --L, --R;
            int result = 0;

            for (int i = 0; i < 10; i++) {
                tmp = sum[R][i] - (L>0?sum[L-1][i]:0);
                if (tmp > 0) result++;
            }

            cout << result << endl;
        }
    }

    return 0;
}
