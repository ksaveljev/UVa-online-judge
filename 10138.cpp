#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <sstream>
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

struct photo {
    string time;
    string action;
    int pos;
    bool operator<(const photo &other) const {
        return time < other.time;
    }
};

int main(void) {
    int cases;
    int toll[24];
    string license;
    string input;
    photo tmp;

    cin >> cases;

    while (cases--) {
        rep (i, 24) cin >> toll[i];
        cin.ignore(100, '\n');

        map< string, vector<photo> > photos;

        while (getline(cin, input)) {
            if (input == "") break;

            istringstream iss(input);
	    iss >> license >> tmp.time >> tmp.action >> tmp.pos;

            photos[license].push_back(tmp);
        }

        for (map< string, vector<photo> >::iterator it = photos.begin(); it != photos.end(); it++) {
            vector<photo> &v = it->second;

            sort(v.begin(), v.end());

            int cost = 0;

            REP (i, 1, sz(v)) {
                if (v[i].action == "exit" && v[i-1].action != "exit") {
                    int hour = (v[i-1].time[6] - '0') * 10 + v[i-1].time[7] - '0';
                    if (v[i].pos > v[i-1].pos) {
                        cost += (v[i].pos - v[i-1].pos) * toll[hour] + 100;
                    } else {
                        cost += (v[i-1].pos - v[i].pos) * toll[hour] + 100;
                    }
                }
            }

            if (cost > 0) {
                printf("%s $%.2lf\n", (it->first).c_str(), cost / 100.0 + 2);
            }
        }

        if (cases) cout << endl;
    }

    return 0;
}
