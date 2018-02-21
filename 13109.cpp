#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int t, m, w, e;

    cin >> t;

    while (t--) {
        cin >> m >> w;
        vector<int> weights(m);

        rep (i, m) {
            cin >> e;
            weights[i] = e;
        }

        sort(weights.begin(), weights.end());

        int count = 0;
        int sum = 0;

        rep (i, m) {
            if (sum + weights[i] > w) break;
            sum += weights[i];
            count += 1;
        }

        cout << count << endl;
    }

    return 0;
}
