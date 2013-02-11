#include <iostream>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int n, bets[10001];

    while ((cin >> n) && n) {
        rep (i,n)
            cin >> bets[i];

        int current = 0;
        int best = 0;
        rep (i, n) {
            current += bets[i];
            current = current < 0 ? 0 : current;
            if (current > best)
                best = current;
        }

        if (best == 0)
            cout << "Losing streak." << endl;
        else
            cout << "The maximum winning streak is " << best << "." << endl;
    }

    return 0;
}
