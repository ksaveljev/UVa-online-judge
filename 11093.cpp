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
    int T, N, tmp;

    cin >> T;

    REPI (case_number, 1, T) {
        cout << "Case " << case_number << ": ";

        vector<int> p, q;

        cin >> N;

        rep (i, N) {
            cin >> tmp;
            p.push_back(tmp);
        }

        rep (i, N) {
            cin >> tmp;
            q.push_back(tmp);
        }

        bool found = false;

        rep (i, N) {
            int petrol = 0;
            int pos = i;
            bool ok = true;

            rep (j, N) {
                petrol += p[pos];
                petrol -= q[pos];
                if (petrol < 0) {
                    ok = false;
                    if (pos < i) i = N;
                    else i = pos;
                    break;
                }
                pos = (pos + 1) % N;
            }

            if (ok) {
                found = true;
                cout << "Possible from station " << i + 1 << endl;
                break;
            }
        }

        if (!found) cout << "Not possible" << endl;
    }

    return 0;
}
