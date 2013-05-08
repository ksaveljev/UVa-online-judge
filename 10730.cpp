#include <iostream>
#include <vector>
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
    int n, tmp, diff;
    char c;

    while (cin >> n) {
        if (n == 0)
            break;

        cin >> c;

        vector<int> seq;

        rep (i, n) {
            cin >> tmp;
            seq.push_back(tmp);
        }

        map<int,bool> visited;
        bool found = false;

        rep (i, n) {
            visited.clear();

            rep (j, i) {
                diff = seq[i] - seq[j];
                visited[diff] = true;
            }

            REP (j, i+1, n) {
                diff = seq[j] - seq[i];
                if (visited.find(diff) != visited.end()) {
                    found = true;
                    break;
                }
            }

            if (found)
                break;
        }

        if (found)
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }

    return 0;
}
