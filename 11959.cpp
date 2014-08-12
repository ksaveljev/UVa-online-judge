#include <iostream>
#include <string>
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
    int number_of_cases;
    string mary, sue;

    int rotations[24][6] = {
        {0, 1, 2, 3, 4, 5},
        {0, 1, 3, 4, 5, 2},
        {0, 1, 5, 2, 3, 4},
        {0, 1, 4, 5, 2, 3},
        {1, 0, 4, 3, 2, 5},
        {1, 0, 3, 2, 5, 4},
        {1, 0, 2, 5, 4, 3},
        {1, 0, 5, 4, 3, 2},
        {4, 2, 0, 3, 1, 5},
        {4, 2, 3, 1, 5, 0},
        {4, 2, 1, 5, 0, 3},
        {4, 2, 5, 0, 3, 1},
        {2, 4, 1, 3, 0, 5},
        {2, 4, 3, 0, 5, 1},
        {2, 4, 0, 5, 1, 3},
        {2, 4, 5, 1, 3, 0},
        {5, 3, 2, 0, 4, 1},
        {5, 3, 0, 4, 1, 2},
        {5, 3, 4, 1, 2, 0},
        {5, 3, 1, 2, 0, 4},
        {3, 5, 2, 1, 4, 0},
        {3, 5, 1, 4, 0, 2},
        {3, 5, 4, 0, 2, 1},
        {3, 5, 0, 2, 1, 4}
    };

    cin >> number_of_cases;

    while (number_of_cases--) {
        cin >> mary >> sue;

        bool ok = false;

        rep (i, 24) {
            ok = true;

            rep (j, 6) {
                if (mary[j] != sue[rotations[i][j]]) {
                    ok = false;
                    break;
                }
            }

            if (ok) break;
        }

        if (ok) cout << "Equal" << endl;
        else cout << "Not Equal" << endl;
    }

    return 0;
}
