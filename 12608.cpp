#include <iostream>
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
    int cases, weight_limit, n;
    int x[1001], w[1001];

    cin >> cases;

    while (cases--) {
        cin >> weight_limit >> n;

        rep (i, n) {
            cin >> x[i] >> w[i];
        }
        
        int current_weight = 0, distance = 0;

        rep (i, n) {
            if (current_weight + w[i] == weight_limit) {
                distance += 2 * x[i];
                current_weight = 0;
            } else if (current_weight + w[i] > weight_limit) {
                distance += 2 * x[i];
                current_weight = w[i];
            } else {
                current_weight += w[i];
            }
        }

        if (current_weight) distance += 2 * x[n-1];
        cout << distance << endl;
    }

    return 0;
}
