#include <iostream>
#include <algorithm>
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

bool theTruthIsOutThere(const pair<int,int> &a, const pair<int,int> &b) {
    return a.second > b.second;
}

int main(void) {
    int M, N, tmp;
    pair<int,int> members[72], tables[52];

    while (cin >> M >> N) {
        if (M == 0 && N == 0) break;

        vector<int> seatings[M+1];

        rep (i, M) {
            cin >> tmp;
            members[i] = make_pair(i+1, tmp);
        }

        rep (i, N) {
            cin >> tmp;
            tables[i] = make_pair(i+1, tmp);
        }

        sort (members, members + M, theTruthIsOutThere);

        bool ok = true;

        rep (i, M) {
            tmp = members[i].second;

            int seated = 0;
	    sort (tables, tables + N, theTruthIsOutThere);

            rep (j, N) {
                if (tables[j].second > 0) {
                    tables[j].second--;
                    seatings[members[i].first].push_back(tables[j].first);
                    seated++;
                }

                if (seated == tmp) break;
            }

            if (seated != tmp) {
                ok = false;
                break;
            }
        }

        if (ok) {
            cout << 1 << endl;
            rep (i, M) {
                sort (seatings[i+1].begin(), seatings[i+1].end());
                rep (j, sz(seatings[i+1])) {
                    if (j > 0) cout << " ";
                    cout << seatings[i+1][j];
                }
                cout << endl;
            }
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}
