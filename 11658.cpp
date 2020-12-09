#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

bool dp[10001];

int main(void) {
    int n, x;
    int a, b;
    char c;

    while (cin >> n >> x) {
        if (n == 0 && x == 0) break;

        x--;

        vector<int> nums(n);
        rep (i, n) {
            cin >> a >> c >> b;
            nums[i] = a * 100 + b;
        }

        if (nums[x] > 5000) {
            cout << "100.00" << endl;
        } else {
            rep (i, 10001) dp[i] = false;
            dp[0] = true;

            rep (i, n) {
                if (i == x) continue;

                for (int j = 10000; j >= 0; j--) {
                    if (dp[j] && j + nums[i] < 10001) {
                        dp[j+nums[i]] = true;
                    }
                }
            }

            int best = -1;

            rep (i, 10001) {
                if (dp[i] && nums[x] + i > 5000) {
                    if (best == -1) {
                        best = nums[x] + i;
                    } else if (nums[x] + i < best) {
                        best = nums[x] + i;
                    }
                }
            }

            if (best == -1) {
                cout << "0.00" << endl;
            } else {
                double result = nums[x] * 100.0 / (best * 1.0);
                printf("%.2f\n", result);
            }
        }
    }

    return 0;
}
