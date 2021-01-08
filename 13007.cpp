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

int cards[5] = {1, 10, 100, 1000, 10000};

int main(void) {
    int n, m, b, tmp, daedalus;

    while (cin >> n >> m) {
        int best = 0;
        int won = 0;
        int d;

        while (m--) {
            cin >> b;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                cin >> tmp;
                if (i == 0) d = tmp;
                sum += tmp;
            }

            if (sum <= b) {
                won += d;
            }
            sum -= d;

            for (int i = 4; i >= 0; i--) {
                if (sum + cards[i] <= b) {
                    best += cards[i];
                    break;
                }
            }
        }

        cout << best - won << endl;
    }

    return 0;
}
