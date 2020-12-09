#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main(void) {
    int L, G, x, r;
    pair<int,int> tmp;

    while (cin >> L >> G) {
        if (L == 0 && G == 0) {
            break;
        }

        vector< pair<int,int> > gs;

        rep (i, G) {
            cin >> x >> r;
            gs.push_back(make_pair(x - r, x + r));
        }

        sort(gs.begin(), gs.end());

        int start = 0;
        bool ok = true;
        rep (i, G) {
            if (gs[i].second <= start) {
                continue;
            } else if (gs[i].first <= start && gs[i].second > start) {
                start = gs[i].second;
            } else {
                ok = false;
                break;
            }
        }

        if (start < L) {
            ok = false;
        }

        if (!ok) {
            cout << -1 << endl;
        } else {
            int idx = 0;
            int taken = 0;
            start = 0;

            while (start < L) {
                int end = gs[idx].second;
                taken++;
                idx++;
                while (idx < G && gs[idx].first <= start) {
                    if (gs[idx].second > end) {
                        end = gs[idx].second;
                    }
                    idx++;
                }
                start = end;
            }

            cout << G - taken << endl;
        }
    }

    return 0;
}
