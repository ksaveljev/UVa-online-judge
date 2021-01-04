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
    int n, i, j;

    while (cin >> n >> i >> j) {
        if (i > j) swap(i, j);

        int start = 1;
        int end = 1 << n;
        int mid = end / 2;

        while (true) {
            if (i <= mid && j > mid) {
                cout << n << endl;
                break;
            }

            if (j <= mid) {
                end = mid;
            } else {
                start = mid + 1;
            }
            mid = (start - 1 + end) / 2;
            n--;
        }
    }

    return 0;
}
