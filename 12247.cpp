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

bool prince_wins(vector<int> princess, vector<int> prince, int guess) {
    prince.push_back(guess);

    vector<int>::iterator it;

    sort(princess.begin(), princess.end());
    sort(prince.begin(), prince.end());

    int wins = 0;

    rep (i, 3) {
        int prince_card = prince[i];

        it = upper_bound(princess.begin(), princess.end(), prince_card);

        if (it == princess.end()) {
            wins++;
            princess.erase(princess.begin());
        } else {
            princess.erase(it);
        }
    }

    return wins > 1;
}

int main(void) {
    int card;

    while (cin >> card) {
        if (card == 0)
            break;

        bool taken[53] = {false};
        vector<int> princess, prince;

        princess.push_back(card);
        taken[card] = true;
        rep (i, 2) {
            cin >> card;
            taken[card] = true;
            princess.push_back(card);
        }

        rep (i, 2) {
            cin >> card;
            taken[card] = true;
            prince.push_back(card);
        }

        int result = -1;
        REPI (i, 1, 52) {
            if (taken[i]) continue;

            if (prince_wins(princess, prince, i)) {
                result = i;
                break;
            }
        }

        cout << result << endl;
    }

    return 0;
}
