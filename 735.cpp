#include <iostream>
#include <set>
#include <vector>
#include <cstring>
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
    int n;
    set<int> scores;
    bool taken[61][61][61];

    scores.insert(50);

    repi (i, 20) {
        scores.insert(i);
        scores.insert(i*2);
        scores.insert(i*3);
    }

    vector<int> values(scores.begin(), scores.end());

    while (cin >> n) {
        if (n <= 0) {
            cout << "END OF OUTPUT" << endl;
            break;
        }

        memset(taken, false, sizeof(taken));

        int combinations = 0, permutations = 0;

        rep (i, values.size()) {
            rep (j, values.size()) {
                rep (k, values.size()) {
                    if (values[i] + values[j] + values[k] != n) continue;

                    permutations++;

                    if (!taken[values[i]][values[j]][values[k]]) {
                        taken[values[i]][values[j]][values[k]] = true;
                        taken[values[i]][values[k]][values[j]] = true;
                        taken[values[j]][values[i]][values[k]] = true;
                        taken[values[j]][values[k]][values[i]] = true;
                        taken[values[k]][values[i]][values[j]] = true;
                        taken[values[k]][values[j]][values[i]] = true;
                        combinations++;
                    }
                }
            }
        }

        if (combinations == 0 && permutations == 0) {
            cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS." << endl;
        } else {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << combinations << "." << endl;
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << permutations << "." << endl;
        }
        cout << "**********************************************************************" << endl;
    }

    return 0;
}
