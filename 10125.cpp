#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define sz(i) i.size()
#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)

int main(void) {
    int n, tmp;
    int nums[1002];

    while (cin >> n) {
        if (n == 0) break;

        map<int,bool> subset;

        rep (i, n) {
            cin >> nums[i];
            subset[nums[i]] = true;
        }

        sort(nums, nums + n, greater<int>());

        bool found = false;
        int result;

        rep (i, n) {
            rep (j, n) {
                if (i == j) continue;

                rep (k, n) {
                    if (k == i || k == j) continue;

                    tmp = nums[i] - nums[j] - nums[k];
                    if (subset.find(tmp) != subset.end() && tmp != nums[i] && tmp != nums[j] && tmp != nums[k]) {
                        found = true;
                        result = nums[i];
                        i = j = k = n;
                    }
                }
            }
        }

        if (found) cout << result << endl;
        else cout << "no solution" << endl;
    }

    return 0;
}
