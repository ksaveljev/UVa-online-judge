#include <iostream>
#include <map>
#include <set>
#include <cstdio>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)

int main(void) {
    int k, n, m, tmp;

    cin >> k;

    REPI(case_number, 1, k) {
        cin >> n;

        set<int> friends[n];
        map<int,int> stamps;

        rep(i, n) {
            cin >> m;

            rep(j, m) {
                cin >> tmp;

                if (stamps.find(tmp) == stamps.end())
                    stamps[tmp] = 1;
                else if (friends[i].find(tmp) == friends[i].end())
                    stamps[tmp] += 1;

                friends[i].insert(tmp);
            }
        }

        int unique_stamps = 0;

        for (map<int,int>::iterator it = stamps.begin(); it != stamps.end(); it++) {
            if (it->second == 1)
                unique_stamps++;
        }

        cout << "Case " << case_number << ":";

        rep (i, n) {
            int count = 0;

            for (set<int>::iterator it = friends[i].begin(); it != friends[i].end(); it++) {
                if (stamps[(*it)] == 1)
                    count++;
            }

            if (unique_stamps == 0)
                printf(" %.6f%%", 100.0 / n);
            else
                printf(" %.6f%%", count * 100.0 / unique_stamps);
        }

        cout << endl;
    }

    return 0;
}
