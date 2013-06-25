#include <iostream>
#include <string>
#include <cassert>
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
    int t, n, k;
    string names;

    cin >> t;

    REPI (case_number, 1, t) {
        cin >> n >> k >> names;

        assert(n == names.size());

        map<char,int> last_visit;
        int result = 0;

        rep (i, n) {
            if (last_visit.find(names[i]) == last_visit.end()) {
                last_visit[names[i]] = i;
            } else {
                if (last_visit[names[i]] + k >= i) {
                    result++;
                }
                last_visit[names[i]] = i;
            }
        }

        cout << "Case " << case_number << ": " << result << endl;
    }

    return 0;
}
