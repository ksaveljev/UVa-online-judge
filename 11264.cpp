#include <iostream>
#include <vector>
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
    int t, n, coin;

    cin >> t;

    rep (case_number, t) {
        cin >> n;

        vector<int> coins;

        rep (i, n) {
            cin >> coin;
            coins.push_back(coin);
        }

        int result = 1;
        int sum = 1;

        REP (i, 1, n) {
            if (i == n-1) {
                result++;
            } else {
                if (sum + coins[i] < coins[i+1]) {
                    result++;
                    sum += coins[i];
                }
            }
        }

        cout << result << endl;
    }

    return 0;
}
