#include <iostream>
#include <vector>
#include <algorithm>
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
    int n, d, r, duration;

    while (cin >> n >> d >> r) {
        if (n == 0 && d == 0 && r == 0) break;

        vector<int> morning;
        vector<int> evening;

        rep (i, n) {
            cin >> duration;
            morning.push_back(duration);
        }

        rep (i, n) {
            cin >> duration;
            evening.push_back(duration);
        }

        sort (morning.begin(), morning.end(), std::greater<int>());
        sort (evening.begin(), evening.end());

        int result = 0;

        rep (i, n) {
            result += max(0, (morning[i] + evening[i] - d) * r);
        }

        cout << result << endl;
    }

    return 0;
}
